// greta guagnelli
// a01722531
// ITD

#include <iostream>
#include "node.h"
using namespace std;

template<class T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoubleLinkedList();
    void addFirst(T data);
    void addLast(T data);
    void insert (int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T data);
    int findData(T data);
    void print();
    bool isEmpty();
    T operator[](int index);
    void operator=(DoubleLinkedList<T> list);
    void clear();
    void duplicate(DoubleLinkedList<T> &list);
    void bubbleSort(DoubleLinkedList<T> &list);
    void deleteDuplicates(DoubleLinkedList<T> &list);
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void DoubleLinkedList<T>::addFirst(T data) {
    if (isEmpty()) {
        head = new Node<T>(data);
        tail = head;
    } else {
        head = new Node<T>(data, head);
    }
    size++;
}

template <class T>
void DoubleLinkedList<T>::addLast(T data) {
    if (isEmpty()) {
        head = new Node<T>(data);
        tail = head;
    } else {
        Node<T>* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
        
    }
    size++;
}

template<class T>
void DoubleLinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (index != auxIndex) {
            aux = aux->next;
            auxIndex++;
        }
        aux->next = new Node<T>(data, aux->next);
        size++;
    } else if (index == 0) {
        addFirst(data);
    } else if (index == size) {
        addLast(data);
    }
}

template<class T>
bool DoubleLinkedList<T>::deleteData(T data) {
    if (!isEmpty()) {
        int index = findData(data);
        if (index != -1) {
            deleteAt(index);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

template<class T>
bool DoubleLinkedList<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        if (index == 0) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        } else {
            Node<T>* aux = head;
            int auxIndex = 0;
            while (index - 1 != auxIndex) {
                aux = aux->next;
                auxIndex++;
            }
            Node<T>* temp = aux->next;
            aux->next = aux->next->next;
            delete temp;
        }
        size--;
        return true;
    } else {
        return false;
    }
}

template<class T>
T DoubleLinkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (index != auxIndex) {
            aux = aux->next;
            auxIndex++;
        }
        return aux->data;
    } else {
        throw out_of_range("Índice incorrecto");
    }
}

template<class T>
void DoubleLinkedList<T>::updateData(T data, T newData) {
    int index = findData(data);
    if (index != -1) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (index != auxIndex) {
            aux = aux->next;
            auxIndex++;
        }
        aux->data = newData;
    }
}

template<class T>
void DoubleLinkedList<T>::updateAt(int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (index != auxIndex) {
            aux = aux->next;
            auxIndex++;
        }
        aux->data = data;
    } else {
        cout << "Índice inválido" << endl;
    }
}

template<class T>
void DoubleLinkedList<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << "->";
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
int DoubleLinkedList<T>::findData(T data) {
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
void DoubleLinkedList<T>::clear() {
    while (!isEmpty()) {
        deleteAt(0);
    }
}

template<class T>
bool DoubleLinkedList<T>::isEmpty() {
    return size == 0;
}

template<class T>
void DoubleLinkedList<T>::duplicate(DoubleLinkedList<T> &list) {
    for (int i = 0; i < size; i+=2) {
        insert(i, list.getData(i));
    }
}

template<class T>
void DoubleLinkedList<T>::bubbleSort(DoubleLinkedList<T> &list) {
    bool swapped;
    Node<T>* current;
    Node<T>* last = nullptr;

    if (isEmpty())
        return;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                // Intercambiar los datos de los nodos
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

template<class T>
void DoubleLinkedList<T>::deleteDuplicates(DoubleLinkedList<T> &list) {
    for (int i = 0; i < size; i+=2) {
        deleteAt(i);
    }
}



