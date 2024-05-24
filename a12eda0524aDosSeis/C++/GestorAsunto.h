#ifndef GESTORASUNTO_H
#define GESTORASUNTO_H


using namespace std;
class GestorAsunto
{
    public:
        GestorAsunto(string Asunto) {
            if(!fijaAsunto(Asunto)){
                asunto= "asunto";
            }
        }
        virtual ~GestorAsunto() {}
        bool fijaAsunto(string Asunto){
            longitud = static_cast<int>(Asunto.length());
            if(longitud<LONGITUD_ASUNTO){
                asunto = Asunto;
                return true;
            }else{
                return false;
            }
        }
        string dameAsunto(){
            return asunto;
        }

    protected:
        int longitud;
    private:
        string asunto;
        const int LONGITUD_ASUNTO = 30+2;
        bool esTamanioCorrecto(string cadena,int tamanoDefecto){
            if(static_cast<int>(cadena.length()) <= tamanoDefecto){
                return true;
            }
            return false;
        }

};

#endif // GESTORASUNTO_H
