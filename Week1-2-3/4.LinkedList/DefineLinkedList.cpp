#include "LibLinkedlist.h"

// 1. Initialize a NODE from a given integer:
NODE* createNode(int data) {
    NODE *pNode = new NODE;
    pNode->key = data;
    pNode->pNext = NULL;
    return pNode;
}

// 2. Initialize a List from a give NODE:
List* createList(NODE* pNode) {
    List *L = new List;
    L->pHead = pNode;
    L->pTail = pNode;
    return L;
}

// 3. Insert an integer to the head of a given List:
bool addHead(List* &L, int data) {
    NODE *pNode = createNode(data);
    if (L->pHead == NULL) {
        L = createList(pNode);
    } else {
        pNode->pNext = L->pHead;
        L->pHead = pNode;
    }
    return true;
}

// 4. Insert an integer to the tail of a given List:
bool addTail(List* &L, int data) {
    NODE *pNode = createNode(data);
    if (L->pHead == NULL) {
        L = createList(pNode);
    } else {
        L->pTail->pNext = pNode;
        L->pTail = pNode;
    }
    return true;
}

// 5. Remove the first NODE of a given List:
void removeHead(List* &L) {
    if (L->pHead == NULL) {
        return;
    } else {
        NODE *pNode = L->pHead;
        L->pHead = L->pHead->pNext;
        delete pNode;
    }
}

// 6. Remove the last NODE of a given List:
void removeTail(List* &L) {
    if (L->pHead == NULL) {
        return;
    } else {
        NODE *pNode = L->pHead;
        while (pNode->pNext != L->pTail) {
            pNode = pNode->pNext;
        }
        delete L->pTail;
        L->pTail = pNode;
        L->pTail->pNext = NULL;
    }
}

// 7. Remove all NODE from a given List:
void removeAll(List* &L) {
    if (L->pHead == NULL) {
        return;
    } else {
        while (L->pHead != NULL) {
            removeHead(L);
        }
    }
}

// 8. Remove node before the node has val value in a given List:
void removeBefore(List* L, int val) {
    if (L->pHead == NULL) {
        return;
    } else {
        NODE *pNode = L->pHead;
        while (pNode->pNext->key != val) {
            pNode = pNode->pNext;
        }
        NODE *pNode2 = L->pHead;
        while (pNode2->pNext != pNode) {
            pNode2 = pNode2->pNext;
        }
        pNode2->pNext = pNode->pNext;
        delete pNode;
    }
}

// 9. Remove node after the node has val value in a given List:
void removeAfter(List* L, int val) {
    if (L->pHead == NULL) {
        return;
    } else {
        NODE *pNode = L->pHead;
        while (pNode->key != val) {
            pNode = pNode->pNext;
        }
        NODE *pNode2 = pNode->pNext;
        pNode->pNext = pNode2->pNext;
        delete pNode2;
    }
}

// 10. Insert an integer at a position of a given List:
bool addPos(List* &L, int data, int pos) {
    if (L->pHead == NULL) {
        if (pos == 0) {
            addHead(L, data);
            return true;
        } else {
            return false;
        }
    }
    int count = 0 ;
    NODE *temp = L->pHead;
    while (temp != NULL && count < pos) {
        temp = temp->pNext;
        count++;
    }
    NODE *pNode = createNode(data);
    pNode->pNext = temp->pNext;
    temp = pNode;
    return true;
}

// 11. Remove an integer at a position of a given List:
void removePos(List* &L, int pos) {
    if (L->pHead == NULL ) {
        return;
    }
    NODE *pNode = L->pHead;
    int count = 0;
    while (pNode != NULL && count < pos - 1) {
        pNode = pNode->pNext;
        count++;
    }
    NODE *temp = pNode->pNext;
    pNode->pNext = temp->pNext;
    delete temp;
}

// 12. Insert an integer before a value of a given List:
bool addBefore(List* L, int data, int val) {
    if (L->pHead == NULL) {
        return false;
    } 
    NODE *pNode = L->pHead;
    while (pNode != NULL && pNode->pNext->key != val) {
        pNode = pNode->pNext;
    }
    if (pNode == NULL) {
        // val not found
        return false;
    } else {
        NODE *temp = createNode(data);
        temp->pNext = pNode->pNext;
        pNode->pNext = temp;
    }
    return true;
}

// 13. Insert an integer after a value of a given List:
bool addAfter(List* L, int data, int val) {
    if (L->pHead == NULL) {
        return false;
    }
    NODE *temp = L->pHead;
    while (temp != NULL && temp->key != val) {
        temp = temp->pNext;
    }
    if (temp == NULL) {
        // don't have val in list
        return false;
    } else {
        NODE *pNode = createNode(data);
        pNode->pNext = temp->pNext;
        temp->pNext = pNode;
        return true;
    }

}

// 14. Print all elements of a given List:
void printList(List* L) {
    if (L == NULL) {
        return;
    } else {
        NODE *pNode = L->pHead;
        while (pNode != NULL) {
            cout << pNode->key << " ";
            pNode = pNode->pNext;
        }
        cout << endl;
    }
}

// 15. Count the number of elements List:
int countElements(List* L) {
    if (L == NULL) {
        return 0;
    } else {
        int count = 0;
        NODE *pNode = L->pHead;
        while (pNode != NULL) {
            count++;
            pNode = pNode->pNext;
        }
        return count;
    }
}

// 16. Create a new List by reverse a given List:
List* reverseList(List* L){
    if (L->pHead == NULL) {
        return NULL;
    }
    NODE *pNode = L->pHead;
    List *L2 = createList(pNode);
    while (pNode->pNext != NULL) {
        pNode = pNode->pNext;
        addHead(L2, pNode->key);
    }
    return L2;
}

// 17. Remove all duplicates from a given List:
void removeDuplicate(List* &L) {

}

// 18. Remove all key value from a given List:
bool removeElement(List* &L, int key) {
    
}

