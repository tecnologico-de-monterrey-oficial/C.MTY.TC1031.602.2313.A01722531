#ifndef Data_h
#define Data_h

struct Data{
    string CityA, CityB, timeTrain, disTrain, timeCar, disCar;
    Data();
    Data(string line);
    void print();
};

Data::Data(){

}

Data::Data(string line){
    // Utilizar un stringstream para separar los campos por comas
    stringstream ss(line);       
        
    // Leer cada campo y asignarlo a la estructura Record
    getline(ss, CityA, ',');
    getline(ss, CityB, ',');
    getline(ss, timeTrain, ',');
    getline(ss, disTrain, ',');
    getline(ss, timeCar, ',');
    getline(ss, disCar, ',');
}

void Data::print(){
    cout      << 
    CityA     << " " <<
    CityB     << " " <<
    timeTrain << " " <<
    disTrain  << " " <<
    timeCar   << " " <<
    disCar    << " " << endl;
}
#endif