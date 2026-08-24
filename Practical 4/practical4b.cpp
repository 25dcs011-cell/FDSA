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

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
}

void remove(Node*& head, int value) {
    if (head == NULL) {
        return;
    }

    if (head->data == value) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != head && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next->data == value) {
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Circle is empty" << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, value;

    do {
        cout << "\n1. Join Student" << endl;
        cout << "2. Leave Student" << endl;
        cout << "3. Display Circle" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student number: ";
                cin >> value;
                insert(head, value);
                display(head);
                break;

            case 2:
                cout << "Enter student number: ";
                cin >> value;
                remove(head, value);
                display(head);
                break;

            case 3:
                display(head);
                break;

            case 0:
                cout << "Program ended" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}