#include <iostream>
#include <vector>
#include <iomanip>
/**
 * 图的多源最小路径（Floyd算法）
 * 存储结构：邻接矩阵
 * 图的性质：有权图、有向图
 **/
/* text data */
// 7 12
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
std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>
Floyd(const std::vector<std::vector<int>> &);
void printDist(const std::vector<std::vector<int>> &);
void printPath(const std::vector<std::vector<int>> &, int, int);
void print(std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>, int, int);
int main()
{
    int vertexNum, edgeNum;
    std::cin >> vertexNum >> edgeNum;
    std::vector<std::vector<int>> graph{buildGraph(vertexNum, edgeNum)};

    auto shortestPair{Floyd(graph)};

    print(shortestPair, 0, 5);

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
    for (int i = 0 ; i != vertexNum; ++i)
        graph[i][i] = 0;
    return graph;
}
/** Floyd算法
 * dist:        截止当前收录点的多源最短距离
 * path:        最短距离对应的路径
 **/
std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>
Floyd(const std::vector<std::vector<int>> &graph)
{
    std::vector<std::vector<int>> dist{graph}, path(graph.size(), std::vector<int>(graph.size(), -1));
    for (int k = 0; k != graph.size(); ++k)
        for (int i = 0; i != graph.size(); ++i)
            for (int j = 0; j != graph.size(); ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j] && dist[i][k] != __INT_MAX__ && dist[k][j] != __INT_MAX__)
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
                    
    return std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>{path, dist};
}
void print(std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> shortestPair, int row, int col)
{
    std::cout << "from " << row << " to " << col << ": ";
    std::cout << row << "->";
    printPath(shortestPair.first, row, col);
    std::cout << col << "\n";
    std::cout << "The shortest dist matrix:\n";
    printDist(shortestPair.second);
}
void printDist(const std::vector<std::vector<int>> &dist)
{
    for (const auto &c : dist)
    {
        for (const int &d : c)
            std::cout << std::setw(10) << d << " ";
        std::cout << "\n";
    }
}
void printPath(const std::vector<std::vector<int>> &path, int row, int col)
{
    if (path[row][col] == -1)
        return;
    printPath(path, row, path[row][col]);
    std::cout << path[row][col] << "->";
    printPath(path, path[row][col], col);
}