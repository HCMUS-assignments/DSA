#include <bits/stdc++.h>
using namespace std;

// II. AVL Tree

struct NODE_AVL {
    int key;
    NODE_AVL *pLeft, *pRight;
    int height;
};

// 1. Initialize a node with key is a given value:
NODE_AVL* createNodeAVL(int data);
void NLR_AVL(NODE_AVL* pRoot);

// 2. Add a node with given valuexinto a given AVL tree (Notify if the given value existed):
int height(NODE_AVL* p);
int getBalance(NODE_AVL* p);
NODE_AVL* rightRotate(NODE_AVL* root, int key);
NODE_AVL* leftRotate(NODE_AVL* root, int key);

void Insert(NODE_AVL* &pRoot, int x);

// 3. Remove a node with given valuexfrom a given AVL tree (Notify if the given value not existed):
void Remove(NODE_AVL* &pRoot, int x);

// 4. * Determine if a given Binary Tree is an AVL Tree:
bool isAVL(NODE_AVL* pRoot);