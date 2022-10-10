#include <bits/stdc++.h>
using namespace std;

// From No. 17. to No. 20. are Searching Algorithms. Return the first position found, else, return −1

// 17. Sequential Search.
int LinearSearch(int* a, int n, int key) ;

// 18. Sequential Search uses flag.
int SentinelLinearSearch(int* a, int n, int key) ;

// 19. Binary Search in sorted array a.
int BinarySearch(int* a, int n, int key);

// 20. Binary Search in sorted array a uses recursion.
int RecursiveBinarySearch(int* a, int left, int right, int key);