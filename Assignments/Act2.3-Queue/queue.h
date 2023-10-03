#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template <class T>
class Queue {
private:
    Node<T>* frontNode;
    Node<T>* tail;

public:
    Queue();
    void push(const T& data); // agrega un elemento al final de la cola
    void pop(); // elimina el primer elemento de la cola
    T front() const; // regresa el primer elemento
    bool isEmpty() const;
};

template <class T>
Queue<T>::Queue() : frontNode(nullptr), tail(nullptr) {}

template <class T>
void Queue<T>::push(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        frontNode = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <class T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T>* temp = frontNode;
        frontNode = frontNode->getNext();
        delete temp;
    }
}

template <class T>
T Queue<T>::front() const {
    if (!isEmpty()) {
        return frontNode->getData();
    } else {
        throw out_of_range ("La cola está vacía.");
    }
}

template <class T>
bool Queue<T>::isEmpty() const {
    return frontNode == nullptr;
}

#endif // QUEUE_H
