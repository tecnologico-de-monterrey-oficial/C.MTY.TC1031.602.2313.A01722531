#pragma once
#include <unordered_map>
#include <iostream> 
#include <string>
#include <algorithm>
#include <vector>
#include "Node.h"

struct Log {
    string anio;
    string mes;
    string dia;
    string hora;
    string ip;
    string mensaje;
    long long key, rangeKey;
    Log();
    Log(string anio, string mes, string dia, string hora, string ip, string mensaje);
    int getanio();
    string getmes();
    bool operator<(Log &log);
    bool operator>(Log &log);
    bool operator==(Log &log);
    friend ostream& operator<<(ostream& os, Log &log); 
    long long keyGenerator();
    long long keyGeneratorIP();

};

Log::Log()
    : anio(""),
      mes(""),
      dia(""),
      hora(""),
      ip(""),
      mensaje("")
{
}


Log::Log(string anio, string mes, string dia, string hora, string ip, string mensaje) {
    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->ip = ip;
    this->mensaje = mensaje;
    key = keyGenerator();
}

bool Log::operator<(Log &log) {
    return this->key < log.key;
}

bool Log::operator>(Log &log) {
    return this->key > log.key;
}

bool Log::operator==(Log &log) {
    return this->key == log.key;
}

ostream& operator<<(ostream& os, Log &log) {
    os <<  log.mes << " " << log.dia << " " << log.anio << " " << log.hora << " " << log.ip << " " << log.mensaje;
    return os;
}

string Log::getmes()
{
    return this->mes;
}

int Log::getanio()
{
    int anios = stoi(this->anio);
    return anios;
}

long long Log::keyGenerator()
{
    unordered_map<string, string> map = {  
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

    string nummes = map[mes];
    string k;
    k = anio + nummes + dia + hora[0] + hora[1] + hora[3] + hora[4] + hora[6] + hora[7];
    return stoll(k);
}

