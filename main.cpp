#include <iostream>
#include "Diccionario.h"
#include "TextoPredictivo.h"
#include <chrono>

int main() {

    try {

        long int i = 0;

        //long int tama = 178928;//Cuadratica
        long int tama = 130670;//Doble //79422


        auto start = std::chrono::system_clock::now();

        Diccionario d("/home/administrador/Escritorio/pr7_eedd/listado-sin-acentos_v2.txt", tama);


        auto end = std::chrono::system_clock::now();

        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        std::cout << "Time spent (ms): " << elapsed_ms << std::endl;

        i = d.tama();
        std::cout << i << std::endl;
        std::cout << d.factor() << std::endl;
        std::cout << d.nI() << std::endl;
        std::cout << tama << std::endl;
        std::cout << d.maxCol() << std::endl;


        TextoPredictivo tp(d);

        tp.nuevoUsuario("usr1", "Josito");
        tp.nuevoUsuario("usr2", "Manuela");

        Usuario *us1 = tp.getUsuario("usr1");

        us1->escribeFrase("Hola colega como andas Yo regu porque yo estoy pillado con las practicas de estructuras");

        std::list<std::string> lus1 = us1->sugerencia("yo");

        Usuario *us2 = tp.getUsuario("usr2");

        us2->escribeFrase("el whatsapp el colega el tuit el pillao ");

        std::list<std::string> lus2 = us2->sugerencia("el");

        std::list<std::string>::iterator itt = lus1.begin();

        std::cout << "De la uno: " << std::endl;
        while (itt != lus1.end()) {
            std::cout << *itt << std::endl;
            ++itt;
        }
        itt = lus2.begin();

        std::cout << "De la dos: " << std::endl;
        while (itt != lus2.end()) {
            std::cout << *itt << std::endl;
            ++itt;
        }


    } catch (std::string &e) {
        std::cout << e << std::endl;
    }
    return 0;
}