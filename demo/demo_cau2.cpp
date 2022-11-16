
#include <iostream>
using namespace std;

// Viết hàm tìm UCLN của hai số nguyên dương a, b
int UCLN (int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
}

int main() {
    // nhập vào tử mẫu của một phân số, kiểm tra xem phân số có tối giản hay chưa
    int tu, mau;
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
    if (UCLN(tu, mau) == 1)
        cout << "Phan so da toi gian";
    else
        cout << "Phan so chua toi gian";
    return 22;
}

