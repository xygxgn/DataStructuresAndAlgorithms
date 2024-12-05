#include <iostream>
#include <vector>
/**
 * 最小生成树 Prim算法
 * 贪心原则（线）
 * 适合稀疏图 O(ElogE)
 * 最小堆、并查集
 **/
/* text data */
// 7 12 6
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
struct Edge
{
    int v1, v2, weight;
};
bool check(std::vector<int> &, Edge &);
Edge deleteMinHeap(std::vector<Edge> &);
std::vector<Edge> buildHeap(const std::vector<std::vector<int>> &, int);
int Kruskal(const std::vector<std::vector<int>> &, int);
void buildGraph(std::vector<std::vector<int>> &, int );
int main()
{
    int vertexNum, edgeNum, source;
    std::cin >> vertexNum >> edgeNum >> source;
    std::vector<std::vector<int>> MGraph(vertexNum, std::vector<int>(vertexNum,__INT_MAX__));
    buildGraph(MGraph, edgeNum);

    int MSTLen = Kruskal(MGraph, edgeNum);

    std::cout << MSTLen;

    return 0;
}
void buildGraph(std::vector<std::vector<int>> &MGraph, int edgeNum)
{
    for (int v1, v2, weight, i = 0; i != edgeNum; ++i)
    {
        std::cin >> v1 >> v2 >> weight;
        MGraph[v1][v2] = MGraph[v2][v1] = weight;
    }
    for (int i = 0; i != MGraph.size(); ++i)
        MGraph[i][i] = 0;
}
int Kruskal(const std::vector<std::vector<int>> &MGraph, int edgeNum)
{
    int MSTLen{0}, count{0};
    std::vector<int> checkSet(MGraph.size(), -1);
    std::vector<Edge> minHeap = buildHeap(MGraph, edgeNum);
    for (int guard{0}; guard != edgeNum && count != MGraph.size()-1; ++guard)
    {
        Edge minEdge = deleteMinHeap(minHeap);
        if (check(checkSet, minEdge))
        {
            MSTLen += minEdge.weight;
            ++count;
        }
    }
    if (count == MGraph.size()-1)
        return MSTLen;
    return 0;
}
std::vector<Edge> buildHeap(const std::vector<std::vector<int>> &MGraph, int edgeNum)
{
    std::vector<Edge> minHeap;
    minHeap.reserve(edgeNum);
    for (int i = 0; i != MGraph.size(); ++i)
        for (int j = i+1; j != MGraph.size(); ++j)
            if (MGraph[i][j] != __INT_MAX__)
                minHeap.push_back(Edge{i, j, MGraph[i][j]});
    for (int i = (edgeNum-1)>>1; i >= 0; --i)
        for (int parent = i, child = (parent<<1)-1; child <= edgeNum-1; parent = child, ++(child<<=1))
        {
            if (child != edgeNum-1 && minHeap[child].weight > minHeap[child+1].weight)
                ++child;
            if (minHeap[parent].weight > minHeap[child].weight)
                std::swap(minHeap[parent], minHeap[child]);
            else
                break;
        }
    return minHeap;
}
Edge deleteMinHeap(std::vector<Edge> &minHeap)
{
    Edge minEdge = minHeap.front();
    minHeap[0] = minHeap.back();
    minHeap.pop_back();
    for (int parent = 0, child = (parent<<1)+1; child <= minHeap.size()-1; parent = child, ++(child<<=1))
    {
        if (child != minHeap.size()-1 && minHeap[child].weight > minHeap[child+1].weight)
            ++child;
        if (minHeap[parent].weight > minHeap[child].weight)
            std::swap(minHeap[parent], minHeap[child]);
        else
            break;
    }
    return minEdge;
}
bool check(std::vector<int> &checkSet, Edge &minEdge)
{
    int v1 = minEdge.v1, v2 = minEdge.v2;
    while (checkSet[v1] != -1)
        v1 = checkSet[v1];
    while (checkSet[v2] != -1)
        v2 = checkSet[v2];
    if (v1 == v2 && v1 != -1)
        return false;
    checkSet[v2] = v1;
    return true;
}