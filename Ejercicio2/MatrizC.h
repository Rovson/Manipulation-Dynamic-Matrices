#ifndef MATRIZC_H
#define MATRIZC_H

#include "Matriz.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

template<typename T>
class MatrizC : public Matriz<T> {
public:
    // Contructor por defecto
    MatrizC(){
        return;
    }
    // Constructor que recibe un solo valor para el número de filas y columnas (matriz cuadrada)
    MatrizC(size_t dimension) : Matriz<T>(dimension, dimension) {
    }

    // Constructor de copia con verificacion
    MatrizC(Matriz<T> m):Matriz<T>(m){
        if(Matriz<T>::NF!=Matriz<T>::NC){
            if(Matriz<T>::M!=NULL){
                for (size_t i = 0; i < Matriz<T>::NF; ++i) {
                    delete[] Matriz<T>::M[i];
                }
                delete[] Matriz<T>::M;
            }
            Matriz<T>::NF=Matriz<T>::NC=0;
            Matriz<T>::M=NULL;
        }
    }
};

#endif // MATRIZC_H
