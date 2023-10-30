#ifndef minHeap_h
#define minHeap_h

#include <vector>


template <class T>
class minHeap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    minHeap();
    minHeap(vector<T> list);
    minHeap(initializer_list<T> list);
    T pop(); 
    void push(T data);
    int getSize();
    void print();
    bool isEmpty();
};

template <class T>
minHeap<T>::minHeap() {
}

template <class T>
void minHeap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void minHeap<T>::downSort(int father)
{
    int son1;
    int son2;
    int smol;

    while (father * 2 + 1 < heap.size())
    {
        son1 = father * 2 + 1;
        if (father * 2 + 2 < heap.size())
        {
            son2 = father * 2 + 2;
            heap[son1] < heap[son2] ? smol = son1 : smol = son2;
        }
        else
        {
            smol = son1;
        }
        if (heap[smol] < heap[father])
        {
            swap(father, smol);
            father = smol;
        }
        else
        {
            father = heap.size();
        }
    }
}

template <class T>
minHeap<T>::minHeap(vector<T> list)
{
    heap = list;
    int father = heap.size() / 2 - 1;
    while (father >= 0)
    {
        downSort(father);
        father--;
    }
}

template <class T>
minHeap<T>::minHeap(initializer_list<T> list)
{
    heap = list;
    int father = heap.size() / 2 - 1;

    while (father >= 0)
    {
        downSort(father);
        father--;
    }
}

template <class T>
T minHeap<T>::pop()
{
    if (!heap.empty())
    {
        T aux = heap[0];
        swap(0, heap.size() - 1);
        heap.pop_back();
        downSort(0);
        return aux;
    } else {
        throw out_of_range("heap esta vacío");
    }
}

template <class T>
void minHeap<T>::push(T data) {
    heap.push_back(data);
    int son = heap.size()-1;
    while (son > 0) {
        int father = (son - 1) / 2;
        if (heap[son] < heap[father]) {
            swap(son, father);
            son = father;
        } else {
            son = 0;
        }
    }
}

template <class T>
void minHeap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
bool minHeap<T>::isEmpty()
{
    return heap.empty();
}

#endif