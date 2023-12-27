#include <iostream>
using namespace std;

const short PIN_TRIES = 3;

class Stack
{
private:
    int stack[PIN_TRIES + 1];
    int top;

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i <= PIN_TRIES; i++)
        {
            push(i);
        }
    }
    void push(int item)
    {
        if (top == (PIN_TRIES + 1) - 1)
        {
            cout << "Stack overflow! cannot push item.\n";
            return;
        }
        top++;
        stack[top] = item;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow! cannot pop item.\n";
            return -1;
        }
        int poppedItem = stack[top];
        top--;
        cout << endl
             << "Tries: " << poppedItem << endl;
        return poppedItem;
    }
};