#include <iostream>
#include <vector>
/**
 * 最小生成树 Prim算法
 * 贪心原则（点）
 * 适合稠密图 O(V^2)
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
/* text data */
// 4 5 3
// 0 1 2
// 0 2 4
// 0 3 1
// 1 3 2
// 2 3 3


int Prim(const std::vector<std::vector<int>> &, int);
void buildGraph(std::vector<std::vector<int>> &, int);
int main()
{
    int vertexNum, edgeNum, source;
    std::cin >> vertexNum >> edgeNum >> source;
    std::vector<std::vector<int>> MGraph(vertexNum, std::vector<int>(vertexNum, __INT_MAX__));
    buildGraph(MGraph, edgeNum);

    int MINLen = Prim(MGraph, source);
    std::cout << MINLen;

    return 0;
}
void buildGraph(std::vector<std::vector<int>> & MGraph, int edgeNum)
{
    for (int v1, v2, weight, i = 0; i != edgeNum; ++i)
    {
        std::cin >> v1 >> v2 >> weight;
        MGraph[v1][v2] = MGraph[v2][v1] = weight;
    }
    for (int i = 0; i != MGraph.size(); ++i)
        MGraph[i][i] = 0;
}
/** prim算法
 * dist:    到生成树的最短距离
 * MSTLen:  最小生成树的总长度
 * path:    最小生成树路径
 * count:   生成树节点数
 * guard:   岗哨
 **/
int Prim(const std::vector<std::vector<int>> &MGraph, int MST)
{

    int MSTLen{0}, count{0}, guard{-1};
    std::vector<int> dist{MGraph[MST]}, path(MGraph.size(),-1);
    for (int i = 0; i != MGraph.size(); ++i)
        if (MGraph[MST][i] != __INT_MAX__)
            path[i] = MST;
    for ( ; guard != MST; ++count)
    {
        guard = MST;
        for (int temp{__INT_MAX__}, j = 0; j != MGraph.size(); ++j)
            if (dist[j] != __INT_MAX__ && dist[j] && dist[j] < temp)
            {
                temp = dist[j];
                MST = j;
            }
        MSTLen += dist[MST];
        dist[MST] = 0;
        for (int k = 0; k != MGraph.size(); ++k)
            if (MGraph[MST][k] != __INT_MAX__ && dist[k] && MGraph[MST][k] < dist[k])
            {
                dist[k] = MGraph[MST][k];
                path[k] = MST;
            }
    }
    if (count == MGraph.size())
        return MSTLen;
    return 0;
}