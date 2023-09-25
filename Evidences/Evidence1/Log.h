// greta guagnelli
// a01722531
// ITD
// evidencia 1

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// definimos la estructura Log
struct Log {
    string mes;
    string dia;
    string anio;
    string hora;
    string ip;
    string mensaje;
    string output;
    long long key;

    // declaramos las funciones
    long long generateKey();

    // donstructor Log
    Log(string mes, string dia, string anio, string hora, string ip, string mensaje);
    
    // función para obtener una representación en cadena de Log
    string toString() const;
};

// meses a números:
map<string, string> mes_a_numero = {
    {"Jan", "01"},
    {"Feb", "02"},
    {"Mar", "03"},
    {"Apr", "04"},
    {"May", "05"},
    {"Jun", "06"},
    {"Jul", "07"},
    {"Aug", "08"},
    {"Sep", "09"},
    {"Oct", "10"},
    {"Nov", "11"},
    {"Dec", "12"}
};

Log::Log(string mes, string dia, string anio, string hora, string ip, string mensaje) {
    this->mes = mes;
    this->dia = dia;
    this->anio = anio;
    this->hora = hora;
    this->ip = ip;
    this->mensaje = mensaje;
    key = generateKey();
    output = mes + " " + dia + " " + anio + " " + hora + " " + ip + " " + mensaje;
}

// implementamos la función para generar la clave
long long Log::generateKey() {
    string hora1 = hora;
    string mes_N;

    // eliminamos los dos puntos de la hora
    hora1.erase(std::remove(hora1.begin(), hora1.end(), ':'), hora1.end());

    // buscamos el equivalente numérico del mes en el map
    auto it = mes_a_numero.find(mes);

    if (it != mes_a_numero.end()) {
        mes_N = it->second;
    } else {
        mes_N = "00";
    }

    // construimos la clave
    string keyString = anio + mes_N + dia + hora1;

    long long key = stoll(keyString);

    return key;
}

// implementamos la función para obtener una representación en cadena de Log
string Log::toString() const {
    return output;
};

