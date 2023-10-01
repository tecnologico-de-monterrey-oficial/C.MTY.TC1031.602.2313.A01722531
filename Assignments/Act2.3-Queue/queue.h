#ifndef queue_h
#define queue_h

#include "node.h"

template <class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* tail;
public:
    Queue();
    void push (T data); // agrega un elemento al final de la fila
    void pop(); // elimina el primer elemento de la fila
    T front(); // regresa el primer elemento 
    bool isEmpty();

};

#endif