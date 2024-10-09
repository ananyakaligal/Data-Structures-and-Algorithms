#include <iostream>
using namespace std;

class Deque {
    // Properties
public:
    int* arr;       // Array to store elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Maximum size of the deque
    int count;      // Current size of the deque

    // Constructor
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1; // Initialize rear to -1
        count = 0;
    }

    // Push element at the front
    void pushFront(int element) {
        if (count == capacity) {
            cout << "Deque overflow" << endl; // Deque is full
            return;
        }

        if (front == -1) {
            // If deque is empty
            front = 0;
            rear = 0;
        } else {
            // Circular decrement of front
            front = (front + 1) % capacity;
        }
        arr[front] = element; // Add element at front
        count++;
    }

    // Push element at the rear
    void pushRear(int element) {
        if (count == capacity) {
            cout << "Deque overflow" << endl; // Deque is full
            return;
        }

        if (rear == -1) {
            // If deque is empty
            front = 0;
            rear = 0;
        } else {
            // Circular increment of rear
            rear = (rear - 1 + capacity) % capacity;
        }
        arr[rear] = element; // Add element at rear
        count++;
    }

    // Pop front element
    void pop() {
        if (count == 0) {
            cout << "Deque underflow" << endl; // Deque is empty
            return;
        }

        front = (front - 1 + capacity) % capacity; // Circular decrement
        count--;
        
        // Reset front and rear if deque becomes empty
        if (count == 0) {
            front = -1; // Reset front
            rear = -1;  // Reset rear
        }
    }

    // Get front element
    int getFront() {
        if (count == 0) {
            cout << "Deque is empty" << endl;
            return -1; // Indicate empty deque
        }
        return arr[front]; // Return front element
    }

    // Get rear element
    int getRear() {
        if (count == 0) {
            cout << "Deque is empty" << endl;
            return -1; // Indicate empty deque
        }
        return arr[rear]; // Return rear element
    }

    // Check if empty
    bool isEmpty() {
        return count == 0; // Deque is empty if count is 0
    }

    // Destructor to free memory
    ~Deque() {
        delete[] arr; // Free allocated memory
    }
};

int main() {
    Deque dq(5); // Create an instance of the Deque with size 5

    // Push elements
    dq.pushRear(2);
    dq.pushRear(4);
    dq.pushFront(1);

    // Pop front element
    dq.pop();

    // Print front element
    cout << "Printing front element: " << dq.getFront() << endl;

    // Print rear element
    cout << "Printing rear element: " << dq.getRear() << endl;

    // Check if empty
    if (dq.isEmpty()) {
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }

    // Pop the remaining elements
    dq.pop(); // Remove front element

    // Check again if empty
    if (dq.isEmpty()) {
        cout << "Deque is empty after popping elements" << endl;
    } else {
        cout << "Deque is not empty after popping elements" << endl;
    }

    return 0; // End program
}
