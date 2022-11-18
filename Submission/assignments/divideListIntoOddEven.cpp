// cho một danh sách liên kết đơn, mỗi node trong một danh sách có data là số nguyên
//  từ một danh sách liên kết đã cho tách thành hai danh sách liên kết con là lẻ và chẵn

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

struct List {
    Node *pHead = NULL;
    Node *pTail = NULL;
};

// create node function
Node *createNode(int data) {
    Node *pNode = new Node ;
    pNode->data = data;
    pNode->pNext = NULL;
    return pNode;
}

// create list function
List *createList(Node *&pNode) {
    List *L = new List;
    L->pHead = pNode;
    L->pTail = pNode;
    return L;
}

void addHead(List *&L, int data) {
    Node *pNode = createNode(data);
    if (L->pHead == NULL) {
        L = createList(pNode);
        return;
    } 
    pNode->pNext = L->pHead;
    L->pHead = pNode;
}

void addTail(List *&L, int data) {
    Node *pNode = createNode(data);
    if (L->pHead == NULL) {
        L = createList(pNode);
        return ;
    }
    L->pTail->pNext = pNode;
    L->pTail = pNode;
}

void addTail(List *&L, Node *&pNode) {
    if (L->pHead == NULL) {
        L = createList(pNode);
        return;
    }
    L->pTail->pNext = pNode;
    L->pTail = pNode;
    pNode->pNext = NULL;
}

// divide  list into two list
void divideList (List *&L, List *&Even, List *&Odd) {
    Node *temp = L->pHead;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            Node *pNode = temp;
            temp = temp->pNext;
            addTail(Even, pNode);
        } else {
            Node *pNode = temp;
            temp = temp->pNext;
            addTail(Odd, pNode);
        }
    }
}

// print list function
void printList(List *L) {
    Node *temp = L->pHead;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

int main() {
    Node *pNode = createNode(1);
    List *L = createList(pNode);
    addTail(L, 2);
    addTail(L, 3);
    addTail(L, 4);
    addTail(L, 5);
    addTail(L, 6);
    addTail(L, 7);
    addTail(L, 8);
    addTail(L, 9);
    addTail(L, 10);
    addTail(L, 11);
    addTail(L, 12);
    addTail(L, 13);
    addTail(L, 14);
    addTail(L, 15);

    cout << "List: ";
    printList(L);

    List *Even = new List;
    List *Odd = new List;

    divideList(L, Even, Odd);

    cout << "Even list: ";
    printList(Even);

    cout << "Odd list: ";
    printList(Odd);

    return 225;
}