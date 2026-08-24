#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;

    Node(int value) {
        token = value;
        next = NULL;
    }
};

void insertFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertPosition(Node*& head, int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        insertFront(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Error: Position is beyond the queue length!" << endl;
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Queue is empty";
    }

    while (head != NULL) {
        cout << head->token << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, token, position;

    do {
        cout << "\n1. Add Critical Patient (Front)" << endl;
        cout << "2. Add Routine Patient (End)" << endl;
        cout << "3. Add Priority Patient (Specific Position)" << endl;
        cout << "4. Display Queue" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient token: ";
                cin >> token;
                insertFront(head, token);
                cout << "Queue: ";
                display(head);
                break;

            case 2:
                cout << "Enter patient token: ";
                cin >> token;
                insertEnd(head, token);
                cout << "Queue: ";
                display(head);
                break;

            case 3:
                cout << "Enter patient token: ";
                cin >> token;
                cout << "Enter position: ";
                cin >> position;
                insertPosition(head, token, position);
                cout << "Queue: ";
                display(head);
                break;

            case 4:
                cout << "Queue: ";
                display(head);
                break;

            case 0:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}