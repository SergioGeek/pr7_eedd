
#ifndef PR7_EEDD_THASHCERRADA_H
#define PR7_EEDD_THASHCERRADA_H

#include <vector>
#include <climits>
#define intentos 10


// Funciones sobre numeros primos



template < typename  T >
class Entrada {
public:
    T dato;
    bool l1,l2;
    Entrada(): l1(true),l2(true) {};
    Entrada(const T &aDato) : dato(aDato), l2(false) {}
    ~Entrada(){};
};


template < typename T >
class THashCerrada {

private:
    unsigned long tamaf;
    unsigned long tamal;
    std::vector <Entrada<T>> tabla;
    int noInsertado;
public:

    bool esprimo(unsigned n) {
        for (unsigned i = 2; i < n; ++i)
            if (n % i == 0)
                return false;
        return true;
    }

    int primo_menor(unsigned numero) {
        int i = numero-1;
        while (!esprimo(i)) {
            --i;
        }
        return i;
    }
    THashCerrada(unsigned long tam) : tamaf(tam), tabla(tamaf, Entrada<T>()), tamal(0), noInsertado (0) {};

    //  la función de dispersión es cuadratica
    unsigned fDispersion(unsigned long clave, int i) {
        unsigned long posicionfinal;
        // mala FUNCION DE DISPERSION
        posicionfinal = (clave + (i * i)) % tamaf;
        return posicionfinal;
    }

    //  la funcion de dispersion es doble
    unsigned fDispersion2(unsigned clave, int i) {
        unsigned long posicion, posicionfinal, prelativo;

        posicion = clave % tamaf;
        prelativo = primo_menor(tamaf);       //la mejor FUNCION DE DISPERSION
        posicionfinal = (posicion + (i * (prelativo - (clave % (prelativo))))) % tamaf;
        return posicionfinal;
    }

    //funciones privadas
    bool insertar(unsigned long clave, const T &dato) {
        unsigned i = 0, y;

        bool encontrado = false;
        while (!encontrado && i < intentos) {
            y = fDispersion2(clave, i);
            if ((tabla[y].l1 && tabla[y].l2) || (!tabla[y].l1 && !tabla[y].l2)) {
                //     cout << std::endl << "Insertado2 con " << i << " intentos." << std::endl;
                Entrada <T> elem(dato);
                tabla[y] = elem;
                encontrado = true;   //Encontre un sitio libre
            } else
                ++i;   //No he dado aun con una posicion libre
        }
        if (!encontrado) {
            this->noInsertado++;
            return false;
        }
        tamal++;
        return true;
    }

    bool borrar(unsigned long clave, T &resultado) {
        unsigned i = 0, y = 0;

        bool encontrado = false;
        while (!encontrado && i < intentos) {
            y = fDispersion2(clave, i);
            if ((tabla[y].l1 && !tabla[y].l2) && tabla[y].dato == resultado) {
                //  cout << std::endl << "Borrado con " << i << " intentos." << std::endl;
                tabla[y].l1 = false;
                resultado = tabla[y].dato;
                encontrado = true;   
                tamal--;
            } else
                ++i;
        }
        return encontrado;
    }

    bool buscar(unsigned long clave, T &resultado) {
        unsigned i = 0, y = 0;

        bool encontrado = false;
        while (!encontrado && i < intentos) {
            y = fDispersion2(clave, i);
            if ((tabla[y].l1 && !tabla[y].l2) && tabla[y].dato == resultado) {


                encontrado = true;
                resultado = tabla[y].dato;
            } else
                ++i;
        }
        return encontrado;
    }

    //funciones publicas
    unsigned tamaTabla() {
        return tamal;
    }

    unsigned noInsert() {
        return this->noInsertado;
    }

    float factorCarga() {
        return (float) tamal / tamaf;
    }


    ~THashCerrada() {};

};


#endif //PR7_EEDD_THASHCERRADA_H
