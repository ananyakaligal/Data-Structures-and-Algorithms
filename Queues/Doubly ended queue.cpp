  #include <iostream>
#include <deque> // Include the deque header
using namespace std;

int main() {
    // Declare deque
    deque<int> dq;

    // Enqueue at the rear
    dq.push_back(2);
    dq.push_back(4);

    // Enqueue at the front
    dq.push_front(1);

    // Dequeue front element
    dq.pop_front();

    // Print front element
    cout << "Printing front element: " << dq.front() << endl;

    // Print rear element
    cout << "Printing rear element: " << dq.back() << endl;

    // Check if empty
    if (dq.empty()) {
        // Deque is empty
        cout << "Deque is empty" << endl;
    } else {
        // Deque is not empty
        cout << "Deque is not empty" << endl;
    }

    // Dequeue the remaining elements
    dq.pop_back(); // Remove rear element

    // Check again if empty
    if (dq.empty()) {
        cout << "Deque is empty after popping elements" << endl;
    } else {
        cout << "Deque is not empty after popping elements" << endl;
    }

    return 0; // End program
}
