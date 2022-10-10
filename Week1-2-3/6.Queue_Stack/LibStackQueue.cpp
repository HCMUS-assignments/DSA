#include <bits/stdc++.h>
using namespace std;

/*
Utilize the Linked list above, define the data structure of Stack and Queue, then implement functions
to execute the following operations:
1. Stack
• Initialize a stack from a given key.
• Push a key into a given stack.
• Pop an element out of a given stack, return the key’s value.
• Count the number of elements of a given
stack.
• Determine if a given stack is empty.
2. Queue
• Initialize a queue from a given key.
• Enqueue a key into a given queue.
• Dequeue an element out of a given
queue, return the key’s value.
• Count the number of element of a given
queue.
• Determine if a given queue is empty.
*/

struct NODE {
int key;
NODE* pNext;
};