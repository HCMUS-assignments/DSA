#include <bits/stdc++.h>
using namespace std;

struct DNODE {
    int key;

    DNODE* pNext;
    DNODE* pPrev;
};

struct DList {
    DNODE* pHead;
    DNODE* pTail;
};

// 1. Initialize a DNODE from a given integer:
DNODE* createDNode(int data);

// 2. Initialize a DList from a give DNODE:
DList* createDList(DNODE* pNode);

// 3. Insert an integer to the head of a given DList:
bool addHead(DList* &L, int data);

// 4. Insert an integer to the tail of a given DList:
bool addTail(DList* &L, int data);

// 5. Remove the first DNODE of a given DList:
void removeHead(DList* &L);

// 6. Remove the last DNODE of a given DList:
void removeTail(DList* &L);

// 7. Remove all DNODE from a given DList:
void removeAll(DList* &L);

// 8. Remove node before the node has val value in a given DList:
void removeBefore(DList* L, int val);

// 9. Remove node after the node has val value in a given DList:
void removeAfter(DList* L, int val);

// 10. Insert an integer at a position of a given DList:
bool addPos(DList* &L, int data, int pos);

// 11. Remove an integer at a position of a given DList:
void removePos(DList* &L, int pos);

// 12. Insert an integer before a value of a given DList:
bool addBefore(DList* L, int data, int val);

// 13. Insert an integer after a value of a given DList:
bool addAfter(DList* L, int data, int val);

// 14. Print all elements of a given DList:
void printList(DList* L);

// 15. Count the number of elements DList:
int countElements(DList* L);

// 16. Create a new List by reverse a given DList:
DList* reverseList(DList* L);

// 17. Remove all duplicates from a given DList:
void removeDuplicate(DList* &L);

// 18. Remove all key value from a given DList:
bool removeElement(DList* &L, int key);
