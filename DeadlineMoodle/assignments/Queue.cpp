// cho hàng đợi ban đầu như sau: tối đa 6 phần tử : a b c d 
// 1. thêm e vào hàng đợi
// 2. loại hai phần tử khỏi hàng đợi
// 3. bổ sung i, j ,k vào hàng đợi
// 4. loại hai phần tử khỏi hàng đợi'
// 5. thêm o vào hàng đợi

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char key;
    Node *pNext ;
};

struct Queue {
    Node *front = NULL;
    Node *rear = NULL;
    int num = 0;
};

// create node function
Node *createNode (char key) {
    Node *pNode = new Node;
    pNode->key = key;
    pNode->pNext = NULL;
    return pNode;
}

Queue *createQueue(Node *&pNode) {
    Queue *Q = new Queue;
    Q->front = pNode;
    Q->rear = pNode;
    Q->num = 1;
    return Q;
}

void enqueue(Queue *&Q, char key) {
    Node *pNode = createNode(key);
    if (Q->front == NULL) {
        Q = createQueue(pNode);
        return;
    }
    Q->rear->pNext = pNode;
    Q->rear = pNode;
    Q->num++;
}

char dequeue(Queue *&Q) {
    char key = Q->front->key;
    Node *pNode = Q->front;
    Q->front = Q->front->pNext;
    delete pNode;
    Q->num--;
    return key;
}

// print list function
void printList(Queue *Q) {
    Node *temp = Q->front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->key << " " ;
        temp = temp->pNext;
    }
    cout << endl;
}

int main() {
    Node *pNode = createNode('a');
    Queue *Q = createQueue(pNode);
    enqueue(Q, 'b');
    enqueue(Q, 'c');
    enqueue(Q, 'd');
    printList(Q);

    // them 'e' vao hang doi
    enqueue(Q, 'e');
    printList(Q);

    // loai hai phan tu khoi hang doi
    dequeue(Q);
    dequeue(Q);
    printList(Q);

    // bo sung i, j, k vao hang doi
    enqueue(Q, 'i');
    enqueue(Q, 'j');
    enqueue(Q, 'k');
    printList(Q);

    // loai hai phan tu khoi hang doi
    dequeue(Q);
    dequeue(Q);
    printList(Q);

    // them o vao hang doi
    enqueue(Q, 'o');
    printList(Q);

    return 225;
}