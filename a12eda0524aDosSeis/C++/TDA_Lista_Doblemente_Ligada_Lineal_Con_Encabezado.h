#ifndef TDA_LISTA_DOBLEMENTE_LIGADA_LINEAL_CON_ENCABEZADO_H_INCLUDED
#define TDA_LISTA_DOBLEMENTE_LIGADA_LINEAL_CON_ENCABEZADO_H_INCLUDED

#include <iostream>
using namespace std;

template<typename tipo_elemento>
class ListaDobleLigada {
    struct Nodo {
        tipo_elemento dato;
        Nodo* siguiente;
        Nodo* anterior;

        Nodo(tipo_elemento _dato) : dato(_dato), siguiente(nullptr), anterior(nullptr) {}
    };

    Nodo* cabeza;
    int cantidadElementos;

public:
    typedef Nodo* Posicion;

    ListaDobleLigada() : cabeza(nullptr), cantidadElementos(0) {}

    Posicion fin() {
        return cabeza != nullptr ? cabeza->anterior : nullptr;
    }

    Posicion primero() {
        return cabeza;
    }

    Posicion siguiente(Posicion p) {
        if (p != nullptr) {
            return p->siguiente;
        } else {
            return nullptr;
        }
    }

    Posicion anterior(Posicion p) {
        if (p != nullptr) {
            return p->anterior;
        } else {
            return nullptr;
        }
    }

    bool inserta(tipo_elemento elemento, Posicion p) {
        Nodo* nuevoNodo = new Nodo(elemento);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        } else if (p == cabeza->anterior) {
            nuevoNodo->siguiente = cabeza;
            nuevoNodo->anterior = cabeza->anterior;
            cabeza->anterior->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
        } else if (p == cabeza) {
            nuevoNodo->siguiente = cabeza;
            nuevoNodo->anterior = cabeza->anterior;
            cabeza->anterior->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            nuevoNodo->siguiente = p->siguiente;
            nuevoNodo->anterior = p;
            p->siguiente->anterior = nuevoNodo;
            p->siguiente = nuevoNodo;
        }

        cantidadElementos++;
        return true;
    }

    bool eliminar(Posicion p) {
        if (p == nullptr || cabeza == nullptr) {
            return false;
        }

        if (p == cabeza && cabeza->siguiente == cabeza) {
            delete p;
            cabeza = nullptr;
        } else {
            p->anterior->siguiente = p->siguiente;
            p->siguiente->anterior = p->anterior;
            if (p == cabeza) {
                cabeza = p->siguiente;
            }
            delete p;
        }

        cantidadElementos--;
        return true;
    }

    bool estaLlena() {
        return false;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    int dameCuentaElementos() {
        return cantidadElementos;
    }

    tipo_elemento recupera(Posicion p) {
        if (p != nullptr) {
            return p->dato;
        } else {
            tipo_elemento error{};
            return error;
        }
    }

    Posicion localiza(tipo_elemento x) {
        Nodo* nodoActual = cabeza;
        if (nodoActual != nullptr) {
            do {
                if (mismo(nodoActual->dato, x)) {
                    return nodoActual;
                }
                nodoActual = nodoActual->siguiente;
            } while (nodoActual != cabeza);
        }
        return nullptr;
    }

    bool mismo(tipo_elemento x, tipo_elemento y) {
        return x == y;
    }

    ~ListaDobleLigada() {
        while (cabeza != nullptr && cantidadElementos > 0) {
            eliminar(cabeza);
        }
    }
};



#endif // TDA_LISTA_DOBLEMENTE_LIGADA_LINEAL_CON_ENCABEZADO_H_INCLUDED
