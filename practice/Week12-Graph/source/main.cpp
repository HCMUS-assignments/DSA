#include "lib.h"


int main() {
    int **a;
    int n;
    readAdjMatrix("adjMatrix1.txt", a, n);
    printAdjMatrix(a, n);

    return 225;
}
