#ifndef EVALUADOR_H
#define EVALUADOR_H


#include <fstream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>
#include"Materia.h"
#include"ControlAsistencia.h"
#include"Evaluando.h"
#include"util.h"

#define NOMBRE_ARCHIVO "calificacion"
#define TERMINACION_ARCHIVO ".txt"
#define BARRA_BAJA "_"
// PORCENTAJES A CONSIDERAR
#define PORCENTAJE_ASISTENCIA_MINIMA 80
// DECLARACION DE CONSTANTES
#define TOTAL_ACTIVIDADES  9
#define TOTAL_EXAMENES  3
#define CALIFICACION_MINIMA_APROVATORIA 60
#define CANTIDAD_RETARDO_FALTA_ 3


stringstream imprimir(Materia clase,Evaluando evaluando,bool evaluandos[]);
Materia pedirClase();

void precionaEnter();
void guardarEnArchivo(stringstream& salida,Materia clase);
void evaluarCurso();
void pedirDatos(Evaluando* evaluando);
void evaluarCurso(Materia clase){
    // DECLARACION DE VARIABLES PARA ENTARDA DE DATOS
    Evaluando evaluando;
    // DECLARACION DE VARIABLES PARA COMPUTO
    bool DerechoOrdinario, calificacionAprovatoria, aprovado ,evaluandos[C_3];
    stringstream salida,copia;
    string porImprimir;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout << "learnix" << endl;
    //ENTRADA DE DATOS
    pedirDatos(&evaluando);
    precionaEnter();
    //COMPUTO ASISTENCIAS
    evaluando.control.calculaAsistencia();

    if (evaluando.control.damePorcentajeAsistencia() < PORCENTAJE_ASISTENCIA_MINIMA){
        DerechoOrdinario = false;
    }else{
        DerechoOrdinario = true;
    }
    //COMPUTO DE TAREAS
    evaluando.calcularPuntajeTarea();
    //COMPUTO DE ACTIVIDADES
    evaluando.calcularPuntajeActividad();
    //COMPUTO DE EXAMENES}
    evaluando.calcularPuntajeExamen();
    //COMPUTO DE PUNTOS FINALES
    evaluando.calcularResultado();
    calificacionAprovatoria = evaluando.resultado<CALIFICACION_MINIMA_APROVATORIA? false:true;
    if (calificacionAprovatoria&&DerechoOrdinario){
        aprovado = true;
    }else{
        aprovado = false;
    }
    //SALIDA DE DATOS
    evaluandos[C_0]= DerechoOrdinario;
    evaluandos[C_1]= calificacionAprovatoria;
    evaluandos[C_2]= aprovado;
    salida = imprimir(clase,evaluando,evaluandos);
    copia = imprimir(clase,evaluando,evaluandos);
    while(getline(salida,porImprimir)){
        cout<<porImprimir<<endl;
    }
    cout << "Presione Enter para terminar . . .";
    cin.ignore();
    cin.get();
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    guardarEnArchivo(copia,clase);
}
void precionaEnter(){
    cout << "Presione Enter para continuar . . .";
    cin.ignore();
    cin.get();
    limpiar_pantalla(TIEMPO_A_ESPERAR);
}
void pedirDatos(Evaluando* evaluando){
    int i;
    int cantidadFaltas,cantidadRetrasos;
    char a_acentuada = 160;
    string cuenta[C_3] = {"primer", "segundo", "tercer"};
    cout << "dime el numero de faltas que acumulaste: ";
    cin >> cantidadFaltas;
    cout << "dime el numero de retardos que acumulaste: ";
    cin >> cantidadRetrasos;
    cout << "dima la cantidad de tareas que entregaste: ";
    cin>> evaluando->cantidadTareas;
    for (i = C_0; i < TOTAL_ACTIVIDADES; i++) {
        cout << "Cu" << a_acentuada << "nto obtuviste en la actividad #" << i + C_1 << ": ";
        cin >> evaluando->calificacionActividades[i];
    }
    for (i = C_0; i < TOTAL_EXAMENES; i++) {
        cout << "Cu" << a_acentuada << "nto obtuviste en el " << cuenta[i] << " examen parcial: ";
        cin >> evaluando->calificacionExamen[i];
    }
    evaluando->control.fijaCantidadfaltas(cantidadFaltas);
    evaluando->control.fijaCantidadRetardos(cantidadRetrasos);
}
stringstream imprimir(Materia clase,Evaluando evaluando,bool evaluandos[]){
    int i;
    stringstream salida;
    string cuenta[C_3] = {"primer", "segundo", "tercer"};
    salida<<"Evaluador de Curso v1.0 "<<clase.dameNombre()<<" ("<<clase.dameAcronimo()<<") ";
    salida<<clase.dameDia()<<" "<<clase.dameHoraInicio()<<"a"<<clase.dameHoraFinal()<<endl<<endl;
    salida << "Cuantas faltas acumulaste?"<<evaluando.control.dameCantidadFaltas()<<endl;
    salida << "Cuantos retardos acumulaste?"<<evaluando.control.dameCantidadRetardos()<<endl;
    salida << "Cuantas tareas realizaste?"<<evaluando.cantidadTareas<<endl;
    for (i = C_0; i < TOTAL_ACTIVIDADES; i++) {
        salida << "Cuanto obtuviste en la actividad #" << i + C_1 << "?";
        salida<<evaluando.calificacionActividades[i]<<endl;
    }
     for (i = C_0; i < TOTAL_EXAMENES; i++) {
        salida << "Cuanto obtuviste en el " << cuenta[i] << " examen parcial: ";
        salida << evaluando.calificacionExamen[i]<<endl;
    }
    salida << left << setw(15) << "Tareas" << setw(15)
    << "Actividades" << setw(15) << "Examenes" << endl;
    salida << left << setw(15) << evaluando.puntajeTarea << setw(15)
    << evaluando.puntajeActividad << setw(15) << evaluando.puntajeExamen << endl;
    salida <<left<<setw(30) <<"Total asistencias="<<setw(10)
    <<evaluando.control.dameTotalAsistencia()<<endl;
    salida <<left<<setw(30) <<"Porcentaje de asistencias= "<<setw(10)
    <<evaluando.control.damePorcentajeAsistencia();
    salida<<( evaluandos[C_0]?"Tiene derecho":"No tiene derecho")<<endl;
    salida <<left<<setw(30) <<"Calificacion Final="<<setw(10)<<evaluando.resultado;
    salida<<(evaluandos[C_1]?"Calificacion aprobatoria":"Calificacion no aprobatoria")<<endl;
    salida<<(evaluandos[C_2]?"Alumn@ aprobad@":"Alumn@ no aprobad@")<<endl;
    return salida;

}
void guardarEnArchivo(stringstream& salida,Materia clase) {
    ofstream archivo;
    string nombreArchivo;
    nombreArchivo = NOMBRE_ARCHIVO;
    nombreArchivo += BARRA_BAJA;
    nombreArchivo += clase.dameNombre();
    nombreArchivo += TERMINACION_ARCHIVO;
    archivo.open(nombreArchivo);
    if (archivo.is_open()) {
        string texto;
        while (getline(salida, texto)) {
            archivo << texto << endl;
        }
        archivo.close();
        cout << "Datos guardados en el archivo " << nombreArchivo << endl;
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << " para escritura." << endl;
    }
}


#endif // EVALUADOR_H
