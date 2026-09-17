/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <authors>
  *
  * E86 Nombre Apellidos
  * E86 Nombre Apellidos
  *
  *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "TreeSet_AVL_tami.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0)
        return false;

    // los valores de la entrada se insertan en el conjunto
    Set<int> cjto;
    int valor;
    for (int i = 0; i < N; ++i) {
        cin >> valor;
        cjto.insert(valor);
    }

    // COMPLETAR

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> valor;
        int kesimo = cjto.kesimo(valor);
        if (kesimo > 0)
            cout << kesimo;
        else
            cout << "??";
        cout << endl;
    }
    cout << "---\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open()) {
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
        // sin fichero no hay nada que leer, y cin >> ... dejaría las
        // variables sin tocar, con su valor basura
        return 1;
    }
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
