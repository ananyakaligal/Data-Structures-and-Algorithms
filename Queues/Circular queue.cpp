#include<iostream>
using namespace std;

class CircularQueue {
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

    // enqueue element in circular queue
void enqueue(int element) {
    // Check if the queue is full
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
        cout << "Queue is full" << endl;
        return;
    }
    // First element to be inserted
    else if (front == -1) {
        front = rear = 0;
        arr[rear] = element;
    }
    // If rear is at the end but front is not at 0, wrap around
    else if (rear == size - 1 && front != 0) {
        rear = 0;
        arr[rear] = element;
    }
    // Normal case
    else {
        rear++;
        arr[rear] = element;
    }
}
    // dequeue element
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int data=arr[front];
        arr[front=]=-1;

        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
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
