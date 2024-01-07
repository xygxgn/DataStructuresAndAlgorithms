#include <iostream>
#include <vector>
// 11
// 5 3 8 1 4 7 9 2 6 0 10
void quickSort(std::vector<int> &, int, int);
int main()
{
    int num;
    std::cin >> num;
    std::vector<int> group(num);
    for (int  i = 0; i != num; ++i)
        std::cin >> group[i];
    
    quickSort(group, 0, num-1);
    for (const auto &c : group)
        std::cout << c << " ";

    return 0;
}
void quickSort(std::vector<int> &group, int first, int last)
{
    if (first >= last)
        return;
    int left = first, right = last;
    while (left < right)
    {
        while (left < right && group[left] < group[right])
            ++left;
        if (left < right)
            std::swap(group[left], group[right--]);
        while (left < right && group[left] < group[right])
            --right;
        if (left < right)
            std::swap(group[left++], group[right]);
    }
    quickSort(group, first, left-1);
    quickSort(group, right+1, last);
}