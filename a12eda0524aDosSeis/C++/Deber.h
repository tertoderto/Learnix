#ifndef DEBER_H_INCLUDED
#define DEBER_H_INCLUDED

#include "Planificador.h"
#include "Tarea.h"
#include "util.h"


#define LONGITUD_DESCRIPCION  40
#define LONGITUD_MAXIMA_ACRONIMO  5
#define LONGITUD_MINIMA_ACRONIMO  3
#define LONGITUD_ASUNTO 30



enum {AGREGAR_TAREA = C_1,LISTAR_TAREA,MOSTRAR_TAREA,MODIFICAR_TAREA
        ,ELIMINAR_TAREA,GUARDAR_TAREA,REGRESAR_DE_TAREA};
enum{DESCRIPCION = C_1,ASUNTO,ACRONIMO_TAREA,TODO_TAREA,REGRESAR_TAREA};

Planificador plan;


void agregarTarea();
void cambiarAsunto(int index);
void cambiarDescripcion(int index);
void cambiaAcronimoTarea(int index);
void cambiarTodoTarea(int index);
bool checarLongitud(string& dato, int maximo, int minimo);
void checarCaracterGetLineLongitud(string texto, string& dato, int maximo, int minimo);
void eliminarTarea();
void listarTarea();
void menuEditarTarea();
void mostrarTarea();
void mostrarTareaIndex(int index);
void mostrarVacico();


