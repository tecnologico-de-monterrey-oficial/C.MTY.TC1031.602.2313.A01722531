#pragma once
#include <iostream>
using namespace std;


struct Log {
    string mes;
    string anio;
    string hora;
    string dia;
    string ip;
    string message;
    string key;
    bool operator<(Log log);
    string keyGenerator();
    Log(string anio, string mes, string dia, string hora, string ip, string message);
    friend ostream& operator<<(ostream& os, Log log); 
};

Log::Log(string anio, string mes, string dia, string hora, string ip, string message) {
    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->ip = ip;
    this->message = message;
    key = keyGenerator();
}

string Log::keyGenerator() {
    string mm;
    if (mes == "Jan") {
        mm = "01";
    } else if (mes == "Feb") {
        mm = "02";
    } else if (mes == "Mar") {
        mm = "03";
    } else if (mes == "Apr") {
        mm = "04";
    } else if (mes == "May") {
        mm = "05";
    } else if (mes == "Jun") {
        mm = "06";
    } else if (mes == "Jul") {
        mm = "07";
    } else if (mes == "Aug") {
        mm = "08";
    } else if (mes == "Sep") {
        mm = "09";
    } else if (mes == "Oct") {
        mm = "10";
    } else if (mes == "Nov") {
        mm = "11";
    } else if (mes == "Dec") {
        mm = "12";
    }
    return anio + mm + dia + hora;
}

bool Log::operator<(Log log) {
    return key < log.key;
}

ostream& operator<<(ostream& os, Log log) {
    os << log.mes << " " << log.dia << " " << log.anio << " " << log.hora << " " << log.ip << " " << log.message;
    return os;
}