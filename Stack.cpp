#ifndef CARD_STACK_CPP
#define CARD_STACK_CPP

#include "Stack.h"

template <class T>
Stack<T>::Stack() : top(nullptr) {}

template <class T>
Stack<T>::Stack(const Stack<T>& aStack)
{
    if (aStack.empty())
        top = nullptr;
    else
    {
        StackFrame<T>* temp = aStack.top;
        StackFrame<T>* iter = new StackFrame<T>;
        iter->data = temp->data;
        top = iter;

        while (temp != nullptr)
        {
            iter->link = new StackFrame<T>;
            iter = iter->link;
            iter->data = temp->data;
            temp = temp->link;
        }
        iter->link = nullptr;
    }
}

template <class T>
Stack<T>::~Stack()
{
    while (!empty()) pop();
}

template <class T>
void Stack<T>::push(T object)
{
    StackFrame<T>* a = new StackFrame<T>;
    a->data = object;
    a->link = top;
    top = a;
}

template <class T>
void Stack<T>::clear()
{
    while (!empty())
        pop();
}

template <class T>
T Stack<T>::pop()
{
    if (empty())
    {
        cout << "ERROR: Popping an empty stack." << endl;
        exit(1);
    }

    T c = top->data;
    StackFrame<T>* temp = top;
    top = top->link;
    delete temp;
    return c;
}

template <class T>
bool Stack<T>::empty() const
{
    return top == nullptr;
}

#endif