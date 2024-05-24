#ifndef ITINERARIO_H
#define ITINERARIO_H

#include <fstream>
#include <iostream>
using namespace std;

#include "TDA_Lista_Doblemente_Ligada_Lineal_Con_Encabezado.h"
#include "Recordatorio.h"
#define ARCHIVO_RECORDATORIO "Recordatorio.dat"
#define CANTIDAD_INICIAL 3


class Itinerario
{
    public:
        Itinerario() {
            recordatorioModificado = new bool[CANTIDAD_INICIAL];
        }
        virtual ~Itinerario() {
            ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
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
        void agregarRecordatorio(char tipo,char* hora,char* asunto,Fecha* fecha){
            Recordatorio* temporal = new Recordatorio(tipo,hora,asunto,fecha);
            lista.inserta(temporal, lista.fin());
        }
        Recordatorio* mostrar(int posicion) {
            if (posicion >= 0 && posicion < lista.dameCuentaElementos()) {
                ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
                for (int i = 0; i <= posicion; i++) {
                    if (i == posicion) {
                        return lista.recupera(p);
                    }
                    p = lista.siguiente(p);
                }
            }
            return nullptr;
        }
        bool existeRecordatorio(int index){
            if(mostrar(index)==nullptr){
                return false;
            }else return true;
        }
        bool cambiarFecha(int index,Fecha* fecha){
            if (index >= 0 && index < lista.dameCuentaElementos()) {
                ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                recordatorioModificado[index]=true;
                delete lista.recupera(p)->dameFecha();
                return lista.recupera(p)->fijaFecha(fecha);
            } else {
                return false;
            }
        }
        bool cambiarHora(int index,char* hora){
            if (index >= 0 && index < lista.dameCuentaElementos()) {
                ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                recordatorioModificado[index]=true;
                return lista.recupera(p)->fijaHora(hora);
            } else {
                return false;
            }
        }
        bool cambiarAsunto(int index,char* asunto){
            if (index >= 0 && index < lista.dameCuentaElementos()) {
                ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                recordatorioModificado[index]=true;
                return lista.recupera(p)->fijaAsunto(asunto);
            } else {
                return false;
            }
        }
        bool cambiarTipo(int index,char tipo){
            if (index >= 0 && index < lista.dameCuentaElementos()) {
                ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                recordatorioModificado[index]=true;
                return lista.recupera(p)->fijaTipo(tipo);
            } else {
                return false;
            }
        }
        void cambiarTodo(int index,char tipo,char* hora,char* asunto,Fecha* fecha){
            if (index >= 0 && index < lista.dameCuentaElementos()) {
                ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
                for (int i = 0; i < index; ++i) {
                    p = lista.siguiente(p);
                }
                recordatorioModificado[index]=true;
                delete lista.recupera(p)->dameFecha();
                lista.recupera(p)->fijaFecha(fecha);
                lista.recupera(p)->fijaHora(hora);
                lista.recupera(p)->fijaTipo(tipo);
                lista.recupera(p)->fijaAsunto(asunto);
            } else {
            }
        }
        void inicializador(){
            leerTodo();
            for(int i =0;i<C_3;i++){
                recordatorioModificado[i]=false;
            }
        }
        bool checarModificacion(){
            for(int i=0 ;i<longitud();i++){
                if(recordatorioModificado[i]){
                    return true;
                }
            }
            return false;
        }
        void incrementarLista() {
            static int cantidad = CANTIDAD_INICIAL;
            int i;
            if (longitud() == cantidad) {
                bool* temp = new bool[cantidad + C_1];
                for (i = 0; i < longitud(); i++) {
                    temp[i] = recordatorioModificado[i];
                }
                delete[] recordatorioModificado;
                recordatorioModificado = temp;
                recordatorioModificado[i]= false;
                cantidad++;
            }
        }
        void suprimir(int posicion){
            if (posicion >= 0 && posicion < lista.dameCuentaElementos()) {
                ListaDobleLigada<Recordatorio*>::Posicion p = lista.primero();
                for (int i = 0; i < posicion; i++) {
                    p = lista.siguiente(p);
                }
                delete lista.recupera(p);
                lista.eliminar(p);
            }
        }


        int contarRecordatorioArchivo(ifstream& archivo){
            char hora[LONGITUD_HORA + C_1];
            char asunto[LONGITUD_ASUNTO_RECORDATORIO+C_1];
            int recordatorioEscrito;
            archivo.seekg(C_0,ios_base::end);
            recordatorioEscrito = archivo.tellg()/(sizeof(int)+sizeof(int)+sizeof(int)+sizeof(char)
                                                   +sizeof(hora)+sizeof(asunto));
            archivo.seekg(C_0,ios_base::beg);
            return recordatorioEscrito;
        }
        void leerTodo(){
            ifstream archivo;
            Recordatorio* r;
            archivo.open(ARCHIVO_RECORDATORIO,ios::binary);
            if(archivo.is_open()){
                for(int i=0, j = contarRecordatorioArchivo(archivo);i<j;i++){
                    r = leerRecordatorio(archivo);
                    if(r!=nullptr){
                        incrementarLista();
                        lista.inserta(r,lista.fin());
                    }
                }
                archivo.close();
            }else{
            }
        }
        Recordatorio* leerRecordatorio(ifstream& archivo){
            char hora[LONGITUD_HORA + C_1];
            char asunto[LONGITUD_ASUNTO_RECORDATORIO+C_1];
            int dia,mes,anio;
            char tipo;
            Fecha* fecha;
            Recordatorio* recordatorio;
            archivo.read(asunto,sizeof(asunto));
            archivo.read(hora,sizeof(hora));
            archivo.read(reinterpret_cast<char*>(&tipo), sizeof(char));
            archivo.read(reinterpret_cast<char*>(&anio), sizeof(int));
            archivo.read(reinterpret_cast<char*>(&mes), sizeof(int));
            archivo.read(reinterpret_cast<char*>(&dia), sizeof(int));
            fecha = new Fecha();
            fecha->fijaDia(dia);
            fecha->fijaMes(mes);
            fecha->fijaAnio(anio);
            recordatorio = new Recordatorio(tipo,hora,asunto,fecha);
            return recordatorio;
        }
        void guardarModificacion(){
            char hora[LONGITUD_HORA + C_1];
            char asunto[LONGITUD_ASUNTO_RECORDATORIO+C_1];
            ofstream archivo;
            archivo.open(ARCHIVO_RECORDATORIO,std::ios::in|std::ios::out|std::ios::binary);
            if(archivo.is_open()){
                ListaDobleLigada<Recordatorio*>::Posicion p, q;
                int i;
                for(i = 0,p = lista.primero(),q = lista.fin(); p != q;
                    p = lista.siguiente(p), i++){
                    if(recordatorioModificado[i]){
                        archivo.seekp(i*(sizeof(int)+sizeof(int)+sizeof(int)+sizeof(char)
                                         +sizeof(asunto)+sizeof(hora)));
                        escribirRecordatorio(archivo,lista.recupera(p));
                    }
                }
                archivo.close();
            }
        }
        void guardarArchivoRecordatorio() {
            ofstream archivo;
            int i;
            archivo.open(ARCHIVO_RECORDATORIO,ios::trunc|ios::binary);
            if (archivo.is_open()) {
                ListaDobleLigada<Recordatorio*>::Posicion p;
                for (p = lista.primero() ,i=0;i<lista.dameCuentaElementos();
                    i++,p=lista.siguiente(p)) {
                    escribirRecordatorio(archivo,lista.recupera(p));
                }
                archivo.close();
            } else {
            }
        }
        void escribirRecordatorio(ofstream& archivo,Recordatorio* r){
            char tipo = r->dameTipo();
            int anio = r->dameFecha()->dameAnio();
            int mes = r->dameFecha()->dameMes();
            int dia = r->dameFecha()->dameDia();
            char asunto[LONGITUD_ASUNTO_RECORDATORIO+1] ;
            char hora[LONGITUD_HORA+1] ;
            archivo.write(r->dameAsunto(),sizeof(asunto));
            archivo.write(r->dameHora(),sizeof(hora));
            archivo.write(&(tipo), sizeof(char));
            archivo.write(reinterpret_cast<char*>(&anio), sizeof(int));
            archivo.write(reinterpret_cast<char*>(&mes),sizeof(int));
            archivo.write(reinterpret_cast<char*>(&dia),sizeof(int));
        }
        void reiniciarIndicador(){
            for(int i=0 ;i< longitud();i++){
                        recordatorioModificado[i] = false;
                    }
        }
    protected:

    private:
    ListaDobleLigada<Recordatorio*> lista;
    bool* recordatorioModificado;
};

#endif // ITINERARIO_H
