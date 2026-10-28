
#include <iostream>
using namespace std;

template <typename T>
class Arbol {
private:
    struct Nodo {
        T dato;
        Nodo* izquierdo;
        Nodo* derecho;

        Nodo(T valor) : dato(valor),
            izquierdo(nullptr), derecho(nullptr) {}
    };

    Nodo* raiz = nullptr;

    void insertar(Nodo*& nodo, T valor) {
        if (nodo == nullptr) {
            nodo = new Nodo(valor);
        }
        else if (valor < nodo->dato) {
            insertar(nodo->izquierdo, valor);
        }
        else if (valor > nodo->dato) {
            insertar(nodo->derecho, valor);
        }
    }

    void inOrden(Nodo* nodo) const {
        if (nodo == nullptr) return;

        inOrden(nodo->izquierdo);
        cout << nodo->dato << " ";
        inOrden(nodo->derecho);
    }

    void liberar(Nodo* nodo) {
        if (nodo == nullptr) return;

        liberar(nodo->izquierdo);
        liberar(nodo->derecho);
        delete nodo;
    }

public:
    ~Arbol() {
        liberar(raiz);
    }

    void insertar(T valor) {
        insertar(raiz, valor);
    }

    void mostrar() const {
        inOrden(raiz);
        cout << endl;
    }
};

int main() {
    Arbol<int> enteros;
    enteros.insertar(50);
    enteros.insertar(30);
    enteros.insertar(70);
    enteros.insertar(20);
    enteros.insertar(40);

    cout << "Enteros: ";
    enteros.mostrar();

    Arbol<float> flotantes;
    flotantes.insertar(5.5f);
    flotantes.insertar(2.3f);
    flotantes.insertar(8.7f);

    cout << "Flotantes: ";
    flotantes.mostrar();

    Arbol<double> dobles;
    dobles.insertar(10.25);
    dobles.insertar(4.75);
    dobles.insertar(15.50);

    cout << "Doubles: ";
    dobles.mostrar();

    Arbol<char> caracteres;
    caracteres.insertar('M');
    caracteres.insertar('A');
    caracteres.insertar('Z');
    caracteres.insertar('F');

    cout << "Caracteres: ";
    caracteres.mostrar();

    return 0;
}
