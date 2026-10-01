#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int n;
    int *arr;

public:
    Queue(int capacity)
    {
        n = capacity;
        arr = new int[n];
        front = 0;
        rear = -1;
        size = 0;
    }

    void join(int token)
    {
        if (size == n)
        {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % n;
        arr[rear] = token;
        size++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve()
    {
        if (size == 0)
        {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        front = (front + 1) % n;
        size--;

        if (size == 0)
        {
            rear = -1;
            front = 0;
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Front token: " << arr[front] << endl;
        }
    }
};

int main()
{
    Queue q(3);

    q.join(31);
    q.join(32);
    q.join(33);

    q.serve();

    q.join(34);

    q.serve();
    q.serve();
    q.serve();

    return 0;
}