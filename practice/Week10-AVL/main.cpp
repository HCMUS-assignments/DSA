#include "lib.h"

int main() {
    // tạo cây AVL
    NODE *pRoot = NULL;
    Insert(pRoot, 10);
    Insert(pRoot, 20);
    Insert(pRoot, 30);
    Insert(pRoot, 40);
    Insert(pRoot, 50);
    Insert(pRoot, 25);
    Insert(pRoot, 35);
    Insert(pRoot, 45);
    Insert(pRoot, 55);
    Insert(pRoot, 60);
   
    // in cây
    cout << "Duyet cay: ";
    LRN(pRoot);

    // kiểm tra cây có phải AVL không
    if (isAVL(pRoot)) {
        cout << "La cay AVL" << endl;
    } else {
        cout << "Khong phai cay AVL" << endl;
    }

    // remove node
    cout << "Remove node 10" << endl;
    Remove(pRoot, 10);
    LRN(pRoot);
    if (isAVL(pRoot)) {
        cout << "La cay AVL" << endl;
    } else {
        cout << "Khong phai cay AVL" << endl;
    }

    // remove node
    cout << "Remove node 50" << endl;
    Remove(pRoot, 50);
    LRN(pRoot);
    if (isAVL(pRoot)) {
        cout << "La cay AVL" << endl;
    } else {
        cout << "Khong phai cay AVL" << endl;
    }

    return 225;

}