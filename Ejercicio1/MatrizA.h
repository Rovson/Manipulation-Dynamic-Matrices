#ifndef MATRIZA_H
#define MATRIZA_H

#include "MatrizC.h"
using namespace std;


class MatrizA : public MatrizC {
public:
    // Constructor por defecto
    MatrizA(){
        return;
    }

    // Constructor que inicializa la matriz antisimétrica pasando un único valor para dimensiones
    MatrizA(size_t dimension) : MatrizC(dimension) {
        inicializarAntisimetrica();
    }

    // Constructor de copia con verificación
    MatrizA(const MatrizC& m) : MatrizC(m) {
        if (!esAntisimetrica()) {
            hacerNula();
        }
    }

    // Operador de asignación para asignar desde MatrizC
    MatrizA operator=(MatrizC otra) {
        if (this != &otra) {
            MatrizC::operator=(otra);
            if (!esAntisimetrica()) {
                hacerNula();
            }
        }
        return *this;
    }

    // Inicializa una matriz antisimétrica
    void inicializarAntisimetrica() {
        for (size_t i = 0; i < NF; ++i) {
            for (size_t j = 0; j < i; ++j) {
                int valor = (rand() % 20) - 10;
                M[i][j] = valor;
                M[j][i] = -valor;
            }
            M[i][i] = 0; // Asegura que la diagonal sea cero
        }
    }

    // Verifica si la matriz es antisimétrica
    bool esAntisimetrica() {
        for (size_t i = 0; i < NF; ++i) {
            if (M[i][i] != 0) return false; // La diagonal debe ser cero
            for (size_t j = 0; j < i; ++j) {
                if (M[i][j] != -M[j][i]) return false;
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

#endif // MATRIZA_H
