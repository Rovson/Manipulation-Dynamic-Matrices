#ifndef MATRIZC_H
#define MATRIZC_H

#include "Matriz.h"
using namespace std;


class MatrizC : public Matriz {

public:

    // Constructor por defecto
    MatrizC(){
        return;
    }

    // Constructor que recibe un unico entero para filas y columnas
    MatrizC (size_t dimension): Matriz (dimension, dimension) {
    }

    //Constructor de copia con verificación
    MatrizC(Matriz m):Matriz(m){
        if(Matriz::NF!=Matriz::NC){
            if(Matriz::M!=NULL){
                for (size_t i = 0; i < Matriz::NF; i++) {
                    delete[] Matriz::M[i];
                }
                delete[] Matriz::M;
            }
            Matriz::NF=Matriz::NC=0;
            Matriz::M=NULL;
        }
    }

};

#endif // MATRIZC_H
