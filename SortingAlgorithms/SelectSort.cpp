#include <iostream>
#include <vector>
// 11
// 5 3 8 1 4 7 9 2 6 0 10
void selectSort(std::vector<int> &, int);
int main()
{
    int num;
    std::cin >> num;
    std::vector<int> group(num);
    for (int  i = 0; i != num; ++i)
        std::cin >> group[i];
    
    selectSort(group, num);
    for (const auto &c : group)
        std::cout << c << " ";

    return 0;
}
void selectSort(std::vector<int> &group, int num)
{
    for (int i = 0; i != num-1; ++i)
        for (int j = i+1; j != num; ++j)
            if (group[j] < group[i])
                std::swap(group[i], group[j]);
}