#include <iostream>
#include "Matriz.h"
#include "MatrizP.h"
#include "MatrizC.h"
#include "MatrizS.h"
#include "MatrizA.h"

using namespace std;

int main() {

    srand(time(nullptr));


 //-------------------------------------------
 //------------- PROGRAMA --------------------
 //-------------------------------------------

    //-------- MATRICES ------------

     cout << "\033[1m------ MATRICES ------\033[0m\n" << endl;
    Matriz A(3,3);
     Matriz B(3,3);

    cout << "\033[1mMatriz A:\033[0m\n" << A << "\n";
    cout << "\033[1mMatriz B\033[0m:\n" << B << "\n";

    //-------- MATRIZ DIMENSION 0 ---------
/*
     cout << "\033[1m------ DIMENSION 0 ------\033[0m\n" << endl;
    Matriz M(0, 0);
    MatrizC MC(0);
    MatrizP MP(0,0);
    MatrizA MA(0);
    MatrizS MS(0);

    cout << "\033[1mMatriz M:\033[0m\n" << M << "\n";
    cout << "\033[1mMatriz MC:\033[0m:\n" << MC << "\n";
    cout << "\033[1mMatriz MP:\033[0m:\n" << MP << "\n";
    cout << "\033[1mMatriz MA:\033[0m:\n" << MA << "\n";
        cout << "\033[1mMatriz MS:\033[0m:\n" << MS << "\n";


    //-------- IGUALACIONES ---------

    cout << "\033[1m------ IGUALACIONES ------\033[0m\n" << endl;
    Matriz M(4, 7);
    MatrizC MC(3);
    MatrizP MP(M);
    MatrizA MA(MC);
    MatrizS MS(MC);
    MatrizC MC1(M);

    cout << "\033[1mMatriz MC(3) = M(4,7):\033[0m\n" << MC1 << "\n";
    cout << "\033[1mMatriz MP(4,7) = M(4,7):\033[0m\n" << MP << "\n";
    cout << "\033[1mMatriz MA = MC:\033[0m:\n" << MA << "\n";
    cout << "\033[1mMatriz MS = MC:\033[0m:\n" << MS << "\n";


*/

    //-------- OPERACIONES------------

    cout << "\033[1m------ OPERACIONES ------\033[0m\n" << endl;


    // SUMA
    Matriz C = A + B;
    cout << "\033[1mSUMA A + B:\033[0m\n" << C << endl;

    // RESTA
    Matriz D = A - B;
    cout << "\033[1mResta A - B:\033[0m\n" << D << "\n";

    // MULTIPLICACIÓN
    Matriz E = A * B;
    cout << "\033[1mMultiplicacion A * B:\033[0m\n" << E << "\n";


    //------ AUTO-OPERACIONES------

    cout << "\033[1m------ AUTO-OPERACIONES ------\033[0m\n" << endl;

    // Modificaremos A

    // AUTO-SUMA
    A += B; // A se actualiza para ser la suma de A y B
    cout << "\033[1mA despues de A += B:\033[0m\n" << A << "\n";

    // AUTO-RESTA
    A -= B; // A se actualiza para ser la resta de A y B (devolviéndola a su estado original)
    cout << "\033[1mA despues de A -= B:\033[0m\n" << A << "\n";

    // AUTO-MULTIPLICACIÓN
    // Para *=, necesitamos matrices de tamaños compatibles para multiplicación, así que asumiremos nuevas matrices
    Matriz X(2, 3);
    Matriz Y(3, 2);
    X *= Y; // X se actualiza para ser el producto de X y Y
    cout << "\033[1mX despues de X *= Y:\033[0m\n" << X << "\n";


    //------ PRODUCTO ESCALAR------

    cout << "\033[1m------ PRODUCTO ESCALAR ------\033[0m\n" << endl;

    // PRODUCTO POR UN ESCALAR POR LA DERECHA
    Matriz F = A * 3;
    cout << "\033[1mProducto de A por 3:\033[0m\n" << F << "\n";

    // PRODUCTO POR UN ESCALAR POR LA IZQUIERDA
    Matriz G = 2 * A;
    cout << "\033[1mProducto de 2 por A:\033[0m\n" << G << "\n";

    // AUTO-PRODUCTO POR UN ESCALAR
    A *= 4;
    cout << "\033[1mA despues de A *= 4:\033[0m\n" << A << "\n";


    //------ OPERADORES UNARIOS ------

    cout << "\033[1m------ OPERADORES UNARIOS ------\033[0m\n" << endl;

    Matriz traspuesta = ~A;
    cout << "\033[1mTraspuesta de A:\033[0m\n" << traspuesta << "\n";

    Matriz opuesta = -A;
    cout << "\033[1mOpuesta de A:\033[0m\n" << opuesta << "\n";


    //---------------------------------------
    //------------- MatrizP -----------------
    //---------------------------------------

    cout << "\033[1m------ MATRIZ POTENCIA ------\033[0m\n" << endl;

    // Crea una instancia de MatrizP
    MatrizP miMatrizP(4, 4);  // crea una matriz de 4 filas y 5 columnas

    // Muestra la matriz
    cout << "\033[1mMatrizP:\033[0m\n" << miMatrizP << endl;


    //---------------------------------------
    //------------- MatrizC -----------------
    //---------------------------------------

    cout << "\033[1m------ MATRIZ CUADRADA ------\033[0m\n" << endl;

    // Creamos una matriz de dimension 6x6
    MatrizC miMatrizC(4);

    // Muestra la matrizC
    cout << "\033[1mMatrizC:\033[0m\n" << miMatrizC << endl;


    //---------------------------------------
    //------------- MatrizS -----------------
    //---------------------------------------

    cout << "\033[1m------ MATRIZ SIMETRICA ------\033[0m\n" << endl;

    // Creamos una matriz de dimension 6x6
    MatrizS miMatrizS(4);

    // Muestra la matrizS
    cout << "\033[1mMatrizS:\033[0m\n" << miMatrizS << endl;


    //---------------------------------------
    //------------- MatrizA -----------------
    //---------------------------------------

    cout << "\033[1m------ MATRIZ ANTISIMETRICA ------\033[0m\n" << endl;

    // Creamos una matriz de dimension 6x6
    MatrizA miMatrizA(4);

    // Muestra la matrizS
    cout << "\033[1mMatrizA:\033[0m\n" << miMatrizA << endl;



    return 0;


}

