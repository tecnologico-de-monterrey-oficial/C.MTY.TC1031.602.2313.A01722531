
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
    void addLast(T data);
    void insert (int index, T data);
    bool deleteData (T data);
    bool deleteAt (int index);
    T getData (int index);
    void updateData(T data, T newData);
    void updateAt (int index, T data);
    int findData (T data);
    void duplicate(LinkedList<T> &list);
    void print();
    int getSize();
    bool isEmpty();
    T operator [] (int index);
    void operator = (LinkedList<T> list);
    LinkedList<T> duplicate (LinkedList<T> list);
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
bool LinkedList<T>::deleteData (T data){
    // validamos si la lista está vacía
    if (!isEmpty()) {
        if (head -> data == data) {
            Node<T>* aux = head;
            head = head-> next;
            size--;
            delete aux;
            return true;

        } else {
            Node<T>* aux = head -> next;
            Node<T>* auxPrev = nullptr;
            while (aux != nullptr) {
                if (aux-> data == data){
                    auxPrev->next = aux->next;
                    size--;
                    delete aux;
                    return true;
                }
                auxPrev = aux;
                aux = aux->next;
            }
            return false;
        } 
    }
    else {
        return false;
    }
}

template<class T>
bool LinkedList<T>::deleteAt (int index){
    if (index >= 0 && index < size) {
        if (index == 0) {
            Node<T>* aux = head;
            head = head-> next;
            size--;
            delete aux;
            return true;
        } else {
        return false;
        }
    }
}


template<class T>
T LinkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex= 0;
        while (auxIndex < index) {
            aux = aux-> next;
            auxIndex++;
        }

        return aux->data;
    } else {
        throw out_of_range("Índice incorrecto");
    }

}

template<class T>
void LinkedList<T>::updateData(T data, T newData) {
    Node<T>* aux = head;
    int auxIndex = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            aux->data = newData; 
            return;
        }
        aux = aux->next;
        auxIndex++;
    }
    throw out_of_range (" El dato a actualizar no se encontró en la lista");
}

template<class T>
void LinkedList<T>::updateAt (int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }
        aux->data = data;
    } else {
        throw out_of_range ("Índice inválido");
    }

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
int LinkedList<T>::findData(T data) {
    Node<T>* aux = head;
    int auxIndex = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            return auxIndex;
        }
        aux = aux->next;
        auxIndex++;
    }
    return -1;
}

template<class T>
T LinkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex= 0;
        while (auxIndex < index) {
            aux = aux-> next;
            auxIndex++;
        }

        return aux->data;
    } else {
        throw out_of_range("Índice incorrecto");
    }

}

template<class T>
void LinkedList<T>::duplicate() {
    Node<T>* aux = head;
    int auxIndex = 0;
    while(aux != nullptr){
        insert(auxIndex, aux->data);
        aux = aux->next->next;
        auxIndex+=2;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}



#endif