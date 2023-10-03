// greta guagnelli
// a01722531
// ITD

// act2.3 Queue

#include <iostream>
using namespace std;
#include "queue.h"

int main() {
    Queue<int> queue;
    int option;
    do {

        cout << "-------- Menú de operaciones ---------" << endl;
        cout << "1. Borrar primer elemento agregado al Queue" << endl; 
        cout << "2. Agregar un elemento al Queue" << endl;
        cout << "3. Obtener el primer elemento del Queue" << endl;
        cout << "4. Salir" << endl;
        cout << "-------------------------------" << endl;
        cout << "Elija una opción: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1: {
            queue.pop();
            queue.print();
            cout << "El primer elemento ha sido borrado" << endl; 
            break;
        }
        case 2: {
            int element;
            cout << "Ingresa el elemento a agregar: " << endl;
            cin >> element;
            queue.push(element);
            queue.print();
            cout << "El elemento " << element << " ha sido agregado al Queue" << endl;
            break;
        }
        case 3: {
            cout << "El primer elemento del Queue es: " << queue.front() << endl;
            break;
        }
        case 4: {
            break;
        }
        default:
            cout << "Opción inválida" << endl;
            break;
        }

    }
    while (option != 4);
    return 0;
}