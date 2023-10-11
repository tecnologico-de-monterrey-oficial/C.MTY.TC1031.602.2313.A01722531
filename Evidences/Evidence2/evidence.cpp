#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;
#include "Log.h"
#include "DoubleLinkedList.h"

string getFormattedIP(const string& ip) {
    stringstream ss(ip);
    int octet1, octet2, octet3, octet4;
    char dot;

    ss >> octet1 >> dot >> octet2 >> dot >> octet3 >> dot >> octet4;

    if (ss.fail() || dot != '.') {
        cerr << "formato de ip invalido: " << ip << endl;
        return ip; // Return the original IP if it's not in the expected format
    }

    stringstream formattedIP;
    formattedIP << setw(3) << setfill('0') << octet1 << "."
                << setw(3) << setfill('0') << octet2 << "."
                << setw(3) << setfill('0') << octet3 << "."
                << setw(3) << setfill('0') << octet4;

    return formattedIP.str();
}

vector<string> getIPRange(string startIP, string endIP) {
    vector<string> ipRange;
    int startOctet1, startOctet2, startOctet3, startOctet4;
    int endOctet1, endOctet2, endOctet3, endOctet4;
    sscanf(startIP.c_str(), "%d.%d.%d.%d", &startOctet1, &startOctet2, &startOctet3, &startOctet4);
    sscanf(endIP.c_str(), "%d.%d.%d.%d", &endOctet1, &endOctet2, &endOctet3, &endOctet4);
    for (int i = startOctet1; i <= endOctet1; i++) {
        for (int j = startOctet2; j <= endOctet2; j++) {
            for (int k = startOctet3; k <= endOctet3; k++) {
                for (int l = startOctet4; l <= endOctet4; l++) {
                    stringstream ss;
                    ss << setw(3) << setfill('0') << i << "." << setw(3) << setfill('0') << j << "." << setw(3) << setfill('0') << k << "." << setw(3) << setfill('0') << l;
                    string ip = ss.str();
                    ipRange.push_back(ip);
                }
            }
        }
    }
    return ipRange;
}

vector<Log> getLogsInRange(string startIP, string endIP, DoubleLinkedList<Log>& logs) {
    vector<string> ipRange = getIPRange(startIP, endIP);
    vector<Log> logsInRange;
    for (int i = 0; i < ipRange.size(); i++) {
        Log log = logs.findData(ipRange[i]);
        if (log.ip != "") {
            logsInRange.push_back(log);
        }
    }
    return logsInRange;
}

