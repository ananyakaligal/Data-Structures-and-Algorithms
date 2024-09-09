#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

//constructor
    Node(int val){
        data =val;
        next=nullptr;
    }    
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        head=nullptr;
    }

    void insertatBeginning(int value){
        Node* newNode= new Node(value);
        newNode->next=head;
        head=newNode;
    }

    void insertatEnd(int value){
        Node* newNode =new Node(value);
        if (head==nullptr){
            head==newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void deletenode(int value){
        if(head->next==nullptr){
            cout<<"List is empty."<<endl;
            return;
        }
        else if(head->data==value){
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr && temp->next->data!=value){
            temp=temp->next;
        }

        if(temp->next==nullptr){
            cout << "Value not found in the list." << endl;
        }else{
            Node* nodetodelete=temp->next;
            temp->next=temp->next->next;
            delete nodetodelete;
        }
    }

     void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

// Main function
int main() {
    LinkedList list;
    
    // Insert elements
    list.insertatBeginning(10);
    list.insertatBeginning(20);
    list.insertatEnd(30);
    list.insertatEnd(40);
    
    // Display the list
    cout << "Linked List: ";
    list.display();
    
    // Delete a node
    list.deletenode(20);
    cout << "After deleting 20: ";
    list.display();
    
    return 0;
}