

#ifndef PR1_DICCIONARIO_H
#define PR1_DICCIONARIO_H


#include "Palabra.h"
#include "THashCerrada.h"
#include <fstream>
#include <vector>
#include <map>



class Diccionario {


private:


    THashCerrada < Palabra > hojas;
    //std::map < std::string, Palabra > hojas;




public:

    unsigned long djb2(const unsigned char *str){
        unsigned long hash = 5381;
        int c;
        while ((c = *str++))
            hash = ((hash<<5)+hash)+c;
        return hash;
    }

    //Constructores
    Diccionario ();
    Diccionario ( std::string ruta, long int tamm );
    Diccionario ( const Diccionario& orig );

    //Operaciones
    Palabra* busca ( const std::string &termino );
    void entrena ( std::string& palabra1, std::string& palabra2 );
    std::list < std::string > sacaSucesoresDe ( const std::string& p );
    Palabra* inserta ( const std::string& palabra );

    unsigned tama () { return this->hojas.tamaTabla();};

    unsigned nI () { return this->hojas.getSumaColisiones();};

    float factor () { return this->hojas.factorCarga();};

    //Destructor
    virtual ~Diccionario();



};


#endif //PR1_DICCIONARIO_H
