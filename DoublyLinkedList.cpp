#ifndef CARD_DOUBLYLINKEDLIST_CPP
#define CARD_DOUBLYLINKEDLIST_CPP

#include "DoublyLinkedList.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list)
{
    if (list.empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node<T>* iterOld = list.head;
        head = new Node<T>;
        head->data = iterOld->data;
        head->next = nullptr;
        head->prev = nullptr;

        Node<T>* temp = head;
        iterOld = iterOld->next;
        while(iterOld != nullptr)
        {
            Node<T>* afterTemp = new Node<T>;
            temp->next = afterTemp;
            afterTemp->prev = temp;
            temp = afterTemp;
            temp->data = iterOld->data;
            temp->next = nullptr;
            if (iterOld->next == nullptr)
                tail = temp;
            iterOld = iterOld->next;
        }
    }
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T>* temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
}

template <class T>
void DoublyLinkedList<T>::prepend(T value)
{
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->prev = nullptr;

    if (empty())
    {
        tail = temp;
        temp->next = nullptr;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
    }
    head = temp;
}

template <class T>
void DoublyLinkedList<T>::append(T value)
{
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->next = nullptr;

    if (empty())
    {
        head = temp;
        temp->prev = nullptr;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
    }
    tail = temp;
}

template <class T>
void DoublyLinkedList<T>::insertBefore(Node<T>* node, T value)
{
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->next = node;
    temp->prev = node->prev;

    if (node == head)
        prepend(value);
    else
    {
        node->prev->next = temp;
        node->prev = temp;
    }
}
template <class T>
void DoublyLinkedList<T>::insertAfter(Node<T>* node, T value)
{
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->next = node->next;
    temp->prev = node;

    if (node == tail)
        append(value);
    else
    {
        node->next->prev = temp;
        node->next = temp;
    }
}

template <class T>
Node<T>* DoublyLinkedList<T>::search(T value)
{
    Node<T>* here = head;
    if (here == nullptr) return nullptr;
    while (here->data != value && here->next != nullptr) here = here->next;
    if (here->data == value) return here;
    return nullptr;
}

template <class T>
T DoublyLinkedList<T>::getHead()
{
    return head->data;
}

template <class T>
T DoublyLinkedList<T>::getTail()
{
    return tail->data;
}

template <class T>
T DoublyLinkedList<T>::getAt(int i) const
{
    if (i >= size())
    {
        cout << "Attempting to access an index that is greater than the list size.";
        return head->data;
    }
    Node<T>* temp = head;
    for (int j = 0; j < i; j++)
        temp = temp->next;
    return temp->data;
}

template <class T>
bool DoublyLinkedList<T>::empty() const
{
    return head == nullptr;
}

template <class T>
int DoublyLinkedList<T>::size() const
{
    int count = 0;
    Node<T>* iter = head;
    while (iter != nullptr)
    {
        count++;
        iter = iter->next;
    }
    return count;
}

template <class T>
ostream& operator <<(ostream& outs, const DoublyLinkedList<T>& list)
{
    Node<T>* iter = list.head;
    while (iter != nullptr)
    {
        outs << iter->data << " ";
        iter = iter->next;
    }
    return outs;
}

template <class T>
void operator +=(DoublyLinkedList<T>& list, const T value)
{
    list.append(value);
}

#endif //CARD_DOUBLYLINKEDLIST_CPP