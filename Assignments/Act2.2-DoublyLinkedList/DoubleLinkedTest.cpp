
// greta guagnelli
// a01722531
// ITD

// act 2.2 double linked list

#include <iostream>
#include <vector>
using namespace std;
#include "DoubleLinkedList.h"

void createListInt(DoubleLinkedList<int> &listInt, int quantity){
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    listInt.addLast(num);
  }
}

string PalabraAleatoria(int longitud) {
    string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string resultado;
    for (int i = 0; i < longitud; i++) {
        int indiceAleatorio = rand() % caracteres.length();
        resultado += caracteres[indiceAleatorio];
    }
    return resultado;
}

void createListString(DoubleLinkedList<string> &list,int quantity,int longitud){
    for (int i = 0; i < quantity; i++) {
        string nuevoString = PalabraAleatoria(longitud);
        list.addLast(nuevoString);
    }
}

void listInt(DoubleLinkedList<int> &listInt){
    int n = 0;
    cout << "Quisieras que la lista se genere de manera:" << endl;
    cout << "1. Aleatoria" << endl;
    cout << "2. Manual" << endl;
    cout << "Teclea la opcion: ";
    cin >> n; cout << endl;

    while (n != 1 && n != 2){
        cout <<"Opción inválida, vuelve a intentar"<< endl << endl;
        cout << "Quisieras que la lista se genere de manera:" << endl;
        cout << "1. Aleatoria" << endl;
        cout << "2. Manual" << endl;
        cin >> n; cout << endl;
    }
           
    if (n == 1) {
        int x = 0;
        cout << endl; 
        cout << "Teclea la cantidad de números: " << endl;
        cin >> x;
        createListInt(listInt,x);
       
    } else if (n == 2) {
        int x = 0, n = 0;
        cout << endl; 
        cout << "Teclea la cantidad de números: " << endl;
        cin >> x;             
        for (int i = 0; i<x ; i++){
           cout << "Teclea el elemento " << i << " : " ;
           cin >> n; 
           listInt.addLast(n);
        }
        
    throw out_of_range("error!");
}
}

void listString(DoubleLinkedList<string> &listString){
    int n = 0;
    cout << "Quisieras que la lista se genere de manera:" << endl;
    cout << "1. Aleatoria" << endl;
    cout << "2. Manual" << endl;
    cin >> n; cout << endl;

    while (n != 1 && n != 2){
        cout <<"opción no valida"<< endl << endl;
        cout << "Selecciona una opcion" << endl;
        cout << "1) Lista con datos aleatorios" << endl;
        cout << "2) Lista con datos capturados" << endl;
        cin >> n; cout << endl;
    }

    if (n == 1) {
        int x = 0,longString = 0;
        cout << endl; 
        cout << "Teclea la cantidad de palabras: " << endl;
        cin >> x;
        cout << "Ingresa el numero de caracteres en cada palabra: " << endl;
        cin >> longString;
        createListString(listString,x,longString);

    } else if (n == 2) {
        int x = 0;
        string n;
        cout <<  endl; 
        cout << "Teclea la cantidad de palabras: "; 
        cin >> x;               
        for (int i = 0; i<x ; i++){
           cout << "Ingresa la(s) palabra(s) " << i << " : ";
           cin >> n; 
           listString.addLast(n);
        }
       
    }
    throw out_of_range("error!");
}

template<class T>
void options(DoubleLinkedList<T>& list) {
    int option;
    do {
        cout << "------ Menú de Operaciones ------" << endl;
        cout << "1. Agrega un elemento al principio de la lista" << endl;
        cout << "2. Agrega un elemento al final de la lista" << endl;
        cout << "3. Insertar un elemento después del índice dado" << endl;
        cout << "4. Borrar un elemento dado de la lista" << endl;
        cout << "5. Borrar un elemento en una posición de la lista" << endl;
        cout << "6. Obtener el elemento de una posición dada de la lista" << endl;
        cout << "7. Actualizar un elemento dado de la lista" << endl;
        cout << "8. Actualizar un elemento que se encuentra en una posición dada de la lista" << endl;
        cout << "9. Encuentra un elemento dado en la lista" << endl;
        cout << "10. Duplicar lista" << endl;
        cout << "11. Ordenar lista" << endl; 
        cout << "12. Borrar duplicados" << endl;
        cout << "13. Vaciar lista" << endl;
        cout << "14. Imprimir lista" << endl;
        cout << "15. Salir" << endl;
        cout << "-------------------------------" << endl;
        cout << "Elija una opción: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1: { // addFirst
                T element;
                cout << "Ingresa el elemento a agregar: " << endl;
                cin >> element;
                list.addFirst(element);
                list.print();
                break;
            }
            
            case 2: { // addLast
                T element;
                cout << "Ingresa el elemento a agregar: " << endl;
                cin >> element;
                list.addLast(element);
                list.print();
                break;
            }

            case 3: { // insert
                T element;
                int index;
                cout << "Ingresa el elemento a insertar: ";
                cin >> element;
                cout << "Ingresa el indice: ";
                cin >> index;
                list.insert(index, element);
                list.print();
                break;
            }

            case 4: { // deleteData
                T element;
                cout << "Ingresa el elemento a borrar: " << endl;
                cin >> element;
                list.deleteData(element);
                list.print();
                break;
            }

            case 5: { // deleteAt
                int index;
                cout << "Ingresa el índice: " << endl;
                cin >> index;
                list.deleteAt(index);
                list.print();
                break;
            }

            case 6: { // getData
                int index;
                cout << "Ingresa el índice: " << endl;
                cin >> index;
                cout << list.getData(index) << endl;
                break;
            }

            case 7: { // updateData
                T element;
                T newElement;
                cout << "ingresa el elemento: " << endl;
                cin >> element;
                cout << "ingresa el elemento nuevo: " << endl;
                cin >> newElement;
                list.updateData(element, newElement);
                list.print();
                break;
            }

            case 8: { // updateAt
                T element;
                int index;
                cout << "ingresa el elemento: " << endl;
                cin >> index;
                cout << "ingresa el elemento nuevo: " << endl;
                cin >> element;
                list.updateAt(index, element);
                list.print();
                break;
            }

            case 9: { // findData
                T element;
                cout << "ingresa el elemento: " << endl;
                cin >> element;
                cout << "index: " << list.findData(element) << endl << endl;
                break;
            }

            case 10: { // duplicar
                list.duplicate();
                list.print();
                break;
            }
            case 11: { // sort
                list.Sort();
                list.print();
                break;
            }
            case 12: { // delete duplicates
                list.deleteDuplicates(list);
                list.print();
                break;
            }
            case 13: { // clear
                list.clear();
                cout << "Lista vaciada" << endl;
                break;
            }
            case 14: { // print
                list.print();
                break;
            }
            case 15: {
                break;
            }
            default:
            cout << "opción no válida, por favor vuelva a intentar";
            }

     } while (option != 15);

}

int main() {
    int optionList;
    int createList;

    cout << "Qué tipo de lista te gustaría crear? : " << endl;
    cout << "1. int (teclea el número)" << endl;
    cout << "2. string (teclea el número)" << endl;
    cin >> optionList;

    if (optionList == 1) {
        DoubleLinkedList<int> intList;
        listInt(intList);
        intList.print();
        options(intList);

    } else if (optionList == 2) {
        DoubleLinkedList<string> stringList;
        listString(stringList);
        stringList.print();
        options(stringList);
    } else {
        cout << "Opción inválida" << endl;
    }
    

    return 0;
    }

