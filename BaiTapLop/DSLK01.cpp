// 1. Tạo danh sách liên kết cho một mảng cho trước
// 2. Xóa phần tử ở vị trí k trong danh sách liên kết
// 3. Xóa một phần tử bất kì trong danh sách liên kết

// done

#include <iostream>
using namespace std;

// cấu trúc node
struct Node {
    int data;
    Node *pNext;
};

// Tạo danh sách liên kết cho một mảng cho trước
void createList(int a[], int n, Node *&list) {
    Node *p = list;
    for (int i = 0; i < n; i++) {
        Node *node = new Node;
        node->data = a[i];
        node->pNext = NULL;
        p->pNext = node;
        p = p->pNext;
    }
}

// Xóa phần tử ở vị trí k trong danh sách liên kết
void deleteNodeK(Node *&list, int k) {
    Node *p = list;
    for (int i = 0; i < k - 1; i++) {
        p = p->pNext;
    }
    Node *q = p->pNext;
    p->pNext = q->pNext;
    delete q;
}

// Xóa một phần tử bất kì trong danh sách liên kết
void deleteNode(Node *&list, int x) {
    Node *p = list;
    while (p->pNext != NULL) {
        if (p->pNext->data == x) {
            Node *q = p->pNext;
            p->pNext = q->pNext;
            delete q;
        }
        p = p->pNext;
    }
}

// in danh sách liên kết
void printList(Node *list) {
    Node *p = list;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->pNext;
    }
}

// xóa danh sách liên kết
void deleteList(Node *&list) {
    Node *p = list;
    while (p != NULL) {
        Node *q = p;
        p = p->pNext;
        delete q;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(int);
    Node *list = new Node;
    list->pNext = NULL;
    cout << "Danh sach lien ket: ";
    createList(a, n, list);
    printList(list->pNext);
    cout << endl;

    cout << "Danh sach lien ket sau khi xoa phan tu tai vi tri 3: ";
    deleteNodeK(list, 3);   
    printList(list->pNext);
    cout << endl;

    cout << "Danh sach lien ket sau khi xoa phan tu 5: ";
    deleteNode(list, 5);
    printList(list->pNext);
    deleteList(list);
    return 225; 
}

