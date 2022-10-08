#include <bits/stdc++.h>
using namespace std;

// 1. swap 2 given integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2. calculate the total value of 2 integers
int *sum (int *a, int *b) {
    int *sum = new int;
    *sum = *a + *b;
    return sum;
}

// 3. input an array with unknown size
void inputArray(int *&a, int &n) {
    cout << "Enter the size of the array: ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> a[i];
    }
}

// 4. print a given array
void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// 5. find the largest value from a given array
int *findMax(int *arr, int n) {
    int *max = arr;
    for (int i = 1; i < n; i++ ) {
        if (arr[i] > *max) {
            max = arr + i;
        }
    }
    return max;
}

// 6. find the longest ascending subarray from a given array
int *findLongestAscendingSubarray(int *a, int n, int &length) {

}

// 7. swap 2 given arrays
void swapArray(int *&a, int *&b, int &na, int &nb) {
    int *temp = a;
    a = b;
    b = temp;
    int temp2 = na;
    na = nb;
    nb = temp2;
}

// 8. concatenate 2 given arrays
int *concatenateArray(int *a, int *b, int na, int nb, int &nc) {
    nc = na + nb;
    int *c = new int[nc];
    for (int i = 0; i < na; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < nb; i++) {
        c[na + i] = b[i];
    }
    return c;
}

// 9. given 2 ascending arrays with distinguish elements, generate a new ascending array with all elements from the given arrays
int *merge2Arrays(int *a, int *b, int na, int nb, int &nc) {
    nc = na + nb;
    int *c = new int[nc];
    int i = 0, j = 0, k = 0;
    for ( ; i < na && j < nb; k++) {
        if (a[i] < b [j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
    }
    if (i < na) {
        for ( ; i < na; i++, k++) {
            c[k] = a[i];
        }
    } 
    if (j < nb) {
        for ( ; j < nb; j++, k++) {
            c[k] = b[j];
        }
    }
    return c;
}

// 10. generate a random matrix with keyboard input size
void generateMatrix1(int **&a, int &length, int &width) {


}

// 11. given two 1D arrays a and b, generate the matrix c that c[i][j] = a[i] * b[j]
int **generateMatrix2(int *a, int *b, int na, int nb, int &crow, int &ccol) {
    crow = na;
    ccol = nb;
    int **c = new int*[crow];
    for (int i = 0; i < crow; i++) {
        c[i] = new int[ccol];
        for (int j = 0; j < ccol; j++) {
            c[i][j] = a[i] * b[j];
        }
    }
    return c;
}

// 12. Swap 2 columns / rows of a given matrix.
void swapRows(int** a, int length, int width, int ir1, int ir2) {
    for (int j = 0; j < width; j++) {
        swap(a[ir1] + j, a[ir2] + j);
    }

}
void swapColumns(int** a, int length, int width, int ic1, int ic2) {
    for (int i = 0; i < length; i++) {
        swap(a[i] + ic1, a[i] + ic2);
    }
}

// 13. Generate the transpose matrix of a given matrix.
int** transposeMatrix(int** a, int length, int width) {
    int **b = new int*[width];
    for (int i = 0; i < width; i++) {
        b[i] = new int[length];
        for (int j = 0; j < length; j++) {
            b[i][j] = a[j][i];
        }
    }
    return b;
}

// 14. Concatenate 2 given size-equal matrices, horizontally / vertically.
int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres) {

}
int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres) {

}

// 15. Multiple 2 given matrices.
bool multiple2Matrices(int**& res, int** a, int **b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb) {
    if (lengtha == widthb) {
        lengthr = lengthb;
        widthr = widtha;
        res = new int*[widthr];
        for (int i = 0; i < widthr; i++) {
            res[i] = new int[lengthr];
            for (int j = 0; j < lengthr; j++) {
                res[i][j] = 0;
                for (int k = 0; k < lengtha; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

// 16. Given a matrix a. Find the submatrix of a which satisfies keyboard input size and has the largest total value of its elements.
int** findSubmatrix(int** a, int length, int width, int &lres, int &wres) {
    
}


int main() {
    int *a = new int[5];
    int *b = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 2;
        b[i] = i + 1;
    }
    printArray(a, 5);
    printArray(b, 5);

    int na = 5;
    int nb = 5;

    int cc = 0, cr = 0;
    int **c = generateMatrix2(a, b, na, nb, cr, cc);
    for (int i = 0; i < cr; i++) {
        for (int j = 0; j < cc; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    delete[] a;
    delete[] b;

    return 225;
}
