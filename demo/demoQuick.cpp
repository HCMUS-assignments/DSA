#include <bits/stdc++.h>
using namespace std;

void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int a[], int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(a, left, j);
    }
    if (i < right) {
        quickSort(a, i, right);
    }
}

void countingSort(int a[], int n) {
     int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int* count = new int[max + 1];
    for (int i = 0; i < max + 1; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    int i = 0;
    int j = 0;
    while (i < max + 1) {
        if (count[i] > 0) {
            a[j++] = i;
            count[i]--;
        }
        else {
            i++;
        }
    }
}

// 11. flash sort 
double flashSortTime (int a[], int n) {
    clock_t start = clock();

    // flash sort
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);   

	int* Class = new int[m];   // create class array to store the number of elements in each class

	for (int i = 0; i < m; i++)
		Class[i] = 0;

    // find min and max
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}

	if (a[max] == minVal)
		return 0;
        
    // c1 used to calculate the class index
	double c1 = (double)(m - 1) / (a[max] - minVal);

    // calculate the number of elements in each class
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++Class[k];
	}

    // calculate the starting position of each class
	for (int i = 1; i < m; i++)
		Class[i] += Class[i - 1];

    // swap the elements in the array to the correct position
	swap(a[max], a[0]);

	int nmove = 0;   // number of elements moved
	int j = 0;
	int k = m - 1;
	while (nmove < n - 1)
	{
        // j used to calculate the class index
		while (j > Class[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		
		if (k < 0) break;
		while (j != Class[k])  
		{
			k = int(c1 * (a[j] - minVal));
			int pos = --Class[k];
			swap(a[j], a[pos]);
			
			++nmove;
		}
	}
	delete[] Class;

	// insertionSort(a, n);
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while (j >= 0 && a[j] > x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}

    clock_t end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

int main() {
    int a[] = {15, 2, 9, 13, 12, 6, 5, 10, 4, 11, 7, 3, 14, 8, 1};
    int n = sizeof(a) / sizeof(a[0]);
    // quickSort(a, 0, n - 1);
    // countingSort(a, n);
    double time = flashSortTime(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\nTime " << time << " ms" << endl;
    return 0;
}