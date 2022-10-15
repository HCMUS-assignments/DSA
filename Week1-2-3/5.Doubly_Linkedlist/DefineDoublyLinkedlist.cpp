#include "LibDoublyLinkedList.h"

// 1. Initialize a DNODE from a given integer:
DNODE* createDNode(int data) {
    DNODE *pNode = new DNODE;
    pNode->key = data;
    pNode->pNext = NULL;
    pNode->pPrev = NULL;
    return pNode;
}

// 2. Initialize a List from a give DNODE:
DList* createDList(DNODE* pNode) {
    DList *pList = new DList;
    pList->pHead = pNode;
    pList->pTail = pNode;
    pNode->pNext = NULL;
    pNode->pPrev = NULL;
    return pList;
}

// 3. Insert an integer to the head of a given List:
bool addHead(DList* &L, int data) {
    DNODE *pNode = createDNode(data);
    if (L->pHead == NULL) {
        createDList(pNode);
        return true;
    }
    pNode->pNext = L->pHead;
    L->pHead->pPrev = pNode;
    L->pHead = pNode;
    return true;
}

// 4. Insert an integer to the tail of a given List:
bool addTail(DList* &L, int data) {
    DNODE *pNode = createDNode(data);
    if (L->pHead == NULL) {
        createDList(pNode);
        return true;
    }
    pNode->pPrev = L->pTail;
    L->pTail->pNext = pNode;
    L->pTail = pNode;
    return true;

}

// 5. Remove the first DNODE of a given List:
void removeHead(DList* &L) {
    if (L->pHead == NULL) {
        return ;
    }
    DNODE *pNode = L->pHead;
    L->pHead = L->pHead->pNext;
    L->pHead->pPrev = NULL;
    delete pNode;
}

// 6. Remove the last DNODE of a given List:
void removeTail(DList* &L) {
    if (L->pHead == NULL ) {
        return;
    }
    DNODE *pNode = L->pTail;
    L->pTail->pPrev->pNext = NULL;
    L->pTail = L->pTail->pPrev;
    delete pNode;
}

// 7. Remove all DNODE from a given List:
void removeAll(DList* &L) {
    if (L->pHead == NULL) {
        return;
    }
    DNODE *pNode = L->pHead;
    while (L->pHead != NULL && L->pTail != NULL) {
        L->pHead = L->pHead->pNext;
        if (pNode == L->pTail) {
            L->pTail = NULL;
        }
        delete pNode;
    }
}

// 8. Remove node before the node has val value in a given DList:
void removeBefore(DList* L, int val) {
    DNODE *pNode = L->pHead;
    while (pNode != NULL && pNode->key != val) {
        pNode = pNode->pNext;
    }
    if (pNode == NULL) {
        // val not found
        return;
    } else {
        DNODE *temp = pNode->pPrev;
        temp->pPrev->pNext = pNode;
        pNode->pPrev = temp->pPrev;
        delete temp;
    }
}

// 9. Remove node after the node has val value in a given List:
void removeAfter(DList* L, int val) {
    if (L->pHead == NULL) {
        return;
    }
    DNODE *pNode = L->pHead;
    while (pNode != NULL && pNode->key != val) {
        pNode = pNode->pNext;
    }
    if (pNode == NULL) {
        // val not found
        return ;
    } else {
        DNODE *temp = pNode->pNext;
        pNode->pNext = temp->pNext;
        temp->pNext->pPrev = pNode;
        delete temp;
    }
}

// 10. Insert an integer at a position of a given DList:
bool addPos(DList* &L, int data, int pos) {
    if (L->pHead == NULL) {
        if (pos == 0) {
            DNODE *pNode = createDNode(data);
            L = createDList(pNode);
            return true;
        } else {
            return false;
        }
    }
    int count = 0;
    DNODE *temp = L->pHead;
    while (temp != NULL && count != pos) {
        count ++;
        if (temp->pNext == NULL) {
            if (count == pos) {
                // insert to the tail
                addTail(L, data);
                return true;
            } else {
                return false;
            }
        } 
        temp = temp->pNext;
    }
    DNODE *pNode = createDNode(data);
    pNode->pNext = temp;
    pNode->pPrev = temp->pPrev;
    temp->pPrev->pNext = pNode;
    return true;
}

// 11. Remove an integer at a position of a given DList:
void removePos(DList* &L, int pos) {
    if (L->pHead == NULL) {
        return;
    }
    int count = 0;
    DNODE *pNode = L->pHead;
    while (pNode != NULL && count != pos) {
        count ++;
        if (pNode->pNext == NULL) {
            if (count == pos) {
                // remove pNode 
                pNode->pPrev->pNext = pNode->pNext;
                pNode->pNext->pPrev = pNode->pPrev;
                delete pNode;
                return;
            } else {
                // not found pos in list
                return;
            }
        }
        pNode = pNode->pNext;
    }

    pNode->pPrev->pNext = pNode->pNext;
    pNode->pNext->pPrev = pNode->pPrev;
    delete pNode;
}

