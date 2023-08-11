#include <iostream>
#include <vector>
using namespace std;

#include "List.h"
int main()
{

    List<int> list;

    // insertar datos
    list.insert(5);
    list.insert(10);

    // print lista
    list.print();
    
    // eliminar el último elemento de la lista
    try {
        list.removeLast();
        list.removeLast();
        list.removeLast();
        list.removeLast();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    // print lista
    list.print();
    // obtenemos el valor de la posición 0

    // insertar datos
    list.insert(5);
    list.insert(10);
    try {
        cout << "el valor de la posición 0 es: " << list.getData(0) << endl;
        cout << "el valor de la posición 1 es: " << list.getData(1) << endl;
        cout << "el valor de la posición 2 es: " << list.getData(2) << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }




    return 0;
}