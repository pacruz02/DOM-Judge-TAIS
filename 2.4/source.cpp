
/*@ <authors>
 *
 * E14 Pablo Cruz Sojo
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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

struct paciente {
    int gravedad;
    string nombre;
    unsigned long long orden;
};

bool operator<(paciente const& a, paciente const& b) {
    if (a.gravedad != b.gravedad) {
        return a.gravedad > b.gravedad;
    }
    return a.orden < b.orden;
}

bool resuelveCaso() {

    int n; 
    cin >> n;
    if (!n)
        return false;

    PriorityQueue<paciente> cola;
    char evento;
    unsigned long long contadorLlegada = 0;

    for (int i = 0; i < n; i++) {
        cin >> evento;
        if (evento == 'I'){
            string nombre;
            int gravedad;
            cin >> nombre >> gravedad;
            cola.push({gravedad, nombre, contadorLlegada++});
        }
        else if (evento == 'A') {
            cout << cola.top().nombre << '\n';
            cola.pop();
        }

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
