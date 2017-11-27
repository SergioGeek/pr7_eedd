
#ifndef PR6_EEDD_USUARIO_H
#define PR6_EEDD_USUARIO_H

#include <string>
#include "TextoPredictivo.h"

class TextoPredictivo;

class Usuario {

private:

    std::string id;
    std::string nombre;

    TextoPredictivo* tp;
    Diccionario miDic;

public:

    Usuario ();
    Usuario ( std::string i, std::string n, TextoPredictivo* t );

    std::list < std::string > sugerencia ( const std::string& termino );
    void escribeFrase ( const std::string& frase );

};


#endif //PR6_EEDD_USUARIO_H
