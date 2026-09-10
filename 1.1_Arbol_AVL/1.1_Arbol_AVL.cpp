/*@ <authors>
 *
 * E14 Pablo Cruz Sojo
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;
#include "bintree.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================

template <typename T>
pair<bool, int> AVL(const BinTree<T> &tree)
{
    if (tree.empty())
        return {true, 0};

    pair<bool, int> left = AVL(tree.left());
    pair<bool, int> right = AVL(tree.right());

    return {left.first && right.first && abs(left.second - right.second) <= 1 && ord(tree), max(left.second, right.second) + 1};
}

template <typename T>
bool ord(BinTree<T> tree)
{
    if (tree.empty())
        return true;

    auto it = tree.begin();
    T anterior = *it;
    ++it;

    while (it != tree.end())
    {
        if (*it <= anterior)
            return false;

        anterior = *it;
        ++it;
    }
    return true;
}

bool resuelveCaso()
{

    char tipo;

    if (!(cin >> tipo))
        return false;

    if (tipo == 'N')
    {
        BinTree<int> entrada = read_tree<int>(cin);
        cout << (AVL(entrada).first ? "SI" : "NO") << endl;
    }
    else if (tipo == 'P')
    {
        BinTree<string> entrada = read_tree<string>(cin);
        cout << (AVL(entrada).first ? "SI" : "NO") << endl;
    }

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}