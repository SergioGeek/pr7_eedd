
#ifndef PR7_EEDD_THASHCERRADA_H
#define PR7_EEDD_THASHCERRADA_H


#include <vector>
#include <iostream>
#include <climits>
#define limite 14


template<class T>
class Entrada {
public:
    T dato;
    bool l1,l2;
    Entrada(): l1(true),l2(true) {};
    Entrada(const T &aDato) : dato(aDato), l1(true), l2(false) {}
    ~Entrada(){};
};

template<typename T>
class THashCerrada {
private:
    unsigned long tamaf;
    unsigned long tamal;
    unsigned char maxColisiones;
    unsigned long sumaColisiones;
    unsigned long primoRelativo;
    std::vector<Entrada<T> > tabla;

    inline bool primo(unsigned n) {
        for (unsigned i = 2; i < n/2; ++i)
            if (n % i == 0)
                return false;
        return true;
    }

    inline int primoMenor(unsigned numero) {
        int i = numero-1;
        while (!primo(i)) {
            --i;
        }
        return i;
    }

    /*
    inline unsigned DispersionCuadr(unsigned long clave, int i) {
        unsigned long posicionfinal;

        posicionfinal= (clave+(i*i)) % tamaf;
        return posicionfinal;
    }
     */

    inline unsigned DispersionDoble(unsigned clave, int i) {
        unsigned long posicion,posicionfinal;

        posicion = clave % tamaf;

        posicionfinal = (posicion + (i* (primoRelativo-(clave % (primoRelativo))))) % tamaf;
        return posicionfinal;
    }

public:

    THashCerrada(unsigned long tam=0):tamaf(tam), tabla(tamaf,Entrada<T>()), tamal(0),
                                      maxColisiones(0), sumaColisiones(0) {
        primoRelativo = primoMenor(tamaf);
    };


    bool insertar(unsigned long clave, const T& dato){

        if ( this->buscar(clave, dato ) )
            return false;

        unsigned int i = 0;
        unsigned int y;

        bool encontrado = false;
        while (!encontrado && i <= limite) {
            y= DispersionDoble(clave, i);
            if ((tabla[y].l1 && tabla[y].l2) || (!tabla[y].l1 && !tabla[y].l2)) {

                Entrada<T> elem(dato);
                tabla[y]=elem;
                encontrado = true;
            }else
                ++i;
        }
        if (!encontrado){
            return false;
        }
        if (i>maxColisiones){
            maxColisiones=i;
        }
        sumaColisiones+=i;
        tamal++;
        return true;
    }

    bool borrar(unsigned long clave, const T &dato){
        unsigned i = 0,y=0;

        bool encontrado = false;
        while (!encontrado && i<limite) {
            y= DispersionDoble(clave, i);
            if ((tabla[y].l1 && !tabla[y].l2) && tabla[y].dato==dato){

                tabla[y].l1=false;
                encontrado=true;
                tamal--;
            }else
                ++i;
        }
        return encontrado;
    }

    T* buscar(unsigned long clave, const T &dato){
        unsigned i = 0,y=0;

        bool encontrado = false;
        while (!encontrado && i<limite) {
            y= DispersionDoble(clave, i);
            if ((tabla[y].l1 && !tabla[y].l2) && tabla[y].dato==dato){

                return &tabla[y].dato;
            }else
                ++i;
        }
        return 0;
    }

    unsigned tamaTabla(){
        return tamal;
    }
    float factorCarga(){
        return (float)tamal/tamaf;
    }

    ~THashCerrada(){}

    unsigned long getSumaColisiones() const {
        return sumaColisiones;
    }

    unsigned char getMaxColisiones() const {
        return maxColisiones;
    };


};

#endif //PR7_EEDD_THASHCERRADA_H
