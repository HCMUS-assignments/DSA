
#include "lib_BST.h"


int main() {
    // 1. Initialize a Binary Search Tree:
    NODE* pRoot = NULL;
    
    // tạo cây nhị phân tìm kiếm từ dãy số sau:
    // 33 14 15 92 64 35 79 27 38 9 105 99 120 5 8

    Insert(pRoot, 33);
    Insert(pRoot, 14);
    Insert(pRoot, 15);
    Insert(pRoot, 92);
    Insert(pRoot, 64);
    Insert(pRoot, 35);
    Insert(pRoot, 79);
    Insert(pRoot, 27);
    Insert(pRoot, 38);
    Insert(pRoot, 9);
    Insert(pRoot, 105);
    Insert(pRoot, 99);
    Insert(pRoot, 120);
    Insert(pRoot, 5);
    Insert(pRoot, 8);

    // 2. Pre-order Traversal:
    cout << "Pre-order Traversal: ";
    NLR(pRoot);
    cout << endl;

    // 3. In-order Traversal:
    cout << "In-order Traversal: ";
    LNR(pRoot);
    cout << endl;

    // 4. Post-order Traversal:
    cout << "Post-order Traversal: ";
    LRN(pRoot);
    cout << endl;

    // 5. Level-order Traversal:
    cout << "Level-order Traversal: ";
    LevelOrder(pRoot);
    cout << endl;

    // 6. Calculate the height of the tree:
    cout << "Height of the tree: " << Height(pRoot) << endl;

    // 7. Calculate the number of nodes in the tree:
    cout << "Number of nodes in the tree: " << countNode(pRoot) << endl;

    // 8. Calculate the total value of nodes in the tree:
    cout << "Total value of nodes in the tree: " << sumNode(pRoot) << endl;

    // 9. Search for a given key in the tree:   
    cout << "Search for 99: " << Search(pRoot, 99) << endl;

    // 10. Remove a node with given key from the tree:
    Remove(pRoot, 99);
    cout << "Remove 99: ";
    LevelOrder(pRoot);

    // 12. Initialize a Binary Search Tree from a given array:
    int a[] = {33, 14, 15, 92, 64, 35, 79, 27, 38, 9, 105, 99, 120, 5, 8};
    int n = sizeof(a) / sizeof(int);
    NODE* pRoot2 = createTree(a, n);
    cout << "\nCreate tree from array: ";
    LevelOrder(pRoot2);

    // 13. Completely remove a given Binary Search Tree:
    removeTree(pRoot2);

    // 14. Calculate the height of a node with given key:
    cout << "\nHeight of node 64: " << heightNode(pRoot, 64) << endl;

    // 15. Calculate the level of a given node:
    cout << "Level of node 64: " << Level(pRoot, Search(pRoot, 64)) << endl;

    // 16. Count the number leaves from a given Binary Tree:
    cout << "Number of leaves: " << countLeaf(pRoot) << endl;

    // 17. Count the number of nodes which key value is less than a given value:
    cout << "Number of nodes which key value is less than 50: " << countLess(pRoot, 50) << endl;

    // 18. Count the number of nodes which key value is greater than a given value:
    cout << "Number of nodes which key value is greater than 50: " << countGreater(pRoot, 50) << endl;

    // 19. Determine if a given Binary Tree is a Binary Search Tree:
    cout << "Is Binary Search Tree: " << isBST(pRoot) << endl;

    // 20. Determine if a given Binary Tree is a Full Binary Tree:
    cout << "Is Full Binary Tree: " << isFullBST(pRoot) << endl;


    return 225;

}
