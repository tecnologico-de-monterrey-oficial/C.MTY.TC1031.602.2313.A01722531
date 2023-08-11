#ifndef List_h
#define List_h

template <class T>
class List {
private :
    vector<T> list;
    int size;
public:
    List();
    void insert(T data);
    void removeLast();
    T getData(int index);
    int getSize();
    T getMax();
    void print();
};

// hacer constructor por default
template <class T>
List<T>::List(){
    // inicializando el tamaño de la lista en 0
    size = 0;
}

// hacer método de insert
template <class T>
void List<T>::insert(T data) {
    // insertar el dato al final de la lista
    list.push_back(data);
    // incrementar el tamaño de la lista
    size++;
}

// remueve el último elemento de la lista
template <class T>
void List<T>::removeLast(){
    // validamos que la lista no esté vacía
    if (size > 0) {
    // desplegamos el último elemento de la lista
    cout << "El elemento a eliminar es:" << list[size-1] << endl;
    // removemos el último elemento de la lista
    list.pop_back();
    // decrementamos el tamaño de la lista
    size--;
} else {
    throw out_of_range("No hay elementos");
}

}

// obtener el dato de un elemento de la lista
template <class T>
T List<T>::getData(int index){
    // validamos que exista el dato a obtener
    if (index >= 0 && index < size){
        // retornamos el dato
        return list[index];
    } else{
        // retornamos un dato nulo
        throw out_of_range("Posición inválida");
    }
}

// obtener el tamaño de la lista
template <class T>
int List<T>::getSize(){
    return size;
}

// obtener el dato máximo de la lista
template <class T>
T List<T>::getMax() {
    // Validamos que la lista no este vacia
    if (size > 0) {
        // Inicializamos el dato máximo con el primer elemento de la lista
        T max = list[0];
        // Recorremos la lista para encontrar el dato máximo
        for (int i=1; i<size; i++) {
            // Validamos si el dato actual es mayor al dato máximo
            if (list[i] > max) {
                // Actualizamos el dato máximo
                max = list[i];
            }
        }
        // Retornamos el dato máximo
        return max;
    } else {
        // Retornamos un dato nulo
        throw out_of_range("La lista está vacía");
    }
}
 


// hacer método de print
template <class T>
void List<T>::print(){
    // recorrer la lista para imprimir cada uno de sus elementos
    // tradicional
    for (int i=0; i<size; i++){
        // imprimimos el elemento
        cout << "[" << i << "] -" << list[i] << "" << endl;
    }
    // de manera especial en los vectores
    //for (auto el : list) {
        // imprimimos el elemento
        //cout << el << "";
    //}
    // saltamos renglón
    //cout << endl;
}

#endif