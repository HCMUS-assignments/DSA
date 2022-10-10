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

// 6. Count the number of common divisor of 2 given integers.
int CountCommonDivisor(int a, int b) {
    
}

// 7. Calculate the Greatest common divisor and Least common multiple of 2 given integers.
int GCD(int a, int b) {

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

    cout << Reverse(22503) << endl;
    cout << IsAllDigitsEven(22503) << endl;

    char s[] = "ABCD";
    Permutation(s, 4);

    return 225;
}