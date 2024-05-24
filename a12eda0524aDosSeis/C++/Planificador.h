#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

#include "TDA_Lista_Simplemente_Ligada_Lineal_Con_Encabezado.h"
#include "Tarea.h"
#define CANTIDAD_INICIAL 3
#define ARCHIVO_TAREA "Tarea.dat"
#define DELIMITADOR_CAMPOS_TAREA '|'
#define NUMERO_CAMPOS_TAREA 3

class Planificador
{
    public:
        Planificador() {
        }
        virtual ~Planificador() {
            ListaLigada<Tarea*>::Posicion p = lista.primero();
                while (!lista.estaVacia()){
                    delete lista.recupera(p);
                    lista.eliminar(p);
                }
        }
        bool estaVacio(){
            return lista.estaVacia();
        }
        int longitud(){
            return lista.dameCuentaElementos();
        }
        void agregarTarea(string descripcion,string asunto,string acronimo){
            Tarea* temporal = new Tarea(descripcion,asunto,acronimo);
            lista.inserta(temporal, lista.fin());
        }
        Tarea* muestra(int posicion) {
            if (posicion >= 0 && posicion < longitud()) {
                ListaLigada<Tarea*>::Posicion p = lista.primero();
                for (int i = 0; i <= posicion; i++) {
                    if (i == posicion) {
                        return lista.recupera(p);
                    }
                    p = lista.siguiente(p);
                }
            }
            return nullptr;
        }
        bool existeTarea(int index){
            if(muestra(index)==nullptr){
                return false;
            }else return true;
        }
        bool modificarDescripcion(int index,string descripcion){
            if (index >= 0 && index < longitud()) {
                ListaLigada<Tarea*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                return lista.recupera(p)->fijaDescripcion(descripcion);
            } else {
                return false;
            }
        }
        bool modificarAsunto(int index,string asunto){
            if (index >= 0 && index < longitud()) {
                ListaLigada<Tarea*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                return lista.recupera(p)->fijaAsunto(asunto);
            } else {
                return false;
            }
        }
        bool modificarAcronimo(int index, string acronimo){
            if (index >= 0 && index < longitud()) {
                ListaLigada<Tarea*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                return lista.recupera(p)->fijaAcronimo(acronimo);
            } else {
                return false;
            }
        }
        void modificarTodo(int index,string asunto,string descripcion,string acronimo ){
            if (index >= 0 && index < longitud()) {
                ListaLigada<Tarea*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                 lista.recupera(p)->fijaAcronimo(acronimo);
                 lista.recupera(p)->fijaAsunto(asunto);
                 lista.recupera(p)->fijaDescripcion(descripcion);
            } else {
            }
        }
         void suprimir(int posicion){
            if (posicion >= 0 && posicion < longitud()) {
                ListaLigada<Tarea*>::Posicion p = lista.primero();
                for (int i = 0; i < posicion; i++) {
                    p = lista.siguiente(p);
                }
                delete lista.recupera(p);
                lista.eliminar(p);
            }
        }
        void guardarEnArchivo(){
            ofstream archivoTarea(ARCHIVO_TAREA, ios::binary);
            if (archivoTarea.is_open()) {
                ListaLigada<Tarea*>::Posicion p = lista.primero();
                for (int index = 0; index < longitud(); index++,p = lista.siguiente(p)) {
                    string acronimo = lista.recupera(p)->dameAcronimo();
                    string asunto = lista.recupera(p)->dameAsunto();
                    string descripcion = lista.recupera(p)->dameDescripcion();
                    archivoTarea.write(acronimo.c_str(), acronimo.length());
                    archivoTarea.write(DELIMITADOR_CAMPOS, 1);
                    archivoTarea.write(asunto.c_str(), asunto.length());
                    archivoTarea.write(DELIMITADOR_CAMPOS, 1);
                    archivoTarea.write(descripcion.c_str(), descripcion.length());
                    archivoTarea.write(DELIMITADOR_REGISTRO_TEXTO,
                                        sizeof(DELIMITADOR_REGISTRO_TEXTO) - 1);
                }
                archivoTarea.close();
            } else {
            }
        }
        void inicilizar(){
            Tarea* temp;
            ifstream archivoTarea(ARCHIVO_TAREA, ios::binary);
            string campos[NUMERO_CAMPOS_TAREA];
            if (archivoTarea.is_open()) {
                string registro;
                while (getline(archivoTarea, registro)) {
                    size_t pos = registro.find(DELIMITADOR_CAMPOS);
                    campos[C_0] = registro.substr(C_0, pos);
                    registro.erase(C_0, pos + C_1);
                    pos = registro.find(DELIMITADOR_CAMPOS);
                    campos[C_1] = registro.substr(C_0, pos);
                    registro.erase(C_0, pos + C_1);
                    campos[C_2] = registro;
                    temp = new Tarea(campos[C_2],campos[C_1],campos[C_0]);
                    lista.inserta(temp,lista.fin());
                }

                archivoTarea.close();
            }
        }

    protected:

    private:
    ListaLigada<Tarea*> lista;
};

#endif // PLANIFICADOR_H
