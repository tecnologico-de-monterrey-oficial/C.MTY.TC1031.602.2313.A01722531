#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// obtener tiempo inicial para calcular tiempo transcurrido por un algoritmo:
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time:
  begin = chrono::high_resolution_clock::now();
  
}

// Imprimir tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función:
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Crea  lista aleatoria:
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.push_back(num);
  }
}

int main() {

    // generar números aleatorios:
    srand(time(0));

    // Variables para calcular tiempo de ejecución de una función:
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Crear  lista de 1000000 de enteros:
    vector<int> list;
    startTime(begin);
    createListInt(list, 1000000);
    getTime(begin, end);

    return 0;

}