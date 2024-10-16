#include<iostream>
#include<cmath>
using namespace std;

int conversion(int binary) {
    int n = 0;
    int i = 0;
    int lastDigit;

    while (binary > 0) {
        lastDigit = binary % 10;
        n += lastDigit * pow(2, i);
        i++;
        binary /= 10;
    }

    return n;
}

int main() {
    int binary = 1101;
    int n = conversion(binary);
    cout << n << endl;
    return 0;
}
