#ifndef HEAP_H
#define HEAP_H
#include <vector>

template <class T>
class heap {
private:
    vector<T> data; 
    void swap(int a, int b);
    void downSort(int father);

public:
    heap();
    heap(vector<T> list);
    heap(initializer_list<T> list);
    T pop(); 
    void push(T data);
    int getSize();
    void print();
    bool isEmpty();
};

template <class T>
heap<T>::heap() {}

template <class T>
heap<T>::heap(vector<T> list) {
    data = list;
    for (int i = data.size() / 2 - 1; i >= 0; i--) {
        downSort(i);
    }
}

template <class T>
heap<T>::heap(initializer_list<T> list) {
    data = list;
    for (int i = data.size() / 2 - 1; i >= 0; i--) {
        downSort(i);
    }
}

template <class T>
void heap<T>::swap(int a, int b) {
    T temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

template <class T>
void heap<T>::downSort(int father) {
    int left = father * 2 + 1;
    int right = father * 2 + 2;
    int largest = father;
    if (left < data.size() && data[left] > data[largest]) {
        largest = left;
    }
    if (right < data.size() && data[right] > data[largest]) {
        largest = right;
    }
    if (largest != father) {
        swap(father, largest);
        downSort(largest);
    }
}

template <class T>
T heap<T>::pop() {
    T result = data[0];
    data[0] = data[data.size() - 1];
    data.pop_back();
    downSort(0);
    return result;
}

template <class T>
void heap<T>::push(T data) {
    this->data.push_back(data);
    int child = this->data.size() - 1;
    int father = (child - 1) / 2;
    while (child > 0 && this->data[child] > this->data[father]) {
        swap(child, father);
        child = father;
        father = (child - 1) / 2;
    }
}

template <class T>
int heap<T>::getSize() {
    return data.size();
}

template <class T>
void heap<T>::print() {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T>
bool heap<T>::isEmpty() {
    return data.empty();
}

#endif