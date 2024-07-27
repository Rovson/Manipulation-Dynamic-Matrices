
#ifndef MATRIZP_H
#define MATRIZP_H

#include "Matriz.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

template<typename T>
class MatrizP : public Matriz<T> {
public:
    // Contructor por defecto
    MatrizP(){
        return;
    }
    // Constructor que inicializa la matriz de potencia con filas y columnas especificadas
    MatrizP(size_t filas, size_t columnas) : Matriz<T>(filas, columnas) {


        for (size_t i = 0; i < this->NF; ++i) {
            // El primer elemento siempre es 1, asumimos que cualquier T puede inicializarse así
            this->M[i][0] = T(1);

            // Si sólo hay una columna, saltar el resto de la inicialización
            if (this->NC < 2) continue;

            double base = (rand() % 100) / 10.0; // Base aleatoria entre 0.0 y 9.9

            if constexpr (is_floating_point<T>::value || is_integral<T>::value) {
                // Para tipos primitivos numéricos, calcular potencias
                this->M[i][1] = T(base);
                for (size_t j = 2; j < this->NC; ++j) {
                    this->M[i][j] = static_cast<T>(pow(base, static_cast<double>(j)));
                }
            } else if constexpr (is_same<T, Capicua>::value) {
                // Para el tipo Capicua, asumir que se puede generar desde un double o similar
                this->M[i][1] = T::desdeDouble(base);
                for (size_t j = 2; j < this->NC; ++j) {
                    this->M[i][j] = T::potencia(this->M[i][1], j);  // Capicua tiene un método estático potencia()
                }
            }
        }
    }

    // Constructor de copia con verificación
    MatrizP(const Matriz<T>& m) : Matriz<T>(m) {
        if (!esMatrizDePotencia()) {
            if (this->M != NULL) {
                for (size_t i = 0; i < this->NF; i++) {
                    delete[] this->M[i];
                }
                delete[] this->M;
            }
            this->NF = this->NC = 0;
            this->M = NULL;
        }
    }

    // Verificar que es matriz potencia
    bool esMatrizDePotencia() {
        for (size_t i = 0; i < this->NF; ++i) {
            // El primer elemento de cada fila es la base
            T base = this->M[i][0];
            for (size_t j = 1; j < this->NC; ++j) {
                if (this->M[i][j] != this->M[i][j - 1] * this->M[i][1]) {
                    return false;
                }
            }
        }

        return true;
    }

};

#endif // MATRIZP_H
