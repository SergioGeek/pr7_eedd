

#ifndef PR1_DICCIONARIO_H
#define PR1_DICCIONARIO_H


#include "Palabra.h"
#include <fstream>
#include <vector>
#include <map>


class Diccionario {


private:


    std::map < std::string, Palabra > hojas;




public:

    //Constructores
    Diccionario ();
    Diccionario ( std::string ruta );
    Diccionario ( const Diccionario& orig );

    //Operaciones
    Palabra* busca ( const std::string &termino );
    void entrena ( std::string& palabra1, std::string& palabra2 );
    std::list < std::string > sacaSucesoresDe ( const std::string& p );
    Palabra* inserta ( const std::string& palabra );

    //Destructor
    virtual ~Diccionario();



};


#endif //PR1_DICCIONARIO_H
