#include "lib.h"

// 1. Initialize a node with key is a given value:
NODE* createNode(int data) {
    NODE *pNode = new NODE();
    pNode->key = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    pNode->height = 0;
    return pNode;
}

// 2. Add a node with given value x into a given AVL tree (Notify if the given value existed):
void Insert(NODE* &pRoot, int x) {

    if (pRoot == NULL) {
        NODE *pNode = createNode(x);
        pRoot = pNode;
        return;
    }
    if (pRoot->key == x) {
        return;
    }
    if (pRoot->key < x) {
        Insert(pRoot->pRight, x);
    } else {
        Insert(pRoot->pLeft, x);
    }

    // tính lại chiều cao của các node
    updateHeight(pRoot);

    // cân bằng lại cây nếu bị lệch
    if (pRoot->height == 0 && ! isBalanced(pRoot)) {
        makeBalance(pRoot);
    }
}

// 3. Remove a node with given value x from a given AVL tree (Notify if the given value not existed):
void Remove(NODE* &pRoot, int x) {
    NODE *pNode = pRoot;
    NODE *prev = pRoot;
    while (pNode && pNode->key != x) {
        prev = pNode;
        if (x > pNode->key) {
            pNode = pNode-> pRight;
        } else {
            pNode = pNode->pLeft;
        }
        if (pNode == NULL) {
            cout << "Khong tim thay node " << x << endl;
            return;
        }
    }

    // Kiểm tra Nếu trái phải đều là NULL thì remove bình thường
    if (pNode->pLeft == NULL && pNode->pRight == NULL) {
        if (pNode == pRoot) {
            pRoot = NULL;
        } else {
            if (prev->pLeft == pNode) {
                prev->pLeft = NULL;
            } else {
                prev->pRight = NULL;
            }
        }
        delete pNode;
        pNode = NULL;
    } else if (pNode->pLeft != NULL && pNode->pRight != NULL) {
        // nếu có đầy đủ hai con thì node thế mạng là node phải nhất cây con trái
        int rightMost = pNode->pLeft->key;
        NODE *temp = pNode->pLeft;
        NODE *prev = pNode->pLeft;
        while (temp->pRight != NULL) {
            prev = temp;
            temp = temp->pRight;
            rightMost = temp->key;
        }
        // cập nhật lại node trỏ đến node thế mạng
        if (prev == temp) {
            pNode->pLeft = temp->pLeft;
        } else {
            prev->pRight = temp->pLeft;
        }
        delete temp;
        pNode->key = rightMost;
    } else {
        // nếu có node trái hoặc node phải => remode node đó và lấy node trước đó trỏ vào node con trái hoặc phải
        if (prev->pLeft != NULL && prev->pLeft->key == x) {
            if (pNode->pLeft != NULL) {
                prev->pLeft = pNode->pLeft;
            } else {
                prev->pLeft = pNode->pRight;
            }
        } else {
            if (pNode->pLeft != NULL) {
                prev->pRight = pNode->pLeft;
            } else {
                prev->pRight = pNode->pRight;
            }
        }
        delete pNode;
        pNode = NULL;
    } 
    LRN(pRoot);

    // Kiểm tra lại cây có mất cân bằng không, nếu có thì cân bằng lại cây
    if ( ! isBalanced(pRoot)) {
        // cân bằng lại cây
        makeBalance(pRoot);
    }
}

// 4. * Determine if a given Binary Tree is an AVL Tree:
bool isAVL(NODE* pRoot) {
    if (isBST(pRoot) && isBalanced(pRoot)) {
        return true;
    }
    return false;
}

// ----------------- Các hàm hỗ trợ -----------------

// hàm cập nhật lại chiều cao của các node
void updateHeight(NODE* &pRoot) {
    if (pRoot == NULL) {
        return;
    }
    if (pRoot->pLeft != NULL) {
        pRoot->pLeft->height = pRoot->height + 1;
    }
    if (pRoot->pRight != NULL) {
        pRoot->pRight->height = pRoot->height + 1;
    }
    updateHeight(pRoot->pLeft);
    updateHeight(pRoot->pRight);
}


