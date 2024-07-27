// MatrizP.h
#ifndef MATRIZP_H
#define MATRIZP_H

#include "Matriz.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


class MatrizP : public Matriz {
public:
    // Constructor por defecto
    MatrizP(){
        return;
    }

    // Constructor modificado que inicializa la matriz de potencia con filas y columnas especificadas
    MatrizP(size_t filas, size_t columnas) : Matriz(filas, columnas) {
        for (size_t i = 0; i < NF; ++i) {
            int base = rand() % 10; // Genera un número aleatorio entre 0 y 9 para cada fila
            for (size_t j = 0; j < NC; ++j) {
                // Calcula las potencias de base y asigna los valores a la matriz
                M[i][j] = (base == 0 && j > 0) ? 0 : pow(base, j);
            }
        }
    }

    // Constructor de copia con verificación
    MatrizP(const Matriz& m) : Matriz(m) {
        if (!esMatrizDePotencia()) {
            if (M != NULL) {
                for (size_t i = 0; i < NF; i++) {
                    delete[] M[i];
                }
                delete[] M;
            }
            NF = NC = 0;
            M = NULL;
        }
    }

    // Comprobamos si cada fila es una secuencia de potencias
    bool esMatrizDePotencia() {
        for (size_t i = 0; i < NF; ++i) {
            int base = M[i][0]; // El primer elemento de cada fila es la base
            for (size_t j = 1; j < NC; ++j) {
                if (M[i][j] != (base == 0 && j > 0 ? 0 : pow(base, j))) {
                    return false;
                }
            }
        }
        return true;
    }

};

#endif // MATRIZP_H
