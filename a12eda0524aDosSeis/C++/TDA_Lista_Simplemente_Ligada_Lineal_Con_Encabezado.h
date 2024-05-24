#ifndef TDA_LISTA_SIMPLEMENTE_LIGADA_LINEAL_CON_ENCABEZADO_H_INCLUDED
#define TDA_LISTA_SIMPLEMENTE_LIGADA_LINEAL_CON_ENCABEZADO_H_INCLUDED

template<typename tipo_elemento>
class ListaLigada {
    struct Nodo {
        tipo_elemento dato;
        Nodo* siguiente;

        Nodo(tipo_elemento _dato) : dato(_dato), siguiente(nullptr) {}
    };



    Nodo* cabeza;
    int cantidadElementos;

public:
    typedef Nodo* Posicion;
    ListaLigada() : cabeza(nullptr), cantidadElementos(0) {}

    Posicion fin() {
        return nullptr;
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
        if (p == cabeza || p == nullptr) {
            return nullptr;
        }

        Nodo* nodoActual = cabeza;
        while (nodoActual->siguiente != nullptr && nodoActual->siguiente != p) {
            nodoActual = nodoActual->siguiente;
        }

        return nodoActual;
    }

    bool inserta(tipo_elemento elemento, Posicion p) {
        Nodo* nuevoNodo = new Nodo(elemento);
        if (p == nullptr) {
            if (cabeza == nullptr) {
                cabeza = nuevoNodo;
            } else {
                Nodo* nodoActual = cabeza;
                while (nodoActual->siguiente != nullptr) {
                    nodoActual = nodoActual->siguiente;
                }
                nodoActual->siguiente = nuevoNodo;
            }
        } else if (p == cabeza) {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        } else {
            nuevoNodo->siguiente = p->siguiente;
            p->siguiente = nuevoNodo;
        }
        cantidadElementos++;
        return true;
    }

    bool eliminar(Posicion p) {
        if (p == nullptr || cabeza == nullptr) {
            return false;
        }

        if (p == cabeza) {
            cabeza = cabeza->siguiente;
            delete p;
            cantidadElementos--;
            return true;
        } else {
            Nodo* nodoAnterior = anterior(p);
            if (nodoAnterior != nullptr) {
                nodoAnterior->siguiente = p->siguiente;
                delete p;
                cantidadElementos--;
                return true;
            } else {
                return false;
            }
        }
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
            tipo_elemento error = nullptr;
            return error;
        }
    }

    Posicion localiza(tipo_elemento x) {
        Nodo* nodoActual = cabeza;
        while (nodoActual != nullptr) {
            if (mismo(nodoActual->dato,x)) {
                return nodoActual;
            }
            nodoActual = nodoActual->siguiente;
        }
        return nullptr;
    }

    bool mismo(tipo_elemento x, tipo_elemento y) {
        return x == y;
    }

    ~ListaLigada() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif // TDA_LISTA_SIMPLEMENTE_LIGADA_LINEAL_CON_ENCABEZADO_H_INCLUDED
