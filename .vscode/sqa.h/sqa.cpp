#include "sqa.h"

Stack::Stack(int cap)
{
    capacity = cap;
    arr = new int[capacity];
    top = -1; 

}
Stack::~Stack()
{
    delete[] arr;
}

void Stack::push(int value)
{
    if (top >= capacity -1)
    {
        cout << "Stack Overflow!" << endl;
        return;
    }
    top++;
    arr[top] = value;
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return; 
    }
    int popped = arr[top];
    top--;
    return popped;
}

int Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return -1; 
    } 

    return arr[top];
}
bool Stack::isEmpty()
{
    return top == -1;
}
int Stack::size()
{
    return top +1;
}
void Stack::display()
{
     if(isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return; 
    }
    cout << "Stack Elements" << endl;
    for(int i = top; i >= 0; i--)
    { 
        cout << arr[i] << endl;
    }
    cout << endl;
}