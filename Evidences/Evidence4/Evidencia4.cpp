#include <algorithm>
#include <fstream>
#include <iostream>
#include <climits>
#include <sstream>
#include <vector>

using namespace std;

#include "Data.h"
#include "Edge.h"
#include "Graph.h"

void readFile(string fileName, vector<Data> &DataCities) {
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "Error" << endl;
    return;
  }
  string line;
  bool firstLine = true;
  while (getline(file, line)) {
    if (firstLine) {
      firstLine = false;
      continue;
    }
    DataCities.push_back(Data(line));
  }
  file.close();
}

int Hash(string name) {
  int hashValue = 0;

  for (char ch : name) {
    char lowerChar = tolower(ch);

    if (isalpha(lowerChar)) {
      hashValue += static_cast<int>(lowerChar) - 'a' + 1;
    }
  }

  return hashValue % 200;
};

int findIndex(string &name, vector<string> &Cities) {
  int index = Hash(name);
  int auxIndex = index;


  int count = Cities.size() + 1;
  while (count > 0) {
    if (index >= Cities.size()) {
      index = 0;
    }
    if (Cities[index] == name) {
      return -1;
    }
    if (Cities[index] == "") {
      auxIndex = index;
    }
    index += 1;
    count--;
  }
  return auxIndex;
}

void getCities(vector<string> &Cities, vector<Data> &DataCities) {
  for (auto &value : DataCities) {
    string CityName = value.CityA;
    int index = findIndex(CityName, Cities);
    if (index != -1) {
      Cities[index] = CityName;
    }
  }
}

void printHash(vector<string> &Cities) {
  vector<int> colisions;
  for (int i = 0; i < Cities.size(); i++) {
    int index = Hash(Cities[i]);
    colisions.push_back(index);
    cout << "[" << i << "] " << Cities[i] << " - " << index << endl;
  }

  int totalCollisions = 0;
  for (int i = 0; i < colisions.size(); i++) {
    for (int j = i + 1; j < colisions.size(); j++) {
      if (colisions[i] == colisions[j] && colisions[j] != -1) {
        totalCollisions++;
        colisions[j] = -1;
      }
    }
  }

  cout << "Colisiones: " << totalCollisions << endl;
}

void getEdges(vector<Data> &DataCities, vector<Edge<string>> &edges) {

  string source, target, DisTrain, DisCar, TimeTrain, TimeCar;
  for (auto &value : DataCities) {
    source = value.CityA;
    target = value.CityB;
    DisTrain = value.disTrain;
    DisCar = value.disCar;
    TimeTrain = value.timeTrain;
    TimeCar = value.timeCar;
    edges.emplace_back(source, target, DisTrain, DisCar, TimeTrain, TimeCar);
  }
}

void menu(Graph<string> &graph) {
  int opcion;
  do {
    cout << "\n~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~" << endl;
    cout << "1. Desplegar ciudades ordenadas por alfabeto" << endl;
    cout << "2. Desplegar lista de adyacencias del grafo" << endl;
    cout << "3. Desplegar recorridos del grafo" << endl;
    cout << "4. Ruta más corta entre dos ciudades" << endl;
    cout << "5. Salir" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      graph.Sort("output603-1.txt");
      cout << "Respuesta guardada en output603-1.txt" << endl;
      break;
    case 2:
      graph.print("output603-2.txt");
      cout << "Respuesta guardada en output603-2.txt" << endl;
      break;
    case 3:
      {string vertex;
      cout << "Ciudad de salida: ";
      cin >> vertex;
      graph.bfs(vertex, "output603-3.txt");
      graph.dfs(vertex, "output603-4.txt");
      break;}
    case 4:
      {string cityA, cityB;
      cout << "Primera ciudad: ";
      cin >> cityA;
      if( graph.findVertex(cityA) == -1){
        cout << "Ciudad no encontrada" << endl;
        continue;
      }
      cout << "Segunda ciudad: ";
      cin >> cityB;
      if( graph.findVertex(cityB) == -1){
        cout << "Esta ciudad no existe en el registro" << endl;
        continue;
      }
      graph.dijkstraTrain(cityA, cityB);
      graph.dijkstraCar(cityA, cityB);
      break;}
    case 5:
      return;
      break;
    default:
      cout << "Opción no válida" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }
  } while (true);
}

int main() {
  string fileName = "EuropeCities.csv";
  vector<Data> DataCities;
  vector<string> Cities;
  Cities.resize(100);
  fill(Cities.begin(), Cities.end(), "");
  vector<Edge<string>> edges;
  readFile(fileName, DataCities);
  getCities(Cities, DataCities);
  getEdges(DataCities, edges);
  Graph<string> graph(Cities, edges);
  menu(graph);
  return 0;
}