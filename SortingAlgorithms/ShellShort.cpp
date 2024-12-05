#include <iostream>
#include <vector>
// 11
// 5 3 8 1 4 7 9 2 6 0 10
void shellSort(std::vector<int> &, int);
int main()
{
    int num;
    std::cin >> num;
    std::vector<int> group(num);
    for (int  i = 0; i != num; ++i)
        std::cin >> group[i];
    
    shellSort(group, num);
    for (const auto &c : group)
        std::cout << c << " ";

    return 0;
}
void shellSort(std::vector<int> &group, int num)
{
    for (int d = num/2; d >= 1; d/=2)
        for (int i = d; i != num-1; ++i)
            for (int j = i; j >= d && group[j] < group[j-d]; j -= d)
                std::swap(group[j], group[j-d]);
}