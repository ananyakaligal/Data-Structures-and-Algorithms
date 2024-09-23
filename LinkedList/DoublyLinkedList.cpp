#include <iostream>
using namespace std;

// Node class representing each node in the doubly linked list
class Node {
public:
    int data;          // Data stored in the node
    Node* prev;       // Pointer to the previous node
    Node* next;       // Pointer to the next node

    // Constructor to initialize the node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// DoublyLinkedList class to manage the nodes
class DoublyLinkedList {
private:
    Node* head;       // Pointer to the head of the list
    Node* tail;       // Pointer to the tail of the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int value){
        Node* newNode =new Node(value);
        if(head ==nullptr){
            head=newNode;
            tail=newNode;
        } else {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void insertAtEnd(int value){
        Node* newNode =new Node(value);
        if(tail==nullptr){
            head=newNode;
            tail=newNode;
        } else {
            newNode->prev=tail;
            tail->next=newNode;
            tail= newNode;
        }
    }

    void deleteNode(int value){
        if(head==nullptr){
            cout << "List is empty." <<endl;
            return;
        }

        Node* curr = head;

        if(head->data==value){
            head=head->next;
            if(head!=nullptr){
                head->prev=nullptr;
            }
            else{
                tail=nullptr;
            }
            delete curr;
            return;
        }

        while(curr!=nullptr && curr->data!=value){
            curr=curr->next;
        }

        if(curr==nullptr){
            cout << "Value not found in the list." << endl;
            return;
        }

        // Adjust the pointers to remove the node
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev; // Link next node's prev to current node's prev
        }
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next; // Link previous node's next to current node's next
        }
        delete curr; // Delete the node
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert elements
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // Display the list
    cout << "Doubly Linked List: ";
    list.display();

    // Delete a node
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    return 0;
}
