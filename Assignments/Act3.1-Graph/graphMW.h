#ifndef GraphMW_h
#define GraphMW_h

#include "Edge.h"

template <class T>
class GraphMW {
private:
    vector<T> vertices;
    vector< vector<int> > matrix;
    int findVertex(T vertex);
public:
    GraphMW();
    GraphMW(vector<T> vertices, vector< Edge<T> > edges);
    void print();
};

template <class T>
GraphMW<T>::GraphMW() {

}

template <class T>
int GraphMW<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}


template <class T>
GraphMW<T>::GraphMW(vector<T> vertices, vector< Edge<T> > edges) {
    this->vertices = vertices;
    vector<int> rows(vertices.size(),0);
    matrix.assign(vertices.size(), rows);
    for (auto edge : edges) {
        int sourceIndex = findVertex(edge.source);
        int targetIndex = findVertex(edge.target);
        if (sourceIndex != -1 && targetIndex != -1) {
            matrix[sourceIndex][targetIndex] = edge.weight;
        }

    }
}

template <class T>
void GraphMW<T>::print() {
    cout << "   ";
    for (auto vertex : vertices) {
        cout << " " << vertex;
    }
    cout << endl;
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (int j=0; j<vertices.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


#endif /* GraphMW_h */

