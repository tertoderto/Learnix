#ifndef ADMINISTRADORNOTA_H_INCLUDED
#define ADMINISTRADORNOTA_H_INCLUDED

#include"Blog.h"
#include<cstring>

using namespace std;
enum {AGREGAR_NOTA = C_1,LISTAR_NOTA,MOSTRAR_NOTA,MODIFICAR_NOTA
        ,ELIMINAR_NOTA,GUARDAR_NOTA,REGRESAR_DE_NOTA};
enum{TITULO=C_1,CUERPO,TODO_NOTA,REGRESAR_NOTA};
Blog blog;
void agregarNota();
void modificarNota();
void listarNota();
void mostarNota();
void mostarListaNota();
void menuEditarNota();
void eliminarNota();
void guardarArchivoNota();
void incrementarIndicadorBlog();
void eliminarNota();
void cambiarTitulo(int index);
void cambiarCuerpo(int index);
void cambiarTodo(int index);
void mostarNotaPosicion(int posicion);
void gestinaNota(){
    int opcion;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    do{
        cout<<"1.- Agregar nota"<<endl;
        cout<<"2.- Listar notas"<<endl;
        cout<<"3.- Mostrar detalles de una nota"<<endl;
        cout<<"4.- Modificar una nota"<<endl;
        cout<<"5.- Eliminar nota"<<endl;
        cout<<"6.- Guardar cambios"<<endl;
        cout<<"7.- Regresar al menu anterior"<<endl<<endl<<endl<<endl;
        cout<<"opcion:";
        limpiarBufferEntero(opcion);
        switch(opcion) {
            case AGREGAR_NOTA:
                agregarNota();
                break;
            case LISTAR_NOTA:
                listarNota();
                break;
            case MOSTRAR_NOTA:
                mostarNota();
                break;
            case MODIFICAR_NOTA:
                menuEditarNota();
                break;
            case ELIMINAR_NOTA:
                eliminarNota();
                break;
            case GUARDAR_NOTA:
                guardarArchivoNota();
                break;
            case REGRESAR_DE_NOTA:
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
        espera();
    }while(opcion != REGRESAR_DE_NOTA);
}

void agregarNota(){
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    titulo("Creacion de Nota");
    blog.incrementarIndicadorModificado();
    modificarNota();

}

void listarNota() {
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout << "Listado de Notas" << endl << endl << endl << endl << endl;

    if (!blog.estaVacio()) {
        mostarListaNota();
    } else {
        cout << "No hay Notas por listar" << endl;
    }
}
void mostarListaNota(){
    const int CUERPO_MOSTRAR = 10;
    const char* cuerpo;
    string cuerpoRecortado;
    Nota* temp;
    cout << left << setw(ANCHO_NUMERO) << "#" << "" << setw(MAX_TITULO)
         << "titulo" << "" << setw(CUERPO_MOSTRAR) << "cuerpo" << endl;
    for (int i = 0; i < blog.longitud(); i++) {
        temp = blog.mostrar(i);
        cuerpo = temp->dameCuerpo();
        if (strlen(cuerpo) <= CUERPO_MOSTRAR) {
            cuerpoRecortado = cuerpo;
        } else {
            cuerpoRecortado = string(cuerpo, CUERPO_MOSTRAR);
        }
        cout << left << setw(ANCHO_NUMERO) << (i + 1) << ""
             << setw(MAX_TITULO+C_1) << temp->dameTitulo() << ""
             << setw(CUERPO_MOSTRAR) << cuerpoRecortado << endl;
    }
}
void modificarNota(){
    char titulo[MAX_TITULO+C_3];
    char cuerpo[MAX_CUERPO+C_3];
    do{
        cout<<"Dame el titulo de la Nota:";
        cin.getline(titulo,MAX_TITULO+C_1);
        if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    }while(titulo[C_0] == '\0');
    do{
    cout<<"Dame el cuerpo de la Nota:";
    cin.getline(cuerpo,MAX_CUERPO);
    }while(cuerpo[C_0] == '\0');
    blog.agregarNota(titulo,cuerpo);
}
void mostarNota(){
    int opcion;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout << "Mostrar Notas" << endl << endl << endl << endl << endl;

    if (!blog.estaVacio()) {
        mostarListaNota();
        cout<<endl<<"dime el numero de la nota que quieres mostrar"<<endl;
        cout<<"eleccion: ";
        cin>>opcion;
        opcion--;
        if(!blog.existeNota(opcion)){
            cout<<"no exite esa Nota"<<endl;
        }else{
            mostarNotaPosicion(opcion);
        }
    } else {
        cout << "No hay Notas por mostrar" << endl;
    }
}
void mostarNotaPosicion(int posicion){
    Nota* temp;
    cout << left << setw(ANCHO_NUMERO) << "#" << "" << setw(MAX_TITULO)
         << "titulo" << " " << setw(MAX_CUERPO) << "cuerpo" << endl;
        temp = blog.mostrar(posicion);
        cout << left << setw(ANCHO_NUMERO) << (posicion + 1) << ""
             << setw(MAX_TITULO) << temp->dameTitulo() << " "
             << setw(MAX_CUERPO) << temp->dameCuerpo() << endl;
}
void menuEditarNota(){
    int index,opcion;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"modificador de Notas"<<endl<<endl<<endl<<endl<<endl;
    if(!blog.estaVacio()){
        mostarListaNota();
        cout<<endl<<"dime el numero de la nota que quieres modificar"<<endl;
        cin>>index;
        index--;
        if(blog.existeNota(index)){
            do{
                limpiar_pantalla(TIEMPO_A_ESPERAR);
                cout<<"dime que es lo que quieres modificar?"<<endl;
                cout<<"1.-Titulo"<<endl;
                cout<<"2.-Cuerpo"<<endl;
                cout<<"3.-Todo"<<endl;
                cout<<"4.-Regresar"<<endl;
                cout<<"opcion:";
                limpiarBufferEntero(opcion);
                limpiar_pantalla(TIEMPO_A_ESPERAR);
                switch(opcion){
                case TITULO:
                    cambiarTitulo(index);
                    break;
                case CUERPO:
                    cambiarCuerpo(index);
                    break;
                case TODO_NOTA:
                    cambiarTodo(index);
                    break;
                case REGRESAR_NOTA:
                    break;
                default:
                    cout<<"opcion no valida"<<endl;
                    break;
                }
            }while(opcion!=REGRESAR_NOTA);
        }
    }else{
        cout<<"no hay Notas por modificar"<<endl;
    }
}
void cambiarTitulo(int index){
    blog.ponerIndicador(index);
    char titulo[MAX_TITULO+C_3];
    do{
        cout<<"Dame el nuevo titulo de la Nota:";
        cin.getline(titulo,MAX_TITULO+C_1);
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(titulo[C_0] == '\0');
    cout<<titulo<<endl;
    blog.modificarTitulo(index,titulo);
}
void cambiarCuerpo(int index){
    blog.ponerIndicador(index);
    char cuerpo[MAX_CUERPO+C_3];
    do{
    cout<<"Dame el nuevo cuerpo de la Nota:";
    cin.getline(cuerpo,MAX_CUERPO);
    }while(cuerpo[C_0] == '\0');
    blog.modificarCuerpo(index,cuerpo);

}
void cambiarTodo(int index){
    blog.ponerIndicador(index);
    char titulo[MAX_TITULO+C_3];
    char cuerpo[MAX_CUERPO+C_3];
    do{
        cout<<"Dame el nuevo titulo de la Nota:";
        cin.getline(titulo,MAX_TITULO+C_1);
        if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    }while(titulo[C_0] == '\0');
    do{
    cout<<"Dame el nuevo cuerpo de la Nota:";
    cin.getline(cuerpo,MAX_CUERPO);
    }while(cuerpo[C_0] == '\0');
    blog.modificarTodo(index,titulo,cuerpo);
}

void eliminarNota(){
    int index;
    char opcion;
    limpiar_pantalla(TIEMPO_A_ESPERAR);
    cout<<"eliminacion de Notas"<<endl<<endl<<endl<<endl<<endl;
    if(!blog.estaVacio()){
        mostarListaNota();
        cout<<"dime el numero de la Nota a eliminar"<<endl;
        cin>>index;
        index--;
        if(blog.existeNota(index)){
            mostarNotaPosicion(index);
            cout<<"estas seguro de querer eliminar la Nota (s/n)?"<<endl;
            cin.ignore();
            cin>>opcion;
            if(opcion=='s'||opcion=='S'){
                blog.suprimir(index);
                cout<<"Nota eliminada!"<<endl;
                blog.reiniciarIndicador();
            }
            else{
                cout<<"Nota conservada!"<<endl;
            }
        }
    }
    else{
        cout<<"no hay Notas para eliminar"<<endl;
    }
}
void guardarArchivoNota(){
    cout<<"guardando..."<<endl;
    if(blog.checarModificacion()){
        blog.modificarArchivo();
    }else{

        blog.guardarArchivo();
    }
    cout<<"guardado"<<endl;
}
#endif // ADMINISTRADORNOTA_H_INCLUDED
