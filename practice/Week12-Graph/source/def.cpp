// #include "lib.h"
#include <bits/stdc++.h>
using namespace std;

// struct directedGraph 
struct Graph {
    int n; // number of vertices
    int **a; // adjacency matrix
    vector <vector<int>> list; // adjacency list

    int numEdges; // number of edges
    bool isDirected; // true if graph is directed

    vector <int> deg; // degree of each vertex (undirected graph)
    vector <int> inDeg; // in-degree of each vertex (directed graph)
    vector <int> outDeg; // out-degree of each vertex (directed graph)

    vector <int> isolatedV; // isolated vertices
    vector <int> leafV; // leaf vertices

    Graph();

    Graph(int **&a, int n) {
        this->n = n;
        this->a = a;
        // tạo danh sách kề
        for (int i = 0; i < n; i++) {
            vector <int> temp;
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    temp.push_back(j);
                }
            }
            list.push_back(temp);
        }
    }
    Graph(vector <vector<int>> &list, int n) {
        this->n = n;
        this->list = list;
        // tạo ma trận kề
        a = new int*[n];
        for (int i = 0; i < n; i++) {
            a[i] = new int[n];
            for (int j = 0; j < n; j++) {
                a[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < list[i].size(); j++) {
                int v = list[i][j];
                a[i][v] += 1;
            }
        }
    }
};


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

// 3.1. check a graph is directed or undirected: kiểm tra liệu đồ thị có hướng hay vô hướng
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

// 3.2. cal the number of edges and number of vertices
int numEdges (int **a, int n) {
    int count = 0;
    if (isDirected(a, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count += a[i][j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                count += a[i][j];
            }
        }
    }
    return count;
}

int numEdges (vector <vector<int>> list, int n) {
    int count = 0;
    if (isDirected(list, n)) {
        for (int i = 0; i < n; i++) {
            count += list[i].size();
        }
    } else {
        for (int i = 0; i < n; i++) {
            count += list[i].size();
            for (int j = 0; j < list[i].size(); j++) {
                if (list[i][j] == i) {
                    count++; // đỉnh i kề với chính nó, gấp đôi số cạnh để chia 2 phía sau
                }
            }
        }
        count /= 2;
    }
    return count;
}

// 3.3. degree of each vertices for undirected graph. In-degree and out-degree for directed graph.
void calDeg (Graph &g1) {
    // đối với đồ thị vô hướng: số bậc của đỉnh = số đỉnh kề với nó
    // khuyên được tính hai lần
    if ( ! g1.isDirected) {
        for (int i = 0; i < g1.n; i++) {
            int deg = 0;
            for (int j = 0; j < g1.n; j++) {
                deg += g1.a[i][j];
                if (j == i && g1.a[i][j] == 1) {    // khuyên được tính hai lần
                    deg++;
                }
            }
            g1.deg.push_back(deg);
        }
    } else {
        // đối với đồ thị có hướng: số bậc vào của đỉnh = tổng cột của đỉnh đó
        // số bậc ra của đỉnh = tổng dòng của đỉnh đó
        // khuyên được tính 1 lần bậc vào và 1 lần bậc ra
        for (int i = 0; i < g1.n; i++) {
            int inDeg = 0;
            int outDeg = 0;
            for (int j = 0; j < g1.n; j++) {
                inDeg += g1.a[j][i];
                outDeg += g1.a[i][j];
            }
            g1.inDeg.push_back(inDeg);
            g1.outDeg.push_back(outDeg);
        }

        // tính bậc tổng của đỉnh
        for (int i = 0; i < g1.n; i++) {
            g1.deg.push_back(g1.inDeg[i] + g1.outDeg[i]);
        }
    }
}

// 4. list of isolated vertices/ leaf vertices
void listIsolated (Graph &g1) {
    // Đỉnh cô lập: đỉnh có bậc bằng 0
    for (int i = 0; i < g1.n; i++) {
        if (g1.deg[i] == 0) {
            g1.isolatedV.push_back(i);
        }
    }
}

void listLeaf (Graph &g1) {
    // Đỉnh lá: đỉnh có bậc bằng 1
    for (int i = 0; i < g1.n; i++) {
        if (g1.deg[i] == 1) {
            g1.leafV.push_back(i);
        }
    }
}

