#include <bits/stdc++.h>
using namespace std;

// 1. swap 2 given integers
void swap(int *a, int *b) ;

// 2. calculate the total value of 2 integers
int *sum (int *a, int *b) ;

// 3. input an array with unknown size
void inputArray(int *&a, int &n) ;

// 4. print a given array
void printArray(int *a, int n) ;

// 5. find the largest value from a given array
int *findMax(int *arr, int n) ;

// 6. find the longest ascending subarray from a given array
int *findLongestAscendingSubarray(int *a, int n, int &length) ;

// 7. swap 2 given arrays
void swapArray(int *&a, int *&b, int &na, int &nb) ;

// 8. concatenate 2 given arrays
int *concatenateArray(int *a, int *b, int na, int nb, int &nc) ;

// 9. given 2 ascending arrays with distinguish elements, generate a new ascending array with all elements from the given arrays
int *merge2Arrays(int *a, int *b, int na, int nb, int &nc) ;

// 10. generate a random matrix with keyboard input size
void generateMatrix1(int **&a, int &length, int &width) ;

// 11. given two 1D arrays a and b, generate the matrix c that c[i][j] = a[i] * b[j]
int **generateMatrix2(int *a, int *b, int na, int nb, int &crow, int &ccol) ;

// 12. Swap 2 columns / rows of a given matrix.
void swapRows(int** a, int length, int width, int ir1, int ir2) ;
void swapColumns(int** a, int length, int width, int ic1, int ic2) ;

// 13. Generate the transpose matrix of a given matrix.
int** transposeMatrix(int** a, int length, int width) ;

// 14. Concatenate 2 given size-equal matrices, horizontally / vertically.
int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres) ;
int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres) ;

// 15. Multiple 2 given matrices.
bool multiple2Matrices(int**& res, int** a, int **b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb) ;

// 16. Given a matrix a. Find the submatrix of a which satisfies keyboard input size and has the largest total value of its elements.
int** findSubmatrix(int** a, int length, int width, int &lres, int &wres) ;