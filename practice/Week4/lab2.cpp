#include <bits/stdc++.h>
using namespace std;

// function 1: majority element
// find integer k such that k appears in more than half of the positions of A if such a k exists
bool hasMajorityElement (int arr[] , int a, int &value, int &count) {
    bool counted[a] = {0};
    for (int i = 0; i < a; i++) {
        if (counted[i] == false) {
            count = 1;
            for (int j = i + 1; j < a; j++) {
                if (arr[j] == arr[i]) {
                    count ++;
                    counted[j] = true;
                }
            }
            if (count > a/2) {
                value = arr[i];
                return true;
            }
        }
    }
    return false;
}

void majorityElement (int arr[], int a) {
    int value ;
    int count = 0;
    if (hasMajorityElement (arr, a, value, count)) {
        cout << "Majority: " << value << ", count: " << count  << ", n: " << a << endl;
    } else {
        cout << "No\n";
    }
}

// function 2: greatest common divisor
int greatestCommonDivisor (int a, int b) {


}

// function 3: word cloud problem
// given a string of words, return a map of the words and their frequencies
map<string, int> wordCloud (string s) {

}


// function 4: see saw problem


int main() {
    int arr[] = {1, 2,3, 4, 5, 6, 1,1,1,1,1,1,1};
    int a = sizeof(arr)/sizeof(int);
    majorityElement(arr,a);

    cout << "hihi" << endl;

    int arr2[] = {1, 2 ,3, 0, 1, 1};
    cout << "huhu\n";
    int b = sizeof(arr2) /sizeof(int);
    majorityElement(arr2, b);

    return 225;
    

    


}