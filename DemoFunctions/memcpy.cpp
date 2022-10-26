#include <bits/stdc++.h>
using namespace std;

int main() {
    // demo how to use memcpy
    // ex1: copy int array
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];
    memcpy(b, a, sizeof(a));
    cout << "ex1: copy int array" << endl;
    for (int i = 0; i < 5; i++) {
        cout << b[i] << endl;
    }

    // ex2: copy string
    string s = "hello world";
    char c[100];
    memcpy(c, s.c_str(), s.size());
    cout << "ex2: copy string" << endl;
    cout << c << endl;

    // ex3: copy struct
    struct Point {
        int x, y;
    };
    Point p1 = {1, 2};
    Point p2;
    memcpy(&p2, &p1, sizeof(p1));
    cout << "ex3: copy struct" << endl;
    cout << p2.x << " " << p2.y << endl;

    // ex4: như bài đọc file , copy dữ liệu từ mảng subject vào mảng examinee 
    int subject[5] = {1, 2, 3, 4, 5};
    struct Examinee {
        int id;
        int score[5];
    };
    Examinee e;
    memcpy(e.score, subject, sizeof(subject));
    // tham số thứ nhất của memcpy là địa chỉ của biến cần copy
    // tham số thứ hai của memcpy là địa chỉ của biến nguồn
    // tham số thứ ba của memcpy là kích thước của biến nguồn
    cout << "ex4: copy array to struct" << endl;
    for (int i = 0; i < 5; i++) {
        cout << e.score[i] << endl;
    }



    return 225;
}