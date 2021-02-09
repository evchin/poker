#ifndef CARD_STACK_H
#define CARD_STACK_H

#include <iostream>
using namespace std;

template <class T>
struct StackFrame
{
    T data;
    StackFrame *link;
};

template <class T>
class Stack
{
    public:
        Stack();
        Stack(const Stack<T>& aStack);
        ~Stack();

        void push(T object);
        void clear();
        T pop();
        bool empty() const;

    private:
        StackFrame<T>* top;
};

#include "Stack.cpp"

#endif //CARD_STACK_H