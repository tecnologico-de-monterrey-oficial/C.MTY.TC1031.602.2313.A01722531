#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void addFirst(T data);
    void print();
    int getSize();
    bool isEmpty();
    void addLast(T data);
    void insert (int index, T data);
    int findData (T data);
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::addFirst(T data) {
    // Apuntamos head a un nuevo nodo que apunte a head
    head = new Node<T>(data, head);
    //Incrementamos el valor de size en 1
    size++;
}

template<class T>
void LinkedList<T>::print() {
    // Define a pointer of the node type and initialize it to the head;
    Node<T>* aux = head;
    while (aux != nullptr) {
        // Print the value of the node
        cout << aux->data;
        // Check if there is a next node
        if (aux->next != nullptr) {
            cout << " -> ";
        }
        // Move to the next node
        aux = aux->next;
    }
    // Print a newline character after the list
    cout << endl;
}

template<class T>
void LinkedList<T>::addLast(T data){
    // validamos si la lista está vacía
    if (isEmpty()) {
        head = new Node<T>(data);
    } else { 
    // definimos un apuntador auxiliar igual a head para recorrer la lista
    Node<T>* aux = head;
    while (aux -> next != nullptr) {
        aux = aux -> next;
    }

    aux -> next = new Node<T>(data);
    }
    size++;
}

template<class T>
void LinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size){
        int auxIndex = 0;
        Node<T>* aux = head;
        while (auxIndex != index) {
            // recorremos aux
            aux = aux -> next;
            // incrementamos el valor de indice auxiliar
            auxIndex++;
        }
        // insertamos el valor
        aux ->next = new Node<T>(data, aux -> next);
        // incrementamos valor size
        size++;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
}

template<class T>
int LinkedList<T>::findData(T data) {
    // definimos un apuntador auxiliar igual a head 
    Node<T>* aux = head;
    // definimos un índice auxiliar
    int auxIndex = 0;
    while (aux != nullptr) {
        if (data == aux->data) {
            // ya lo encontramos
            return auxIndex;
        } else {
            // recorremos aux
            aux = aux->next;
            // incrementamos el índice auxiliar
            auxIndex++;
        }
    }
    // no lo encontramos
    return -1;
    
}

template<class T>
T LinkedList<T>::getData(int index) {
    

}



template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}


#endif