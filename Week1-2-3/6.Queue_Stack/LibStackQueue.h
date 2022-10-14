#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int key;
    NODE *pNext;
};

struct STACK {
    NODE *top;
};

struct QUEUE {
    int count;
    NODE *front;
    NODE *rear;
};

// 1. Initialize a stack from a given key:
STACK* createStack(int data) ;

// 2. Push a key into a given stack:
bool push(STACK* &S, int data) ;

// 3. Pop an element out of a given stack, return the key’s value:
int pop(STACK* &S) ;

// 4. Count the number of elements of a given stack:
int countElements(STACK* S) ;

// 5. Determine if a given stack is empty:
bool isEmpty(STACK* S) ;

// 6. Initialize a queue from a given key:
QUEUE* createQueue(int data) ;

// 7. Enqueue a key into a given queue:
bool enqueue(QUEUE* &Q, int data) ;

// 8. Dequeue an element out of a given queue, return the key’s value:
int dequeue(QUEUE* &Q) ;

// 9. Count the number of element of a given queue:
int countElements(QUEUE* Q) ;

// 10. Determine if a given queue is empty:
bool isEmpty(QUEUE* Q) ;
