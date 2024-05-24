#ifndef TDA_LISTA_ARREGLOS_H_INCLUDED
#define TDA_LISTA_ARREGLOS_H_INCLUDED

#define ELEMENTO_NO_EXISTE -1
#define ELEMENTO_POR_DEFECTO nullptr

typedef int Posicion;
template<typename tipo_elemento>
class Lista {
    tipo_elemento* elementos;
    int ultimo;
    int maxElementos;
public:
    Lista(int tamano);
    Posicion fin();
    Posicion primero();
    Posicion siguiente(Posicion p);
    Posicion anterior(Posicion p);
    bool inserta(tipo_elemento elemento,Posicion );
    bool eliminar(Posicion p);
    bool estaLlena();
    bool estaVacia();
    int dameCuentaElementos();
    tipo_elemento recupera(Posicion p);
    Posicion localiza(tipo_elemento x);
    bool mismo(tipo_elemento x,tipo_elemento y);
};






template<typename tipo_elemento>
Lista<tipo_elemento>::Lista(int tamano){
    maxElementos = tamano;
    elementos = new tipo_elemento[maxElementos];
    ultimo =-1;
}
template<typename tipo_elemento>
Posicion Lista<tipo_elemento>::fin(){
    return ultimo+1;
}
template<typename tipo_elemento>
Posicion Lista<tipo_elemento>::primero(){
    return 0;
}
template<typename tipo_elemento>
Posicion Lista<tipo_elemento>::siguiente(Posicion p){
    if(p>=0&&p<=ultimo){
        return p+1;
    }else {
        return p;
    }
}
template<typename tipo_elemento>
bool Lista<tipo_elemento>::inserta(tipo_elemento elemento,Posicion p){
    if(p>=0&&p<=ultimo+1&&p<maxElementos&&!estaLlena()){
        for (int i=++ultimo;i>p;i--){
            elementos[i]=elementos[i-1];
        }
        elementos[p]=elemento;
        return true;
    }
    else{
        return false;
    }
}
template<typename tipo_elemento>
bool Lista<tipo_elemento>::eliminar(Posicion p) {
    if (p >= 0 && p <= ultimo) {
        for (int i = p; i < ultimo; i++) {
            elementos[i] = elementos[i + 1];
        }
        ultimo--;
        return true;
    }
    return false;
}

template<typename tipo_elemento>
bool Lista<tipo_elemento>::estaLlena(){
    return ultimo == maxElementos-1;
}
template<typename tipo_elemento>
bool Lista<tipo_elemento>::estaVacia(){
    return ultimo == -1;
}
template<typename tipo_elemento>
int Lista<tipo_elemento>::dameCuentaElementos(){
    return ultimo+1;
}
template<typename tipo_elemento>
tipo_elemento Lista<tipo_elemento>::recupera(Posicion p){
    if (p>=0&&p<=ultimo){
        return elementos[p];
    }else{
        tipo_elemento Error = ELEMENTO_POR_DEFECTO;
        return Error;
    }
}
template<typename tipo_elemento>
Posicion Lista<tipo_elemento>::localiza(tipo_elemento x){
    Posicion p,q;
    for(p=primero(),q=fin();p!=q;p=siguiente(p)){
        if(mismo(x,elementos[p])){
            break;
        }
    }
    return p;
}
template<typename tipo_elemento>
Posicion Lista<tipo_elemento>::anterior(Posicion p){
    if(p>0&&p>=ultimo){
        return p-1;
    }else{
        return p;
    }
}









template<typename tipo_elemento>
bool Lista<tipo_elemento>::mismo(tipo_elemento x,tipo_elemento y){
    return x<=y&&x>=y;
}

#endif // TDA_LISTA_ARREGLOS_H_INCLUDED
