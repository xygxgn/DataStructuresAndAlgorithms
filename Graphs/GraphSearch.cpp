#include <iostream>
#include <vector>
#include <deque>
/**
 * 图的深度优先搜索和广度优先搜索
 * 存储结构：邻接矩阵
 * 图的特点：无权图、无向图
 **/
/* text data */
// 10 10 0
// 0 1
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 8
// 8 9
// 0 9

std::vector<std::vector<int>> buildGraph(int, int);
void DFS(const std::vector<std::vector<int>> &, int, bool []);
void BFS(const std::vector<std::vector<int>> &, int, bool []);
int main()
{
    int vertexNum, edgeNum, vertex;
    std::cin >> vertexNum >> edgeNum >> vertex;
    std::vector<std::vector<int>> graph {buildGraph(vertexNum, edgeNum)};

    bool visited[vertexNum] {false};
    DFS(graph, vertex, visited);
    std::cout << "\n";
    for (bool &c : visited)
        c = false;
    BFS(graph, vertex, visited);
}
/* build graph */
std::vector<std::vector<int>> buildGraph(int vertexNum, int edgeNum)
{
    std::vector<std::vector<int>> graph(vertexNum, std::vector<int>(vertexNum));
    for (int v1, v2, i = 0; i != edgeNum; ++i)
    {
        std::cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    return graph;
}
/* DFS */
void DFS(const std::vector<std::vector<int>> &graph, int vertex, bool visited[])
{
    visited[vertex] = true;
    std::cout << vertex << " ";
    for (unsigned int i = 0; i != graph.size(); ++i)
        if (graph[vertex][i] && !visited[i])
                DFS(graph, i, visited);
}
/* BFS */
void BFS(const std::vector<std::vector<int>> &graph, int vertex, bool visited[])
{
    std::deque<int> Queue;
    visited[vertex] = true;
    Queue.push_back(vertex);
    while (!Queue.empty())
    {
        vertex = Queue.front();
        std::cout << vertex << " ";
        Queue.pop_front();
        for (unsigned int i = 0; i != graph.size(); ++i)
            if (graph[vertex][i] && !visited[i])
            {
                visited[i] = true;
                Queue.push_back(i);
            }
    }
}