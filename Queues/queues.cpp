#include<iostream>
#include<queue>
using namespace std;

int main() {
    // Declare queue
    queue<int> q;

    // Enqueue 2
    q.push(2);
    
    // Enqueue 4
    q.push(4);

    // Dequeue front element
    q.pop();

    // Print front element
    cout << "Printing front element: " << q.front() << endl;

    // Check if empty
    if(q.empty()) {
        // Queue is empty
        cout << "Queue is empty" << endl;
    } else {
        // Queue is not empty
        cout << "Queue is not empty" << endl;
    }

    return 0; // End program
}
