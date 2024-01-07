#include <iostream>
#include <vector>
#include <deque>
/**
 * 中序后序建树
 * 中序后序求后序
 * 树的前序中序后序层序遍历
 * 控制递归中不打印最后空字符
 **/

/* test data */
// 8
// D B F E A H G C
// D F E B H G C A

struct TNode
{
    char data;
    TNode *left, *right;
};

void destroyTree(TNode *);
void preOrder(TNode *, bool &);
void inOrder(TNode *, bool &);
void postOrder(TNode *, bool &);
void levelOrder(TNode *, bool &);
TNode* inpostBuildTree(std::vector<char> &, std::vector<char> &, std::vector<char> &, int, int, int);
void getPre(std::vector<char> &, std::vector<char> &, std::vector<char> &, int, int, int);
int main()
{
    int nodeNum;
    std::cin >> nodeNum;
    std::vector<char> inGroup(nodeNum), postGroup(nodeNum), preGroup;
    for (unsigned int i = 0; i != nodeNum; ++i)
        std::cin >> inGroup[i];
    for (unsigned int i = 0; i != nodeNum; ++i)
        std::cin >> postGroup[i];

    // getPre(inGroup, postGroup, preGroup, nodeNum-1, 0, nodeNum-1);
    TNode *rootNode = inpostBuildTree(inGroup, postGroup, preGroup, nodeNum-1, 0, nodeNum-1);
    std::cout << "preorder:   ";
    bool firstprint = true;
    preOrder(rootNode, firstprint);
    std::cout << "\ninorder:    ";
    firstprint = true;
    inOrder(rootNode, firstprint);
    std::cout << "\npostorder:  ";
    firstprint = true;
    postOrder(rootNode, firstprint);
    std::cout << "\nlevelorder: ";
    firstprint = true;
    levelOrder(rootNode, firstprint);

    destroyTree(rootNode);

    return 0;
}
void getPre(std::vector<char> &inGroup, std::vector<char> &postGroup, 
std::vector<char> &preOrder, int root, int first, int last)
{
    preOrder.reserve(inGroup.size());
    if (first > last)
        return;
    int pivot = first;
    while (pivot < last && inGroup[pivot] != postGroup[root])
        ++pivot;
    preOrder.push_back(postGroup[root]);
    getPre(inGroup, postGroup, preOrder, root-last+pivot-1, first, pivot-1);
    getPre(inGroup, postGroup, preOrder, root-1, pivot+1, last);
}
TNode* inpostBuildTree(std::vector<char> &inGroup, std::vector<char> &postGroup, 
std::vector<char> &preGroup, int root, int first, int last)
{
    if (first > last)
        return nullptr;
    int pivot = first;
    while (pivot < last && inGroup[pivot] != postGroup[root])
        ++pivot;
    TNode *pnode = new TNode;
    pnode->data = postGroup[root];
    pnode->left = inpostBuildTree(inGroup, postGroup, preGroup, root-last+pivot-1, first, pivot-1);
    pnode->right = inpostBuildTree(inGroup, postGroup, preGroup, root-1, pivot+1, last);
    return pnode;
}
void preOrder(TNode *rootNode, bool &firstprint)
{
    if (!rootNode)
        return;
    firstprint ? std::cout << rootNode->data : std::cout << " " << rootNode->data;
    firstprint = false;
    preOrder(rootNode->left, firstprint);
    preOrder(rootNode->right, firstprint);
}
void inOrder(TNode *rootNode, bool &firstprint)
{
    if (!rootNode)
        return;
    inOrder(rootNode->left, firstprint);
    firstprint ? std::cout << rootNode->data : std::cout << " " << rootNode->data;
    firstprint = false;
    inOrder(rootNode->right, firstprint);
}
void postOrder(TNode *rootNode, bool &firstprint)
{
    if (!rootNode)
        return;
    postOrder(rootNode->left, firstprint);
    postOrder(rootNode->right, firstprint);
    firstprint ? std::cout << rootNode->data : std::cout << " " << rootNode->data;
    firstprint = false;
}
void levelOrder(TNode *rootNode, bool &firstprint)
{
    std::deque<TNode*> Queue{rootNode};
    while (!Queue.empty())
    {
        rootNode = Queue.front();
        Queue.pop_front();
        firstprint ? std::cout << rootNode->data : std::cout << " " << rootNode->data;
        firstprint = false;
        if (rootNode->left)
            Queue.push_back(rootNode->left);
        if (rootNode->right)
            Queue.push_back(rootNode->right);
    }
}
void destroyTree(TNode *rootNode)
{
    if (!rootNode)
        return;
    destroyTree(rootNode->left);
    destroyTree(rootNode->right);
    free(rootNode);
}