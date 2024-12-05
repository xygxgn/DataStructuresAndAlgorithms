#include <iostream>
#include <vector>
// 11
// 5 3 8 1 4 7 9 2 6 0 10
void betterBubbleSort(std::vector<int> &, int);
void bubbleSort(std::vector<int> &, int);
int main()
{
    int num;
    std::cin >> num;
    std::vector<int> group(num);
    for (int  i = 0; i != num; ++i)
        std::cin >> group[i];
    
    betterBubbleSort(group, num);
    for (const auto &c : group)
        std::cout << c << " ";

    return 0;
}
void bubbleSort(std::vector<int> &group, int num)
{
    for (int i = 0; i != num-1; ++i)
        for (int j = num-1; j != i; --j)
            if (group[j] < group[j-1])
                std::swap(group[j], group[j-1]);
}
void betterBubbleSort(std::vector<int> &group, int num)
{
    for (int exchange = num-1, i = 0; i != num-1; i = exchange, exchange = num-1)
        for (int j = num-1; j != i; --j)
            if (group[j] < group[j-1])
            {
                std::swap(group[j], group[j-1]);
                exchange = j;
            }
}