// 12. Insert an integer before a value of a given DList:
bool addBefore(DList* L, int data, int val) {
    if (L->pHead == NULL) {
        return false;
    }
    if (L->pHead->key == val) {
        addHead(L, data);
        return true;
    }
    DNODE *pNode = L->pHead;
    while (pNode != NULL && pNode->key != val) {
        pNode = pNode->pNext;
    }
    if (pNode == NULL) {
        // val not found
        return false;
    }
    DNODE *newDNode = createDNode(data);
    pNode->pPrev->pNext = newDNode;
    newDNode->pPrev = pNode->pPrev;
    newDNode->pNext = pNode;
    pNode->pPrev = newDNode;
    return true;
}

// 13. Insert an integer after a value of a given DList:
bool addAfter(DList* L, int data, int val) {
    if (L->pHead == NULL) {
        return false;
    }
    DNODE *temp = L->pHead;
    while (temp != NULL && temp->key != val) {
        temp = temp->pNext;
    }
    if (temp == NULL) {
        return false;
    }
    DNODE *pNode = createDNode(data);
    pNode->pPrev = temp;
    pNode->pNext = temp->pNext;
    temp->pNext->pPrev = pNode;
    temp->pNext = pNode;
    return true;
}

// 14. Print all elements of a given DList:
void printList(DList* L) {
    if (L->pHead == NULL) {
        return;
    }

    cout << "List: ";

    DNODE *pNode = L->pHead;
    while (pNode != NULL) {
        cout << pNode->key << " ";
        pNode = pNode->pNext;
    }

}

// 15. Count the number of elements DList:
int countElements(DList* L) {
    if (L->pHead == NULL) {
        return 0;
    }
    DNODE *pNode = L->pHead;
    int count = 0;
    while (pNode != NULL) {
        count ++;
        pNode = pNode->pNext;
    }
    return count ;
}

// 16. Create a new DList by reverse a given DList:
DList* reverseList(DList* L) {
    DList *L2 = createDList(createDNode(L->pHead->key));
    DNODE *temp = L->pHead->pNext;
    while (temp != NULL) {
        addHead(L2, temp->key);
        temp = temp->pNext;
    }
    return L2;
}

// 17. Remove all duplicates from a given DList:
void removeDuplicate(DList* &L) {
    if (L->pHead == NULL) {
        return ;
    }
    DNODE *pNode = L->pHead;
    int i = 0;
    while (pNode != NULL) {
        DNODE *temp = pNode->pNext;
        while (temp != NULL) {
            if (temp->key == pNode->key) {
                // remove temp
                if (temp->pNext == NULL) {
                    temp = temp->pNext;
                    removeTail(L);
                } else {
                    temp->pPrev->pNext = temp->pNext;
                    temp->pNext->pPrev = temp->pPrev;
                    DNODE *pNode2 = temp;
                    temp = temp->pNext;
                    delete pNode2;
                }
            } else {
                temp = temp->pNext;
            }
        }
        pNode = pNode->pNext;
    }
}

// 18. Remove all key value from a given DList:
bool removeElement(DList* &L, int key) {
    if (L->pHead == NULL) {
        return false;
    }
    
    // if pHead has key value
    while (L->pHead->key == key) {
        removeHead(L);
    }
    DNODE *temp = L->pHead;
    while (temp != NULL) {
        if (temp->key == key) {
            // remove temp
            if (temp->pNext == NULL) {
                temp = temp->pNext;
                removeTail(L);
            } else {
                DNODE *pNode = temp;
                temp->pPrev->pNext = temp->pNext;
                temp->pNext->pPrev = temp->pPrev;
                temp = temp->pNext;
                delete pNode;
            }
        } else {
            temp = temp->pNext;
        }
    }
    return true;

}

/* 
int main() {
    DNODE *FirstNode = createDNode(1);
    DList *L = createDList(FirstNode);
    addTail(L, 2);
    addTail(L, 3);
    addTail(L, 4);
    addTail(L, 5);
    addTail(L, 6);
    addTail(L, 7);
    addTail(L, 8);
    addTail(L, 9);
    addTail(L, 10);
    printList(L);
    cout << endl;

    cout << "Add 11 to head: ";
    addHead(L, 11);
    printList(L);

    cout << endl << "Add 12 to tail: ";
    addTail(L, 12);
    printList(L);

    cout << endl << "Remove head: ";
    removeHead(L);
    printList(L);

    cout << endl << "Remove tail: ";
    removeTail(L);
    printList(L);

    cout << endl << "Remove element at position 5: ";
    removePos(L, 5);
    printList(L);

    cout << endl << "Insert 13 before 5: ";
    addBefore(L, 13, 5);
    printList(L);

    cout << endl << "Insert 14 after 5: ";
    addAfter(L, 14, 5);
    printList(L);

    cout << endl << "Count elements: " << countElements(L);

    cout << endl << "Reverse list: ";
    DList *L2 = reverseList(L);
    printList(L2);

    cout << endl << "Remove duplicate: ";
    addTail(L, 5);
    addTail(L, 5);
    printList(L);
    removeDuplicate(L);
    printList(L);

    cout << endl << "Remove element 5: ";
    printList(L2);
    removeElement(L2, 5);
    printList(L2);

    return 225;
}
*/