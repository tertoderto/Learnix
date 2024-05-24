#ifndef EVALUANDO_H
#define EVALUANDO_H
#include"ControlAsistencia.h"
class Evaluando
{
    public:
        static const int C_0 = 0;
        // PORCENTAJES A CONSIDERAR
        static const int PORCENTAJE_TAREAS = 7;
        static const int PORCENTAJE_ACTIVIDADES = 63;
        static const int PORCENTAJE_MAXIMO = 100;
        static const int PORCENTAJE_EXAMENES = 30;
        // DECLARACION DE CONSTANTES
        static const int TOTAL_TAREAS = 10;
        static const int TOTAL_ACTIVIDADES = 9;
        static const int TOTAL_EXAMENES = 3;
        ControlAsistencia control;
        // DECLARACION DE VARIABLES PARA ENTARDA DE DATOS
        float calificacionExamen[TOTAL_EXAMENES], calificacionActividades[TOTAL_ACTIVIDADES];
        int cantidadTareas,i;
        // DECLARACION DE VARIABLES PARA COMPUTO
        float puntajeTarea,puntajeActividad,puntajeExamen,resultado;
        Evaluando() {}
        virtual ~Evaluando() {}
        void calcularPuntajeTarea(){
            puntajeTarea=(float)cantidadTareas * PORCENTAJE_TAREAS / TOTAL_TAREAS;
        }
        void calcularPuntajeActividad(){
            for (i = C_0; i < TOTAL_ACTIVIDADES; i++) {
                puntajeActividad += calificacionActividades[i];
            }
            puntajeActividad = (float)puntajeActividad  * PORCENTAJE_ACTIVIDADES /
            (TOTAL_ACTIVIDADES * PORCENTAJE_MAXIMO);
        }
        void calcularPuntajeExamen(){
            for (i = C_0; i < TOTAL_EXAMENES; i++) {
                puntajeExamen += calificacionExamen[i];
            }
            puntajeExamen = (float)puntajeExamen * PORCENTAJE_EXAMENES
            / (TOTAL_EXAMENES * PORCENTAJE_MAXIMO);
        }
        void calcularResultado(){
            resultado = puntajeActividad+puntajeExamen+puntajeTarea;
        }

    protected:

    private:
};




#endif // EVALUANDO_H
