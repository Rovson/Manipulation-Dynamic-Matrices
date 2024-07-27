#ifndef MATRIZA_H
#define MATRIZA_H

#include "MatrizC.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

template<typename T>
class MatrizA : public MatrizC<T> {
public:
    // Contructor por defecto
    MatrizA(){
        return;
    }

    // Constructor que inicializa la matriz antisimétrica pasando un único valor para dimensiones
    MatrizA(size_t dimension) : MatrizC<T>(dimension) {
        inicializarAntisimetrica();
    }

    // Constructor de copia con verificación
    MatrizA(const MatrizC<T>& m) : MatrizC<T>(m) {
        if (!esAntisimetrica()) {
            hacerNula();
        }
    }

    // Operador de asignación para asignar desde MatrizC
    MatrizA operator=(MatrizC<T> otra) {
        if (this != otra) {
            MatrizC<T>::operator=(otra);
            if (!esAntisimetrica()) {
                hacerNula();
            }
        }
        return *this;
    }

    // Inicializa una matriz antisimétrica
    void inicializarAntisimetrica() {
        for (size_t i = 0; i < this->NF; ++i) {
            for (size_t j = 0; j < i; ++j) {
                T valor = (rand()%100)/10.0; // Genera un número aleatorio entre 0 y 9 para cada fila
                this->M[i][j] = valor;
                this->M[j][i] = -valor;
            }
            this->M[i][i] = 0; // Asegura que la diagonal sea cero
        }
    }

    // Verifica si la matriz es antisimétrica
    bool esAntisimetrica() {
        for (size_t i = 0; i < this->NF; ++i) {
            if (this->M[i][i] != 0) return false; // La diagonal debe ser cero
            for (size_t j = 0; j < i; ++j) {
                if (this->M[i][j] != -this->M[j][i]) return false;
            }
        }
        return true;
    }

    // Establece todos los elementos de la matriz a cero y reinicia las dimensiones
    void hacerNula() {
        for (size_t i = 0; i < this->NF; i++) {
            for (size_t j = 0; j < this->NC; j++) {
                this->M[i][j] = 0;
            }
        }
        this->NF = this->NC = 0;
    }
};

#endif // MATRIZA_H
