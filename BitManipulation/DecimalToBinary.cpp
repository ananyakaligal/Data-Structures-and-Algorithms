#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> conversion(int n) {
    vector<int> binary; // Use a vector to store binary digits
    if (n == 0) {
        binary.push_back(0); // Handle case for 0
        return binary;
    } else {
        while (n > 0) {
            binary.push_back(n % 2); // Store the binary digit
            n = n / 2; // Update n
        }
    }
    reverse(binary.begin(), binary.end()); // Reverse to get the correct order
    return binary; // Return the vector of binary digits
}

int main() {
    int n = 7;
    vector<int> binary = conversion(n); // Call conversion function
    // Print binary representation
    cout << "Binary representation of " << n << " is: ";
    for (int bit : binary) {
        cout << bit;
    }
    cout << endl; // Print newline
    return 0; 
}
