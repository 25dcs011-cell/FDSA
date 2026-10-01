#include <iostream>
using namespace std;

class Node
{
public:
    int patient;
    Node* next;

    Node(int p)
    {
        patient = p;
        next = NULL;
    }
};

class PatientQueue
{
    Node* front;
    Node* rear;

public:
    PatientQueue()
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(int patient)
    {
        Node* newNode = new Node(patient);

        if (rear == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << endl;
    }

    void attend()
    {
        if (front == NULL)
        {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL)
        {
            rear = NULL;
            cout << "Ward is empty" << endl;
        }
        else
        {
            cout << "Front patient: " << front->patient << endl;
        }
    }
};

int main()
{
    PatientQueue q;

    q.arrive(12);
    q.arrive(13);
    q.arrive(14);

    q.attend();
    q.arrive(15);

    q.attend();
    q.attend();
    q.attend();

    q.attend();

    return 0;
}