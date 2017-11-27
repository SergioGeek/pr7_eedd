
#ifndef PR1_PALABRA_H
#define PR1_PALABRA_H

#include <string>
#include "Sucesor.h"
#include <list>


class Palabra {

private:

    std::string termino;

    std::list < Sucesor > siguientes;


public:

    Palabra ();
    Palabra ( const std::string &t );
    Palabra ( const Palabra &orig );


    bool operator == ( const Palabra &orig );
    bool operator < ( const Palabra &orig );


    std::string getPalabra();
    void nuevoSucesor ( const std::string& termino );
    std::list < std::string > sucesores();

    virtual ~Palabra();

};

#endif //PR1_PALABRA_H
