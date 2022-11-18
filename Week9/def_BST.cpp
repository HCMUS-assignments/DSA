#include "lib_BST.h"

// 1. Initialize a NODE from a given value:
NODE* createNode(int data) {
    NODE* p = new NODE;
    p->key = data;
    p->pLeft = p->pRight = NULL;
    return p;
}

// 2. Add a NODE with given value into a given Binary Search Tree:
void Insert(NODE* &pRoot, int x) {
    if (pRoot == NULL) {
        pRoot = createNode(x);
        return;
    }
    if (x < pRoot->key) Insert(pRoot->pLeft, x);
    else if (x > pRoot->key) Insert(pRoot->pRight, x);

}

// 3. Pre-order Traversal:
void NLR(NODE* pRoot) {
    if (pRoot == NULL) return;
    cout << pRoot->key << " ";
    NLR(pRoot->pLeft);
    NLR(pRoot->pRight);
}

// 4. In-order Traversal:
void LNR(NODE* pRoot) {
    if (pRoot == NULL) return;
    LNR(pRoot->pLeft);
    cout << pRoot->key << " ";
    LNR(pRoot->pRight);
}

// 5. Post-order Traversal:
void LRN(NODE* pRoot) {
    if (pRoot == NULL) return;
    LRN(pRoot->pLeft);
    LRN(pRoot->pRight);
    cout << pRoot->key << " ";
}

// 6. Level-order Traversal:
void LevelOrder(NODE* pRoot) {
    if (pRoot == NULL) return;
    queue<NODE*> q;
    q.push(pRoot);
    while (!q.empty()) {
        NODE* p = q.front();
        q.pop();
        cout << p->key << " ";
        if (p->pLeft != NULL) q.push(p->pLeft);
        if (p->pRight != NULL) q.push(p->pRight);
    }

}

// 7. Calculate the height of a given Binary Tree;
int Height(NODE* pRoot) {
    if (pRoot == NULL) return -1;
    int hLeft = Height(pRoot->pLeft);
    int hRight = Height(pRoot->pRight);
    return 1 + max(hLeft, hRight);

}

// 8. Count the number of NODE from a given Binary Tree:
int countNode(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    return 1 + countNode(pRoot->pLeft) + countNode(pRoot->pRight);

}

// 9. Calculate the total value of all NODEs from a given Binary Tree:
int sumNode(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    return pRoot->key + sumNode(pRoot->pLeft) + sumNode(pRoot->pRight);
}

// 10. Find and return a NODE with given value from a given Binary Search Tree:
NODE* Search(NODE* pRoot, int x) {
    if (pRoot == NULL) return NULL;
    if (pRoot->key == x) return pRoot;
    if (x < pRoot->key) return Search(pRoot->pLeft, x);
    return Search(pRoot->pRight, x);
}

// 11. Remove a NODE with given value from a given Binary Search Tree:
void Remove(NODE* &pRoot, int x) {
    if (pRoot == NULL) return;
    if (x < pRoot->key) Remove(pRoot->pLeft, x);
    else if (x > pRoot->key) Remove(pRoot->pRight, x);
    else {
        if (pRoot->pLeft == NULL && pRoot->pRight == NULL) {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->pLeft == NULL) {
            NODE* p = pRoot;
            pRoot = pRoot->pRight;
            delete p;
        }
        else if (pRoot->pRight == NULL) {
            NODE* p = pRoot;
            pRoot = pRoot->pLeft;
            delete p;
        }
        else {
            NODE* p = pRoot->pRight;
            while (p->pLeft != NULL) p = p->pLeft;
            pRoot->key = p->key;
            Remove(pRoot->pRight, p->key);
        }
    }
}

// 12. Initialize a Binary Search Tree from a given array:
NODE* createTree(int a[], int n) {
    NODE* pRoot = NULL;
    for (int i = 0; i < n; i++) Insert(pRoot, a[i]);
    return pRoot;

}

// 13. Completely remove a given Binary Search Tree:
void removeTree(NODE *&pRoot) {
    if (pRoot == NULL) return;
    removeTree(pRoot->pLeft);
    removeTree(pRoot->pRight);
    delete pRoot;
    pRoot = NULL;
}

// 14. Calculate the height of aNODEwith given value:(return -1 if value not exist)
int heightNode(NODE* pRoot, int value) {
    if (pRoot == NULL) return -1;
    if (pRoot->key == value) return Height(pRoot);
    if (value < pRoot->key) return heightNode(pRoot->pLeft, value);
    return heightNode(pRoot->pRight, value);
}

// 15. * Calculate the level of a given NODE:
int Level(NODE* pRoot, NODE* p) {
    if (pRoot == NULL) return -1;
    if (pRoot == p) return 1;
    int levelLeft = Level(pRoot->pLeft, p);
    if (levelLeft != -1) return 1 + levelLeft;
    int levelRight = Level(pRoot->pRight, p);
    if (levelRight != -1) return 1 + levelRight;
    return -1;

}

// 16. * Count the number leaves from a given Binary Tree:
int countLeaf(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    if (pRoot->pLeft == NULL && pRoot->pRight == NULL) return 1;
    return countLeaf(pRoot->pLeft) + countLeaf(pRoot->pRight);

}

// 17. * Count the number ofNODEfrom a given Binary Search Tree which key value is less than a given value:
int countLess(NODE* pRoot, int x) {
    if (pRoot == NULL) return 0;
    if (pRoot->key < x) return 1 + countLess(pRoot->pLeft, x) + countLess(pRoot->pRight, x);
    return countLess(pRoot->pLeft, x);

}

// 18. * Count the number ofNODEfrom a given Binary Search Tree which key value is greater than agiven value:
int countGreater(NODE* pRoot, int x) {
    if (pRoot == NULL) return 0;
    if (pRoot->key > x) return 1 + countGreater(pRoot->pLeft, x) + countGreater(pRoot->pRight, x);
    return countGreater(pRoot->pRight, x);

}

// 19. * Determine if a given Binary Tree is Binary Search Tree:
bool isBST(NODE* pRoot) {
    if (pRoot == NULL) return true;
    if (pRoot->pLeft != NULL && pRoot->pLeft->key > pRoot->key) return false;
    if (pRoot->pRight != NULL && pRoot->pRight->key < pRoot->key) return false;
    return isBST(pRoot->pLeft) && isBST(pRoot->pRight);
}

// 20. * Determine if a given Binary Tree is a Full Binary Search Tree:
bool isFullBST(NODE* pRoot) {
    if (pRoot == NULL) return true;
    if (pRoot->pLeft == NULL && pRoot->pRight == NULL) return true;
    if (pRoot->pLeft != NULL && pRoot->pRight != NULL) return isFullBST(pRoot->pLeft) && isFullBST(pRoot->pRight);
    return false;

}
