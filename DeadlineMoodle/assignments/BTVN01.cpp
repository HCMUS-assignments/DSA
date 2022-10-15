// cho một danh sách liên kết đơn, mỗi node trong một danh sách có data là số nguyên
//  từ một danh sách liên kết đã cho tách thành hai danh sách liên kết con là lẻ và chẵn

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

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

void main() {
    // chưa xong
    //  làm bài tập stack and queue trên hackerank
}