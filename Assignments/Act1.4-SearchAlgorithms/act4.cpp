// greta guagnelli
// a01722531
// act 1.4

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int sequentialSearch(vector<int> list, int data) {
    // Iteramos la lista para comparar el valor buscado con cada elemento de la lista
}

// Búsqueda binaria
int binarySearch(vector<int> list, int data) {
    // Inicializamos low y high
    int low = 0;
    int high = list.size()-1;
    // Hacemos un ciclo mientras left <= right
    while (low <= high) {
        // Calculamos el valor de en medio
        int mid = low + (high - low) / 2;
        // Comparamos el valor buscado con el valor de la lista en el indice mid
        if (data == list[mid]) {
            // Ya lo encontramos
            return mid;
        } else {
            // No son iguales
            // Revisamos si es menor
            if (data < list[mid]) {
                // si es menor
                high = mid - 1;
            } else {
                // es mayor
                low = mid + 1;
            }
        }
    }
    // se termina el ciclo no se encontró el valor
    return -1;
}

// obtener  tiempo inicial para calcular tiempo transcurrido por un algoritmo:
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = chrono::high_resolution_clock::now();
  
}

// imprimir tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función:
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.push_back(num);
  }
}

int main() {

    // Semilla para generar números aleatorios
    srand(time(0));

    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;



    vector<int>

    return 0;

}