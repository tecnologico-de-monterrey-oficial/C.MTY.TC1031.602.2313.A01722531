#ifndef Graph_h
#define Graph_h

#include "Edge.h"
#include <queue>
#include <stack>

template <class T> class Graph {
private:
  vector<T> vertices;
  vector<vector<Edge<T>>> adjacencyList;
  void dfsr(T vertex, vector<bool> &status, vector<T> &list);
  int findShortest(vector<bool> &status, vector<int> &cost);
  void merge(vector<T> &list, int left, int mid, int right);
  void mergeSort(vector<T> &list, int left, int right);
  void exportCities(T name, vector<T> &cities);
  int Hash(T name);

public:
  Graph();
  Graph(vector<T> &vertices, vector<Edge<T>> &edges);

  void addVertex(T vertex);
  void addEdge(Edge<T> edge);

  void removeVertex(T vertex);
  void removeEdge(Edge<T> edge);

  int findVertex(T vertex);

  void Sort(T name);

  void bfs(T vertex, T name);
  void dfs(T vertex, T name);
  void dijkstraTrain(T vertexA, T vertexB);
  void dijkstraCar(T vertexA, T vertexB);

  void print(T name);
};

template <class T> int Graph<T>::Hash(T name) {
  int hashValue = 0;

  for (char ch : name) {
    char lowerChar = tolower(ch);

    if (isalpha(lowerChar)) {
      hashValue += static_cast<int>(lowerChar) - 'a' + 1;
    }
  }

  return hashValue % 200;
};

template <class T> int Graph<T>::findVertex(T vertex) {
  int index = Hash(vertex);
  int count = vertices.size() + 1;
  while (count > 0) {
    if (index >= vertices.size()) {
      index = 0;
    }
    if (vertices[index] == vertex && vertices[index] != "") {
      return index;
    }
    index += 1;
    count--;
  }
  return -1;
}

template <class T> Graph<T>::Graph() {}

template <class T> Graph<T>::Graph(vector<T> &vertices, vector<Edge<T>> &edges) {
  this->vertices = vertices;


  adjacencyList.resize(vertices.size());

  for (auto edge : edges) {
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    if (sourceIndex != -1 && targetIndex != -1) {
      adjacencyList[sourceIndex].push_back(edge);
    }
  }
}

template <class T> void Graph<T>::addVertex(T vertex) {
  int vertexIndex = findVertex(vertex);
  if (vertexIndex == -1) {
    vertices.push_back(vertex);
    vector<Edge<T>> emptyEdges;
    adjacencyList.push_back(emptyEdges);
  } else {
    throw invalid_argument("Vertice ya existe");
  }
}

template <class T> void Graph<T>::addEdge(Edge<T> edge) {
  int sourceIndex = findVertex(edge.source);
  int targetIndex = findVertex(edge.target);
  if (sourceIndex != -1 && targetIndex != -1) {
    for (auto neighbor : adjacencyList[sourceIndex]) {
      if (neighbor.target == edge.target) {
        throw invalid_argument("Arco ya existe");
      }
    }
    adjacencyList[sourceIndex].push_back(edge);
  } else {
    throw invalid_argument("Algunos de los vertices no existen");
  }
}

