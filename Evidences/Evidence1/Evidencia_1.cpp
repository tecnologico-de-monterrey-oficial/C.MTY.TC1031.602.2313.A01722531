// greta guagnelli
// a01722531
// ITD
// evidencia 1

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Log.h"

using namespace std;

template<class T>
void swapElements(vector<T> &list, int a, int b) {
    if (list[a] != list[b]) {
        T temp = list[a];
        list[a] = list[b];
        list[b] = temp;
    }
}

template <class T>
void insertionSort(vector<T> &list, vector<int> &indices) {
    for (int i = 1; i < list.size(); i++) {
        int j = i - 1;
        while (j >= 0) {
            if (list[j + 1] < list[j]) {
                swapElements(list, j, j + 1);
                swapElements(indices, j, j + 1);
            } else {
                j = -1; // break
            }
            j--;
        }
    }
}

int binarySearch(vector<long long> sortedKeys) {
    string inputAnio, inputMes, inputDia, inputHora;

    cout << "teclea el año: " << endl;
    cin >> inputAnio;
    cout << "teclea el mes: " << endl;
    cin >> inputMes;
    cout << "teclea el día: " << endl;
    cin >> inputDia;
    cout << "teclea la hora: " << endl;
    cin >> inputHora;

    string inputDataString = inputAnio + inputMes + inputDia + inputHora;
    long long inputData = stoll(inputDataString);

    int low = 0;
    int high = sortedKeys.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (inputData == sortedKeys[mid]) {
            return mid;
        } else {
            if (inputData < sortedKeys[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1; // valor no encontrado
}

int main() {
    ifstream inputFile("log602.txt");
    ofstream outputFile("output602.txt");
    string line;
    string word;
    // definimos variables
    string mes;
    string dia;
    string anio;
    string hora;
    string ip;
    string mensaje;
    vector<Log> logs;
    vector<long long> keys;
    int recordCount = 0;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        ss >> mes >> dia >> anio >> hora >> ip >> mensaje;
        Log log(mes, dia, anio, hora, ip, mensaje);
        log.key = log

    };