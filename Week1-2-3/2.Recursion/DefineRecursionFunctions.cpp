#include "LibRecursion.h"

// 1. Calculate the sum of S = 1 + 2 + 3 + ... + n.
int Sum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + Sum(n - 1);
}

// 2. Calculate the factorial n! = 1 ∗ 2 ∗ 3 ∗ ... ∗ n.
int Factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

// 3. Calculate x^n
int Power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return x * Power(x, n - 1);
}

// 4. Count the number of digits of a given integer.
int CountDigits(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + CountDigits(n / 10);
}

// 5. Verify if every digits of given integer are even.
bool IsAllDigitsEven(int n) {
    if (n == 0) {
        return true;
    }
    if (n % 2 != 0) {
        return false;
    }
    return IsAllDigitsEven(n % 2) && IsAllDigitsEven(n / 10);
}

// some finding greatest common divisor functions supporting the sixth function

// the first way: using a - b / if a == b => return a;
int UCLN_1 (int a, int b) {
    while (a != b) {
        if (a > b ) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

// the second way: using a mod b operator / if a == 0 || b == 0 return a + b;
int UCLN_2 (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a + b;
}

// the third way: using recursion: 
int UCLN_3 (int a, int b) {
    if (b == 0) {
        return a;
    }
    return UCLN_3(b, a % b);
}

// 6. Count the number of common divisor of 2 given integers.
int CountCommonDivisor(int a, int b) {
    /*  1. find the greatest common divisor of a and b 
        2. count the number of divisor of that number */ 

    // 1. find the greatest common divisor:
    int ucln = UCLN_2(a,b);

    // 2. count the number of divisor of ucln
    int count = 2;
    for (int i = 2; i <= ucln/2; i++) {
        if (ucln % i == 0) {
            count ++;
        }
    }
    return count ;
}

// 7. Find the least common multiple of 2 given integers.
int GCD(int a, int b) {  
    // find the greatest common divisor of a and b
    int ucln = UCLN_2(a, b);

    // find the least common multiple of a and b
    int bcnn = a * b / ucln;

    return bcnn;
}

// 8. Calculate the reverse value of a given integer.
int Reverse(int n) {
    if (n < 10) {
        return n;
    }
    return n % 10 * Power(10, CountDigits(n) - 1) + Reverse(n / 10);
}

/* 9. Calculate the ith Fibonacci number.
    • F0 = 0, F1 = 1
    • Fn = Fn−1 + Fn−2,(n ≥ 2)
*/
int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 10. * Given 4 single distinguish characters. Print out all possible permutation. Example: ABCD, ABDC, ACBD, ..
void Permutation(char* a, int n) {
    if (n == 1) {
        cout << a << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        swap(a[i], a[n - 1]);
        Permutation(a, n - 1);
        swap(a[i], a[n - 1]);
    }
}

int main() {
    // test cases

    // cout << Reverse(22503) << endl;
    // cout << IsAllDigitsEven(22503) << endl;

    // char s[] = "ABCD";
    // Permutation(s, 4);

    // test ucln
    // cout << UCLN_1(125,75) << endl;
    // cout << UCLN_2(185, 15) << endl;
    // cout << UCLN_3(144, 13) << endl;

    // cout << CountCommonDivisor(180, 45) << endl;

    // cout << GCD(15, 90) << endl;

    return 225;
}