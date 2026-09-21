
/*@ <authors>
 *
 * E14 Pablo Cruz Sojo
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct registro {
    int momento, id, periodo;
};

bool operator<(registro const& a, registro const& b) {
    return b.momento < a.momento ||
        (a.momento == b.momento && b.id < a.id);
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n;

    cin >> n;

    if (n == 0)
        return false;

    priority_queue <registro> cola;

    for (int i = 0; i < n; i++) {
        int id, per;
        cin >> id >> per;
        cola.push({ per,id,per });
    }

    int envios;
    cin >> envios;

    while (envios--) {
        registro aux = cola.top();
        cola.pop();
        cout << aux.id << endl;
        aux.momento += aux.periodo;
        cola.push(aux);
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
