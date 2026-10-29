#include <iostream>
#include <string>
using namespace std;

template <class T>
class Elemento {
public:
    T valor;
    Elemento<T>* enlace;
    Elemento(T v) : valor(v), enlace(nullptr) {}
};

template <class T>
class ListaSimple {
public:
    ListaSimple() : primero(nullptr), cantidad(0) {}
    ~ListaSimple();
    void agregarAlInicio(T v);
    void agregarAlFinal(T v);
    bool quitarPorPosicion(int pos);
    T obtener(int pos) const;
    int tamanio() const;
    void mostrar() const;
private:
    Elemento<T>* primero;
    int cantidad;
};

template <class T>
ListaSimple<T>::~ListaSimple() {
    while (primero != nullptr) {
        Elemento<T>* sobra = primero;
        primero = primero->enlace;
        delete sobra;
    }
}

template <class T>
void ListaSimple<T>::agregarAlInicio(T v) {
    Elemento<T>* nuevo = new Elemento<T>(v);
    nuevo->enlace = primero;
    primero = nuevo;
    cantidad++;
}

template <class T>
void ListaSimple<T>::agregarAlFinal(T v) {
    Elemento<T>* nuevo = new Elemento<T>(v);
    if (primero == nullptr) {
        primero = nuevo;
    } else {
        Elemento<T>* aux = primero;
        while (aux->enlace != nullptr) aux = aux->enlace;
        aux->enlace = nuevo;
    }
    cantidad++;
}

template <class T>
bool ListaSimple<T>::quitarPorPosicion(int pos) {
    if (pos < 0 || pos >= cantidad) return false;
    Elemento<T>* borrar = primero;
    if (pos == 0) {
        primero = primero->enlace;
    } else {
        Elemento<T>* previo = primero;
        for (int i = 0; i < pos - 1; i++) previo = previo->enlace;
        borrar = previo->enlace;
        previo->enlace = borrar->enlace;
    }
    delete borrar;
    cantidad--;
    return true;
}

template <class T>
T ListaSimple<T>::obtener(int pos) const {
    if (pos < 0 || pos >= cantidad) return T();
    Elemento<T>* aux = primero;
    for (int i = 0; i < pos; i++) aux = aux->enlace;
    return aux->valor;
}

template <class T>
int ListaSimple<T>::tamanio() const {
    return cantidad;
}

template <class T>
void ListaSimple<T>::mostrar() const {
    for (Elemento<T>* aux = primero; aux != nullptr; aux = aux->enlace)
        cout << aux->valor << " -> ";
    cout << "NULL" << endl;
}

int main() {
    ListaSimple<int> edades;
    edades.agregarAlFinal(19);
    edades.agregarAlFinal(22);
    edades.agregarAlFinal(35);
    edades.agregarAlInicio(17);
    cout << "Edades: ";
    edades.mostrar();
    edades.quitarPorPosicion(2);
    cout << "Edades (sin posicion 2): ";
    edades.mostrar();
    cout << "Edad en posicion 1: " << edades.obtener(1) << endl;

    ListaSimple<string> palabras;
    palabras.agregarAlFinal("template");
    palabras.agregarAlFinal("lista");
    palabras.agregarAlFinal("enlazada");
    palabras.agregarAlInicio("Qt");
    cout << "Palabras: ";
    palabras.mostrar();
    cout << "Tamanio: " << palabras.tamanio() << endl;
    palabras.quitarPorPosicion(0);
    cout << "Palabras (sin posicion 0): ";
    palabras.mostrar();

    return 0;
}
