#ifndef Graph_h
#define Graph_h

#include "Edge.h"
#include <algorithm>
#include <stack>
#include <queue>


template <class T>
class Graph{
private:
    vector<T> vertices;
    vector< vector< Edge<T> > > adjacencyList;
    int findVertex(T vertex);
    void dfsr(T vertex, vector<bool> &status);
    int findShortest(vector<bool> &status, vector<int> &cost);

public:
    Graph();
    Graph(vector<T> vertices, vector< Edge<T> > edges);

    void addVertex(T vertex);
    void addEdge(Edge<T> edge);

    void removeVertex(T vertex);
    void removeEdge(Edge<T> edge);

    void print();

    void bfs(T vertex);
    void dfs(T vertex);
    void dijkstra(T vertex);
};

template <class T>
Graph<T>::Graph(){
    
}

template <class T>
int Graph<T>::findVertex(T vertex){
    typename vector<T>::iterator it;

    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template <class T>
Graph<T>::Graph(vector<T> vertices, vector< Edge<T> > edges){
    this->vertices = vertices;

    adjacencyList.resize(vertices.size());

    for (auto edge : edges){
        int sourceIndex = findVertex(edge.source);
        int targetIndex = findVertex(edge.target);
        if (sourceIndex != -1 && targetIndex != -1) {
            adjacencyList[sourceIndex].push_back(edge);
        }
    }
}

// addVertex
template <class T>
void Graph<T>::addVertex(T vertex){
    int vertexIndex = findVertex(vertex);
    if (vertexIndex == -1){
        vertices.push_back(vertex);
        vector< Edge<T> > emptyEdges;
        adjacencyList.push_back(emptyEdges);
    } else {
        throw invalid_argument("Vertice ya existe");
    }
}

// addEdge
template <class T>
void Graph<T>::addEdge(Edge<T> edge){
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    if (sourceIndex != -1 && targetIndex != -1) {
        for (auto neighbor : adjacencyList[sourceIndex]){
            if (neighbor.target == edge.target){
                throw invalid_argument("El arco ya existe");
            }
        }
        adjacencyList[sourceIndex].push_back(edge);
    } else {
        throw invalid_argument("Algunos de los vertices no existen");
    }
}

// removeVertex
template <class T>
void Graph<T>::removeVertex(T vertex){
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        vertices.erase(vertices.begin() + vertexIndex);
        adjacencyList.erase(adjacencyList.begin() + vertexIndex);
        for (auto &adjacency : adjacencyList) {
            typename vector< Edge<T> >::iterator it;
            it = adjacency.begin();
            while (it != adjacency.end()) {
                if (it->target == vertex) {
                    adjacency.erase(it);
                } else {
                    it++;
                }
            }
        }
    }
}

// removeEdge   
template <class T>
void Graph<T>::removeEdge(Edge<T> edge){
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    if (sourceIndex != -1 && targetIndex != -1) {
        typename vector< Edge<T> >::iterator it;
        it = adjacencyList[sourceIndex].begin();
        while (it != adjacencyList[sourceIndex].end()) {
            if (it->target == edge.target) {
                adjacencyList[sourceIndex].erase(it);
            } else {
                it++;
            }
        }
    }
}


template <class T>
void Graph<T>::bfs(T vertex){
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        vector<bool> visited(vertices.size(), false);
        queue<int> queue;
        queue.push(vertexIndex);
        visited[vertexIndex] = true;
        while (!queue.empty()) {
            int currentVertex = queue.front();
            for (auto neighbor : adjacencyList[currentVertex]) {
                int targetIndex = findVertex(neighbor.target);
                if (!visited[targetIndex]) {
                    queue.push(targetIndex);
                    visited[targetIndex] = true;
                }
            }
            cout << vertices[currentVertex] << " ";
            queue.pop();
        }
        cout << endl;
    } else {
        throw invalid_argument("el vertice no existe");
    }
}

template <class T>
void Graph<T>::dfsr(T vertex, vector<bool> &status){
    cout << vertex << " ";
    int vertexIndex = findVertex(vertex);
    status[vertexIndex] = true;
    for (auto neighbor : adjacencyList[vertexIndex]) {
        int neighborIndex = findVertex(neighbor.target);
        if (!status[neighborIndex]) {
            dfsr(neighbor.target, status);
        }
    }
}

template <class T>
void Graph<T>::dfs(T vertex) {
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        vector<bool> status(vertices.size(), false);
        dfsr(vertex, status);
    } else {
        throw invalid_argument("el vertice no es valido");
    }
}

template <class T>
int Graph<T>::findShortest(vector<bool> &status, vector<int> &cost) {
    int shortestIndex = -1;
    int shortestCost = INT_MAX;
    for (int i=0; i<vertices.size(); i++) {
        if (!status[i]) {
            if (cost[i] < shortestCost) {
                shortestCost = cost[i];
                shortestIndex = i;
            }
        }
    }
    return shortestIndex;
}

template <class T>
void Graph<T>::dijkstra(T vertex) {
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        vector<bool> status(vertices.size(), false);
        vector<int> cost(vertices.size(), INT_MAX);
        vector<int> path(vertices.size(), -1);
        cost[vertexIndex] = 0;
        int shortestIndex = vertexIndex;
        while (shortestIndex != -1) {
            status[shortestIndex] = true;
            for (auto neighbor : adjacencyList[shortestIndex]) {
                int neighborIndex = findVertex(neighbor.target);
                if (!status[neighborIndex]) {
                    if (cost[neighborIndex] > cost[shortestIndex] + neighbor.weight) {
                        cost[neighborIndex] = cost[shortestIndex] + neighbor.weight;
                        path[neighborIndex] = shortestIndex;
                    }
                }
            }
            shortestIndex = findShortest(status, cost);
        }
        vector< stack<int> > shortestPaths(vertices.size());
        for (int i=0; i<vertices.size(); i++) {
            if (cost[i] != INT_MAX) { 
                shortestPaths[i].push(i);
                int pathIndex = path[i];
                while (pathIndex != -1) {
                    shortestPaths[i].push(pathIndex);   
                    pathIndex = path[pathIndex];
                }
            }
        }
        for (int i=0; i<vertices.size(); i++) {
            cout << vertices[i] << " -> ";
            if (cost[i] != INT_MAX) {
                while (!shortestPaths[i].empty()) {
                    cout << shortestPaths[i].top() << " ";
                    shortestPaths[i].pop();
                }
                cout << "- " << cost[i] << endl;
            } else {
                cout << "no hay ruta" << endl;
            }
        }
    } else {
        throw invalid_argument("vertice no existe");
    }
}

template <class T>
void Graph<T>::print(){
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (auto edge : adjacencyList[i]) {
            cout << edge.target << " " << edge.weight << " - ";
        }
        cout << endl;
    }
}

#endif 