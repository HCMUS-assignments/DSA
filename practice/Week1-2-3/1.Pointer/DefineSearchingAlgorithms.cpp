#include "LibSearchingAlgorithms.h"

// 17. Sequential Search.
int LinearSearch(int* a, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

// 18. Sequential Search uses flag.
int SentinelLinearSearch(int* a, int n, int key) {
    int last = a[n - 1];
    a[n - 1] = key;
    int i = 0;
    while (a[i] != key) {
        i++;
    }
    a[n - 1] = last;
    if (i < n - 1 || a[n - 1] == key) {
        return i;
    }
    return -1;
}

// 19. Binary Search in sorted array a.
int BinarySearch(int* a, int n, int key) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

// 20. Binary Search in sorted array a uses recursion.
int RecursiveBinarySearch(int* a, int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (a[mid] == key) {
        return mid;
    } else if (a[mid] > key) {
        return RecursiveBinarySearch(a, left, mid - 1, key);
    } else {
        return RecursiveBinarySearch(a, mid + 1, right, key);
    }
}

/*
int main () {
    // test cases

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);

    int key = 5;
    cout << "LinearSearch: " << LinearSearch(a, n, key) << endl;
    cout << "SentinelLinearSearch: " << SentinelLinearSearch(a, n, key) << endl;
    cout << "BinarySearch: " << BinarySearch(a, n, key) << endl;
    cout << "RecursiveBinarySearch: " << RecursiveBinarySearch(a, 0, n - 1, key) << endl;

    return 225;
}
*/
