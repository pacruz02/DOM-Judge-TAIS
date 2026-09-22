
/*@ <authors>
 *
 * E14 Pablo Cruz Sojo
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct caja {
    int tiempo, numero;
};

bool operator<(caja const& a, caja const& b) {
    return a.tiempo < b.tiempo ||
        (a.tiempo == b.tiempo && a.numero < b.numero);
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int nCajas, nClientes;
    
    cin >> nCajas >> nClientes;

    if (!nCajas && !nClientes)
        return false;

    vector<int> clientes;
    PriorityQueue<caja> cajas;

    for (int i = 0; i < nClientes; i++) {
        int c;
        cin >> c;
        clientes.push_back(c);
    }

    for (int i = 1; i <= nCajas; i++)
        cajas.push({ 0,i });

    for (int i = 0; i < nClientes; i++) {
        auto aux = cajas.top();
        cajas.pop();
        aux.tiempo += clientes[i];
        cajas.push(aux);
    }

    // escribir la solución
    
    cout << cajas.top().numero << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
