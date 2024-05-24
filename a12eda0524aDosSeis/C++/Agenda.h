#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include <iomanip>
#include "util.h"
#include "Itinerario.h"

#define CANT_RECORDATORIO  3
#define LONGITUD_FECHA 10
#define LONGITUD_TIPO_RECORDATORIO 5
#define LONGITUD_DIA 2
#define LONGITUD_MES 2
#define LONGITUD_ANIO 4
#define NUMERO_CAMPOS_RECORDATORIO 6

enum {AGREGAR_RECORDATORIO = C_1,LISTAR_RECORDATORIO ,MOSTRAR_RECORDATORIO ,MODIFICAR_RECORDATORIO
        ,ELIMINAR_RECORDATORIO ,GUARDAR_RECORDATORIO ,REGRESAR_DE_RECORDATORIO };
enum{FECHA = C_1,ASUNTO_RECORDATORIO,HORA,TIPO,TODO_RECORDATORIO,REGRESAR_RECORDATORIO};

Itinerario lista;

void checarCaracterRecordatorio(string texto,char* atributo,int maximo);
void menuEditarRecordatorio();
void agregarRecordatorio();
void modificarRecordatorio();
void listarRecordatorio();
void mostrarRecordatorio();
void mostarVacico();
void eliminarRecordatorio();
void mostrarRecordatorioIndex(int index);
void cambiarHora(int index);
void cambiarAsuntoRecordatorio(int index);
void cambiarFecha(int index);
void cambiarTipo(int index);
void cambiarTodoRecordatorio(int inedex);
void checarFechaValida(string texto,Fecha* fecha);
void guardarArcivoEleccion();

