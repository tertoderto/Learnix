#ifndef BLOG_H
#define BLOG_H

#include "TDA_Lista_Arreglos.h"
#include "BlogDAO.h"
#include <fstream>
#include "Nota.h"
#define CANTIDAD_INICIAL 3
#define ARCHIVO_NOTA "Nota.dat"
class Blog {
public:
    Blog() {
        lista = new Lista<Nota*>(CANTIDAD_INICIAL);
        NotaModificada = new bool[CANTIDAD_INICIAL];
    }
    virtual ~Blog() {
        Posicion p = lista->primero();
            while (!lista->estaVacia()){
                delete lista->recupera(p);
                lista->eliminar(p);
            }
        }

    void agregarNota( char* titulo, char* cuerpo) {
        Nota* temporal = new Nota(cuerpo, titulo);
        lista->inserta(temporal, lista->fin());
        dao.agregar(temporal);

    }

    Nota* mostrar(int posicion) {
        if (posicion >= 0 && posicion < lista->dameCuentaElementos()) {
            Posicion p = lista->primero();
            for (int i = 0; i <= posicion; i++) {
                if (i == posicion) {
                    return lista->recupera(p);
                }
                p = lista->siguiente(p);
            }
        }
        return nullptr;
    }


    void suprimir(int posicion) {
        if (posicion >= 0 && posicion < lista->dameCuentaElementos()) {
            Posicion p = lista->primero();
            for (int i = 0; i < posicion; i++) {
                p = lista->siguiente(p);
            }
            delete lista->recupera(p);
            lista->eliminar(p);
        }
    }


    bool existeNota(int index){
        if(mostrar(index)==nullptr){
            return false;
        }else return true;
    }


    bool modificarCuerpo(int posicion, const char* cuerpo) {
        if (posicion >= 0 && posicion < lista->dameCuentaElementos()) {
            Posicion p = lista->primero();
            for (int i = 0; i < posicion; ++i) {
                p = lista->siguiente(p);
            }
            return lista->recupera(p)->fijaCuerpo(cuerpo);
        } else {
            return false;
        }
    }

    bool modificarTitulo(int posicion, const char* titulo) {
        if (posicion >= 0 && posicion < lista->dameCuentaElementos()) {
            Posicion p = lista->primero();
            for (int i = 0; i < posicion; ++i) {
                p = lista->siguiente(p);
            }
            return lista->recupera(p)->fijaTitulo(titulo);
        } else {
            return false;
        }
    }

    void modificarTodo(int posicion, const char* titulo, const char* cuerpo) {
        if (posicion >= 0 && posicion < lista->dameCuentaElementos()) {
            Posicion p = lista->primero();
            for (int i = 0; i < posicion; ++i) {
                p = lista->siguiente(p);
            }
            lista->recupera(p)->fijaTitulo(titulo);
            lista->recupera(p)->fijaCuerpo(cuerpo);
        }
    }

    bool estaVacio(){
        return lista->estaVacia();
    }
    int longitud(){
        return lista->dameCuentaElementos();
    }
    void inicializadorNota(){
        leerTodaNota();
        for(int i =0;i<C_3;i++){
            NotaModificada[i]=false;
        }
    }
    void incrementarIndicadorModificado() {
        static int cantidad = CANTIDAD_INICIAL;
        int i;
        if (longitud() == cantidad) {
            bool* temp = new bool[cantidad + C_1];
            Lista<Nota*>* prov = new Lista<Nota*>(cantidad + C_1);
            Posicion p = lista->primero();
            for (i = 0; i < longitud(); i++) {
                temp[i] = NotaModificada[i];
                prov->inserta(lista->recupera(p), prov->fin());
                p = lista->siguiente(p);
            }
            delete lista;
            lista = new Lista<Nota*>(cantidad + C_1);
            for (i = 0, p = prov->primero(); i < prov->dameCuentaElementos(); i++) {
                lista->inserta(prov->recupera(p), lista->fin());
                p = prov->siguiente(p);
            }
            delete[] NotaModificada;
            NotaModificada = temp;
            NotaModificada[i] = false;
            cantidad++;
            delete prov;
        }
    }


    void reiniciarIndicador(){
        for(int i=0 ;i< longitud();i++){
                    NotaModificada[i] = false;
                }
    }
    void ponerIndicador(int posicion){
        NotaModificada[posicion]=true;
    }
    bool checarModificacion(){
        for(int i=0 ;i<longitud();i++){
            if(NotaModificada[i]){
                return true;
            }
        }
        return false;
    }
    void modificarArchivo(){
        Posicion p, q;
        int i;
        for(i = 0,p = lista->primero(),q = lista->fin(); p != q; p = lista->siguiente(p), i++){
            if (NotaModificada[i]) {
                dao.actualizar(lista->recupera(p),i);
            }
        }
    }
    void guardarArchivo(){
        int i,j;
        Posicion p;
        dao.limpiarArchivo();
        for(i=0,j=lista->dameCuentaElementos(),p=lista->primero();i<j;i++,p=lista->siguiente(p)){
            dao.escribirNotaEnArchivo(lista->recupera(p));
        }
    }
    void leerTodaNota() {
        Nota* n;
        for(int i=0, j = dao.dameLongitud();i<j;i++){
            n =dao.obtener(i);
            if(n!=nullptr){
                incrementarIndicadorModificado();
                lista->inserta(n,lista->fin());
            }
        }
    }


protected:

private:
    BlogDAO dao;
    Lista<Nota*>* lista;
    bool* NotaModificada;
};

#endif // BLOG_H

