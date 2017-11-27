#include <iostream>
#include "Diccionario.h"

int main() {


    Diccionario d ( "/home/anonymous/Documents/eedd_practice/pr7_eedd/listado-sin-acentos_v2.txt");

    std::cout << d.tama() << std::endl;
    std::cout << d.factor() << std::endl;
    std::cout << d.nI()<< std::endl;


    return 0;
}