void gestionarAgenda(){
    int opcion;
    do{
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        cout << "1. Agregar recordatorio" << endl;
        cout << "2. Listar recordatorios" << endl;
        cout << "3. Mostrar detalles de un recordatorio" << endl;
        cout << "4. Modificar un recordatorio" << endl;
        cout << "5. Eliminar recordatorio" << endl;
        cout << "6. Guardar cambios" << endl;
        cout << "7. Regresar al menu anterior." << endl<< endl<< endl<< endl<< endl;
        cout << "opcion:" ;
        limpiarBufferEntero(opcion);
        switch(opcion) {
            case AGREGAR_RECORDATORIO:
                agregarRecordatorio();
                break;
            case LISTAR_RECORDATORIO:
                listarRecordatorio();
                break;
            case MOSTRAR_RECORDATORIO:
                mostrarRecordatorio();
                break;
            case MODIFICAR_RECORDATORIO:
                menuEditarRecordatorio();
                break;
            case ELIMINAR_RECORDATORIO:
                eliminarRecordatorio();
                break;
            case GUARDAR_RECORDATORIO:
                guardarArcivoEleccion();
                break;
            case REGRESAR_DE_RECORDATORIO:
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
        espera();
    }while(opcion != REGRESAR_DE_RECORDATORIO );

}
void agregarRecordatorio(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    titulo("Creacion de recordatorio");
    lista.incrementarLista();
    modificarRecordatorio();
}
void modificarRecordatorio(){
    char asunto[LONGITUD_ASUNTO_RECORDATORIO+C_1];
    char hora[LONGITUD_HORA+C_1];
    char tipo;
    Fecha* fecha = new Fecha();
    checarCaracterRecordatorio("Dime el asunto del recordatorio: ",
                               asunto,LONGITUD_ASUNTO_RECORDATORIO);
    checarFechaValida("Dime la Fecha de la recordatorio ",fecha);
    checarCaracterRecordatorio("dame la hora de la reunion: ",hora,LONGITUD_HORA);
    cout<<"dame el tipo de Recordatorio: ";
    cin>>tipo;
    cin.ignore();
    lista.agregarRecordatorio(tipo,hora,asunto,fecha);
}
void checarCaracterRecordatorio(string texto,char* atributo,int maximo){
    do{
        cout<<texto;
        cin.getline(atributo,maximo+C_1);
        if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    }while(atributo[C_0] == '\0');
}
void checarFechaValida(string texto,Fecha* fecha){
    int anio,dia,mes;
    cout<<texto<<endl;
    do{
    cout<<"dame el a"<<ene<<"o del recordatorio: ";
    cin>>anio;
    cout<<"dame el mes del recordatorio: ";
    cin>>mes;
    cout<<"dame el dia del recordatorio: ";
    limpiarBufferEntero(dia);
    }while(!fecha->esFechaValida(anio,mes,dia));
    fecha->fijaAnio(anio);
    fecha->fijaMes(mes);
    fecha->fijaDia(dia);
}
void listarRecordatorio(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"listado de recordatorios"<<endl<<endl<<endl<<endl<<endl;
    if(!lista.estaVacio()){
        mostarVacico();
    }else{
        cout<<"no hay recordatorios por mostrar"<<endl;
    }
}
void mostarVacico(){
    cout <<left<<setw(ANCHO_NUMERO)<< "#" <<""<< setw(LONGITUD_FECHA)
    << "fecha" <<""<< setw(LONGITUD_TIPO_RECORDATORIO) << " tipo" << endl;
    for(int i=C_0;i<lista.longitud();i++){
        cout <<left<<setw(ANCHO_NUMERO)<< (i+C_1)<<""
        <<setw(LONGITUD_DIA) << lista.mostrar(i)->dameFecha()->dameDia()<<"/"
        <<setw(LONGITUD_MES) << lista.mostrar(i)->dameFecha()->dameMes()<<"/"
        <<setw(LONGITUD_ANIO) << lista.mostrar(i)->dameFecha()->dameAnio()<<" "
        << setw(LONGITUD_TIPO_RECORDATORIO) << lista.mostrar(i)->dameTipo() << endl;
    }
}
void mostrarRecordatorio(){
    int numRecordatorio;
    if(!lista.estaVacio()){
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        cout<<"mostrar recordatorios"<<endl<<endl<<endl<<endl<<endl;
        mostarVacico();
        cout<<"dime el numero del recordatorio que quieres ver(1 a "<<lista.longitud()<<"): "<<endl;
        cin>>numRecordatorio;
        numRecordatorio--;
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        cout <<left<< setw(LONGITUD_ASUNTO_RECORDATORIO)<< "Asunto" <<""<<
        setw(LONGITUD_TIPO_RECORDATORIO-1) << "Tipo" <<""<<setw(LONGITUD_HORA)<< "Hora"<<" "<<
        setw(LONGITUD_FECHA)<<"Fecha"<<endl;
        cout << left << setw(LONGITUD_ASUNTO_RECORDATORIO)
        << lista.mostrar(numRecordatorio)->dameAsunto() <<"" << setw(LONGITUD_TIPO_RECORDATORIO-1)
        << lista.mostrar(numRecordatorio)->dameTipo() << "" <<setw(LONGITUD_HORA)
        << lista.mostrar(numRecordatorio)->dameHora() << " "
        << setw(LONGITUD_DIA) << lista.mostrar(numRecordatorio)->dameFecha()->dameDia() << "/"
        << setw(LONGITUD_MES) << lista.mostrar(numRecordatorio)->dameFecha()->dameMes() << "/"
        << setw(LONGITUD_ANIO) << lista.mostrar(numRecordatorio)->dameFecha()->dameAnio() <<endl;
    }else{
        cout<<"no hay recordatorios por mostrar"<<endl;
    }
}
void menuEditarRecordatorio(){
    int opcion,index;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"modificador de recordatorios"<<endl<<endl<<endl<<endl<<endl;
    if(!lista.estaVacio()){
        mostarVacico();
        cout<<"dime el numero del recordatorios a modificar: "<<endl;
        cin>>index;
        index--;
        if(lista.existeRecordatorio(index)){
            limpiar_pantalla(TIEMPO_A_ESPERAR);
            cout<<"Que queires modificar?"<<endl;
            cout<<"1.- fecha del recordatorio"<<endl;
            cout<<"2.- Asunto del Recordatorio"<<endl;
            cout<<"3.- Hora del recordatorio"<<endl;
            cout<<"4.- tipo de recordatorio"<<endl;
            cout<<"5.- Todo "<<endl;
            cout<<"6.- Regresar"<<endl;
            limpiarBufferEntero(opcion);
            switch(opcion){
            case FECHA:
                cambiarFecha(index);
                break;
            case ASUNTO_RECORDATORIO:
                cambiarAsuntoRecordatorio(index);
                break;
            case HORA:
                cambiarHora(index);
                break;
            case TIPO:
                cambiarTipo(index);
                break;
            case TODO_RECORDATORIO:
                cambiarTodoRecordatorio(index);
                break;
            case REGRESAR_RECORDATORIO:
                break;
            default:
                cout<<"opcion no valida"<<endl;
                break;
            }
        }else{
            cout<<"ese recordatorio no existe"<<endl;
        }
    }else{
        cout<<"no hat recordatorios por editar"<<endl;
    }
}
void cambiarHora(int index){
    char hora[LONGITUD_HORA+C_1];
    checarCaracterRecordatorio("Dime la nueva Hora del Recordatorio: "
                                  ,hora,LONGITUD_HORA);
    lista.cambiarHora(index,hora);
}
void cambiarAsuntoRecordatorio(int index){
    char asunto[LONGITUD_ASUNTO_RECORDATORIO+C_1];
    checarCaracterRecordatorio("Dime el nuevo Asunto de la tarea: "
                                  ,asunto,LONGITUD_ASUNTO_RECORDATORIO);
    lista.cambiarAsunto(index,asunto);
}
void cambiarFecha(int index){
    Fecha* fecha = new Fecha;
    checarFechaValida("Dime la nueva Fecha de la recordatorio ",fecha);
    lista.cambiarFecha(index,fecha);
}
void cambiarTipo(int index){
    char tipo;
    cout<<"dame el tipo de Recordatorio: ";
    cin>>tipo;
    cin.ignore();
    lista.cambiarTipo(index,tipo);
}
void cambiarTodoRecordatorio(int index){
    char asunto[LONGITUD_ASUNTO_RECORDATORIO+C_1];
    char hora[LONGITUD_HORA+C_1];
    char tipo;
    Fecha* fecha = new Fecha();
    checarCaracterRecordatorio("Dime el asunto del recordatorio: ",
                               asunto,LONGITUD_ASUNTO_RECORDATORIO);
    checarFechaValida("Dime la Fecha de la recordatorio ",fecha);
    checarCaracterRecordatorio("dame la hora de la reunion: ",hora,LONGITUD_HORA);
    cout<<"dame el tipo de Recordatorio: ";
    cin>>tipo;
    cin.ignore();
    lista.cambiarTodo(index,tipo,hora,asunto,fecha);
}
void eliminarRecordatorio(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    int indice;
    char opcion;
    cout<<"eliminacion de recordatorio"<<endl;
    if(!lista.estaVacio()){
        mostarVacico();
        cout<<"indica el numero de registro del recordatorio  a eliminar (1 a "
        <<lista.longitud()<<"): "<<endl;
        cin>>indice;
        indice--;
        if(lista.existeRecordatorio(indice)){
            mostrarRecordatorioIndex(indice);
            cout<<"estas seguro de querer eliminar el recordatorio (s/n)?"<<endl;
            cin.ignore();
            cin>>opcion;
            if(opcion=='s'||opcion=='S'){
                lista.suprimir(indice);
                cout<<"recordatorio eliminado!"<<endl;
                lista.reiniciarIndicador();
            }
            else{
                cout<<"recordatorio conservado!"<<endl;
            }
        }
    }
}
void mostrarRecordatorioIndex(int index){
        cout <<left<< setw(LONGITUD_ASUNTO_RECORDATORIO)<< "Asunto" <<""<<
        setw(LONGITUD_TIPO_RECORDATORIO-1) << "Tipo" <<""<<setw(LONGITUD_HORA)<< "Hora"<< " "<<
        setw(LONGITUD_FECHA)<<"Fecha"<<endl;
        cout << left << setw(LONGITUD_ASUNTO_RECORDATORIO)
        << lista.mostrar(index)->dameAsunto() <<"" << setw(LONGITUD_TIPO_RECORDATORIO-1)
        << lista.mostrar(index)->dameTipo() << "" <<setw(LONGITUD_HORA)
        << lista.mostrar(index)->dameHora() << " "
        << setw(LONGITUD_DIA) << lista.mostrar(index)->dameFecha()->dameDia() << "/"
        << setw(LONGITUD_MES) << lista.mostrar(index)->dameFecha()->dameMes() << "/"
        << setw(LONGITUD_ANIO) << lista.mostrar(index)->dameFecha()->dameAnio() <<endl;
}


void guardarArcivoEleccion(){
    cout<<"guardando..."<<endl;
    if(lista.checarModificacion()){
        lista.guardarModificacion();
    }else{
        lista.guardarArchivoRecordatorio();
    }
    cout<<"guardado"<<endl;
}







#endif // AGENDA_H_INCLUDED
