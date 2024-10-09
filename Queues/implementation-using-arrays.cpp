#include<iostream>
using namespace std;

class Queue {
    // properties
    public:
        int *arr;
        int front;
        int rear;
        int size;

    // constructor
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // enqueue element
    void enqueue(int element) {
        if (rear == size - 1) {
            // Queue is full
            cout << "Queue overflow" << endl;
        } else {
            if (front == -1) {
                // Set front to 0 if it's the first element being added
                front = 0;
            }
            arr[++rear] = element; // Move rear and add element
        }
    }

    // dequeue element
    void dequeue() {
        if (front == -1 || front > rear) {
            // Queue is empty
            cout << "Queue underflow" << endl;
        } else {
            front++; // Move front forward
        }
    }

    // get front element
    int peek() {
        if (front == -1 || front > rear) {
            // Queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // check if empty
    bool isempty() {
        return front == -1 || front > rear;
    }
};

int main() {
    // create queue of size 5
    Queue q(5);

    // enqueue elements
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    // print front element
    cout << "Front element: " << q.peek() << endl;

    // dequeue front element
    q.dequeue();

    // print front element after dequeue
    cout << "Front element after dequeue: " << q.peek() << endl;

    // check if empty
    if (q.isempty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
