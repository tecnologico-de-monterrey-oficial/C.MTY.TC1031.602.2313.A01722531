#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "log.h"
#include "heap.h"
#include "minHeap.h"
#include "BST.h"
#include <unordered_map>
#include <map>
using namespace std;

template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "asc") {
        heap<T> heap(list);
        for (int i=0; i<list.size(); i++) {
            list[i] = heap.pop();
        }
    } else {
        minHeap<T> heap(list);
        for (int i=0; i<list.size(); i++) {
            list[i] = heap.pop();
        }
    }
}

string padIP(string ip) {
    string paddedIP = "";
    int lastDotIndex = ip.find_last_of(".");
    string lastNumber = ip.substr(lastDotIndex + 1);
    if (lastNumber.length() == 1) {
        paddedIP = ip.substr(0, lastDotIndex + 1) + "00" + lastNumber;
    } else if (lastNumber.length() == 2) {
        paddedIP = ip.substr(0, lastDotIndex + 1) + "0" + lastNumber;
    } else {
        paddedIP = ip;
    }
    return paddedIP;
}

int main() {

    ifstream fileIn("log602-3.txt");
    ofstream fileOut("output602-1-ip.out");
    ofstream fileOut2("output602-1-fecha.out");
    ofstream fileOut3("output602-2-ip.out");
    ofstream fileOut4("output602-2-fecha.out");
    string line;
    string word;
    string anio;
    string mes;
    string dia;
    string hora;
    string ip;
    string message;
    vector<Log> logs;
    unordered_map<string, int> map;
    int cont = 0;

    while (getline(fileIn,line)) { 
        stringstream ss(line);
        ss >> mes >> dia >> anio >> hora >> ip >> message;
        while (ss >> word) {
            message = message + " " + word;
        }
        Log log(anio, mes, dia, hora, padIP(ip), message);
        logs.push_back(log);
        cont++;
    }

    vector<string> ips;
    for (int i = 0; i < logs.size(); i++) {
        ips.push_back(logs[i].ip);
    }
    
    vector<string> keys;
    for (int i = 0; i < logs.size(); i++) {
        keys.push_back(logs[i].key);
    }


    int option = 0;
    int option1 = 0;
    while (option != 5) {
        cout << endl;
        cout << "----------- menu de operaciones -----------" << endl;
        cout << "que deseas hacer? (teclea el numero)" << endl;
        cout << "1) ordenar datos: mayor a menor" << endl;
        cout << "2) ordenar datos: menor a mayor" << endl;
        cout << "3) imprimir las 10 ips con mayor numero de registros" << endl;
        cout << "4) buscar un ip" << endl;
        cout << "5) salir" << endl;
        cout << endl;
        cin >> option;

        if (option == 1) {
            cout << "1) ordenar datos por ip" << endl;
            cout << "2) ordenar datos por fecha" << endl;
            cout << endl;
            cin >> option1;
            if (option1 == 1) {
                heapSort(ips, "asc");
                vector<Log> logsByIpAsc;
                for (int i = 0; i < ips.size(); i++) {
                    for (int j = 0; j < logs.size(); j++) {
                        if (ips[i] == logs[j].ip) {
                            logsByIpAsc.push_back(logs[j]);
                        }
                    }
                }

                for (int i = 0; i < logsByIpAsc.size(); i++) {
                    fileOut << logsByIpAsc[i] << endl;
                }
                
                cout << "Listo! tu archivo ordenado se encuentra en output602-1-ip" << endl;

            } else if (option1 == 2) {
                heapSort(keys, "asc");
                vector<Log> logsByKeyAsc;
                for (int i = 0; i < keys.size(); i++) {
                    for (int j = 0; j < logs.size(); j++) {
                        if (keys[i] == logs[j].key) {
                            logsByKeyAsc.push_back(logs[j]);
                        }
                    }
                }

                for (int i = 0; i < logsByKeyAsc.size(); i++) {
                    fileOut2 << logsByKeyAsc[i] << endl;
                }

                cout << "Listo! tu archivo ordenado se encuentra en output602-1-fecha" << endl;

            } else {
                cout << "opcion incorrecta :( vuelve a intentarlo" << endl;
            }
        } else if (option == 2) {
            cout << "1) ordenar datos por ip" << endl;
            cout << "2) ordenar datos por fecha" << endl;
            cout << endl;
            cin >> option1;
            if (option1 == 1) {
                heapSort(ips, "desc");
                vector<Log> logsByIpDesc;
                for (int i = 0; i < ips.size(); i++) {
                    for (int j = 0; j < logs.size(); j++) {
                        if (ips[i] == logs[j].ip) {
                            logsByIpDesc.push_back(logs[j]);
                        }
                    }
                }

                for (int i = 0; i < logsByIpDesc.size(); i++) {
                    fileOut3 << logsByIpDesc[i] << endl;
                }
                
                cout << "Listo! tu archivo ordenado se encuentra en output602-2-ip" << endl;

            } else if (option1 == 2) {
                heapSort(keys, "desc");
                vector<Log> logsByKeyDesc;
                for (int i = 0; i < keys.size(); i++) {
                    for (int j = 0; j < logs.size(); j++) {
                        if (keys[i] == logs[j].key) {
                            logsByKeyDesc.push_back(logs[j]);
                        }
                    }
                }

                for (int i = 0; i < logsByKeyDesc.size(); i++) {
                    fileOut4 << logsByKeyDesc[i] << endl;
                }

                cout << "Listo! tu archivo ordenado se encuentra en output602-2-fecha" << endl;

            } else {
                cout << "opcion incorrecta :( vuelve a intentarlo" << endl;
            }
        } else if (option == 3) {
            for (int i = 0; i < logs.size(); i++) {
                map[logs[i].ip]++;
            }

            for (int i = 0; i < 10; i++) {
            int max = 0;
            string maxIp = "";
            for (auto el : map) {
                if (el.second > max) {
                    max = el.second;
                    maxIp = el.first;
                }
            }
            cout << maxIp << " = " << max << endl;
            map.erase(maxIp);
        }
        } else if (option == 4) {
            BST<string> bst;
            for (int i = 0; i < logs.size(); i++) {
                bst.insert(logs[i].ip);
            }
            string findIP;
            cout << "teclea una direccion de ip ";
            cin >> findIP;
            if (bst.find(findIP)) {
                cout << "la ip " << findIP << " aparece " << bst.count(findIP) << " veces" << endl;
            } else {
                cout << "la IP " << findIP << " no aparece" << endl;
            }
        } else {
            cout << endl;
        }
    

    }
}