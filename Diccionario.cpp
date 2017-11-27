
#include <iostream>
#include <sstream>
#include "Diccionario.h"


Diccionario::Diccionario() : hojas() {}

Diccionario::Diccionario( std::string ruta ) {


    std::ifstream fe;
    std::string linea;


    fe.open( ruta );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                Palabra p ( linea );
                this->hojas[ linea ] = p;
            }
        }

        fe.close();



    } else {

        throw std::string ( "El archivo no se ha podido abrir correctamente" );

    }
}


Diccionario::Diccionario(const Diccionario &orig) : hojas ( orig.hojas ) {}


//BUSCA
Palabra* Diccionario::busca ( const std::string &termino ) {

    std::map < std::string, Palabra >::iterator itt = this->hojas.find( termino );

    if ( itt == this->hojas.end() )
        return 0;

    return &itt->second;
}


void Diccionario::entrena (  std::string& palabra1, std::string& palabra2 ) {

    Palabra* p1 = this->inserta ( palabra1 );

   p1->nuevoSucesor( palabra2 );
}


std::list < std::string > Diccionario::sacaSucesoresDe(const std::string &p) {

    std::map< std::string, Palabra >::iterator itt = this->hojas.find( p );

    if ( itt == this->hojas.end() )
        throw std::string ( "La palabra no tiene sucesores porque no está en el diccionario" );

    return itt->second.sucesores();
}

Palabra* Diccionario::inserta ( const std::string& palabra ) {

    Palabra p ( palabra );

    auto itt = this->hojas.insert( std::pair < std::string, Palabra > ( palabra, p ) );


    return &itt.first->second;
}

Diccionario::~Diccionario() {}