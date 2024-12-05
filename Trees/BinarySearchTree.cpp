#include <iostream>

/**
 * ∂˛≤ÊÀ—À˜ ˜Ω®¡¢
 * ≈–∂œ∂˛≤ÊÀ—À˜ ˜ «∑Ò“ª÷¬
 * Œ≤µ›πÈ
 **/

/* test data */
// 9 4
// 5 3 8 1 4 7 9 2 6
// 5 8 7 3 4 1 6 9 2
// 5 3 4 7 9 8 1 6 2
// 5 8 7 4 2 1 4 9 6

struct TNode
{
    int data;
    TNode *left, *right;
};
bool checkTree(TNode *, TNode *);
void destroyTree(TNode *);
void insert(TNode *&, int);
TNode* buildSearchTree(int);
int main()
{
    int nodeNum, seqNum;
    std::cin >> nodeNum >> seqNum;
    TNode *rootNode = buildSearchTree(nodeNum);
    for (unsigned int i = 0; i != seqNum-1; ++i)
    {
        std::cout << "sequence" << i+1 << ": ";
        TNode *temp = buildSearchTree(nodeNum);
        checkTree(rootNode, temp) ? std::cout << "YES\n" : std::cout << "NO\n";
        destroyTree(temp);
    }

    destroyTree(rootNode);

    return 0;
}
TNode* buildSearchTree(int nodeNum)
{
    TNode *root = nullptr;
    for (int data, i = 0; i != nodeNum; ++i)
    {
        std::cin >> data;
        insert(root, data);
    }
    return root;
}
/** Œ≤µ›πÈ **/
void insert(TNode* &root, int data)
{
    if (!root)
        root = new TNode{data, nullptr, nullptr};
    else if (data < root->data)
        return insert(root->left, data);
    else
        return insert(root->right, data);
}
bool checkTree(TNode *root1, TNode *root2)
{
    if (!(root1 || root2))
        return true;
    else if (!(root1 && root2))
        return false;
    else if (root1->data != root2->data)
        return false;
    return checkTree(root1->left, root2->left) && checkTree(root1->right, root2->right);
}
void destroyTree(TNode *root)
{
    if (!root)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}
/** ∑«µ›πÈ≤Â»Î **/
// void insert(TNode *&root, int data)
// {
//     TNode *temp = root;
//     if (!root)
//         root = new TNode{data, nullptr, nullptr};
//     while (temp)
//         if (data < temp->data)
//             if (temp->left)
//                 temp = temp->left;
//             else
//             {
//                 temp->left = new TNode{data, nullptr, nullptr};
//                 break;
//             } 
//         else
//             if (temp->right)
//                 temp = temp->right;
//             else
//             {
//                 temp->right = new TNode{data, nullptr, nullptr};
//                 break;
//             }
// }
