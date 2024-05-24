#ifndef MATERIA_H
#define MATERIA_H
#include"Clase.h"
using namespace std;
class Materia : public Clase
{
    public:
        Materia(string Acronimo,string Nombre,string Profesor,string Dia,int HoraInicio,
                int HoraFinal){
            fijaProfesor(Profesor);
            fijaAcronimo(Acronimo);
            fijaNombre(Nombre);
            fijaDia(Dia);
            fijaHoraInicio(HoraInicio);
            fijaHoraFinal(HoraFinal);
        }
       bool fijaProfesor(string Profesor) {
            if (Profesor.empty()) {
                profesor = "Default Profesor";
                return false;
            } else {
                profesor = Profesor;
                return true;
            }
        }
        string dameProfesor() {
            return profesor;
        }


    protected:

    private:
        string profesor;
};

#endif // MATERIA_H
