#include <iostream>
#include <vector>
/**
 * 最大堆最小堆建立
 * 堆的插入删除
 **/
// 9
// 5 3 8 1 4 7 9 2 6
int deleteMinHeap(std::vector<int> &);
int deleteMaxHeap(std::vector<int> &);
void insertMinHeap(std::vector<int> &, int);
void insertMaxHeap(std::vector<int> &, int);
void buildMinHeap(std::vector<int> &, int);
void buildMaxHeap(std::vector<int> &, int);
int main()
{
    int nodeNum;
    std::cin >> nodeNum;
    std::vector<int> heap;
    heap.reserve(nodeNum);

    buildMinHeap(heap, nodeNum);

    for (unsigned int i = 0; i != nodeNum; ++i)
        std::cout << deleteMinHeap(heap) << " ";

    return 0;
}
/** 直接建堆 O(n) **/
void buildMaxHeap(std::vector<int> &heap, int nodeNum)
{
    for (int data, i = 0; i != nodeNum; ++i)
    {
        std::cin >> data;
        heap.push_back(data);
    }
    for (int i = (heap.size()-1)>>1; i >= 0; --i)
        for (int parent{i}, child{(i<<1)+1}; child <= heap.size()-1; parent = child, ++(child<<=1))
        {
            if (child != heap.size()-1 && heap[child] < heap[child+1])
                ++child;
            if (heap[parent] < heap[child])
                std::swap(heap[parent], heap[child]);
            else
                break;
        }
}
/** 插入建堆 O(nlogn) **/
// void buildMaxHeap(std::vector<int> &heap, int nodeNum)
// {
//     for (int data, i = 0; i != nodeNum; ++i)
//     {
//         std::cin >> data;
//         insertMaxHeap(heap, data);
//     }
// }
void insertMaxHeap(std::vector<int> &heap, int data)
{
    heap.push_back(data);
    for (int i = heap.size()-1; i && heap[i] > heap[(i-1)>>1]; i = (i-1)>>1)
        std::swap(heap[i], heap[(i-1)>>1]);
}
int deleteMaxHeap(std::vector<int> &heap)
{
    if (heap.empty())
        return 0;
    int maxroot = heap.front();
    heap[0] = heap.back();
    heap.pop_back();
    for (int parent{0}, child{1}; child <= heap.size()-1; parent = child, ++(child<<=1))
    {
        if (child != heap.size()-1 && heap[child] < heap[child+1])
            ++child;
        if (heap[parent] < heap[child])
            std::swap(heap[parent], heap[child]);
        else
            break;
    }
    return maxroot;
}
void buildMinHeap(std::vector<int> &heap, int nodeNum)
{
    for (int data, i = 0; i != nodeNum; ++i)
    {
        std::cin >> data;
        heap.push_back(data);
    }
    for (int i = (heap.size()-1)>>1; i >= 0; --i)
        for (int parent{i}, child{(i<<1)+1}; child <= heap.size()-1; parent = child, ++(child<<=1))
        {
            if (child != heap.size()-1 && heap[child] > heap[child+1])
                ++child;
            if (heap[parent] > heap[child])
                std::swap(heap[parent], heap[child]);
            else
                break;
        }
}
// void buildMinHeap(std::vector<int> &heap, int nodeNum)
// {
//     for (int data, i = 0; i != nodeNum; ++i)
//     {
//         std::cin >> data;
//         insertMinHeap(heap, data);
//     }
// }
void insertMinHeap(std::vector<int> &heap, int data)
{
    heap.push_back(data);
    for (int i = heap.size()-1; i && heap[i] < heap[(i-1)>>1]; i = (i-1)>>1)
        std::swap(heap[i], heap[(i-1)>>1]);
}
int deleteMinHeap(std::vector<int> &heap)
{
    if (heap.empty())
        return 0;
    int minroot = heap.front();
    heap[0] = heap.back();
    heap.pop_back();
    for (int parent{0}, child{1}; child <= heap.size()-1; parent = child, ++(child<<=1))
    {
        if (child != heap.size()-1 && heap[child] > heap[child+1])
            ++child;
        if (heap[parent] > heap[child])
            std::swap(heap[parent], heap[child]);
        else
            break;
    }
    return minroot;
}