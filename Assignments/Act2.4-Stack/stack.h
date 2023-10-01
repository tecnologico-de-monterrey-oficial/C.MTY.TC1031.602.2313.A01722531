#ifndef stack_h
#define stack_h

template <class T>
class Stack {
private:
    Node<T>* top;

public:
    Stack();
    void push(T data); // agrega elemento al tope de la pila
    void pop(); // elimina el elemento al tope de la pila
    T top(); // regresa el valor del elemento al tope
    bool isEmpty(); // regresa si la pila está vacía

}

#endif