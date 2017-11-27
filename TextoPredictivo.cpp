
#include "TextoPredictivo.h"


TextoPredictivo::TextoPredictivo( Diccionario dic ): dicBase ( dic ), usuarios () {
}

TextoPredictivo::TextoPredictivo (  TextoPredictivo& orig ) : dicBase ( orig.dicBase ), usuarios ( orig.usuarios ) {
}

std::list<std::string> TextoPredictivo::sugerencia(std::string &termino) {

    return this->dicBase.busca ( termino )->sucesores();

}

bool TextoPredictivo::entrena( std::string& termino1, std::string& termino2 ){


    Palabra* p1 = this->dicBase.busca( termino1 );

    if ( p1 ){
        
        Palabra* p2 = this->dicBase.busca( termino2 );
        
        if ( p2 ) {
            this->dicBase.entrena( termino1, termino2 );
            return true;
        }
    }
    
    return false;
}


void TextoPredictivo::nuevoUsuario ( std::string id, std::string nombre ) {

    Usuario u ( id, nombre, this );

    this->usuarios [ id ] = u;
}

Usuario* TextoPredictivo::getUsuario( std::string id ) {

    std::map < std::string, Usuario >::iterator itt = this->usuarios.find( id );

    if ( itt != this->usuarios.end() )
        return &itt->second;
    return 0;
}

TextoPredictivo::~TextoPredictivo() {
}
