#ifndef CURSO_H
#define CURSO_H

#include "TDA_Lista_Arreglos.h"
#define ARCHIVO_MATERIA "Materia.txt"
#define NUMERO_MATERIA 5
#define NUMERO_CAMPOS 5

class Curso
{
    public:
        Curso() {
            lista = new Lista<Materia*>(NUMERO_MATERIA);
        }
        virtual ~Curso() {
            Posicion p = lista->primero();
            while (!lista->estaVacia()){
                delete lista->recupera(p);
                lista->eliminar(p);
            }
        }
        bool estaVacio(){
            return lista->estaVacia();
        }
        int longitud(){
            return lista->dameCuentaElementos();
        }
        bool estaLleno(){
            return longitud() == NUMERO_MATERIA;
        }
        void agregarMateria(string acronimo,string nombre,string profesor,
                            string dia,int horaInicio,int horaFinal){
            Materia* temporal = new Materia(acronimo,nombre,profesor,dia,horaInicio,horaFinal);
            lista->inserta(temporal, lista->fin());
        }
        Materia* muestra(int posicion) {
            if (posicion >= 0 && posicion < longitud()) {
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
        bool existeMateria(int index){
            if(muestra(index)==nullptr){
                return false;
            }else return true;
        }
        bool modificarNombre(int index,string nombre){
            if (index >= 0 && index < longitud()) {
                Posicion p = lista->primero();
                for (int i = 0; i < index; ++i) {
                    p = lista->siguiente(p);
                }
                return lista->recupera(p)->fijaNombre(nombre);
            } else {
                return false;
            }
        }
        bool modificarProfesor(int index,string profesor){
            if (index >= 0 && index < longitud()) {
                Posicion p = lista->primero();
                for (int i = 0; i < index; ++i) {
                    p = lista->siguiente(p);
                }
                return lista->recupera(p)->fijaProfesor(profesor);
            } else {
                return false;
            }
        }
        bool modificarAcronimo(int index,string acronimo){
            if (index >= 0 && index < longitud()) {
                Posicion p = lista->primero();
                for (int i = 0; i < index; ++i) {
                    p = lista->siguiente(p);
                }
                return lista->recupera(p)->fijaAcronimo(acronimo);
            } else {
                return false;
            }
        }
        bool modificarDia(int index,string dia){
                if (index >= 0 && index < longitud()) {
                    Posicion p = lista->primero();
                    for (int i = 0; i < index; ++i) {
                        p = lista->siguiente(p);
                    }
                    return lista->recupera(p)->fijaDia(dia);
                } else {
                    return false;
                }
        }
        bool modificarHoraInicio(int index,int horaInicio){
                if (index >= 0 && index < longitud()) {
                    Posicion p = lista->primero();
                    for (int i = 0; i < index; ++i) {
                        p = lista->siguiente(p);
                    }
                    return lista->recupera(p)->fijaHoraInicio(horaInicio);
                } else {
                    return false;
                }
        }
        bool modificarHoraFinal(int index,int horaFinal){
                if (index >= 0 && index < longitud()) {
                    Posicion p = lista->primero();
                    for (int i = 0; i < index; ++i) {
                        p = lista->siguiente(p);
                    }
                    return lista->recupera(p)->fijaHoraFinal(horaFinal);
                } else {
                    return false;
                }
        }
        void modificarTodo(int index,string acronimo,string nombre,string profesor,
                            string dia,int horaInicio,int horaFinal){
            if (index >= 0 && index < longitud()) {
                    Posicion p = lista->primero();
                    for (int i = 0; i < index; ++i) {
                        p = lista->siguiente(p);
                    }
                    lista->recupera(p)->fijaNombre(nombre);
                    lista->recupera(p)->fijaProfesor(profesor);
                    lista->recupera(p)->fijaAcronimo(acronimo);
                    lista->recupera(p)->fijaDia(dia);
                    lista->recupera(p)->fijaHoraFinal(horaFinal);
                    lista->recupera(p)->fijaHoraInicio(horaInicio);
                } else {
                }
        }
        void suprimir(int posicion){
            if (posicion >= 0 && posicion < lista->dameCuentaElementos()) {
                Posicion p = lista->primero();
                for (int i = 0; i < posicion; i++) {
                    p = lista->siguiente(p);
                }
                delete lista->recupera(p);
                lista->eliminar(p);
            }
        }
        void guardarArchivoMateria(){
        int index;
        ofstream archivoMateria;
        archivoMateria.open(ARCHIVO_MATERIA);
        if(archivoMateria.is_open()){
            for(index=C_0;index<longitud();index++){
                archivoMateria << lista->recupera(index)->dameAcronimo() <<DELIMITADOR_CAMPOS
                <<lista->recupera(index)->dameNombre() <<DELIMITADOR_CAMPOS<<
                 lista->recupera(index)->dameProfesor()<<DELIMITADOR_CAMPOS<<
                 lista->recupera(index)->dameDia()<<DELIMITADOR_CAMPOS<<
                 lista->recupera(index)->dameHoraInicio()<<DELIMITADOR_CAMPOS<<
                 lista->recupera(index)->dameHoraFinal();
                if(index!= longitud()-C_1){
                    archivoMateria<<endl;
                }
            }
            archivoMateria.close();
            cout << "Datos guardados en el archivo " << ARCHIVO_MATERIA << endl;
        }else{
            cout << "No se pudo abrir el archivo " << ARCHIVO_MATERIA << " para escritura." << endl;
        }
    }
    void inicializadorMateria(){
        ifstream archivoMateria;
        string linea,campos[NUMERO_CAMPOS];
        char determinante;
        int i,k,horainicio,horafinal;
        Materia* temp;
        i=C_0;
        archivoMateria.open(ARCHIVO_MATERIA);
        if(archivoMateria.is_open()){
            while(getline(archivoMateria,linea)){
                for(k=C_0;k<static_cast<int>(linea.length());k++){
                    determinante = linea[k];
                    if(determinante=='|'){
                        campos[i]=linea.substr(C_0,k);
                        linea.erase(C_0,k+C_1);
                        i++;
                        k=C_0;
                    }
                }
                horainicio = std::stoi(campos[C_4]);
                horafinal = std::stoi(linea);
                temp=new Materia(campos[C_0],campos[C_1],campos[C_2],campos[C_3]
                                       ,horainicio,horafinal);
                lista->inserta(temp,lista->fin());
                i=C_0;
            }
            archivoMateria.close();
        }
    }

    protected:

    private:
    Lista<Materia*>* lista;
};

#endif // CURSO_H
