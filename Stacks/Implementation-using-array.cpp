#include<iostream>
using namespace std;

class Stack {
    // properties
    public:
        int *arr;
        int top;
        int size;

    // constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // push element
    void push(int element) {
        if (top + 1 < size) {
            arr[++top] = element;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    // pop element
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    // peek top element
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
        }
        return -1;
    }

    // check if empty
    bool isempty() {
        return top == -1;
    }
};

int main() {
    // create stack of size 5
    Stack st(5);

    // push elements
    st.push(5);
    st.push(10);
    st.push(15);

    // print top element
    cout << "Top element: " << st.peek() << endl;

    // pop top element
    st.pop();

    // print top element
    cout << "Top element after pop: " << st.peek() << endl;

    // check if empty
    if (st.isempty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