// 3.5. is the given graph special: complete graph, circular graph, bigraph, complete bi-graph
/*
    Complete graph: đồ thị đơn vô hướng có n đỉnh và n(n-1)/2 cạnh, giữa hai đỉnh bất kì đều có một cạnh nối
    Circular graph: đồ thị chứa 1 chu trình duy nhất qua tất cả các đỉnh, mỗi đỉnh có bậc đúng bằng 2
    Bigraph: đồ thị có thể chia thành 2 phần không có cạnh nối giữa các đỉnh trong cùng 1 phần
    Complete bi-graph: đồ thị có thể chia thành 2 phần không có cạnh nối giữa các đỉnh trong cùng 1 phần, mỗi phần đều liên kết với các đỉnh trong phần còn lại
*/
bool isComplete (Graph g1) {
    if (g1.isDirected) {
        return false;
    }
    if (g1.isolatedV.size() > 0) {
        return false;
    }
    if (g1.numEdges != g1.n * (g1.n - 1) / 2) {
        return false;
    }
    for (int i = 0; i < g1.n; i++) {
        for (int j = 0; j < g1.n; j++) {
            if (i != j && g1.a[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool isCircular (Graph g1) {
    if (g1.isDirected) {
        return false;
    }
    if (g1.isolatedV.size() > 0) {
        return false;
    }
    for (int i = 0; i < g1.n; i++) {
       if (g1.list.size() != 2) {
           return false;
       }
    }
    return true;
}

bool isBigraph(Graph g1) {
    // nếu có đỉnh cô lập thi không phải đồ thị 2 phần
    if (g1.isolatedV.size() > 0) {
        return false;
    }
    // tạo mảng color để đánh dấu màu cho các đỉnh
    int color[g1.n] = {0};
    // tạo queue các đỉnh đã tô màu để duyệt
    queue<int> q;
    // tạo vector visited để đánh dấu các đỉnh đã duyệt
    vector <int> visited;
    // sử dụng hai màu 1 và 2 để tô màu cho các đỉnh

    // tô màu cho đỉnh đầu tiên là 1
    color[0] = 1;
    // đưa đỉnh đầu tiên vào queue
    q.push(0);

    while (visited.size() < g1.n) {
        // lấy đỉnh đầu tiên trong queue
        int u = q.front();
        // xóa đỉnh đầu tiên trong queue
        q.pop();
        // duyệt các đỉnh kề với đỉnh u
        for (int x : g1.list[u]) {
            // nếu đỉnh x chưa được tô màu
            if (color[x] == 0) {
                // tô màu cho đỉnh x là màu khác với màu của đỉnh u
                color[x] = 3 - color[u];
                // đưa đỉnh x vào queue
                q.push(x);
            }
            // nếu đỉnh x đã được tô màu
            else {
                // nếu đỉnh x có cùng màu với đỉnh u
                if (color[x] == color[u]) {
                    return false;
                }
            }
        }
        // đánh dấu đỉnh u đã được duyệt
        visited.push_back(u);
    }
    return true;
}

bool isCompleteBigraph(Graph g1) {
    if (! isBigraph(g1)) {
        return false;
    }

    // tạo mảng color để đánh dấu màu cho các đỉnh
    int color[g1.n] = {0};
    // tạo queue các đỉnh đã tô màu để duyệt
    queue<int> q;
    // tạo vector visited để đánh dấu các đỉnh đã duyệt
    vector <int> visited;
    // sử dụng hai màu 1 và 2 để tô màu cho các đỉnh

    // tô màu cho đỉnh đầu tiên là 1
    color[0] = 1;
    // đưa đỉnh đầu tiên vào queue
    q.push(0);

    while (visited.size() < g1.n) {
        // lấy đỉnh đầu tiên trong queue
        int u = q.front();
        // xóa đỉnh đầu tiên trong queue
        q.pop();
        // duyệt các đỉnh kề với đỉnh u
        for (int x : g1.list[u]) {
            // nếu đỉnh x chưa được tô màu
            if (color[x] == 0) {
                // tô màu cho đỉnh x là màu khác với màu của đỉnh u
                color[x] = 3 - color[u];
                // đưa đỉnh x vào queue
                q.push(x);
            }
        }
        // đánh dấu đỉnh u đã được duyệt
        visited.push_back(u);
    }

    // lấy các đỉnh cùng màu 1 vào vector v1
    vector <int> v1;
    for (int i = 0; i < g1.n; i++) {
        if (color[i] == 1) {
            v1.push_back(i);
        }
    }

    int nV2 = g1.n - v1.size();

    // duyệt qua các đỉnh trong v1, nếu có số  đỉnh kề khác nv2 thì đồ thị không phải là complete bigraph
    for (int x : v1) {
        if (g1.list[x].size() != nV2) {
            return false;
        }
    }

    return true;
}

bool isSpecialGraph (Graph g1) {
    if (isComplete(g1)) {
        cout << "Complete graph" << endl;
        return true;
    }
    if (isCircular(g1)) {
        cout << "Circular graph" << endl;
        return true;
    }
    if (isBigraph(g1)) {
        if (isCompleteBigraph(g1)) {
            cout << "Complete bigraph" << endl;
            return true;
        }
        cout << "Bigraph" << endl;
        return true;
    }

    return false;
}

// 3.6. the number of connected components. how many of them are trees
/*
    Đồ thị liên thông: đồ thị có thể đi từ một đỉnh bất kì đến mọi đỉnh khác
    Cây: đồ thị liên thông không có chu trình
*/
// void connectedComponents (Graph g1) {
//     int count = 0;
//     for (int i = 0; i < g1.n; i++) {
//         if (g1.visited[i] == false) {
//             count++;
//             DFS(g1, i);
//         }
//     }
//     cout << "Number of connected components: " << count << endl;
//     cout << "Number of trees: " << count - g1.cycles << endl;
// }


// 3.7. the number of cut vertices and bridge edges


// -------------------------------------------------------

// 4. generate a base undirected graph from a given directed graph
void generateUndirectedGraph (Graph g1, Graph &g2) {
    // thiết lập các giá trị cho đồ thị mới
    g2.n = g1.n;
    g2.numEdges = g1.numEdges;
    g2.isDirected = false;
    g2.isolatedV = g1.isolatedV;
    g2.leafV = g1.leafV;

    g2.list = g1.list;

    // chuyển danh sách kề của đồ thị có hướng thành đồ thị vô hướng
    for (int i = 0; i < g1.n; i++) {
        for (int j = 0; j < g1.list[i].size(); j++) {
            int x = g1.list[i][j];
            // duyệt qua danh sách kề của x nếu không có i thì thêm vào
            if (find(g2.list[x].begin(), g2.list[x].end(), i) == g2.list[x].end()) {
                g2.list[x].push_back(i);
            }
        }
    }

    // khởi tạo ma trận kề cho đồ thị vô hướng
    g2.a = new int*[g2.n];
    for (int i = 0; i < g2.n; i++) {
        g2.a[i] = new int[g2.n];
        for (int j = 0; j < g2.n; j++) {
            g2.a[i][j] = 0;
        }
    }

    // chuyển danh sách kề thành ma trận kề
    for (int i = 0; i < g2.n; i++) {
        for (int j = 0; j < g2.list[i].size(); j++) {
            int x = g2.list[i][j];
            g2.a[i][x] += 1;
        }
    }

    // tính số bậc cho  các đỉnh
    calDeg(g2);
}

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

    // chuyển sang dạng cấu trúc
    Graph g1(a, n1);
    Graph g2(list, n2);

    // tính số cạnh
    g1.numEdges = numEdges(a, n1);
    g2.numEdges = numEdges(list, n2);

    // kiểm tra đồ thị có hướng hay không
    g1.isDirected = isDirected(a, n1);
    g2.isDirected = isDirected(list, n2);

    // xác định bậc của đỉnh
    calDeg(g1);
    calDeg(g2);

    // xác định đỉnh cô lập, đỉnh lá
    listIsolated(g1);
    listIsolated(g2);
    listLeaf(g1);
    listLeaf(g2);

    // xác định có phải đồ thị đặc biệt hay không
    isSpecialGraph(g1);
    isSpecialGraph(g2);

    // xác định số thành phần liên thông


    return 225;
}