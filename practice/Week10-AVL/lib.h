#include <bits/stdc++.h>
using namespace std;

// II. AVL Tree

struct NODE {
    int key;
    NODE *pLeft, *pRight;
    int height;
};

// 1. Initialize a node with key is a given value:
NODE* createNode(int data);

// 2. Add a node with given value x into a given AVL tree (Notify if the given value existed):
void Insert(NODE* &pRoot, int x);

// 3. Remove a node with given value x from a given AVL tree (Notify if the given value not existed):
void Remove(NODE* &pRoot, int x);

// 4. * Determine if a given Binary Tree is an AVL Tree:
bool isAVL(NODE* pRoot);

// -----------------------------Các hàm bổ trợ--------------------------------

// hàm cập nhật chiều cao của các node
void updateHeight(NODE* &pRoot);

// hàm xoay phải một node
void rotateRight (NODE *&root);

// hàm xoay trái một node
void rotateLeft (NODE *&root);

// hàm cân bằng lại cây
void makeBalance(NODE *&root);

// hàm tìm giá trị lớn nhất giữa hai số
int max (int a, int b);

// hàm kiểm tra cây có phải binary search tree không
bool isBST (NODE *pRoot);

// hàm lấy chiều cao lớn nhất của cây con
int height (NODE *pRoot);

// hàm kiểm tra cây có cân bằng không
bool isBalanced (NODE *pRoot);

// hàm kiểm tra node có cân bằng không
bool isBalancedNode (NODE *pRoot);

// Hàm duyệt cây theo LRN
void LRN (NODE *root) ;

// hàm in ra chiều cao của các node
void printHeight(NODE *root);
