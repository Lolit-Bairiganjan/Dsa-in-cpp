#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {head = nullptr;}

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void traverseLinkedList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
    }

    ~LinkedList(){
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList* linkedList1 = new LinkedList();
    linkedList1->insertAtHead(10);
    linkedList1->insertAtHead(20);
    linkedList1->traverseLinkedList();
    return 0;
}