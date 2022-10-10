#include <bits/stdc++.h>
using namespace std;

// 1. Calculate the sum of S = 1 + 2 + 3 + ... + n.
int Sum(int n) ;

// 2. Calculate the factorial n! = 1 ∗ 2 ∗ 3 ∗ ... ∗ n.
int Factorial(int n) ;

// 3. Calculate x^n
int Power(int x, int n) ;

// 4. Count the number of digits of a given integer.
int CountDigits(int n) ;

// 5. Verify if every digits of given integer are even.
bool IsAllDigitsEven(int n) ;

// 6. Count the number of common divisor of 2 given integers.
int CountCommonDivisor(int a, int b) ;

// 7. Calculate the Greatest common divisor and Least common multiple of 2 given integers.
int GCD(int a, int b) ;

// 8. Calculate the reverse value of a given integer.
int Reverse(int n) ;

/* 9. Calculate the ith Fibonacci number.
    • F0 = 0, F1 = 1
    • Fn = Fn−1 + Fn−2,(n ≥ 2)
*/
int Fibonacci(int n) ;

// 10. * Given 4 single distinguish characters. Print out all possible permutation. Example: ABCD, ABDC, ACBD, ..
void Permutation(char* a, int n) ;