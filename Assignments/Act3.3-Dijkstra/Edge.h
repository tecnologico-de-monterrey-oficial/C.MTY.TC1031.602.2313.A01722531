#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Edge {
    T target;
    T source;
    int weight;
    Edge();
    Edge(T source, T target);
    Edge(T source, T target, int weight);

};


template <class T>
Edge<T>::Edge(T source, T target) {
    this->source = source;
    this->target = target;
    this->weight = 0;
}

template <class T> 
Edge<T>::Edge(T source, T target, int weight) {
    this->source = source;
    this->target = target;
    this->weight = weight;
}

template <class T>
Edge<T>::Edge() {
    weight = 0;
}