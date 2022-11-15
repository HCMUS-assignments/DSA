#include <bits/stdc++.h>
using namespace std;

// demo how to use friend function

class SinhVien {
private:
    string id;
    int age;

public:
    SinhVien(string id, int age) : id(id), age(age) {}

    friend void print(SinhVien sv); // friend function: can access private members of class

    friend ostream &operator<<(ostream &os, SinhVien &sv) {
        os << "id: " << sv.id << " age: " << sv.age << endl;
        return os;
    }

    friend istream &operator>>(istream &is, SinhVien &sv) {
        is >> sv.id >> sv.age;
        return is;
    }
};

void print(SinhVien sv) {
    cout << "id: " << sv.id << " age: " << sv.age << endl;
}


int main() {
    SinhVien sv("B20DCCN001", 20);
    print(sv);
    cout << sv;

    SinhVien sv2("B20DCCN002", 21);
    cin >> sv2;
    cout << sv2;
    return 0;
}