#ifndef FECHA_H
#define FECHA_H
#include "VariablesGlobales.h"
 class Fecha {
    private:
    int anio;
    int mes;
    int dia;
public:
Fecha() {
    anio = ANIO_PREDETERMINADO;
    mes = MES_PREDETERMINADO;
    dia = DIA_PREDETERMINADO;
}

int dameAnio() {
    return anio;
}

bool fijaAnio(int anio) {
    if(!esFechaValida(anio,mes,dia)){
        return false;
    }else {
        this->anio = anio;
        return true;
    }
}

int dameMes() {
    return mes;
}

bool fijaMes(int mes) {
    if(mes > MAX_MESES||mes<=J_0||!esFechaValida(anio,mes,dia)){
        return false;
    }else {
        this->mes = mes;
        return true;
    }
}

int dameDia() {
    return dia;
}

bool fijaDia(int dia) {
    if(dia > DIA_MAXIMO||dia<=J_0||!esFechaValida(anio,mes,dia)){
        return false;
    }else {
        this->dia = dia;
        return true;
    }
}
bool esFechaValida(int a,int m,int d){
    switch (m){
        case ENERO :
        case MARZO:
        case MAYO:
        case JULIO:
        case AGOSTO:
        case OCTUBRE:
        case DICIEMBRE:
            return true;
        case ABRIL:
        case JUNIO:
        case SEPTIEMBRE:
        case NOVIEMBRE:
            return d != DIA_MAXIMO;
        case FEBRERO:
            if((a % J_4 == J_0 &&a % CASO1 != J_0) ||(a % CASO2 == J_0)){
                return d <= FEBRERO_BISIESTO;
            } else {
                return d <= FEBRERO_NORMAL;
            }
        default:
            return false;
    }
    return false;
}
};


#endif // FECHA_H
