#ifndef CAPICUA_H
#define CAPICUA_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;

class Capicua {
private:
    int ordinal;
    static int* precalculados;
    static int* ordinales;
    static int tamanoPrecalculados;
    static int cantidad;

public:
    // Constructor que establece el ordinal o por defecto a 1 si es cero.
    Capicua(int ord = 0) : ordinal(ord == 0 ? 1 : ord) {
        asegurarPrecalculados(abs(ordinal));  // Asegura que al menos haya suficientes números capicúas calculados
    }

    ~Capicua() {
        // No se libera memoria aquí porque la memoria es compartida por todas las instancias
    }

    // Devuelve el número capicúa basado en el índice ordinal.
    int obtenerCapicua() {
        int indice = abs(ordinal) - 1; // Ajuste para índice base-0
        if (indice >= cantidad) {
            asegurarPrecalculados(indice + 1); // Asegura que hay suficientes capicúas
        }
        return precalculados[indice];
    }

    // Asegura que el array de precalculados tenga al menos `cantidadRequerida` elementos.
    static void asegurarPrecalculados(int cantidadRequerida) {
        if (cantidad >= cantidadRequerida) return;

        int nuevaCantidad = max(cantidadRequerida, tamanoPrecalculados * 2); // Aumenta la capacidad si es necesario
        if (nuevaCantidad > tamanoPrecalculados) {
            int* nuevoAlmacenamiento = new int[nuevaCantidad];
            int* nuevoOrdinales = new int[nuevaCantidad];
            if (precalculados != nullptr) {
                copy(precalculados, precalculados + cantidad, nuevoAlmacenamiento);
                copy(ordinales, ordinales + cantidad, nuevoOrdinales);
                delete[] precalculados;
                delete[] ordinales;
            }
            precalculados = nuevoAlmacenamiento;
            ordinales = nuevoOrdinales;
            tamanoPrecalculados = nuevaCantidad;
        }

        // Genera capicúas hasta que se alcance la nueva capacidad
        int candidato = cantidad > 0 ? precalculados[cantidad - 1] + 1 : 1;
        while (cantidad < nuevaCantidad) {
            if (esCapicua(candidato)) {
                ordinales[cantidad] = cantidad + 1; // Guarda el ordinal
                precalculados[cantidad++] = candidato;
            }
            candidato++;
        }
    }

    // Determina si un número es capicúa.
    static bool esCapicua(int numero) {
        string num = to_string(numero);
        return equal(num.begin(), num.end(), num.rbegin());
    }

    // Limpia los recursos estáticos utilizados.
    static void limpiar() {
        delete[] precalculados;
        delete[] ordinales;
        precalculados = nullptr;
        ordinales = nullptr;
        tamanoPrecalculados = 0;
        cantidad = 0;
    }

    // Sobrecarga del operador de salida para imprimir el número capicúa.
    friend ostream& operator<<(ostream& os, Capicua c) {
        os << c.obtenerCapicua();
        return os;
    }

    static Capicua potencia(Capicua base, size_t exp) {
        Capicua result(1); // Inicializar a 1
        for (size_t i = 0; i < exp; ++i) {
            result = result * base; // Multiplicar la base por el resultado actual
        }
        return result;
    }

    // Constructor que acepta un double, asumiendo que queremos un ordinal aproximado
    static Capicua desdeDouble(double num) {
        int base = static_cast<int>(round(num));
        return Capicua(base);
    }

    // Sobrecarga del operador de desigualdad
    bool operator!=(Capicua otra) {
        return !(*this == otra);
    }

    // Sobrecarga del operador de igualdad para comparar dos objetos Capicua
    bool operator==(Capicua otro) {
        return this->ordinal == otro.ordinal;
    }

    // Sobrecarga del operador de igualdad para comparar un objeto Capicua con un entero
    bool operator==(int number) {
        return this->ordinal == number;
    }
    //-----------------------------------------------------------------------
    // -------------------------- OPERACIONES -------------------------------
    //-----------------------------------------------------------------------

    // Operadores aritméticos con manejo de ordinales
    Capicua operator+(Capicua otra) {
        return Capicua(this->ordinal + otra.ordinal);
    }
    Capicua operator-(Capicua otra) {
        return Capicua(this->ordinal - otra.ordinal);
    }
    Capicua operator*(Capicua otra) {
        return Capicua(this->ordinal * otra.ordinal);
    }
    Capicua operator+=(Capicua otra) {
        this->ordinal += otra.ordinal;
        return *this;
    }
    Capicua operator-=(Capicua otra) {
        this->ordinal -= otra.ordinal;
        return *this;
    }
    Capicua operator*=(Capicua otra) {
        this->ordinal *= otra.ordinal;
        return *this;
    }
    Capicua operator-() {
        return Capicua(-this->ordinal);
    }

};

int* Capicua::precalculados = nullptr;
int* Capicua::ordinales = nullptr;
int Capicua::tamanoPrecalculados = 0;
int Capicua::cantidad = 0;

#endif // CAPICUA_H
