#include <bits/stdc++.h>
using namespace    std;

int main() {
    string name, sex;
    int age, weight;
    float height;

    // input
    getline(cin, name);
    cin >> age;
    fflush(stdin);
    getline(cin, sex);
    cin >> height >> weight;
    
    // output
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: " << sex << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;

    return 0;
}