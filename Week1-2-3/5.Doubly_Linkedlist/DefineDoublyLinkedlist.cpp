#include "LibDoublyLinkedList.h"

// 1. Initialize a NODE from a given integer:
DNODE* createNode(int data);

// 2. Initialize a List from a give NODE:
DList* createList(DNODE* pNode);

// 3. Insert an integer to the head of a given List:
bool addHead(DList* &L, int data);

// 4. Insert an integer to the tail of a given List:
bool addTail(DList* &L, int data);

// 5. Remove the first NODE of a given List:
void removeHead(DList* &L);

// 6. Remove the last NODE of a given List:
void removeTail(DList* &L);

// 7. Remove all NODE from a given List:
void removeAll(DList* &L);

// 8. Remove node before the node has val value in a given List:
void removeBefore(DList* L, int val);

// 9. Remove node after the node has val value in a given List:
void removeAfter(DList* L, int val);

// 10. Insert an integer at a position of a given List:
bool addPos(DList* &L, int data, int pos);

// 11. Remove an integer at a position of a given List:
void removePos(DList* &L, int pos);

// 12. Insert an integer before a value of a given List:
bool addBefore(DList* L, int data, int val);

// 13. Insert an integer after a value of a given List:
bool addAfter(DList* L, int data, int val);

// 14. Print all elements of a given List:
void printList(DList* L);

// 15. Count the number of elements List:
int countElements(DList* L);

// 16. Create a new List by reverse a given List:
DList* reverseList(DList* L);

// 17. Remove all duplicates from a given List:
void removeDuplicate(DList* &L);

// 18. Remove all key value from a given List:
bool removeElement(DList* &L, int key);