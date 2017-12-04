
#ifndef PR7_EEDD_THASHCERRADA_H
#define PR7_EEDD_THASHCERRADA_H

#include <vector>
#include <climits>
#define intentos 10


// Funciones sobre numeros primos



#include <vector>
#include <iostream>
#include <climits>
#define limite 10


template<class T>
class Entrada {
public:
    T dato;
    bool l1,l2;  //true,true(libre), true,false(ocupada), false,false(disponible)
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
    unsigned long prelativo;
    std::vector<Entrada<T> > tabla;

    //funciones privadas

    // Funciones sobre numeros primos
    inline bool esprimo(unsigned n) {
        for (unsigned i = 2; i < n/2; ++i)
            if (n % i == 0)
                return false;
        return true;
    }

    inline int primo_menor(unsigned numero) {
        int i = numero-1;
        while (!esprimo(i)) {
            --i;
        }
        return i;
    }

    //  la función de dispersión es cuadratica
    inline unsigned fDispersion(unsigned long clave, int i) {
        unsigned long posicionfinal;
        // mala FUNCION DE DISPERSION
        posicionfinal= (clave+(i*i)) % tamaf;
        return posicionfinal;
    }

    //  la funcion de dispersion es doble
    inline unsigned fDispersion2(unsigned clave, int i) {
        unsigned long posicion,posicionfinal;//,prelativo;

        posicion = clave % tamaf;
        //prelativo=tamaf-3;    // primo_menor(tamaf);       //la mejor FUNCION DE DISPERSION

        posicionfinal = (posicion + (i* (prelativo-(clave % (prelativo))))) % tamaf;
        return posicionfinal;
    }

public:

    THashCerrada(unsigned long tam=0):tamaf(tam), tabla(tamaf,Entrada<T>()), tamal(0),
                                      maxColisiones(0), sumaColisiones(0)  {
        prelativo=primo_menor(tamaf);
    };

    //clave para dispersion de cadenas
    static inline unsigned long djb2(const unsigned char *str){
        unsigned long hash = 5381;
        int c;
        while ((c = *str++))
            hash = ((hash<<5)+hash)+c;
        return hash;
    }

    bool insertar(unsigned long clave, const T& dato){
        unsigned i = 0,y;

        bool encontrado = false;
        while (!encontrado && i<limite) {
            y=fDispersion(clave, i);
            if ((tabla[y].l1 && tabla[y].l2) || (!tabla[y].l1 && !tabla[y].l2)) {

                Entrada<T> elem(dato);
                tabla[y]=elem;
                encontrado = true;   //Encontre un sitio libre
            }else
                ++i;   //No he dado aun con una posicion libre
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
            y=fDispersion2(clave, i);
            if ((tabla[y].l1 && !tabla[y].l2) && tabla[y].dato==dato){
                //  cout << std::endl << "Borrado con " << i << " intentos." << std::endl;
                tabla[y].l1=false; //lo encontre lo borro y salgo del bucle
                encontrado=true;
                tamal--;
            }else
                ++i;   //No he dado aun con su posicion
        }
        return encontrado;
    }

    T* buscar(unsigned long clave, const T &dato){
        unsigned i = 0,y=0;

        bool encontrado = false;
        while (!encontrado && i<limite) {
            y=fDispersion2(clave, i);
            if ((tabla[y].l1 && !tabla[y].l2) && tabla[y].dato==dato){

                //  cout << std::endl << "Buscado con " << i << " intentos." << std::endl;
                //encontrado=true;   //lo encontre y salgo del bucle
                return &tabla[y].dato;
            }else
                ++i;   //No he dado aun con su posicion
        }
        return 0;   //encontrado
    }

    //funciones publicas
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
