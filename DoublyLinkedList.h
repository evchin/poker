#ifndef CARD_DOUBLYLINKEDLIST_H
#define CARD_DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    Node* next;
    Node* prev;
    T data;
};

template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& list);
    ~DoublyLinkedList();

    void prepend(T value);
    void append(T value);
    void insertBefore(Node<T>* node, T value);
    void insertAfter(Node<T>* node, T value);
    Node<T>* search(T value);
    T getHead();
    T getTail();
    T getAt(int i) const;
    bool empty() const;
    int size() const;

    template <class S>
    friend ostream& operator <<(ostream& outs, const DoublyLinkedList<S>& list);
    template <class S>
    friend void operator +=(DoublyLinkedList<S>& list, const S value);
private:
    Node<T>* head;
    Node<T>* tail;
};

#include "DoublyLinkedList.cpp"

#endif //CARD_DOUBLYLINKEDLIST_H
