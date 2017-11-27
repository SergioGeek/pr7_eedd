
#include <iostream>
#include <sstream>
#include "Diccionario.h"


Diccionario::Diccionario() : hojas(100000) {}

Diccionario::Diccionario( std::string ruta ) : hojas(100000) {


    std::ifstream fe;
    std::string linea;


    fe.open( ruta );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                Palabra p ( linea );
                this->hojas.insertar(djb2((unsigned char*)linea.c_str()), p);
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

    Palabra p (termino);

    if (this->hojas.buscar(djb2((unsigned char*)termino.c_str()), p ))
        return &p;
    else
        return 0;
}


void Diccionario::entrena (  std::string& palabra1, std::string& palabra2 ) {

    Palabra* p1 = this->inserta ( palabra1 );

   p1->nuevoSucesor( palabra2 );
}


std::list < std::string > Diccionario::sacaSucesoresDe(const std::string &p) {

    Palabra pa(p);

    if (!this->hojas.buscar(djb2((unsigned char *) p.c_str()), pa))
        throw std::string("La palabra no tiene sucesores porque no está en el diccionario");

    return pa.sucesores();
}



Palabra* Diccionario::inserta ( const std::string& palabra ) {

    Palabra p ( palabra );

    if ( this->hojas.insertar(djb2((unsigned char*)palabra.c_str()), p ) )
        return &p;

    return 0;
}

Diccionario::~Diccionario() {}