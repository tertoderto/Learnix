#ifndef NOTA_H
#define NOTA_H
#include <cstring>
#define MAX_CUERPO 70
#define MAX_TITULO 20

class Nota
{
    public:
        Nota(char* Cuerpo,char*Titulo ) {
            if(!(fijaTitulo(Titulo))){
                strcpy(titulo,"tiulo");
            }
            if(!(fijaCuerpo(Cuerpo))){
                strcpy(cuerpo,"cuerpo");
            }
        }
        virtual ~Nota() {}
    bool fijaTitulo(const char* Titulo) {
        if (strlen(Titulo) <= MAX_TITULO) {
            strcpy(titulo, Titulo);
            return true;
        } else {
            return false;
        }
    }

    const char* dameTitulo() const {
        return titulo;
    }
    bool fijaCuerpo(const char* Cuerpo) {
        if (strlen(Cuerpo) <= MAX_CUERPO) {
            strcpy(cuerpo, Cuerpo);
            return true;
        } else {
            return false;
        }
    }

    const char* dameCuerpo() const {
        return cuerpo;
    }
    protected:

    private:
    char cuerpo[MAX_CUERPO + 1];
    char titulo[MAX_TITULO + 1];
};


#endif // NOTA_H
