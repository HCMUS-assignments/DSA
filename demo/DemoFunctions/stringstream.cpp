#include <bits/stdc++.h>
using namespace std;

int main () {
    // demo how to use stringstream
    // ex1: convert string to int
    string s = "1 2 3 4 5";
    stringstream ss(s);
    int x;
    while (ss >> x) {
        cout << x << endl;
    }

    // ex2: convert int to string
    int y = 12345;
    stringstream ss2;
    ss2 << y;
    string s2 = ss2.str();
    cout << s2 << endl;

    // ex3: split string
    string s3 = "1,2,3,4,5";
    stringstream ss3(s3);
    string temp;
    while (getline(ss3, temp, ',')) {
        cout << temp << endl;
        cout << "remaining string: " << ss3.str() << endl;
        /*
            sau khi tách được số đầu tiên từ string s3, thì ss3.str() sẽ trả về chuỗi còn lại ở buffer
            sau đó tiếp tục tách tiếp từ buffer đó
            ss3 vẫn giữ nguyên giá trị ban đầu
        */
        
    }

    // ex4: convert string to float
    string s4 = "1.2 2.3 3.4 4.5 5.6";
    stringstream ss4(s4);
    float f;
    while (ss4 >> f) {
        cout << f << endl;
    }


    return 225;
}