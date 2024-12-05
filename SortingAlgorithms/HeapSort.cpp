#include <iostream>
#include <vector>
// 11
// 5 3 8 1 4 7 9 2 6 0 10
int deleteMaxHeap(std::vector<int> &, int);
void buildMaxHeap(std::vector<int> &, int);
void heapSort(std::vector<int> &, int);
int main()
{
    int num;
    std::cin >> num;
    std::vector<int> group(num);
    for (int  i = 0; i != num; ++i)
        std::cin >> group[i];
    
    heapSort(group, num);
    for (const auto &c : group)
        std::cout << c << " ";

    return 0;
}
void heapSort(std::vector<int> &group, int num)
{
    buildMaxHeap(group, num);

    while (--num)
        group[num] = deleteMaxHeap(group, num+1);
}
void buildMaxHeap(std::vector<int> &group, int num)
{
    for (int i = (num-1)>>1; i >= 0; --i)
        for (int parent{i}, child{(parent<<1)+1}; child <= num-1; parent = child, ++(child<<=1))
        {
            if (child != num-1 && group[child] < group[child+1])
                ++child;
            if (group[parent] < group[child])
                std::swap(group[parent], group[child]);
            else
                break;
        }
}
int deleteMaxHeap(std::vector<int> &group, int num)
{
    int maximum = group.front();
    group[0] = group[num-1];
    for (int parent{0}, child{1}; child <= num-1; parent = child, ++(child<<=1))
    {
        if (child != num-1 && group[child] < group[child+1])
            ++child;
        if (group[parent] < group[child])
            std::swap(group[parent], group[child]);
        else
            break;
    }
    return maximum;
}