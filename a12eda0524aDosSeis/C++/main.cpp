/*
NickName:DosSeis
Ejercicio: a12
Tiempo=02:00

*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include"evaluador.h"
#include"Deber.h"
#include"Kardex.h"
#include"util.h"
#include"Agenda.h"
#include"administradorNota.h"
enum{EVALUAR = 1,GESTIONAR_MATERIA,GESTIONAR_TAREA,AGENDA,BLOG,SALIR};
using namespace std;



void inicializarPrograma();

int main()
{
    int opcion;
    inicializarPrograma();
    do{
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        cout<<"1. Evaluacion del Curso"<<endl;
        cout<<"2. Gestion de Materias "<<endl;
        cout<<"3. Control de Tareas "<<endl;
        cout<<"4. Agenda"<<endl;
        cout<<"5. Bloc de Notas "<<endl;
        cout<<"6. Salir"<<endl<<endl<<endl<<endl<<endl;
        cout<<"opcion: ";
        limpiarBufferEntero(opcion);
        switch(opcion){
        case EVALUAR:
            verSiEvaluar();
            break;
        case GESTIONAR_MATERIA:
            gestionarMateria();
            break;
        case GESTIONAR_TAREA:
            gestionarTarea();
            break;
        case AGENDA:
            gestionarAgenda();
            break;
        case BLOG:
            gestinaNota();
            break;
        case SALIR:
            break;
        default:
            cout<<"opcion no valida"<<endl;
            break;

        }
    }while(opcion !=SALIR);
    return C_0;
}

void inicializarPrograma(){
    curso.inicializadorMateria();
    plan.inicilizar();
    lista.inicializador();
    blog.inicializadorNota();
}


