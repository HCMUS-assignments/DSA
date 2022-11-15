#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}


int main() {
    SetConsoleOutputCP(65001);
    setcolor( 225 , 2003);
    
        cout << setw(80) << "chúc bạn thi may mắn nhé" << endl;
    
    return 225;
}