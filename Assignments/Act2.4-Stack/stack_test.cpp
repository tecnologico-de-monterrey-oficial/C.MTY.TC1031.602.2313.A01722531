// greta guagnelli
// a01722531
// ITD

// act2.4 Stack

#include <iostream>
using namespace std;

#include "stack.h"

int main(){
    Stack<int> stack;
    int option;

    do {
        cout << "---------- Menú de operaciones ----------" << endl;
        cout << " 1. Pop" << endl;
        cout << " 2. Push" << endl;
        cout << " 3. Top" << endl;
        cout << " 4. Salir" << endl;
        cin >> option;

        switch (option) {
            case 1: {
                int element;
                cout << "Ingresa el elemento a borrar: ";
                cin >> element;
                stack.pop();
                stack.print();
                break;
            }
            case 2: {
                int element;
                cout << "Ingresa el elemento a agregar: ";
                cin >> element;
                stack.push(element);
                stack.print();
                break;
            }
            case 3: {
                cout << "El último elemento agregado es: " << stack.top() << endl;
                break;
            }
            case 4: {
                cout << endl;
                break;
            }
            default: {
                cout << "Opción inválida" << endl;
                break;
            }
        }
    }
    while (option != 4);
    return 0;
}