#ifndef CONTROLASISTENCIA_H
#define CONTROLASISTENCIA_H


class ControlAsistencia
{
    public:
        ControlAsistencia() {}
        virtual ~ControlAsistencia() {}
        void fijaCantidadfaltas(int Cantidadfaltas){
            cantidadFaltas=Cantidadfaltas ;
        }
        void fijaCantidadRetardos(int CantidadRetardos){
            cantidadRetardos = CantidadRetardos;
        }
        void calculaAsistencia(){
            calculaTotalAsistencia();
            calculaPorcentajaAsistencia();
        }
         int dameCantidadFaltas() {
        return cantidadFaltas;
        }
        int dameCantidadRetardos() {
            return cantidadRetardos;
        }
        float dameTotalAsistencia() {
            return totalAsistencia;
        }
        float damePorcentajeAsistencia() {
            return porcentajeAsistencia;
        }
    protected:

    private:
        int cantidadFaltas;
        int cantidadRetardos;
        float totalAsistencia;
        float porcentajeAsistencia;
        const int TOTAL_ASISTENCIAS = 34;
        const int PORCENTAJE_MAXIMO = 100;
        const int C_3=3;
        void calculaTotalAsistencia(){
           totalAsistencia = (float)TOTAL_ASISTENCIAS - cantidadFaltas ;
           totalAsistencia = totalAsistencia - ((float)cantidadRetardos / C_3);
        }
        void calculaPorcentajaAsistencia(){
           porcentajeAsistencia=(totalAsistencia / TOTAL_ASISTENCIAS) * PORCENTAJE_MAXIMO;
        }
};

#endif // CONTROLASISTENCIA_H
