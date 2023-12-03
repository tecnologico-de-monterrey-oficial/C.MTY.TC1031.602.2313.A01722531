#pragma once
#include <iomanip>

template <class T> struct Edge {
  T source;
  T target;
  string DisTrain;
  string DisCar;
  string TimeTrain;
  string TimeCar;
  Edge();
  Edge(T source, T target);
  Edge(T source, T target, string DisTrain, string DisCar, string TimeTrain, string TimeCar);

  int ConvertToMinutes(string time);
  string ConvertToTimeString(int totalMinutes);
  string ConvertTime(string time1, string time2);
};

template <class T> Edge<T>::Edge() {
  DisTrain = "0";
  DisCar = "0";
  TimeTrain = "0";
  TimeCar = "0";
}

template <class T> Edge<T>::Edge(T source, T target) {
  this->source = source;
  this->target = target;
  this->DisTrain = "0";
  this->DisCar = "0";
  this->TimeTrain = "0";
  this->TimeCar = "0";
}

template <class T>
Edge<T>::Edge(T source, T target, string DisTrain, string DisCar,
              string TimeTrain, string TimeCar) {
  this->source = source;
  this->target = target;
  this->DisTrain = DisTrain;
  this->DisCar = DisCar;
  this->TimeTrain = TimeTrain;
  this->TimeCar = TimeCar;
}

template <class T>
int Edge<T>::ConvertToMinutes(string time) {
    int hours, minutes;
    char colon;

    istringstream iss(time);
    iss >> hours >> colon >> minutes;

    return hours * 60 + minutes;
}

template <class T>
string Edge<T>::ConvertToTimeString(int totalMinutes) {
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    ostringstream oss;
    oss << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes;

    return oss.str();
}

template <class T>
string Edge<T>::ConvertTime(string time1, string time2) {
    int totalMinutes1 = ConvertToMinutes(time1);
    int totalMinutes2 = ConvertToMinutes(time2);

    int sumTotalMinutes = totalMinutes1 + totalMinutes2;

    return ConvertToTimeString(sumTotalMinutes);
}

