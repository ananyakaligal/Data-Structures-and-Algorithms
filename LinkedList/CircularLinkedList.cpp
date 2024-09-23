#include <iostream>
using namespace std;

// Node class representing each node in the circular doubly linked list
class Node {
public:
    int data;          // Data stored in the node
    Node* prev;        // Pointer to the previous node
    Node* next;        // Pointer to the next node

    // Constructor to initialize the node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Circular Doubly Linked List class
class CircularDoublyLinkedList {
private:
    Node* head;       // Pointer to the head of the list
    Node* tail;       // Pointer to the tail of the list

public:
    // Constructor to initialize an empty list
    CircularDoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = head;  // Circular property
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = head;  // Circular property
            head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = head;

        // If the node to be deleted is the head
        if (head->data == value) {
            if (head == tail) {  // Single node case
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = tail;
                tail->next = head;
                delete curr;
            }
            return;
        }

        // Traverse to find the node
        do {
            if (curr->data == value) {
                break;
            }
            curr = curr->next;
        } while (curr != head);

        if (curr == head) {
            cout << "Value not found in the list." << endl;
            return;
        }

        // Adjust pointers and delete the node
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }

        if (curr == tail) {  // If it's the tail node
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }

        delete curr;  // Delete the node
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularDoublyLinkedList list;

    // Insert elements
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // Display the list
    cout << "Circular Doubly Linked List: ";
    list.display();

    // Delete a node
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    return 0;
}