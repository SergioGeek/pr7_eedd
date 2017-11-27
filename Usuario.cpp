
#include <sstream>
#include "Usuario.h"

Usuario::Usuario() : id ( "" ), nombre ( "" ), tp ( 0 ), miDic() {}

Usuario::Usuario(std::string i, std::string n, TextoPredictivo* t) : id ( i ), nombre ( n ), tp ( t ), miDic() {}


std::list < std::string > Usuario::sugerencia ( const std::string& termino ) {

    return this->miDic.busca ( termino )->sucesores();
}

void Usuario::escribeFrase ( const std::string &frase ) {
    
    std::string palabra1 = "", palabra2 = "";
    std::stringstream ss;
    std::map < std::string, Palabra >::iterator pos;
    std::pair < std::map < std::string, Palabra >::iterator, bool > insertado;
    ss << frase;	//enviamos la cadena al stream
    ss >> palabra1;
    while (!ss.eof()) {
        ss >> palabra2;	//leemos la siguiente palabra
        if (palabra1 != "" && palabra2 != "") {

            if ( !this->tp->entrena( palabra1, palabra2 ) )
                this->miDic.entrena( palabra1, palabra2 );
        }
        
        palabra1 = palabra2;
    }
}