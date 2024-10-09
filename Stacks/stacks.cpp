#include<iostream>
#include<stack>
using namespace std;

int main() {
    // Declare stack
    stack<int> s;

    // Push 2
    s.push(2);
    
    // Push 4
    s.push(4);

    // Pop top element
    s.pop();

    // Print top element
    cout << "Printing top element: " << s.top() << endl;

    // Check if empty
    if(s.empty()) {
        // Stack is empty
        cout << "Stack is empty" << endl;
    } else {
        // Stack is not empty
        cout << "Stack is not empty" << endl;
    }

    return 0; // End program
}
