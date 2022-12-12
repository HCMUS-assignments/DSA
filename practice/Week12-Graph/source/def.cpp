// #include "lib.h"
#include <bits/stdc++.h>
using namespace std;


// Đọc ma trận kề từ file (done)
void readAdjMatrix (string fileName, int **&a, int &n) {
    fstream fin(fileName, ios::in) ;
    if (fin.fail()) {
        cout << "Failing open file !" << endl;
        return;
    }

    fin >> n;
    a = new int*[n];
    for (int i = 0; i < n ; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }
    fin.close();
}

// Đọc danh sách kề từ file (done)
void readAdjList (string fileName, vector <vector<int>> &list, int &n) {
    ifstream fin(fileName, ios::in);
    if (fin.fail()) {
        cout << "Failing open file !" << endl;
        return;
    }

    fin >> n;
    string line;
    for (int i = 0; i < n; i++) {
        vector <int> temp;
        getline(fin, line);
        // tách số bởi dấu cách và đẩy vào vector
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' ')) {
            temp.push_back(stoi(token));
        }
        list.push_back(temp);
    }
    fin.close();
}

// xuất danh sách kề (done)
void printAdjList (vector <vector<int>> list, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < list[i].size(); j++) {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
}

// xuất ma trận kề (done)
void printAdjMatrix (int **a, int n) {
    cout << "Adjacency matrix: " << endl;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


// --------------------------------------------------------------

// I. Implement functions to provide information about a given graph

// 1. check a graph is directed or undirected: kiểm tra liệu đồ thị có hướng hay vô hướng
bool isDirected (int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return true;
            }
        }
    }
    return false;
}

bool isDirected (vector <vector<int>> list, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < list[i].size(); j++) {
            int v = list[i][j]; // đỉnh i kề với đỉnh v
            bool found = false;
            for (int k = 0; k < list[v].size(); k++) {
                if (list[v][k] == i) { // đỉnh v cũng kề với đỉnh i
                    found = true;
                    break;
                }
            }
            if (!found) {
                return true;
            }
        }
    }
    return false;
}

// 2. cal the number of edges and number of vertices
int numEdges (int **a, int n);
int numVertices (int **a, int n);

// 3. degree of each vertices for undirected graph. In-degree and out-degree for directed graph


// 4. list of isolated vertices/ leaf vertices

// 5. is the given graph special: complete graph, circular graph, bigraph, complete bi-graph

// 6. the number of connected components. how many of them are trees

// 7. the number of cut vertices and bridge edges


// -------------------------------------------------------

// 4. generate a base undirected graph from a given directed graph

// 5. generate a complement graph from a given undirected graph, outputting the corresponding adjacency matrix

// 6.  Generate aConverse graph from a given directed graph, outputting the corresponding adjacency matrix.

// 7. determined euler cycle from a given graph using Hiehozer's algorithm

// 8.1. find the spanning tree of a given graph using DFS traversal

// 8.2. find the spanning tree of a given graph using BFS traversal


// 9.1. find the minimum spanning tree of a given graph using Prim algorithm

// 9.2. find the minimum spanning tree of a given graph using Kruskal algorithm

// 10. verify the connection between 2 vertices of a given graph

// 11.1. find the shortest path between 2 vertices of a graph using Dijkstra algorithm

// 11.2. find the shortest path between 2 vertices of a graph using Bellman-Ford algorithm

// 11.3. find the shortest path between 2 vertices of a graph using Floyd-Warshall algorithm




int main() {
    // đọc ma trận kề từ file
    int **a;
    int n1;
    readAdjMatrix("adjMatrix1.txt", a, n1);
    printAdjMatrix(a, n1);

    // đọc danh sách kề từ file
    vector <vector<int>> list;
    int n2;
    readAdjList("adjList1.txt", list, n2);
    printAdjList(list, n2);


    return 225;
}