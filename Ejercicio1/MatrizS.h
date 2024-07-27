#ifndef MATRIZS_H
#define MATRIZS_H

#include "MatrizC.h"
#include <cmath>
using namespace std;


    class MatrizS : public MatrizC {

public:

    MatrizS(){
        return;
    }
    // Constructor que inicializa la matriz simétrica pasando un único valor para dimensiones
    MatrizS(size_t dimension) : MatrizC(dimension) {
        inicializarSimetrica();
    }

    // Constructor de copia con verificación
    MatrizS(const MatrizC& m) : MatrizC(m) {
        if (!esSimetrica()) {
            hacerNula();
        }
    }

    // Operador de asignación para asignar desde MatrizC
    MatrizS operator=(MatrizC otra) {
        if (this != &otra) {
            MatrizC::operator=(otra);
            if (!esSimetrica()) {
                hacerNula();
            }
        }
        return *this;
    }

    // Inicializa una matriz simétrica
    void inicializarSimetrica() {
        for (size_t i = 0; i < NF; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                int valor = (rand() % 20) - 10;
                M[i][j] = valor;
                M[j][i] = valor;  // Establece el elemento simétrico
            }
        }
    }

    // Verifica si la matriz es simétrica
    bool esSimetrica() {
        for (size_t i = 0; i < NF; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (M[i][j] != M[j][i]) return false;
            }
        }
        return true;
    }

    // Establece todos los elementos de la matriz a cero y reinicia las dimensiones
    void hacerNula() {
        for (size_t i = 0; i < NF; i++) {
            for (size_t j = 0; j < NC; j++) {
                M[i][j] = 0;
            }
        }
        NF = NC = 0;
    }
};

#endif // MATRIZS_H
