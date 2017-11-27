
#include <queue>
#include "Palabra.h"

Palabra::Palabra () : termino ( "" ), siguientes () {}

Palabra::Palabra ( const std::string &t ) : termino ( t ), siguientes () {}

Palabra::Palabra ( const Palabra &orig ) : termino ( orig.termino ), siguientes ( orig.siguientes ) {}

//OPERATOR ==
bool Palabra::operator == ( const Palabra &orig ) {

    if ( this->termino == orig.termino )
        return true;

    return false;
}

bool Palabra::operator < ( const Palabra &orig ) {

    if ( this->termino < orig.termino )
        return true;

    return false;
}

std::string Palabra::getPalabra () {
    return this->termino;
}

void Palabra::nuevoSucesor( const std::string& termino ) {

    bool encontrado = false;
    std::list < Sucesor >::iterator it = this->siguientes.begin();

    while ( (it != this->siguientes.end()) && !encontrado  ) {

        if ( (*it).getTermino() == termino ) {

            (*it).incrementar();
            encontrado = true;
        }

        ++it;
    }

    if ( !encontrado ) {
        Sucesor s ( termino );
        this->siguientes.push_back ( s );
    }
}

std::list < std::string > Palabra::sucesores() {

    std::list<std::string> lstr;
    std::priority_queue < Sucesor > pqs;
    std::list<Sucesor>::iterator it(siguientes.begin());
    int cont = 0;

    while ( it != siguientes.end() ){

        pqs.push(*it);
        it++;
    }

    while ( !pqs.empty() && cont < 10 ){

        lstr.push_back( pqs.top().getTermino());
        pqs.pop();
        ++cont;
    }
    return lstr;
}


Palabra::~Palabra() {}