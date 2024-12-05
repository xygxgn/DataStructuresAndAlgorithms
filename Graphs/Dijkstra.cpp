#include <iostream>
#include <vector>
#include <algorithm>
/**
 * 图的单源最小路径（Dijkstra算法）
 * 存储结构：邻接矩阵
 * 图的性质：有权图、有向图
 **/

/* text data */
// 7 12 0
// 0 1 2
// 0 3 1
// 1 3 3
// 1 4 10
// 2 0 4
// 2 5 5
// 3 2 2
// 3 4 2
// 3 5 8
// 3 6 4
// 4 6 6
// 6 5 1

std::vector<std::vector<int>> buildGraph(int, int);
std::pair<std::vector<int>, std::vector<int>> Dijkstra(const std::vector<std::vector<int>> &, int);
void printPath(std::vector<int>, std::vector<int>, int);
int main()
{
    int vertexNum, edgeNum, source;
    std::cin >> vertexNum >> edgeNum >> source;
    std::vector<std::vector<int>> graph {buildGraph(vertexNum, edgeNum)};
    auto shortestPair{Dijkstra(graph, source)};

    printPath(shortestPair.first, shortestPair.second, source);

    return 0;
}
std::vector<std::vector<int>> buildGraph(int vertexNum, int edgeNum)
{
    std::vector<std::vector<int>> graph(vertexNum, std::vector<int>(vertexNum, __INT_MAX__));
    for (int v1, v2, weight, i = 0; i != edgeNum; ++i)
    {
        std::cin >> v1 >> v2 >> weight;
        graph[v1][v2] = weight;
    }
    for (int i = 0; i != vertexNum; ++i)
        graph[i][i] = 0;
    return graph;
}
/** Dijkstra算法
 * collected:   未收录点
 * dist:        收录点到源点的最短距离
 * path:        最短距离对应的路径
 **/
std::pair<std::vector<int>, std::vector<int>> 
Dijkstra(const std::vector<std::vector<int>> &graph, int vertex)
{
    std::vector<bool> collected(graph.size(), false);
    std::vector<int> dist{graph[vertex]}, path(graph.size(), -1);
    for (unsigned int i = 0; i != graph.size(); ++i)
        if (dist[i] != __INT_MAX__ && i != vertex)
            path[i] = vertex;
    collected[vertex] = true;
    for ( ; std::find(collected.begin(), collected.end(), false) != collected.end(); )
    {
        vertex = std::find(collected.begin(), collected.end(), false)-collected.begin();
        for (unsigned int i = 0; i != graph.size(); ++i)
            if (!collected[i] && dist[i] < dist[vertex])
                vertex = i;
        collected[vertex] = true;
        for (unsigned int i = 0; i != graph.size(); ++i)
            if (collected[i] == false && graph[vertex][i] != __INT_MAX__)
                if (dist[vertex] + graph[vertex][i] < dist[i])
                {
                    dist[i] = dist[vertex] + graph[vertex][i];
                    path[i] = vertex;
                }
    }
    return std::pair<std::vector<int>, std::vector<int>>{path, dist};
}
void printPath(std::vector<int> path, std::vector<int> dist, int vertex)
{
    std::vector<int> goalPath;
    for (int goal = 0, next = goal; goal != path.size(); ++goal, next = goal)
    {
        while (next != -1)
        {
            goalPath.push_back(next);
            next = path[next];
        }
        std::cout << "from " << vertex << " to " << goal << ": ";
        for (auto riter = goalPath.rbegin(); riter != goalPath.rend(); ++riter)
            riter!=goalPath.rend()-1 ? std::cout << *riter << "->" : std::cout << *riter;
        std::cout << "\ndistance: " << dist[goal] << "\n";
        goalPath.clear();
    }
}