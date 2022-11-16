#include <iostream>
using namespace std;

// viết hàm tính tổng các chữ số của một số nguyên dương n
int tongChuSo(int n)
{
    int tong = 0;
    while (n > 0)
    {
        tong = tong + n % 10;
        n = n / 10;
    }
    return tong;
}

int main() {
    // kiểm tra xem một số có chia hết cho 3 hay không
    int n;
    cout << "Nhap n: ";
    cin >> n;
    if (tongChuSo(n) % 3 == 0)
        cout << "Chia het cho 3";
    else
        cout << "Khong chia het cho 3";

    return 22;

}