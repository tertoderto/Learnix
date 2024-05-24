#ifndef CLASE_H
#define CLASE_H

using namespace std;
class Clase
{
    public:
        Clase() {}
        virtual ~Clase() {}
        string dameNombre() { return nombre; }
        bool fijaNombre(string val) {
            if (val.empty()) {
                nombre = "Default Nombre";
                return false;
            } else {
                nombre = val;
                return true;
            }
        }
        string dameAcronimo() { return acronimo; }
        bool fijaAcronimo(string val) {
            if (val.empty()) {
                acronimo = "Default Acrónimo";
                return false;
            } else {
                acronimo = val;
                return true;
            }
        }
        string dameDia() { return dia; }
        bool fijaDia(string val) {
            if (val.empty()) {
                dia = "Monday";
                return false;
            } else {
                dia = val;
                return true;
            }
        }
        int dameHoraInicio() { return horaInicio; }
        bool fijaHoraInicio(int val) {
            if (val >= 0 && val <= 23) {
                horaInicio = val;
                return true;
            } else {
                horaInicio = 8;
                return false;
            }
        }
        int dameHoraFinal() { return horaFinal; }
        bool fijaHoraFinal(int val) {
            if (val >= 0 && val <= 23 && val > horaInicio) {
                horaFinal = val;
                return true;
            } else {
                horaFinal = horaInicio + 2;
                return false;
            }
        }
    protected:

    private:
        string nombre;
        string acronimo;
        string dia;
        int horaInicio;
        int horaFinal;
};

#endif // CLASE_H
