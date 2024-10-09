/*
Problem Statement:
Design a data structure, which represents two stacks using only one array common for both stacks. 
The data structure should support the following operations:

push1(NUM) - Push ‘NUM’ into stack1.
push2(NUM) - Push ‘NUM’ into stack2.
pop1() - Pop out a top element from stack1 and return popped element; in case of underflow return -1.
pop2() - Pop out a top element from stack2 and return popped element; in case of underflow return -1.

There are 2 types of queries in the input:
Type 1 - These queries correspond to Push operation.
Type 2 - These queries correspond to Pop operation.
*/

#include <iostream>
using namespace std;

class TwoStacks {
private:
    int *arr;     // Array to store elements of both stacks
    int size;     // Size of the array
    int top1;     // Index for Stack1
    int top2;     // Index for Stack2

public:
    // Constructor to initialize the stacks
    TwoStacks(int n) {
        size = n;
        arr = new int[n]; // Dynamically allocate array
        top1 = -1;        // Stack1 starts from the beginning
        top2 = size;      // Stack2 starts from the end
    }

    // Push element into Stack1
    void push1(int num) {
        if (top1 + 1 == top2) { // Check for overflow
            cout << "Stack1 overflow" << endl;
            return;
        }
        arr[++top1] = num; // Increment top1 and add element
    }

    // Push element into Stack2
    void push2(int num) {
        if (top2 - 1 == top1) { // Check for overflow
            cout << "Stack2 overflow" << endl;
            return;
        }
        arr[--top2] = num; // Decrement top2 and add element
    }

    // Pop element from Stack1
    int pop1() {
        if (top1 == -1) { // Check for underflow
            cout << "Stack1 underflow" << endl;
            return -1;
        }
        return arr[top1--]; // Return top element and decrement top1
    }

    // Pop element from Stack2
    int pop2() {
        if (top2 == size) { // Check for underflow
            cout << "Stack2 underflow" << endl;
            return -1;
        }
        return arr[top2++]; // Return top element and increment top2
    }

    // Destructor to free allocated memory
    ~TwoStacks() {
        delete[] arr; // Free dynamically allocated array
    }
};

int main() {
    TwoStacks stacks(10); // Create two stacks in an array of size 10

    // Test push operations
    stacks.push1(5);
    stacks.push2(10);
    stacks.push1(15);
    stacks.push2(20);

    // Test pop operations
    cout << "Popped from Stack1: " << stacks.pop1() << endl; // Should return 15
    cout << "Popped from Stack2: " << stacks.pop2() << endl; // Should return 20

    // Testing underflow conditions
    stacks.pop1(); // Pops remaining element from Stack1
    stacks.pop1(); // Should trigger underflow for Stack1

    stacks.pop2(); // Pops remaining element from Stack2
    stacks.pop2(); // Should trigger underflow for Stack2

    return 0; // End program
}
