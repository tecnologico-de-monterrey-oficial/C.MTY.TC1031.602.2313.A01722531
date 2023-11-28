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
    graph.print();
    cout << "agregar vertex 8" << endl;
    graph.addVertex(8);
    graph.print();
    cout << "agregar edge 8-0" << endl;
    graph.addEdge(Edge<int>(8,0,5));
    graph.print();
    cout << "borrar vertex 3" << endl;
    graph.removeVertex(3);
    graph.print();
    cout << "borrar edge 0-2" << endl;
    graph.removeEdge(Edge<int>(0,2,9));
    graph.print();
    cout << "BFS: ";
    graph.bfs(5);
    cout << endl;
    cout << "DFS: ";
    graph.dfs(5);
    cout << endl;
    cout << "Dijkstra: ";
    graph.dijkstra(5);
    cout << endl;
    return 0;
}