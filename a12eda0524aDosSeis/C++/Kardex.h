#ifndef KARDEX_H
#define KARDEX_H

#include "Curso.h"
#include"Materia.h"
#include"util.h"

#define ARCHIVO_MATERIA "Materia.txt"
#define APROVACION_MNUSCULA 's'
#define APROVACION_MAYUSCULA 'S'
#define ANCHO_DIA 5
#define ANCHO_HORA 4
#define ANCHO_PROFESOR 40
#define ANCHO_NOMBRE 40
#define ANCHO_ACRONIMO 10
#define NUMERO_CAMPOS 5
#define NUMERO_MATERIA 5
#define LONGITUD_NOMBRE 30

enum {AGREGAR_MATERIA = C_1,LISTAR_MATERIA,MOSTRAR_MATERIA,MODIFICAR_MATERIA
        ,ELIMINAR_MATERIA,GUARDAR_MATERIA,REGRESAR_DE_MATERIA};
enum{NOMBRE = C_1,PROFESOR,ACRONIMO,DIA,HORA_INICIO,HORA_FINAL,TODO,REGRESAR};

Curso curso;
using namespace std;

Materia* elegirMateria();
void gestionarMateria();
void agregarMateria();
void listarMateria();
void verSiEvaluar();
void mostrarMateria();
void mostrarVacicoMateria();
void eliminarMateria();
void mostrarMateriaIndex(int index);
void checarCaracterGetLine(string texto,string& dato);
void checarCaracter(string texto,string& dato);
void menuEditarMateria();
void cambiarNombre(int index);
void cambiaAcronimo(int index);
void cambiarProfesor(int index);
void cambioDia(int index);
void cambiaHoraFinal(int index);
void cambiaHoraInicio(int index);
void modificarTodo(int index);

