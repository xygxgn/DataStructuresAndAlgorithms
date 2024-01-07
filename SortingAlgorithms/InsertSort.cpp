#include <iostream>
#include <vector>
#define GUARD -__INT_MAX__-1
// 11
// 5 3 8 1 4 7 9 2 6 0 10
void insertSort(std::vector<int> &, int);
int main()
{
    int num;
    std::cin >> num;
    std::vector<int> group(num+1, GUARD);
    for (int i = 1; i != num+1; ++i)
        std::cin >> group[i];
    
    insertSort(group, num);
    for (int i = 1; i != num+1; ++i)
        std::cout << group[i] << " ";

    return 0;
}
void insertSort(std::vector<int> &group, int num)
{
    for (int i = 2; i != num+1; ++i)
        for (int j = i; group[j] < group[j-1]; --j)
            std::swap(group[j], group[j-1]);
}
