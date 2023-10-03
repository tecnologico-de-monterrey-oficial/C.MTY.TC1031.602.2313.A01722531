<<<<<<< HEAD
#pragma once

template <class T>
struct Node {

    T data;
    Node<T>* next;
    Node();
    Node(T data);
    Node(T data, Node<T>* next);

};

template<class T>
Node<T>::Node() {
    next = nullptr;
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
}

template<class T>
Node<T>::Node(T data, Node<T>* next) {
    this->data = data;
    this->next = next;
=======
#pragma once

template <class T>
struct Node {

    T data;
    Node<T>* next;
    Node();
    Node(T data);
    Node(T data, Node<T>* next);

};

template<class T>
Node<T>::Node() {
    next = nullptr;
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
}

template<class T>
Node<T>::Node(T data, Node<T>* next) {
    this->data = data;
    this->next = next;
>>>>>>> 370b8e64c86f5af7741995a4fcac804e5d059359
}