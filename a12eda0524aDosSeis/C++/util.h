#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#define TIEMPO_A_ESPERAR 1000
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif
#define C_0 0
#define C_1 1
#define C_2 2
#define C_3 3
#define C_4 4
#define C_5 5
#define C_12 12
#define ANCHO_NUMERO 3
#define DELIMITADOR_REGISTRO "&"
#define DELIMITADOR_REGISTRO_TEXTO "\n"
const char DELIMITADOR_CAMPOS[] = "|";
const char ene= 164;

void limpiar_pantalla(int timepo_a_esperar);
void esperar(int timepo_a_esperar);
void espera();
void limpiarBufferEntero(int& opcion);
void titulo(string texto);
void titulo(string texto){
    cout<<texto<<endl<<endl<<endl<<endl<<endl;
}
void limpiar_pantalla(int timepo_a_esperar) {
    esperar(timepo_a_esperar);
    system(CLEAR);
}
void esperar(int timepo_a_esperar){
    this_thread::sleep_for(chrono::milliseconds(timepo_a_esperar));
}
void espera(){
    cout<<"presiona enter para continuar . . .";
    cin.ignore();
    cin.get();
    system(CLEAR);
}
void limpiarBufferEntero(int& dato){
    cin>>dato;
    cin.ignore();
}

#endif // UTIL_H_INCLUDED
