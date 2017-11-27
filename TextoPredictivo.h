
#ifndef PR5_EEDD_TEXTOPREDICTIVO_H
#define PR5_EEDD_TEXTOPREDICTIVO_H


#include "Diccionario.h"
#include "Usuario.h"
#include <list>

class Usuario;

class TextoPredictivo {

private:

    Diccionario dicBase;

    std::map < std::string, Usuario > usuarios;

public:

    TextoPredictivo( Diccionario dic );
    TextoPredictivo(  TextoPredictivo& orig);

    std::list<std::string> sugerencia(std::string &termino);
    bool entrena ( std::string& termino1, std::string& termino2 );

    void nuevoUsuario ( std::string id, std::string nombre );
    Usuario* getUsuario ( std::string id );

    virtual ~TextoPredictivo();

};


#endif //PR5_EEDD_TEXTOPREDICTIVO_H
