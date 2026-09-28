#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLL {

    Node* last = NULL;

    // Insert at start
    void insertAtStart(int value) {
        Node* newNode = new Node(value);

        if (last == NULL) {
            last = newNode;
            newNode->next = newNode;
        }
        else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (last == NULL) {
            last = newNode;
            newNode->next = newNode;
        }
        else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Delete from start
    void deleteAtStart() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;

        if (temp == last) {
            last = NULL;
        }
        else {
            last->next = temp->next;
        }

        delete temp;
    }

    // Delete from end
    void deleteAtEnd() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (last->next == last) {
            delete last;
            last = NULL;
            return;
        }

        Node* temp = last->next;

        while (temp->next != last) {
            temp = temp->next;
        }

        temp->next = last->next;

        Node* deleteNode = last;
        last = temp;

        delete deleteNode;
    }

    // Display
    void display() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);

        cout << endl;
    }
};


int main() {

    CircularLL list;

    list.insertAtStart(30);
    list.insertAtStart(20);
    list.insertAtStart(10);

    list.display();

    list.insertAtEnd(40);
    list.insertAtEnd(50);

    list.display();

    return 0;
}
