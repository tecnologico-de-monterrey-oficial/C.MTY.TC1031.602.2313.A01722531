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
    // Se termina el ciclo, no se encontró el valor
    // throw out_of_range('No se encontró el valor buscado')
    return -1;
}

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
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

    // vector<int> list = {5,12,23,27,32,34,38,40,45};
    // int n = 15;
    // int index = binarySearch(list,n);
    // if (index >= 0) {
    //     cout << "El valor " << n << " se encuentra en la posición " << index << endl;
    // } else {
    //     cout << "El valor " << n << " no se encuentra en la lista" << endl;
    // }

    vector<int>

return 0;

}

