/*@ <authors>
 *
 * E14 Pablo Cruz Sojo
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Coste: N*Log(N)

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct instrumento {
    int musicos, partituras;
};

bool operator<(instrumento const& a, instrumento const& b) {
    return (float) a.musicos/a.partituras > (float) b.musicos/b.partituras;
}

void resuelveCaso() {

    int nPartituras, nInstrumentos, nMusicos;

    cin >> nPartituras >> nInstrumentos;

    PriorityQueue<instrumento>cola;

    for (int i = 0; i < nInstrumentos; i++) {
        cin >> nMusicos;
        cola.push({ nMusicos, 1 });
    }

    while (nPartituras-- > nInstrumentos && cola.top().musicos != cola.top().partituras) {
        auto m = cola.top();
        cola.pop();
        m.partituras++;
        cola.push(m);
    }
    auto ins = cola.top();
    cout << (ins.musicos % ins.partituras != 0 ? ins.musicos / ins.partituras + 1 : ins.musicos / ins.partituras) << '\n';
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // entrada/salida rápida
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ajustes para que cin extraiga directamente de un fichero (solamente en local)
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

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
