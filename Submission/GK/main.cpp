#include<iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

struct Animal
{
	string en;
	string vn;
	string ph;
	int loai;
};

struct Node
{
	Animal data;
	Node* pnext;
};

struct LinkedList
{
	Node* pHead;
	Node* pTail;
};

void outputAnimal(Animal a)
{
    cout << a.en << " " << a.vn << " " << a.ph << " " << a.loai << endl;
}

void outputList(LinkedList *L)
{
    Node* p = L->pHead;
    while (p != NULL)
    {
        outputAnimal(p->data);
        p = p->pnext;
    }
}

LinkedList* readAnimals(string filename)
{
    //CODE HERE
    // init new List
    LinkedList *L = new LinkedList;
    L->pHead = NULL;
    L->pTail = NULL;

    fstream fin;
    fin.open(filename, ios::in);
    if (fin.fail()) {
        cout << "Error opening file !\n";
        exit(225);
    }

    string lineInfo;
    while (getline(fin, lineInfo)) {
        // init new Node
        Node *newNode = new Node;
        newNode->data.en = lineInfo;
        getline(fin, lineInfo);
        newNode->data.ph = lineInfo;
        getline(fin, lineInfo);
        newNode->data.vn = lineInfo;
        getline(fin, lineInfo);
        newNode->data.loai = stoi(lineInfo);
        newNode->pnext = NULL;

        // add to List
        if (L->pHead == NULL) {
            L->pHead = newNode;
            L->pTail = newNode;
        } else {
            L->pTail->pnext = newNode;
            L->pTail = newNode;
        }
    }

    // outputList(L);

    fin.close();
    return L;

}

void removeDuplicate(LinkedList* list)
{
    //CODE HERE
    Node *p = list->pHead;
    while (p != NULL) {
        Node *q = p->pnext;
        Node *prev = p;
        while (q != NULL) {
            if (p->data.en == q->data.en) {
                prev->pnext = q->pnext;
                delete q;
                q = prev->pnext;
            } else {
                prev = q;
                q = q->pnext;
            }
        }
        p = p->pnext;
    }
    // cout << "\nafter remove duplicate: " << endl;
    // outputList(list);
}


void printPaths(int** matrix, vector<int> &route, int len_route,  int i, int j, int M, int N, int &countAssign, int &countCompare)
{
    // MxN matrix
    if(++countCompare && M == 0 || ++countCompare && N == 0)
    {
        return;
    }

    // if the last cell is reached
    if(++countCompare && i == M-1 && ++countCompare && j == N-1)
    {
        // print the route
        for (int k = 0 && ++countAssign; ++countCompare && k < len_route;++countAssign && k++)
        {
            cout << route[k] << " ";
        }
        cout << matrix[i][j] << endl;
        return;
    }

    // add the current cell to route
    route.push_back(matrix[i][j]);
    len_route += 1;
    ++countAssign;

    // move down
    if (++countCompare && i + 1 < M)
    {
        printPaths(matrix, route, len_route, i+1, j, M, N, countAssign, countCompare);
    }
    
    // move right
    if (++countCompare && j + 1 < N)
    {
        printPaths(matrix, route, len_route, i, j+1, M, N, countAssign, countCompare);
    }

    // move diagonally
    if (++countCompare && i + 1 < M && ++countCompare && j + 1 < N)
    {
        printPaths(matrix, route, len_route,  i+1, j+1, M, N, countAssign, countCompare);
    }

    // backtrack
    route.pop_back();
}


void CountAssignmentandComparision()
{
    int M = 3, N=3;
    int** matrix = new int*[M];

    for(int i =0; i < M; i++)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < M*N; i++)
    {
        matrix[i/N][i%N] = i;
    }

    vector<int> route;
    int len_route = 0;
    int i = 0, j = 0;

    int countAssign = 0;
    int countCompare = 0;
    
    // Goi ham printPaths
    printPaths(matrix, route, len_route, i, j, M, N, countAssign, countCompare); // Ban co the thay doi dong nay neu co thay doi tham so cua ham
    
    // In ra so phep gan và so phep so sanh
    // CODE HERE
    cout << "So phep gan: " << countAssign << endl;
    cout << "So phep so sanh: " << countCompare << endl;
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i) {
    int l = 2*i - 1;
    int r = 2*i + 1;
    if (l < n && r <n) {
        if (arr[l] > arr[r]) {
            if (arr[l] > arr[i]) {
                swap(arr[l], arr[i]);
            } 
        } else {
            if (arr[r] > arr[i]) {
                swap(arr[r], arr[i]);
            }
        }
    } else if (l < n) {
        if (arr[l] > arr[i]) {
            swap(arr[l], arr[i]);
        }
    } else if (r < n) {
        if (arr[r] > arr[i]) {
            swap(arr[r], arr[i]);
        }
    }
    
}

void heapSort(int *arr, int n) {
    // xay dung max heap
    for (int i = (n-1)/2; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // heap sort
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int kthSmallest(int* arr, int n, int k)
{
    //CODE HERE
    // sap xep mang arr theo thu tu tang dan
    heapSort(arr, n);

    // tra ve phan tu thu k trong mang arr
    return arr[k-1];
}

int main()
{

    // Cau 1
    string filename = "data.txt";
    // 1.1
    LinkedList* list = readAnimals(filename);
    // 1.2
    removeDuplicate(list);
    
    // Cau 2
    CountAssignmentandComparision();

    // Cau 3

    int n = 10;
    int * arr = new int[n]{0, 5, 2, 4, 1, 9, 10, 10, 7, 2};
    int k = 5;

    int res = kthSmallest(arr, n, k);
    cout << "phan tu nho thu " << k << " cua mang la: " << res << endl;
    delete arr;
    return -1;
}
