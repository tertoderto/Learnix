#ifndef TAREA_H
#define TAREA_H
#include"GestorAsunto.h"
using namespace std;
class Tarea: public GestorAsunto
{
    public:
        Tarea(string Descripcion,string Asunto,string Acronimo) : GestorAsunto(Asunto){
            if(!fijaAcronimo(Acronimo)){
                acronimo = "acro";
            }
            if(!fijaDescripcion(Descripcion)){
                descripcion="descripcion";
            }
        }
        virtual ~Tarea() {}
    bool fijaDescripcion(string Descripcion) {
        longitud = static_cast<int>(Descripcion.length());
        if(longitud<LONGITUD_DESCRIPCION){
            descripcion = Descripcion;
            return true;
        }else{
            return false;
        }

    }
    bool fijaAcronimo(string Acronimo) {
        longitud = static_cast<int>(Acronimo.length());
        if (longitud>LONGITUD_MAXIMA_ACRONIMO||longitud<LONGITUD_MINIMA_ACRONIMO){
            return false;
        }else{
            acronimo = Acronimo;
            return true;
        }

    }
    string dameDescripcion() {
        return descripcion;
    }
    string dameAcronimo() {
        return acronimo;
    }

    protected:

    private:
        string descripcion;
        string acronimo;
        const int LONGITUD_DESCRIPCION = 40+2;
        const int LONGITUD_MAXIMA_ACRONIMO = 5+2;
        const int LONGITUD_MINIMA_ACRONIMO = 3;
};

#endif // TAREA_H
