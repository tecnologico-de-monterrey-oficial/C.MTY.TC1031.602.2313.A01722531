#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

int main(){
    vector<int> vertices = {0,1,2,3,4,5,6,7};
    vector< Edge<int> > edges;
    edges.emplace_back(0,2,9);
    edges.emplace_back(0,3,9);
    edges.emplace_back(1,0,7);
    edges.emplace_back(2,0,9);
    edges.emplace_back(2,3,8);
    edges.emplace_back(2,4,9);
    edges.emplace_back(3,0,9);
    edges.emplace_back(3,2,8);
    edges.emplace_back(3,4,9);
    edges.emplace_back(3,5,9);
    edges.emplace_back(4,2,9);
    edges.emplace_back(4,3,9);
    edges.emplace_back(4,5,9);
    edges.emplace_back(4,6,9);
    edges.emplace_back(5,3,9);
    edges.emplace_back(5,4,9);
    edges.emplace_back(5,6,9);
    edges.emplace_back(5,7,9);
    edges.emplace_back(6,4,9);
    edges.emplace_back(6,5,9);
    edges.emplace_back(6,7,9);
    edges.emplace_back(7,5,9);
    edges.emplace_back(7,6,9);
    Graph<int> graph(vertices, edges);
  

    int option;
    int number;
    cout << "elija una opción: " << endl;
    cout << "1. BFS" << endl;
    cout << "2. DFS" << endl;
    cout << "3. Dijkstra" << endl;

    cin >> option;

    cout << "elija una opción para ver: ";

    cin >> number;
    
    if (option == 1){
        cout << "BFS: ";
        graph.bfs(number);
        cout << endl;
    } else if (option == 2){
        cout << "DFS: ";
        graph.dfs(number);
        cout << endl;
    } else if (option == 3){
        cout << "Dijkstra: ";
        graph.dijkstra(number);
        cout << endl;
    } else {
        cout << "opción incorrecta" << endl;
    }

    return 0;
}