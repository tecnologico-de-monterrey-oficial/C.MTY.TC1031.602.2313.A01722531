// greta guagnelli
// a01722531
// act 1.3


#include <iostream>
#include <vector>

using namespace std;

//Escribe una función iterativa que dado un vector que contiene enteros positivos,
//regrese la suma de los enteros impares contenidos en el vector. 
int sumaImparesIterativa(const vector<int>& numeros) {
    int suma = 0;
    for (int i = 0; i < numeros.size(); ++i) {
        if (numeros[i] % 2 != 0) {
            suma += numeros[i];
        }
    }
    return suma;
}
//Escribe una función recursiva que dado un vector que contiene enteros positivos, 
//regrese la suma de los enteros impares contenidos en el vector.
int sumaImparesRecursiva(const vector<int>& numeros, int indice = 0) {
    if (indice >= numeros.size()) {
        return 0;
    }
return (numeros[indice] % 2 != 0) ? numeros[indice] + sumaImparesRecursiva(numeros, indice + 1) : sumaImparesRecursiva(numeros, indice + 1);
}

//Agrega a cada una de las funciones el orden en base a la notación sintónica de cada función.
int main() {
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    cout << "Suma de impares (iterativa): " << sumaImparesIterativa(numeros) << endl;
    cout << "Suma de impares (recursiva): " << sumaImparesRecursiva(numeros) << endl;
    
return 0;

}