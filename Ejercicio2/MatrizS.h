#ifndef MATRIZS_H
#define MATRIZS_H

#include "MatrizC.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

template<typename T>
class MatrizS : public MatrizC<T> {
public:
    // Constructor por defecto
    MatrizS(){
        return;
    }

    // Constructor que inicializa la matriz simétrica pasando un único valor para dimensiones
    MatrizS(size_t dimension) : MatrizC<T>(dimension) {
        inicializarSimetrica();
    }

    // Constructor de copia con verificación
    MatrizS(const MatrizC<T>& m) : MatrizC<T>(m) {
        if (!esSimetrica()) {
            hacerNula();
        }
    }

    // Operador de asignación para asignar desde MatrizC
    MatrizS operator=(MatrizC<T> otra) {
        if (this != otra) {
            MatrizC<T>::operator=(otra);  // Usa el operador de asignación de la clase base
            if (!esSimetrica()) {
                hacerNula();
            }
        }
        return *this;
    }

    // Inicializa una matriz simétrica
    void inicializarSimetrica() {
        for (size_t i = 0; i < this->NF; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                T valor = (rand()%100)/10.0; // 0-9
                this->M[i][j] = valor;
                this->M[j][i] = valor;  // Establece el elemento simétrico
            }
        }
    }

    // Verifica si la matriz es simétrica
    bool esSimetrica() {
        for (size_t i = 0; i < this->NF; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (this->M[i][j] != this->M[j][i]) return false;
            }
        }
        return true;
    }

    void hacerNula() {
        for (size_t i = 0; i < this->NF; i++) {
            for (size_t j = 0; j < this->NC; j++) {
                this->M[i][j] = 0;
            }
        }
        this->NF = this->NC = 0; // Resetear las dimensiones a 0 para reflejar que la matriz es nula
    }
};

#endif // MATRIZS_H
