#include <iostream>
#include "queue.h" // Asegúrate de incluir el archivo de encabezado de tu clase Queue
using namespace std;


int main() {
    Queue<int> myQueue;
    int option;
    int element;
    do {
        cout << "----- Menu de Opciones:------ " << endl;
        cout << "1. Eliminar elemento de la cola" << endl;
        cout << "2. Agregar elemento a la cola" << endl;
        cout << "3. Obtener el frente de la cola" << endl;
        cout << "4. Verificar si la cola está vacía" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> option;

    switch (option) {
            case 1:
                try {
                    myQueue.pop();
                    cout << "Elemento a agregar." << endl;
                } catch (const runtime_error& e) {
                    cerr << e.what() << endl;
                }
            case 2: {
                cout << "Elemento eliminado: ";
                cin >> element;
                myQueue.push(element);
                break;
            }
            case 3:
                try {
                    cout << "Frente de la cola: " << myQueue.front() << endl;
                } catch (const runtime_error& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 4:
                if (myQueue.isEmpty()) {
                    cout << "La cola está vacía." << endl;
                } else {
                    cout << "La cola no está vacía." << endl;
                }
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (option != 5);

    return 0;
}



















