#include <iostream>
#include <vector>
#include <deque>

/**
 * 前序后序建树
 * 前序中序求后序
 * 树的前序中序后序层序遍历
 * 控制递归中不打印最后空字符
 **/
// 8
// A B D E F C G H
// D B F E A H G C

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
void getPost(std::vector<char> &, std::vector<char> &, std::vector<char> &, int, int, int);
TNode* preinBuildTree(std::vector<char> &, std::vector<char> &, std::vector<char> &, int, int, int);
int main()
{
    int nodeNum;
    std::cin >> nodeNum;
    std::vector<char> preGroup(nodeNum), inGroup(nodeNum), postGroup;
    for (int i = 0; i != nodeNum; ++i)
        std::cin >> preGroup[i];
    for (int i = 0; i != nodeNum; ++i)
        std::cin >> inGroup[i];

    // getPost(preGroup, inGroup, postGroup, 0, 0, nodeNum-1);
    TNode *rootNode = preinBuildTree(preGroup, inGroup, postGroup, 0, 0, nodeNum-1);
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
void getPost(std::vector<char> &preGroup, std::vector<char> &inGroup, 
std::vector<char> &postGroup, int root, int first, int last)
{
    postGroup.reserve(preGroup.size());
    if (first > last)
        return;
    int pivot = first;
    while (pivot < last && inGroup[pivot] != preGroup[root])
        ++pivot;
    getPost(preGroup, inGroup, postGroup, root+1, first, pivot-1);
    getPost(preGroup, inGroup, postGroup, root+pivot-first+1, pivot+1, last);
    postGroup.push_back(preGroup[root]);
}
TNode* preinBuildTree(std::vector<char> &preGroup, std::vector<char> &inGroup, 
std::vector<char> &postGroup, int root, int first, int last)
{
    if (first > last)
        return nullptr;
    int pivot = first;
    while (pivot < last && inGroup[pivot] != preGroup[root])
        ++pivot;
    TNode *pnode = new TNode;
    pnode->data = preGroup[root];
    pnode->left = preinBuildTree(preGroup, inGroup, postGroup, root+1, first, pivot-1);
    pnode->right = preinBuildTree(preGroup, inGroup, postGroup, root+1+pivot-first, pivot+1, last);
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
    if (!rootNode)
        return;
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