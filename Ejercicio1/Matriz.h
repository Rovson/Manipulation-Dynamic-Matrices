#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <cstdlib> // generación de números aleatorios
#include <ctime>
#include <stdexcept>
using namespace std;


class Matriz {

protected: // accesibles por las herencias pero privados para el resto
    int** M;
    size_t NF, NC;

public:
    // Constructor por defecto (inicializa matriz NULA)
    Matriz() : M(nullptr), NF(0), NC(0) {}

    // Constructor con parámetros (inicializa una matriz de tamaño fila x columna con valores aleatorios)
    Matriz(size_t filas, size_t columnas) : NF(filas), NC(columnas) {
        M = new int*[NF];
        for(size_t i = 0; i < NF; ++i) {
            M[i] = new int[NC];
            for(size_t j = 0; j < NC; ++j) {
                M[i][j] = rand() % 10; // Números aleatorios 0-9
            }
        }
    }

    // Constructor copia (realiza una copia de otra matriz)
    Matriz(const Matriz& otra) : NF(otra.NF), NC(otra.NC) {
        M = new int*[NF];
        for(size_t i = 0; i < NF; ++i) {
            M[i] = new int[NC];
            for(size_t j = 0; j < NC; ++j) {
                M[i][j] = otra.M[i][j];
            }
        }
    }

    // Destructor (libera memoria dinámica asignada a la matriz)
    ~Matriz() {
        for(size_t i = 0; i < NF; ++i) {
            delete[] M[i];
        }
        delete[] M;
    }

    // Asignación (asegura copia adecuada y evita la auto-asignación)
    Matriz operator=(Matriz otra) {
        if(this == &otra) return *this; // Evita autoasignación

        // Liberar la memoria actual
        for(size_t i = 0; i < NF; ++i) {
            delete[] M[i];
        }
        delete[] M;

        // Copiar desde "otra"
        NF = otra.NF;
        NC = otra.NC;
        M = new int*[NF];
        for(size_t i = 0; i < NF; ++i) {
            M[i] = new int[NC];
            for(size_t j = 0; j < NC; ++j) {
                M[i][j] = otra.M[i][j];
            }
        }

        return *this;
    }


    // Operador de salida (imprimir matriz)
    friend ostream& operator<<(ostream& os, Matriz matriz) {
        if (matriz.esNula()) {
            os << "MATRIZ NULA\n";
        } else {
            for(size_t i = 0; i < matriz.NF; ++i) {
                for(size_t j = 0; j < matriz.NC; ++j) {
                    os << matriz.M[i][j] << " ";
                }
                os << endl;
            }
        }
        return os;
    }

    // Función para verificar si la matriz es nula
    bool esNula() {
        return NF == 0 || NC == 0 || M == nullptr;
    }

    // Operador de igualdad
    bool operator==( Matriz otra)  {
        if (NF != otra.NF || NC != otra.NC) {
            return false;
        }
        for (size_t i = 0; i < NF; ++i) {
            for (size_t j = 0; j < NC; ++j) {
                if (M[i][j] != otra.M[i][j]) {
                    return false;
                }
            }
        }
        return true; // Si todas las comprobaciones anteriores son correctas, las matrices son iguales
    }

    // Operador de desigualdad
    bool operator!=( Matriz otra) {
        return !(*this == otra);
    }

    //-----------------------------------------------------------------------
    // -------------------------- OPERACIONES -------------------------------
    //-----------------------------------------------------------------------

    // Controlamos compatibilidad de las dimensiones antes de realizar las operaciones

    // Suma de matrices
    Matriz operator+(Matriz otra) {
        if(esNula() || otra.esNula() || NF != otra.NF || NC != otra.NC) return Matriz();
        Matriz resultado(NF, NC);
        for(size_t i = 0; i < NF; ++i) {
            for(size_t j = 0; j < NC; ++j) {
                resultado.M[i][j] = M[i][j] + otra.M[i][j];
            }
        }
        return resultado;


    }

    // Resta de matrices
    Matriz operator-(Matriz otra) {
        if(esNula() || otra.esNula() || NF != otra.NF || NC != otra.NC) return Matriz();
        Matriz resultado(NF, NC);
        for(size_t i = 0; i < NF; ++i) {
            for(size_t j = 0; j < NC; ++j) {
                resultado.M[i][j] = M[i][j] - otra.M[i][j];
            }
        }
        return resultado;
    }

    // Multiplicación de matrices
    Matriz operator*(Matriz otra) {
        if(esNula() || otra.esNula() || NC != otra.NF) return Matriz();
        Matriz resultado(NF, otra.NC);
        for(size_t i = 0; i < resultado.NF; ++i) {
            for(size_t j = 0; j < resultado.NC; ++j) {
                resultado.M[i][j] = 0;
                for(size_t k = 0; k < NC; ++k) {
                    resultado.M[i][j] += M[i][k] * otra.M[k][j];
                }
            }
        }
        return resultado;
    }

    // Auto-suma
    Matriz operator+=(Matriz otra) {
        if(esNula() || otra.esNula() || NF != otra.NF || NC != otra.NC) {
            *this = Matriz(); // Convertir en matriz nula si no son compatibles
        } else {
            for(size_t i = 0; i < NF; ++i) {
                for(size_t j = 0; j < NC; ++j) {
                    M[i][j] += otra.M[i][j];
                }
            }
        }
        return *this;
    }

    // Auto-resta
    Matriz operator-=(Matriz otra) {
        if(esNula() || otra.esNula() || NF != otra.NF || NC != otra.NC) {
            *this = Matriz();
        } else {
            for(size_t i = 0; i < NF; ++i) {
                for(size_t j = 0; j < NC; ++j) {
                    M[i][j] -= otra.M[i][j];
                }
            }
        }
        return *this;
    }

    // Auto-producto
    Matriz operator*=(Matriz otra) {
        if(esNula() || otra.esNula() || NC != otra.NF) {
            *this = Matriz();
        } else {
            *this = *this * otra; // Utiliza el operador* ya definido
        }
        return *this;
    }

    // Producto por un escalar desde la derecha
    Matriz operator*(int escalar) {
        if (esNula()) return Matriz();
        Matriz resultado(NF, NC);
        for (size_t i = 0; i < NF; ++i) {
            for (size_t j = 0; j < NC; ++j) {
                resultado.M[i][j] = M[i][j] * escalar;
            }
        }
        return resultado;
    }

    // Auto-producto por un escalar
    Matriz operator*=(int escalar) {
        if (!esNula()) {
            for (size_t i = 0; i < NF; ++i) {
                for (size_t j = 0; j < NC; ++j) {
                    M[i][j] *= escalar;
                }
            }
        }
        return *this;
    }

    // Producto por un escalar desde la izquierda (función amiga)
    friend Matriz operator*(int escalar, Matriz matriz) {
        return matriz * escalar;
    }


    // Operador para obtener la traspuesta de la matriz
    Matriz operator~() {
        if (esNula()) return Matriz();

        Matriz traspuesta(NC, NF); // Nota el cambio de filas por columnas
        for (size_t i = 0; i < NF; ++i) {
            for (size_t j = 0; j < NC; ++j) {
                traspuesta.M[j][i] = M[i][j];
            }
        }
        return traspuesta;
    }

    // Operador para obtener la matriz opuesta
    Matriz operator-() {
        if (esNula()) return Matriz();

        Matriz opuesta(NF, NC);
        for (size_t i = 0; i < NF; ++i) {
            for (size_t j = 0; j < NC; ++j) {
                opuesta.M[i][j] = -M[i][j];
            }
        }
        return opuesta;
    }


};

#endif
