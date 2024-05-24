#ifndef BLOGDAO_H
#define BLOGDAO_H

#include <fstream>
#include "Nota.h"
#define ARCHIVO_NOTA "Nota.dat"
class BlogDAO
{
     private:
        fstream archivo;


















    public:
        BlogDAO() {
            archivo.open(ARCHIVO_NOTA,ios::in|ios::out|ios::binary|ios::app);
            if(archivo.is_open()){
                archivo.close();
            }
            archivo.open(ARCHIVO_NOTA,ios::in|ios::out|ios::binary);
        }
        virtual ~BlogDAO() {}
        void agregar(Nota* n){
            archivo.seekp(0,ios_base::end);
            char cuerpo[MAX_CUERPO + 1];
            char titulo[MAX_TITULO + 1];
            archivo.write(n->dameTitulo(),sizeof(titulo));
            archivo.write(n->dameTitulo(),sizeof(cuerpo));
        }
        void obtener(Nota* n,int posicion){
            char cuerpo[MAX_CUERPO + 1];
            char titulo[MAX_TITULO + 1];
            archivo.seekg(posicion*(sizeof(cuerpo)+sizeof(titulo)),ios_base::beg);
            archivo.read(const_cast<char*>(titulo), sizeof(titulo));
            archivo.read(const_cast<char*>(cuerpo), sizeof(cuerpo));
            n ->fijaCuerpo(cuerpo);
            n->fijaTitulo(titulo);
        }
        Nota* obtener(int posicion){
            Nota* n = new Nota((char*)"",(char*)"");
            obtener(n,posicion);
            return n;
        }
        void actualizar(Nota* n,int posicion){
            char cuerpo[MAX_CUERPO + 1];
            char titulo[MAX_TITULO + 1];
            archivo.seekp(posicion*(sizeof(cuerpo)+sizeof(titulo)),ios_base::beg);
            archivo.write(n->dameTitulo(),sizeof(titulo));
            archivo.write(n->dameTitulo(),sizeof(cuerpo));
        }
        int dameLongitud(){
            char cuerpo[MAX_CUERPO + 1];
            char titulo[MAX_TITULO + 1];
            archivo.seekg(0,ios_base::end);
            return archivo.tellg()/(sizeof(cuerpo)+sizeof(titulo));
        }
        int dimePosicionNotaPorTitulo(string titulo){
            Nota* n = new Nota((char*)"",(char*)"");
            int i,longitud;
            archivo.seekg(0,ios_base::beg);
            for(i=0,longitud=dameLongitud();i<longitud;i++){
                obtener(n,i);
                if(n->dameTitulo()==titulo){
                    delete n;
                    return i;
                }
            }
            return -1;
        }
        void limpiarArchivo(){
            archivo.close();
            archivo.open(ARCHIVO_NOTA, std::ios::out | std::ios::trunc | std::ios::binary);
            archivo.close();
            archivo.open(ARCHIVO_NOTA, std::ios::in | std::ios::out | std::ios::binary);
        }

        void escribirNotaEnArchivo(Nota* n){
            char cuerpo[MAX_CUERPO + 1];
            char titulo[MAX_TITULO + 1];
            archivo.write(n->dameTitulo(),sizeof(titulo));
            archivo.write(n->dameCuerpo(),sizeof(cuerpo));
        }

    protected:


};

#endif // BLOGDAO_H
