#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int key;
    NODE *pNext;
};

struct List {
    NODE *pHead;
    NODE *pTail;
};

// 1. Initialize a NODE from a given integer:
NODE* createNode(int data);

// 2. Initialize a List from a give NODE:
List* createList(NODE* pNode);

// 3. Insert an integer to the head of a given List:
bool addHead(List* &L, int data);

// 4. Insert an integer to the tail of a given List:
bool addTail(List* &L, int data);

// 5. Remove the first NODE of a given List:
void removeHead(List* &L);

// 6. Remove the last NODE of a given List:
void removeTail(List* &L);

// 7. Remove all NODE from a given List:
void removeAll(List* &L);

// 8. Remove node before the node has val value in a given List:
void removeBefore(List* L, int val);

// 9. Remove node after the node has val value in a given List:
void removeAfter(List* L, int val);

// 10. Insert an integer at a position of a given List:
bool addPos(List* &L, int data, int pos);

// 11. Remove an integer at a position of a given List:
void removePos(List* &L, int pos);

// 12. Insert an integer before a value of a given List:
bool addBefore(List* L, int data, int val);

// 13. Insert an integer after a value of a given List:
bool addAfter(List* L, int data, int val);

// 14. Print all elements of a given List:
void printList(List* L);

// 15. Count the number of elements List:
int countElements(List* L);

// 16. Create a new List by reverse a given List:
List* reverseList(List* L);

// 17. Remove all duplicates from a given List:
void removeDuplicate(List* &L);

// 18. Remove all key value from a given List:
bool removeElement(List* &L, int key);