void gestionarTarea(){
    int opcion;
    do{
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        cout << "1. Agregar tarea" << endl;
        cout << "2. Listar tareas" << endl;
        cout << "3. Mostrar detalles de una tarea" << endl;
        cout << "4. Modificar una tarea" << endl;
        cout << "5. Eliminar tarea" << endl;
        cout << "6. Guardar cambios" << endl;
        cout << "7. Regresar al menu anterior." << endl<< endl<< endl<< endl<< endl;
        cout << "opcion:" ;
        limpiarBufferEntero(opcion);
        switch(opcion) {
            case AGREGAR_TAREA:
                agregarTarea();
                break;
            case LISTAR_TAREA:
                listarTarea();
                break;
            case MOSTRAR_TAREA:
                mostrarTarea();
                break;
            case MODIFICAR_TAREA:
                menuEditarTarea();
                break;
            case ELIMINAR_TAREA:
                eliminarTarea();
                break;
            case GUARDAR_TAREA:
                plan.guardarEnArchivo();
                break;
            case REGRESAR_DE_TAREA:
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
        espera();
    }while(opcion != REGRESAR_DE_TAREA );

}
void agregarTarea(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    titulo("Creacion de tarea");
    string asunto,acronimo,descripcion;
    checarCaracterGetLineLongitud("Dime el asunto de la tarea: ",asunto,LONGITUD_ASUNTO,C_0);
    checarCaracterGetLineLongitud("Dime el acronimo de la tarea que dejo la tarea: "
                                  ,acronimo,LONGITUD_MAXIMA_ACRONIMO,LONGITUD_MINIMA_ACRONIMO);
    checarCaracterGetLineLongitud("Dime una descripcion de la tarea: "
                                  ,descripcion,LONGITUD_DESCRIPCION,C_0);
    plan.agregarTarea(descripcion,asunto,acronimo);
}
void checarCaracterGetLineLongitud(string texto,string& dato,int maximo,int minimo){
    size_t caracterEncontardo,segundocaracterEncontardo;
    bool encontrado,encontradoDos,longituValida;
    do{
    cout<<texto;
    getline(cin,dato);
    longituValida = checarLongitud(dato,maximo,minimo);
    caracterEncontardo= dato.find(DELIMITADOR_CAMPOS);
    segundocaracterEncontardo= dato.find(DELIMITADOR_REGISTRO);
    encontrado = caracterEncontardo!= string::npos;
    encontradoDos = segundocaracterEncontardo != string::npos;
    }while(encontrado||encontradoDos||!longituValida);
}
bool checarLongitud(string& dato, int maximo,int minimo){
    int longitud;
    longitud = static_cast<int>(dato.length());
    if (longitud>maximo||longitud<minimo){
        return false;
    }else{
        return true;
    }
}
void listarTarea(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"listado de tareas"<<endl<<endl<<endl<<endl<<endl;
    if(!plan.estaVacio()){
        mostrarVacico();
    }else{
        cout<<"no hay tareas por mostrar"<<endl;
    }
}
void mostrarVacico(){
    int i;
    cout <<left<<setw(ANCHO_NUMERO)<< "#" <<""<< setw(LONGITUD_MAXIMA_ACRONIMO+C_4)
        << "Acronimo" <<""<< setw(LONGITUD_ASUNTO) << "Asunto" << endl;
        for(i=C_0;i<plan.longitud();i++){
            cout <<left<<setw(ANCHO_NUMERO)<< (i+C_1)<<""
            << setw(LONGITUD_MAXIMA_ACRONIMO+C_4) << plan.muestra(i)->dameAcronimo()<<""
            << setw(LONGITUD_ASUNTO) << plan.muestra(i)->dameAsunto() << endl;
        }
}
void mostrarTarea(){
    int numTarea;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"mostrar tarea"<<endl<<endl<<endl<<endl<<endl;
    if(!plan.estaVacio()){
        mostrarVacico();
        cout<<"dime el numero de la tarea que quieres ver(1 a "<<plan.longitud()<<"): "<<endl;
        cin>>numTarea;
        numTarea--;
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        if(plan.existeTarea(numTarea)){
            cout <<left<< setw(LONGITUD_MAXIMA_ACRONIMO+C_4)<< "Acronimo" <<""<<
            setw(LONGITUD_DESCRIPCION) << "Descripcion" <<""
            <<setw(LONGITUD_ASUNTO)<< "Asunto"<<""<<endl;
            cout <<left<< setw(LONGITUD_MAXIMA_ACRONIMO+C_4)
            << plan.muestra(numTarea)->dameAcronimo()
            <<""<<setw(LONGITUD_DESCRIPCION) << plan.muestra(numTarea)->dameDescripcion() <<""
            <<setw(LONGITUD_ASUNTO)<< plan.muestra(numTarea)->dameAsunto()<<endl;
        }else{
            cout<<"no existe ese numero de tarea"<<endl;
        }
    }else{
        cout<<"no hay tarea por mostrar"<<endl;
    }
}
void menuEditarTarea(){
    int opcion,index;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"modificador de Tareas"<<endl<<endl<<endl<<endl<<endl;
    if(!plan.estaVacio()){
        mostrarVacico();
        cout<<"dime el numero de la tarea a modificar: "<<endl;
        cin>>index;
        index--;
        if(plan.existeTarea(index)){
            limpiar_pantalla(TIEMPO_A_ESPERAR);
            cout<<"Que queires modificar?"<<endl;
            cout<<"1.- descripcion de la tarea"<<endl;
            cout<<"2.- Asunto de la tarea"<<endl;
            cout<<"3.- Acronimo de la tarea"<<endl;
            cout<<"4.- Todo "<<endl;
            cout<<"5.- Regresar"<<endl;
            limpiarBufferEntero(opcion);
            switch(opcion){
            case DESCRIPCION:
                cambiarDescripcion(index);
                break;
            case ASUNTO:
                cambiarAsunto(index);
                break;
            case ACRONIMO_TAREA:
                cambiaAcronimoTarea(index);
                break;
            case TODO_TAREA:
               cambiarTodoTarea(index);
               break;
            case REGRESAR_TAREA:
                break;
            default:
                cout<<"opcion no valida"<<endl;
                break;
            }
        }else{
            cout<<"no existe ese numero de tarea"<<endl;
        }
    }else{
        cout<<"no hay Traeas por modificar"<<endl;
    }
}
void cambiarDescripcion(int index){
    string descripcion;
    checarCaracterGetLineLongitud("Dime la nueva Descripcion de la tarea: "
                                  ,descripcion,LONGITUD_DESCRIPCION,C_0);
    plan.modificarDescripcion(index,descripcion);
}
void cambiarAsunto(int index){
    string asunto;
    checarCaracterGetLineLongitud("Dime el nuevo Asunto de la tarea: "
                                  ,asunto,LONGITUD_ASUNTO,C_0);
    plan.modificarAsunto(index,asunto);
}
void cambiaAcronimoTarea(int index){
    string acronimo;
    checarCaracterGetLineLongitud("Dime el nuevo acronimo de la tarea: "
                                  ,acronimo,LONGITUD_ASUNTO,C_0);
    plan.modificarAcronimo(index,acronimo);
}
void cambiarTodoTarea(int index){
    string descripcion, asunto, acronimo;
    checarCaracterGetLineLongitud("Dime la nueva Descripcion de la tarea: "
                                  ,descripcion,LONGITUD_DESCRIPCION,C_0);
    checarCaracterGetLineLongitud("Dime el nuevo Asunto de la tarea: "
                                  ,asunto,LONGITUD_ASUNTO,C_0);
    checarCaracterGetLineLongitud("Dime el nuevo acronimo de la tarea: "
                                  ,acronimo,LONGITUD_ASUNTO,C_0);
    plan.modificarTodo(index,asunto,descripcion,acronimo);
}
void eliminarTarea(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    int indice;
    char opcion;
    cout<<"eliminacion de tareas"<<endl;
    if(!plan.estaVacio()){
        mostrarVacico();
        cout<<"indica el numero de registro del la tarea  a eliminar (1 a "
        <<plan.longitud()<<"): "<<endl;
        cin>>indice;
        indice--;
        if(plan.existeTarea(indice)){
            mostrarTareaIndex(indice);
            cout<<"estas seguro de querer eliminar la tarea (s/n)?"<<endl;
            cin.ignore();
            cin>>opcion;
            if(opcion=='s'||opcion=='S'){
                plan.suprimir(indice);
                cout<<"tarea eliminada!"<<endl;
            }
            else{
                cout<<"tarea conservada!"<<endl;
            }
        }
    }
}
void mostrarTareaIndex(int index){
        cout <<left<< setw(LONGITUD_MAXIMA_ACRONIMO+C_4)<< "Acronimo" <<""<<
        setw(LONGITUD_DESCRIPCION) << "Descripcion" <<""
        <<setw(LONGITUD_ASUNTO)<< "Asunto"<<""<<endl;
        cout <<left<< setw(LONGITUD_MAXIMA_ACRONIMO+C_4)<< plan.muestra(index)->dameAcronimo() <<""<<
        setw(LONGITUD_DESCRIPCION) << plan.muestra(index)->dameDescripcion() <<""
        <<setw(LONGITUD_ASUNTO)<< plan.muestra(index)->dameAsunto()<<endl;
}

#endif // DEBER_H_INCLUDED
