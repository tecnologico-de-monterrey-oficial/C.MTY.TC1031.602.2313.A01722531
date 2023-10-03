
// greta guagnelli
// a01722531
// ITD

#ifndef stack_h
#define stack_h

#include <iostream>
#include "node.h"

template <class T>
class Stack {
private:
    Node<T>* head;
    int size;

public:
    Stack();
    void pop(); // elimina el elemento al tope de la pila
    void push(T data); // agrega elemento al tope de la pila
    T top(); // regresa el valor del elemento al tope
    bool isEmpty(); // regresa si la pila está vacía
    void print();
    
};

template <class T>
Stack<T>::Stack() {
    head = nullptr;
    size = 0;
}

template <class T>
void Stack<T>::pop() {
    if (head == nullptr) {
        cout << "La pila está vacía" << endl;
    } else {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
    }
}

template <class T>
void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    size++;
}

template <class T>
T Stack<T>::top() {
    if (head == nullptr) {
        cout << "La pila está vacía" << endl;
        return 0;
    } else {
        return head->data;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void Stack<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " -> ";
        aux = aux->next;
    }
    cout << endl;
}

#endif