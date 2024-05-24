#ifndef RECORDATORIO_H
#define RECORDATORIO_H
#include "Fecha.h"
#define LONGITUD_HORA 5
#define LONGITUD_ASUNTO_RECORDATORIO 100
using namespace std;
class Recordatorio
{
    public:
        Recordatorio(char Tipo,char* Hora,char* Asunto,Fecha* fechaa) {
            if (!fijaAsunto(Asunto)){
                strcpy(asunto,"asunto");
            }
            if(!fijaFecha(fechaa)){
                fecha = new Fecha;
            }
            if(!fijaHora(Hora)){
                strcpy(hora,"00:00");
            }
            if(!fijaTipo(Tipo)){
                tipo='R';
            }
        }
        virtual ~Recordatorio() {}
        bool fijaAsunto(const char* Asunto) {
            if (strlen(Asunto) <= LONGITUD_ASUNTO_RECORDATORIO) {
                strcpy(asunto, Asunto);
                return true;
            } else {
                return false;
            }
        }
        bool fijaTipo(char Tipo) {
            tipo = Tipo;
            return true;
        }
        bool fijaHora(const char* Hora) {
            if (strlen(Hora) <= LONGITUD_HORA) {
                strcpy(hora, Hora);
                return true;
            } else {
                return false;
            }
        }
        bool fijaFecha(Fecha* fechaa) {
            if(fecha == nullptr){
                return false;
            }else{
                fecha = fechaa;
                return true;
            }
        }
        char dameTipo() {
            return tipo;
        }
        const char* dameHora() {
            return hora;
        }
        Fecha* dameFecha() {
            return fecha;
        }
        const char* dameAsunto() const {
            return asunto;
        }
    protected:

    private:
        Fecha* fecha;
        char hora[LONGITUD_HORA + C_1];
        char asunto[LONGITUD_ASUNTO_RECORDATORIO+C_1];
        char tipo;
};


#endif // RECORDATORIO_H