void gestionarMateria(){
    int opcion;
    do{
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        cout << "1. Agregar materia" << endl;
        cout << "2. Listar materias" << endl;
        cout << "3. Mostrar detalles de una materia" << endl;
        cout << "4. Modificar una materia" << endl;
        cout << "5. Eliminar materia" << endl;
        cout << "6. Guardar cambios" << endl;
        cout << "7. Regresar al menu anterior." << endl<< endl<< endl<< endl<< endl;
        cout << "opcion:" ;
        limpiarBufferEntero(opcion);
        switch(opcion) {
            case AGREGAR_MATERIA:
                agregarMateria();
                break;
            case LISTAR_MATERIA:
                listarMateria();
                break;
            case MOSTRAR_MATERIA:
                mostrarMateria();
                break;
            case MODIFICAR_MATERIA:
                menuEditarMateria();
                break;
            case ELIMINAR_MATERIA:
                eliminarMateria();
                break;
            case GUARDAR_MATERIA:
                curso.guardarArchivoMateria();
                break;
            case REGRESAR_DE_MATERIA:
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
        espera();
    }while(opcion != REGRESAR_DE_MATERIA);
}
void agregarMateria(){
    string nombre,acronimo,profesor,dia;
    int horaInicio,horaFinal;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"creando materia"<<endl<<endl<<endl;
    if(curso.estaLleno()){
        cout<<"maximo de Materias alcansado"<<endl;
    }else{
        checarCaracterGetLine("dime el nombre de la materia: ",nombre);
        checarCaracter("dime el acronimo de la materia: ",acronimo);
        checarCaracter("dime los dias que se imparte la materia: ",dia);
        cin.ignore();
        checarCaracterGetLine("dime el nombre del profesor de la materia: ",profesor);
        cout<<"dime su hora de inicio: ";
        cin>>horaInicio;
        cout<<"dime su hora de salida: ";
        cin>>horaFinal;
        curso.agregarMateria(acronimo,nombre,profesor,dia,horaInicio,horaFinal);
    }
}
void checarCaracter(string texto,string& dato){
    size_t caracterEncontardo,segundocaracterEncontardo;
    bool encontrado,encontradoDos;
    do{
    cout<<texto;
    cin>>dato;
    caracterEncontardo= dato.find(DELIMITADOR_CAMPOS);
    segundocaracterEncontardo= dato.find(DELIMITADOR_REGISTRO);
    encontrado = caracterEncontardo!= std::string::npos;
    encontradoDos = segundocaracterEncontardo != std::string::npos;
    }while(encontrado||encontradoDos);
}
void checarCaracterGetLine(string texto,string& dato){
    size_t caracterEncontardo,segundocaracterEncontardo;
    bool encontrado,encontradoDos;
    do{
    cout<<texto;
    getline(cin,dato);
    caracterEncontardo= dato.find(DELIMITADOR_CAMPOS);
    segundocaracterEncontardo= dato.find(DELIMITADOR_REGISTRO);
    encontrado = caracterEncontardo!= std::string::npos;
    encontradoDos = segundocaracterEncontardo != std::string::npos;
    }while(encontrado||encontradoDos);
}
void menuEditarMateria(){
    int opcion,index;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"modificador de materias"<<endl<<endl<<endl<<endl<<endl;
    if(!curso.estaVacio()){
        mostrarVacicoMateria();
        cout<<"dime el numero de la materia a Modificar : "<<endl;
        cin>>index;
        index--;
        if(curso.existeMateria(index)){
            limpiar_pantalla(TIEMPO_A_ESPERAR);
            cout<<"Que queires modificar?"<<endl;
            cout<<"1.- Nombre de la materia"<<endl;
            cout<<"2.- Profesor de la materia"<<endl;
            cout<<"3.- Acronimo de la materia"<<endl;
            cout<<"4.- Dias que se imparte"<<endl;
            cout<<"5.- Hora de Inicio"<<endl;
            cout<<"6.- Hora de salida "<<endl;
            cout<<"7.- Todo"<<endl;
            cout<<"8.- Regresar"<<endl;
            limpiarBufferEntero(opcion);
            switch(opcion){
            case NOMBRE:
                cambiarNombre(index);
                break;
            case PROFESOR:
                cambiarProfesor(index);
                break;
            case ACRONIMO:
                cambiaAcronimo(index);
                break;
            case DIA:
                cambioDia(index);
                break;
            case HORA_INICIO:
                cambiaHoraInicio(index);
                break;
            case HORA_FINAL:
                cambiaHoraFinal(index);
                break;
            case TODO:
                modificarTodo(index);
                break;
            case REGRESAR:
                break;
            default:
                cout<<"opcion no valida"<<endl;
                break;
            }
        }
    }
}
void cambiarNombre(int index){
    string nombre;
    checarCaracterGetLine("dame el nuevo nombre: ",nombre);
    curso.modificarNombre(index,nombre);
}
void cambiarProfesor(int index){
    string profesor;
    checarCaracterGetLine("dame el nuevo profesor: ",profesor);
    curso.modificarProfesor(index,profesor);
}
void cambiaAcronimo(int index){
    string Acronimo;
    checarCaracter("dame el nuevo acronimo: ",Acronimo);
    curso.modificarAcronimo(index,Acronimo);
}
void cambioDia(int index){
    string dia;
    checarCaracter("dame el nuevo dia: ",dia);
    curso.modificarDia(index,dia);
}
void cambiaHoraInicio(int index){
    int Hora;
    cout<<"dime la nueva Hora inicail: ";
    cin>>Hora;
    curso.modificarHoraInicio(index,Hora);
}
void cambiaHoraFinal(int index){
    int Hora;
    cout<<"dime la nueva Hora de salida: ";
    cin>>Hora;
    curso.modificarHoraFinal(index,Hora);
}
void modificarTodo(int index){
    string nombre,acronimo,profesor,dia;
    int horaInicio,horaFinal;
    checarCaracterGetLine("dime el nombre de la materia: ",nombre);
        checarCaracter("dime el acronimo de la materia: ",acronimo);
        checarCaracter("dime los dias que se imparte la materia: ",dia);
        cin.ignore();
        checarCaracterGetLine("dime el nombre del profesor de la materia: ",profesor);
        cout<<"dime su hora de inicio: ";
        cin>>horaInicio;
        cout<<"dime su hora de salida: ";
        cin>>horaFinal;
    curso.modificarTodo(index,acronimo,nombre,profesor,dia,horaInicio,horaFinal);
}
void listarMateria(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"listado de materias"<<endl<<endl<<endl<<endl<<endl;
    if(!curso.estaVacio()){
        mostrarVacicoMateria();
    }else{
        cout<<"no hay materias por mostrar"<<endl;
    }
}
void mostrarVacicoMateria(){
    int i;
    cout <<left<<setw(ANCHO_NUMERO)<< "#" <<""<< setw(ANCHO_ACRONIMO)
    << "Acronimo" <<""<< setw(ANCHO_NOMBRE) << "Nombre" << endl;
    for(i=C_0;i<curso.longitud();i++){
        cout <<left<<setw(ANCHO_NUMERO)<< (i+C_1)<<""
        << setw(ANCHO_ACRONIMO) << curso.muestra(i)->dameAcronimo()<<""
        << setw(ANCHO_NOMBRE) << curso.muestra(i)->dameNombre() << endl;
    }
}
void mostrarMateria(){
    int numMateria;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"mostrar materia"<<endl<<endl<<endl<<endl<<endl;
    if(!curso.estaVacio()){
        mostrarVacicoMateria();
        cout<<"dime el numero de la materia que quieres ver(1 a "<<curso.longitud()<<"): "<<endl;
        cin>>numMateria;
        numMateria--;
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        if(curso.existeMateria(numMateria)){
            cout <<left<< setw(ANCHO_ACRONIMO)<< "Acronimo" <<""<<
            setw(ANCHO_NOMBRE) << "Nombre" <<""<<setw(ANCHO_PROFESOR)<< "Profesor"<<""<<
            setw(ANCHO_DIA)<<"Dias"<<""<<setw(ANCHO_HORA)<<"hora"<<""<<endl;
            cout <<left<< setw(ANCHO_ACRONIMO)<< curso.muestra(numMateria)->dameAcronimo() <<""<<
            setw(ANCHO_NOMBRE) << curso.muestra(numMateria)->dameNombre() <<""
            <<setw(ANCHO_PROFESOR)<< curso.muestra(numMateria)->dameProfesor()
            <<""<<setw(ANCHO_DIA)<< curso.muestra(numMateria)->dameDia()<<""
            <<curso.muestra(numMateria)->dameHoraInicio()
            <<"a"<<curso.muestra(numMateria)->dameHoraFinal()<<endl;
        }
    }else{
        cout<<"no hay materias por mostrar"<<endl;
    }
}
Materia* elegirMateria() {
    int opcion;
    if (!curso.estaVacio()) {
        limpiar_pantalla(TIEMPO_A_ESPERAR);
        cout << "Elige una de las siguientes materias:" << endl;
        mostrarVacicoMateria();
        cout << endl << "Ingresa el numero de la materia: ";
        limpiarBufferEntero(opcion);
        opcion--;
        if (curso.existeMateria(opcion)) {
            return curso.muestra(opcion);
        } else {
            cout<<"Opcion invalida. Debes elegir un numero entre 1 y "<<curso.longitud()<<"."<<endl;
            return nullptr;
        }
    } else {
        cout << "No hay materias disponibles." << endl;
        return nullptr;
    }
}

void verSiEvaluar(){
    Materia* materiaElegida;
    materiaElegida = elegirMateria();
    if(materiaElegida!= nullptr){
        evaluarCurso(*materiaElegida);
    }
}
void eliminarMateria(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    int indice;
    char opcion;
    cout<<"eliminacion de Materias"<<endl;
    if(!curso.estaVacio()){
        mostrarVacicoMateria();
        cout<<"indica el numero de registro del la Materia  a eliminar (1 a "
        <<curso.longitud()<<"): "<<endl;
        cin>>indice;
        indice--;
        if(curso.existeMateria(indice)){
            mostrarMateriaIndex(indice);
            cout<<"estas seguro de querer eliminar la Materia (s/n)?"<<endl;
            cin.ignore();
            cin>>opcion;
            if(opcion=='s'||opcion=='S'){
                curso.suprimir(indice);
                cout<<"Materia eliminada!"<<endl;
            }
            else{
                cout<<"Materia conservada!"<<endl;
            }
        }
    }
}
void mostrarMateriaIndex(int index){
        cout <<left<< setw(ANCHO_ACRONIMO)<< "Acronimo" <<""<<
        setw(ANCHO_NOMBRE) << "Nombre" <<""<<setw(ANCHO_PROFESOR)<< "Profesor"<<""<<
        setw(ANCHO_DIA)<<"Dias"<<""<<setw(ANCHO_HORA)<<"hora"<<""<<endl;
        cout <<left<< setw(ANCHO_ACRONIMO)<< curso.muestra(index)->dameAcronimo() <<""<<
        setw(ANCHO_NOMBRE) << curso.muestra(index)->dameNombre() <<""
        <<setw(ANCHO_PROFESOR)<< curso.muestra(index)->dameProfesor()
        <<""<<setw(ANCHO_DIA)<<curso.muestra(index)->dameDia()<<""
        <<curso.muestra(index)->dameHoraInicio()
        <<"a"<<curso.muestra(index)->dameHoraFinal()<<endl;
}



#endif // KARDEX_H
