
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>


#include "node.h"

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();
    void pop();
    void push (T data);
    T front();
    bool isEmpty();
    void print();
};

template <class T>
Queue<T>::Queue(){
    head = nullptr;
    tail = nullptr;
} 

template <class T>
void Queue<T>::pop() {
    if (isEmpty()) {
        cout << "La fila está vacía" << endl;
    } else {
        Node<T>* aux = head;
        head = head -> next;
        delete aux; 
    }
}

template <class T>  
void Queue<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

template <class T>
T Queue<T>::front() {
    if (isEmpty()) {
        cout << "La fila está vacía" << endl;
        return 0;
    } else {
        return head -> data;
    }
}

template <class T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void Queue<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux -> data << endl;
        aux = aux -> next;
    }
    cout << endl << endl;  
}


#endif