// hàm xoay phải một node
void rotateRight (NODE *&root) {
    cout << "Xoay phai node " << root->key << endl;
    NODE *temp = root;
    root = root->pLeft;
    root->height = temp->height;    // cập nhật lại chiều cao của node 
    if (root->pRight != NULL) {
        NODE *temp2 = root->pRight;
        root->pRight = temp;
        temp2->pLeft = temp2;
    } else {
        root->pRight = temp;
        temp->pLeft = NULL;
    }
    // cập nhật lại chiều cao của các node:     
    updateHeight(root);
    temp->height = root->height + 1;
    updateHeight(temp);
}

// hàm xoay trái một node
void rotateLeft (NODE *&root) {
    cout << "Xoay trai node " << root->key << endl;
    NODE *temp = root;
    root = root->pRight;
    root->height = temp->height;    // cập nhật lại chiều cao node
    if (root->pLeft != NULL) {
        NODE *temp2 = root->pLeft;
        root->pLeft = temp;
        temp->pRight = temp2;
    } else {
        root->pLeft = temp;
        temp->pRight = NULL;
    }
    // cập nhật lại chiều cao của các node:
    updateHeight(root);
    temp->height = root->height + 1;
    updateHeight(temp);
}

// hàm cân bằng lại cây
void makeBalance(NODE *&root) {
    if (root == NULL || isBalanced(root)) {
        return;
    }
    if (!isBalancedNode(root)) {
        int l = height(root->pLeft);
        int r = height(root->pRight);
        if (l == 0) l = root->height;
        if (r == 0) r = root->height;
        if (l > r) {
            if (height(root->pLeft->pLeft) > height(root->pLeft->pRight)) {
                // cây lệch trái trái
                rotateRight(root);
            } else {
                // cây lệch trái phải
                rotateLeft(root->pLeft);
                rotateRight(root);
            }
        } else {
            if (height(root->pRight->pRight) > height(root->pRight->pLeft)) {
                // cây lệch phải phải
                rotateLeft(root);
            } else {
                // cây lệch phải trái
                rotateRight(root->pRight);
                rotateLeft(root);
            }
        }
    }
    if (!isBalanced(root->pLeft)) { // cân bằng cây con trái
        makeBalance(root->pLeft);
    }
    if (!isBalanced(root->pRight)) {   // cân bằng cây con phải
        makeBalance(root->pRight);
    }
}


// Kiểm tra cây có phải cây BST
bool isBST (NODE *pRoot) {
    if (pRoot == NULL) {
        return true;
    }
    if (pRoot->pLeft != NULL && pRoot->pLeft->key > pRoot->key) {
        return false;
    }
    if (pRoot->pRight != NULL && pRoot->pRight->key < pRoot->key) {
        return false;
    }
    return isBST(pRoot->pLeft) && isBST(pRoot->pRight);
}

int max (int a, int b) {
    return a > b ? a : b;
}

// lấy chiều cao lớn nhất của cây con
int height (NODE *pRoot) {
    if (pRoot == NULL) {
        return 0;
    }
    if (pRoot->pLeft == NULL && pRoot->pRight == NULL) {
        return pRoot->height;
    } 
    return max(height(pRoot->pLeft), height(pRoot->pRight));
}
// kiểm tra node có cân bằng hay không
bool isBalancedNode (NODE *pRoot) {
    if (pRoot == NULL) {
        return true;
    }
    int l = height(pRoot->pLeft);
    int r = height(pRoot->pRight);
    if (l == 0) l = pRoot->height;
    if (r == 0) r = pRoot->height;
    if (abs(l - r) > 1) {
        return false;
    } else {
        return true;
    }
}

// kiểm tra cây có cân bằng hay không
bool isBalanced (NODE *pRoot) {
    if (pRoot == NULL) {
        return true;
    }
    int l = height(pRoot->pLeft);
    int r = height(pRoot->pRight);
    if (l == 0) l = pRoot->height;
    if (r == 0) r = pRoot->height;
    if (abs(l - r) > 1) {
        return false;
    }
    return isBalanced(pRoot->pLeft) && isBalanced(pRoot->pRight);
}

// hàm duyệt cây theo LRN
void LRN (NODE *root) {
    if (root == NULL) {
        return;
    }
    LRN(root->pLeft);
    LRN(root->pRight);
    cout << root->key << " ";
}


// hàm in ra chiều cao của các node
void printHeight(NODE *root) {
    if (root == NULL) {
        return;
    }
    printHeight(root->pLeft);
    printHeight(root->pRight);
    cout << "Node " << root->key << " co chieu cao: " << root->height << endl;
}
