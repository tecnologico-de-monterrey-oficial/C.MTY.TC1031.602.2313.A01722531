#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include "Node.h"

template<class T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* prev;
    int size;
public:
    DoubleLinkedList();
    void addFirst(T data);
    void addLast(T data);
    void sortDate();
    void sortIP();
    void swap(Node<T>* a, Node<T>* b);
    void print();
    int getSize();
    bool isEmpty();
    T findData(string ip);
    T& operator[](int index);
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    size = 0;
}


template<class T>
int DoubleLinkedList<T>::getSize() {
    return size;
}

template<class T>
void DoubleLinkedList<T>::addFirst(T data) {
    Node<T>* newNode = new Node<T>(data, head, nullptr);

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    size++;
}

template<class T>
void DoubleLinkedList<T>::addLast(T data) {
    Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
    if (isEmpty())
    {
        head = new Node<T>(data);
    }else{
        Node<T>* aux = head;

        while (aux->next != nullptr)
        {
            aux = aux->next;
        }
        aux -> next = newNode;
        newNode -> prev = aux;
    }
    size++;
}

template<class T>
void DoubleLinkedList<T>::swap(Node<T>* a, Node<T>* b)
{
    if (a != nullptr && b != nullptr)
    {
        T aux = a -> data;
        a -> data = b -> data;
        b -> data = aux;
    }
    
}

template<class T>
void DoubleLinkedList<T>::sortDate() {
    Node<T>* aux;
    bool control = true;

    while (control) {
        control = false;
        aux = head;

        while (aux != nullptr && aux -> next != nullptr) {
            if (aux -> data > aux->next->data) {
                swap(aux, aux->next);
                control = true;
            }
            aux = aux->next;
        }
    }
}

template<class T>
void DoubleLinkedList<T>::sortIP() {
    Node<T>* aux;
    bool control = true;

    while (control) {
        control = false;
        aux = head;

        while (aux != nullptr && aux->next != nullptr) {
            if (aux->data.ip > aux->next->data.ip) {
                swap(aux, aux->next);
                control = true;
            }
            aux = aux->next;
        }
    }
}

template <class T>
T& DoubleLinkedList<T>::operator[](int index){
    if (index >= 0 && index <= size)
    {
        Node<T>* aux = head;
        int auxIndex =0;
        while (auxIndex < index)
        {
            aux = aux->next;
            auxIndex ++;
        }
        return aux->data;
    }else{
        throw out_of_range("Indice incorrecto");
    }
}

template<class T>
void DoubleLinkedList<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data;

        if (aux->next != nullptr) {
            cout << " -> " << endl;
        }
    
        aux = aux->next;
    }
   
}

template <class T>
bool DoubleLinkedList<T>::isEmpty()
{
    return size == 0;
}

template <class T>
T DoubleLinkedList<T>::findData(string ip)
{
    Node<T>* aux = head;
    while (aux != nullptr)
    {
        if (aux->data.ip == ip)
        {
            return aux->data;
        }
        aux = aux->next;
    }
    return T();
}

#endif