template <class T> void Graph<T>::removeVertex(T vertex) {
  int vertexIndex = findVertex(vertex);
  if (vertexIndex != -1) {
    vertices.erase(vertices.begin() + vertexIndex);
    adjacencyList.erase(adjacencyList.begin() + vertexIndex);
    for (auto &adjacency : adjacencyList) {
      typename vector<Edge<T>>::iterator it;
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

template <class T> void Graph<T>::removeEdge(Edge<T> edge) {
  int sourceIndex = findVertex(edge.source);
  int targetIndex = findVertex(edge.target);
  if (sourceIndex != -1 && targetIndex != -1) {
    typename vector<Edge<T>>::iterator it;
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

template <class T> void Graph<T>::bfs(T vertex, T name) {
  int vertexIndex = findVertex(vertex);
  if (vertexIndex != -1) {
    cout << endl << "BFS" << endl;
    ofstream archivo(name);
    if (!archivo.is_open()) {
      cerr << "Error al abrir el archivo: " << name << endl;
    }
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
      archivo << vertices[currentVertex] << " ";
      queue.pop();
    }
    cout << endl;
    archivo.close();
    cout << endl << name << " generado" << endl;
  } else {
    try {
      throw invalid_argument("Ciudad no encontrada");
    }
    catch (invalid_argument& e) {
      cerr << "Error: " << e.what() << endl;
    }
  }
}

template <class T> void Graph<T>::dfsr(T vertex, vector<bool> &status, vector<T> &list) {
  cout << vertex << " ";
  list.push_back(vertex);
  int vertexIndex = findVertex(vertex);
  status[vertexIndex] = true;
  for (auto neighbor : adjacencyList[vertexIndex]) {
    int neighborIndex = findVertex(neighbor.target);
    if (!status[neighborIndex]) {
      dfsr(neighbor.target, status, list);
    }
  }
}

template <class T> void Graph<T>::dfs(T vertex, T name) {
  int vertexIndex = findVertex(vertex);
  if (vertexIndex != -1) {
    cout << endl << "DFS" << endl;
    ofstream archivo(name);
    if (!archivo.is_open()) {
      cerr << "Error al abrir el archivo: " << name << endl;
    }
    vector<bool> status(vertices.size(), false);
    vector<T> list;
    dfsr(vertex, status, list);
    for(auto& vertex : list){
      archivo << vertex << " ";
    }
    cout << endl;
    archivo.close();
    cout << endl << name << " generado" << endl;
  } 
  else {
    try {
      throw invalid_argument("Ciudad no encontrada");
    }
    catch (invalid_argument& e) {
      cerr << "Error: " << e.what() << endl;
    }
  }
}
  
template <class T>
int Graph<T>::findShortest(vector<bool> &status, vector<int> &cost) {
  int MAX = INT_MAX;
  int shortestIndex = -1;
  int shortestCost = MAX;
  ;
  for (int i = 0; i < vertices.size(); i++) {
    if (!status[i]) {
      if (cost[i] < shortestCost) {
        shortestCost = cost[i];
        shortestIndex = i;
      }
    }
  }
  return shortestIndex;
}

template <class T> void Graph<T>::dijkstraTrain(T vertexA, T vertexB) {
  int MAX = INT_MAX;
  int vertexIndex = findVertex(vertexB);
  if (vertexIndex != -1) {
    vector<bool> status(vertices.size(), false);
    vector<int> cost(vertices.size(), MAX);
    vector<int> path(vertices.size(), -1);
    cost[vertexIndex] = 0;
    int shortestIndex = vertexIndex;
    while (shortestIndex != -1) {
      status[shortestIndex] = true;
      for (auto neighbor : adjacencyList[shortestIndex]) {
        int neighborIndex = findVertex(neighbor.target);
        if (!status[neighborIndex]) {
          if (cost[neighborIndex] > cost[shortestIndex] + stod(neighbor.DisTrain) ) {
            cost[neighborIndex] = cost[shortestIndex] + stod(neighbor.DisTrain);
            
            path[neighborIndex] = shortestIndex;
          }
        }
      }
      shortestIndex = findShortest(status, cost);
    }
    vector<stack<int>> shortestPaths(vertices.size());
    for (int i = 0; i < vertices.size(); i++) {
      if (cost[i] != MAX) {
        shortestPaths[i].push(i);
        int pathIndex = path[i];
        while (pathIndex != -1) {
          shortestPaths[i].push(pathIndex);
          pathIndex = path[pathIndex];
        }
      }
    }
    
    int totalcost = MAX;
    string totaltime = "00:00";
    int auxIndex = findVertex(vertexA);
    stack<int> shortPaths;
    cout << endl << "Ruta mas corta en tren" << endl;
      if (cost[auxIndex] != MAX) {
        totalcost = cost[auxIndex];
        while (!shortestPaths[auxIndex].empty()) {
          shortPaths.push( shortestPaths[auxIndex].top() );
          shortestPaths[auxIndex].pop();
        }
        string top;
        while (!shortPaths.empty()) {
          auxIndex = shortPaths.top();
          top = vertices[ auxIndex ];
          cout << top;
          shortPaths.pop();
          if(shortPaths.empty()){
            break;
          }
          for (auto& edge : adjacencyList[auxIndex]){
            if( vertices[ shortPaths.top() ] == edge.target){
              totaltime = edge.ConvertTime(totaltime, edge.TimeTrain);
              break;
            }
          }
          cout << " -> ";
        }
      } else {
        cout << "No hay ruta" << endl;
      }
    cout << endl << endl << "Distancia Total (km): " << totalcost << endl << "Tiempo total (hh:mm): " << totaltime << endl;
  } else {
    try {
      throw invalid_argument("Ciudad no encontrada");
    }
    catch (invalid_argument& e) {
      cerr << "Error: " << e.what() << endl;
    }
  }
}

template <class T> void Graph<T>::dijkstraCar(T vertexA, T vertexB) {
  int MAX = INT_MAX;
  int vertexIndex = findVertex(vertexB);
  if (vertexIndex != -1) {
    vector<bool> status(vertices.size(), false);
    vector<int> cost(vertices.size(), MAX);
    vector<int> path(vertices.size(), -1);
    cost[vertexIndex] = 0;
    int shortestIndex = vertexIndex;
    while (shortestIndex != -1) {
      status[shortestIndex] = true;
      for (auto neighbor : adjacencyList[shortestIndex]) {
        int neighborIndex = findVertex(neighbor.target);
        if (!status[neighborIndex]) {
          if (cost[neighborIndex] > cost[shortestIndex] + stod(neighbor.DisCar) ) {
            cost[neighborIndex] = cost[shortestIndex] + stod(neighbor.DisCar);

            path[neighborIndex] = shortestIndex;
          }
        }
      }
      shortestIndex = findShortest(status, cost);
    }
    vector<stack<int>> shortestPaths(vertices.size());
    for (int i = 0; i < vertices.size(); i++) {
      if (cost[i] != MAX) {
        shortestPaths[i].push(i);
        int pathIndex = path[i];
        while (pathIndex != -1) {
          shortestPaths[i].push(pathIndex);
          pathIndex = path[pathIndex];
        }
      }
    }

    int totalcost = MAX;
    string totaltime = "00:00";
    int auxIndex = findVertex(vertexA);
    stack<int> shortPaths;
    cout << endl << "Ruta mas corta en carro" << endl;
      if (cost[auxIndex] != MAX) {
        totalcost = cost[auxIndex];
        while (!shortestPaths[auxIndex].empty()) {
          shortPaths.push( shortestPaths[auxIndex].top() );
          shortestPaths[auxIndex].pop();
        }
        string top;
        while (!shortPaths.empty()) {
          auxIndex = shortPaths.top();
          top = vertices[ auxIndex ];
          cout << top;
          shortPaths.pop();
          if(shortPaths.empty()){
            break;
          }
          for (auto& edge : adjacencyList[auxIndex]){
            if( vertices[ shortPaths.top() ] == edge.target){
              totaltime = edge.ConvertTime(totaltime, edge.TimeCar);
              break;
            }
          }
          cout << " -> ";
        }
      } else {
        cout << "No hay ruta" << endl;
      }
    cout << endl << endl << "Distancia Total (km): " << totalcost << endl << "Tiempo total (hh:mm): " << totaltime << endl;
  } else {
    try {
      throw invalid_argument("Ciudad no encontrada");
    }
    catch (invalid_argument& e) {
      cerr << "Error: " << e.what() << endl;
    }
  }
}


template <class T> void Graph<T>::print(T name) {
  ofstream archivo(name);

  if (!archivo.is_open()) {
    cerr << "Error al abrir el archivo: " << name << endl;
  }

  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i] == "") {
      continue;
    }
    archivo << vertices[i];
    cout << vertices[i];
    for (auto edge : adjacencyList[i]) {
      cout << " - " << edge.target;
      archivo << " - " << edge.target;
    }
    cout << endl;
    archivo << endl;
  }

  archivo.close();
}

template <class T>
void Graph<T>::merge(vector<T> &list, int left, int mid, int right) {
  vector<T> leftList;
  for (int i = left; i <= mid; i++) {
    leftList.push_back(list[i]);
  }
  vector<T> rightList;
  for (int j = mid + 1; j <= right; j++) {
    rightList.push_back(list[j]);
  }
  int auxIndex = left;
  int leftIndex = 0;
  int rightIndex = 0;
  while (leftIndex < leftList.size() && rightIndex < rightList.size()) {
    if (leftList[leftIndex] < rightList[rightIndex]) {
      list[auxIndex] = leftList[leftIndex];
      leftIndex++;
    } else {
      list[auxIndex] = rightList[rightIndex];
      rightIndex++;
    }
    auxIndex++;
  }
  while (leftIndex < leftList.size()) {
    list[auxIndex] = leftList[leftIndex];
    leftIndex++;
    auxIndex++;
  }
  while (rightIndex < rightList.size()) {
    list[auxIndex] = rightList[rightIndex];
    rightIndex++;
    auxIndex++;
  }
}

template <class T>
void Graph<T>::mergeSort(vector<T> &list, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(list, left, mid);
    mergeSort(list, mid + 1, right);
    merge(list, left, mid, right);
  }
}

template <class T> void Graph<T>::exportCities(T name, vector<T> &cities) {
  ofstream archivo(name);

  if (!archivo.is_open()) {
    cerr << "Error al abrir el archivo: " << name << endl;
    return;
  }

  for (int i = 0; i < cities.size(); i++) {
    if (cities[i] == "") {
      continue;
    }
    archivo << cities[i] << endl;
    cout << cities[i] << endl;
  }

  archivo.close();
}

template <class T> void Graph<T>::Sort(T name) {
  vector<T> cities = vertices;
  mergeSort(cities, 0, cities.size() - 1);
  exportCities(name, cities);
}

#endif /* Graph_h */