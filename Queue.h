#include <iostream>
using namespace std;

template <typename t>
class QueueNode
{
public:
    t data;
    QueueNode<t> *next;

    QueueNode(t data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename t>
class Queue
{
private:
    QueueNode<t> *front;
    QueueNode<t> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(t data)
    {
        QueueNode<t> *newNode = new QueueNode<t>(data);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    t dequeue()
    {
        t ret;
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return ret;
        }
        QueueNode<t> *temp = front;
        t dequeuedItem = temp->data;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        return dequeuedItem;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }
};