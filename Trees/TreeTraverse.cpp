#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
/**
 * 结构数组表示二叉树
 * 前序遍历
 * 中序遍历
 * 后序遍历
 * 层序遍历
 * 递归打印控制最后一个空格不打印
 **/
/* test data1 */
// 8
// A 1 2
// B 3 4
// C 5 #
// D # #
// E 6 #
// G 7 #
// F # #
// H # #
/* test data2 */
// 8
// G # 4
// B 7 6
// F # #
// A 5 1
// H # #
// C 0 #
// D # #
// E 2 #

struct TNode
{
    char data;
    signed char left, right;
};
int buildTree(std::vector<TNode> &tree, int);
void preOrder(const std::vector<TNode> &, const int, bool&);
void inOrder(const std::vector<TNode> &, const int, bool&);
void postOrder(const std::vector<TNode> &, const int, bool&);
void levelOrder(const std::vector<TNode> &, int, bool &);
int main()
{
    int nodeNum;
    std::cin >> nodeNum;
    std::vector<TNode> tree(nodeNum);
    int root{buildTree(tree, nodeNum)};

    bool firstprint = true;
    preOrder(tree, root, firstprint);
    std::cout << "\n";
    firstprint = true;
    inOrder(tree, root, firstprint);
    std::cout << "\n";
    firstprint = true;
    postOrder(tree, root, firstprint);
    std::cout << "\n";
    firstprint = true;
    levelOrder(tree, root, firstprint);
        
    return 0;
}
int buildTree(std::vector<TNode> &tree, int nodeNum)
{
    std::vector<bool> check(nodeNum,false);
    for (unsigned int i = 0; i != nodeNum; ++i)
    {
        std::cin >> tree[i].data >> tree[i].left >> tree[i].right;
        if (std::isdigit(tree[i].left))
        {
            tree[i].left -= '0';
            check[tree[i].left] = true;
        }
        else
            tree[i].left = -1;
        if (std::isdigit(tree[i].right))
        {
            tree[i].right -= '0';
            check[tree[i].right] = true;
        }
        else
            tree[i].right = -1;
    }
    return std::find(check.begin(), check.end(), false)-check.begin();
}
void preOrder(const std::vector<TNode> &tree, const int root, bool &firstprint)
{
    if (root == -1)
        return;
    firstprint ? std::cout << tree[root].data : std::cout << " " << tree[root].data;
    firstprint = false;
    preOrder(tree, tree[root].left, firstprint);
    preOrder(tree, tree[root].right, firstprint);
}
void inOrder(const std::vector<TNode> &tree, const int root, bool &firstprint)
{
    if (root == -1)
        return;
    inOrder(tree, tree[root].left, firstprint);
    firstprint ? std::cout << tree[root].data : std::cout << " " << tree[root].data;
    firstprint = false;
    inOrder(tree, tree[root].right, firstprint);
}
void postOrder(const std::vector<TNode> &tree, const int root, bool &firstprint)
{
    if (root == -1)
        return;
    postOrder(tree, tree[root].left, firstprint);
    postOrder(tree, tree[root].right, firstprint);
    firstprint ? std::cout << tree[root].data : std::cout << " " << tree[root].data;
    firstprint = false;
}
void levelOrder(const std::vector<TNode> &tree, int root, bool &firstprint)
{
    std::deque<int> Queue{root};
    while (!Queue.empty())
    {
        root = Queue.front();
        Queue.pop_front(); 
        firstprint ? std::cout << tree[root].data : std::cout << " " << tree[root].data;
        firstprint = false;
        if (tree[root].left != -1)
            Queue.push_back(tree[root].left);
        if (tree[root].right != -1)
            Queue.push_back(tree[root].right);
    }
}