int main() {
    DoubleLinkedList<Log> logs;
    bool sorted = false;
    ifstream fileIn("log602-2.txt");
    ofstream fileOut1("output602-1.out");
    ofstream fileOut2("output602-2.out");
    ofstream fileOut3("iprange602-a.out");
    ofstream fileOut4("iprange602-d.out");
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
        log.ip = getFormattedIP(log.ip);
        logs.addLast(log);
        cont++;
    }

    int option;
    while (option != 5) {
        cout << endl << " --------- menu de operaciones ---------" << endl;
        cout << "que deseas hacer? teclea el numero \n" << endl;
        cout << "1) Ordenar datos por fecha y hora" << endl;
        cout << "2) Ordenar datos por IP address" << endl;
        cout << "3) Busqueda por rango de ips" << endl;
        cout << "4) Sumatoria de datos" << endl;
        cout << "5) Salir" << endl;
        cout << "-----------------------------------------" << endl;
        cout <<  endl;
        cin >> option;
        string startIP, endIP;
        
        if (option == 1) {

            logs.sortDate();

            for (int i = 0; i < logs.getSize(); i++) {
                fileOut1 << logs[i].anio << "-" << logs[i].mes << "-" << logs[i].dia << " " << logs[i].hora << " " << logs[i].ip << " " << logs[i].mensaje << endl;
            }

            fileOut1.close();
            cout << "Listo! Tus datos estan ordenados en el archivo 'output602-1' " << endl;
            
        } else if (option == 2) {
            logs.sortIP();

            for (int i = 0; i < logs.getSize(); i++) {
                fileOut2 << logs[i].anio << "-" << logs[i].mes << "-" << logs[i].dia << " " << logs[i].hora << " " << logs[i].ip << " " << logs[i].mensaje << endl;
            }

            fileOut2.close();
            cout << "Listo! Tus datos estan ordenados en el archivo 'output602-2'" << endl;

        } else if (option == 3) {
            
            logs.sortIP();

            cout << "teclea la ip address del rango inicial: ";
            cout << endl;
            cin >> startIP;
            cout << "teclea la ip address del rango final: ";
            cout << endl;
            cin >> endIP;

            vector<Log> logsInRange = getLogsInRange(startIP, endIP, logs);

            for (int i = 0; i < logsInRange.size(); i++) {
                fileOut3 << logsInRange[i].anio << "-" << logsInRange[i].mes << "-" << logsInRange[i].dia << " " << logsInRange[i].hora << " " << logsInRange[i].ip << " " << logsInRange[i].mensaje << endl;
            }

            cout << "Listo! Tus datos estan ordenados en el archivo 'iprange602-a'" << endl;

            for (int i = logsInRange.size() - 1; i >= 0; i--) {
                fileOut4 << logsInRange[i].anio << "-" << logsInRange[i].mes << "-" << logsInRange[i].dia << " " << logsInRange[i].hora << " " << logsInRange[i].ip << " " << logsInRange[i].mensaje << endl;
            }

            cout << "Listo! Tus datos estan ordenados en el archivo 'iprange602-d'" << endl;



        } else if (option == 4) {
            // Despliega en pantalla la cantidad de ips en el archivo por cada año y mes
            int anio2022 = 0;
            int anio2023 = 0;
            int january = 0;
            int february = 0;
            int march = 0;
            int april = 0;
            int may = 0;
            int june = 0;
            int july = 0;
            int august = 0;
            int september = 0;
            int october = 0;
            int november = 0;
            int december = 0;

            for (int i = 0; i < logs.getSize(); i++) {
                if (logs[i].anio == "2022") {
                    anio2022++;
                } else if (logs[i].anio == "2023") {
                    anio2023++;
                }

                if (logs[i].mes == "Jan") {
                    january++;
                } else if (logs[i].mes == "Feb") {
                    february++;
                } else if (logs[i].mes == "Mar") {
                    march++;
                } else if (logs[i].mes == "Apr") {
                    april++;
                } else if (logs[i].mes == "May") {
                    may++;
                } else if (logs[i].mes == "Jun") {
                    june++;
                } else if (logs[i].mes == "Jul") {
                    july++;
                } else if (logs[i].mes == "Aug") {
                    august++;
                } else if (logs[i].mes == "Sep") {
                    september++;
                } else if (logs[i].mes == "Oct") {
                    october++;
                } else if (logs[i].mes == "Nov") {
                    november++;
                } else if (logs[i].mes == "Dec") {
                    december++;
                }
            }

            cout << "ip address por año:" << endl;
            cout << "2022: " << anio2022 << endl;
            cout << "2023: " << anio2023 << endl;

            cout << "ip address por mes:" << endl;
            cout << "Jan: " << january << endl;
            cout << "Feb: " << february << endl;
            cout << "Mar: " << march << endl;
            cout << "Apr: " << april << endl;
            cout << "May: " << may << endl;
            cout << "Jun: " << june << endl;
            cout << "Jul: " << july << endl;
            cout << "Aug: " << august << endl;
            cout << "Sep: " << september << endl;
            cout << "Oct: " << october << endl;
            cout << "Nov: " << november << endl;
            cout << "Dec: " << december << endl;

        } else if (option == 5) {
            cout << endl;
        } else {
            cout << "por favor intenta de nuevo :( " << endl;
        }
    }

    return 0;
}