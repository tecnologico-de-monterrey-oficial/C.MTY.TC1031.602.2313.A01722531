#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "Log.h"
#include "DoubleLinkedList.h"

void swapLogs(DoubleLinkedList<Log> &logs, int a, int b) {
    if (logs[a].key1Generator() != logs[b].key1Generator()) {
        Log aux = logs[a];
        logs[a] = logs[b];
        logs[b] = aux;
    }
}

int getPivot(DoubleLinkedList<Log> &logs, Log left, Log right) {
   
    Log pivot = right;
    int auxIndex = logs.findData(left) - 1;

    for (int index=logs.findData(left); index<logs.findData(right); index++) {

        if (logs.getData(index).key1Generator() < pivot.key1Generator()) {
            auxIndex++;
            swapLogs(logs, index, auxIndex);
        }
    }
  
    auxIndex++;
    swapLogs(logs, logs.findData(pivot), auxIndex);
    return auxIndex;
}

void quickSort(DoubleLinkedList<Log> &logs, Log left, Log right) {

        if (left < right) {
            
            int pivot = getPivot(logs, left, right);
            
            quickSort(logs, left, logs.getData(pivot-1));
           
            quickSort(logs, logs.getData(pivot+1), right);
        }
    }

string getFormattedIP(const string& ip) {
    stringstream ss(ip);
    int octet1, octet2, octet3, octet4;
    char dot;

    ss >> octet1 >> dot >> octet2 >> dot >> octet3 >> dot >> octet4;

    if (ss.fail() || dot != '.') {
        cerr << "formato invalido: " << ip << endl;
        return ip; 
    }

    stringstream formattedIP;
    formattedIP << setw(3) << setfill('0') << octet1 << "."
                << setw(3) << setfill('0') << octet2 << "."
                << setw(3) << setfill('0') << octet3 << "."
                << setw(3) << setfill('0') << octet4;

    return formattedIP.str();
}

bool compareByIP(const Log& log1, const Log& log2) {
    return getFormattedIP(log1.ip) < getFormattedIP(log2.ip);
}

int main() {
    DoubleLinkedList<Log> logs;
    bool sorted = false;
    ifstream fileIn("log602.txt");
    ofstream fileOut("output602.out");
    string linea;
    string palabra;
    string anio;
    string mes;
    string dia;
    string hora;
    string ip;
    string mensaje;
    int cont = 0;

    while (getline(fileIn,linea)) { 
        stringstream ss(linea);
        ss >> mes >> dia >> anio >> hora >> ip >> mensaje;
        while (ss >> palabra) {
            mensaje = mensaje + " " + palabra;
        }
        Log log(anio, mes, dia, hora, ip, mensaje);
        logs.addLast(log);
        cont++;
    }

    logs.print("asc");
        

}