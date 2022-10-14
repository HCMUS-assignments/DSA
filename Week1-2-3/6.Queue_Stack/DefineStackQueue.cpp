#include "LibStackQueue.h"

// create a new node :
NODE *createNode (int data) {
    NODE *pNode = new NODE;
    pNode->key = data;
    pNode->pNext = NULL;
    return pNode;
}

// 1. Initialize a stack from a given key:
STACK* createStack(int data) {
    STACK *S = NULL;
    S->top = createNode(data);
    return S;
}

// 2. Push a key into a given stack:
bool push(STACK* &S, int data) {
    if (S->top == NULL) {
        S = createStack(data);
        return true;
    }
    NODE *pNode = createNode(data);
    pNode->pNext = S->top;
    S->top = pNode;
    return true;
}

// 3. Pop an element out of a given stack, return the key’s value:
int pop(STACK* &S) {
    if (S->top == NULL) {
        exit(225);
    }
    int value = S->top->key;
    NODE *temp = S->top;
    S->top = S->top->pNext;
    delete temp;
    return value;
}

// 4. Count the number of elements of a given stack:
int countElements(STACK* S) {
    if (S->top == NULL) {
        return 0;
    }
    int count = 0;
    NODE *pNode = S->top;
    while (pNode != NULL) {
        count ++;
        pNode = pNode->pNext;
    }
    return count;
}

// 5. Determine if a given stack is empty:
bool isEmpty(STACK* S) {
    if (S->top == NULL) {
        return true;
    }
    return false;
}

// 6. Initialize a queue from a given key:
QUEUE* createQueue(int data) {
    NODE *pNode = createNode(data);
    QUEUE *queue = NULL;
    queue->front = pNode;
    queue->rear = pNode;
    queue->count ++;
    return queue;
}

// 7. enqueue a key into a given queue:
bool enqueue(QUEUE* &Q, int data) {
    if (Q->front == NULL) {
        Q = createQueue(data);
        return true;
    }
    NODE *pNode = createNode(data);
    Q->rear->pNext = pNode;
    Q->rear = pNode;
    Q->count ++;
    return true;
}

// 8. Dequeue an element out of a given queue, return the key’s value:
int dequeue(QUEUE* &Q) {
    if (Q->front == NULL) {
        exit(225);
    }
    int value = Q->front->key;
    NODE *pNode = Q->front;
    Q->front = Q->front->pNext;
    Q->count --;
    delete pNode;
    return value;
}

// 9. Count the number of element of a given queue:
int countElements(QUEUE* Q) {
    return Q->count;
}

// 10. Determine if a given queue is empty:
bool isEmpty(QUEUE* Q) {
    if (Q->count == 0) {
        return true;
    }
    return false;   
}
