#include <bits/stdc++.h>
using namespace std;

// Implement functions to execute the operations from singly linkedlist section 4.

struct DNODE {
int key;
DNODE* pNext;
DNODE* pPrev;
};
struct DList {
DNODE* pHead;
DNODE* pTail;
};