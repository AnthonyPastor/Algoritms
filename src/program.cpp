#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "models/Graph/Graph_AdjList.cpp"

using namespace std;

int main()
{
    cout << "Prueba de grafo dirigido y no ponderado:" << endl;
    GrafoListaAdyImp *gDirNoPon = new GrafoListaAdyImp(10, true, false);
    cout << "Prueba de grafo dirigido y no ponderado:" << endl;

    gDirNoPon->addEdge(1, 3);
    gDirNoPon->addEdge(1, 2);
    gDirNoPon->addEdge(4, 1);
    cout << "Prueba de grafo dirigido y no ponderado:" << endl;

    gDirNoPon->print();

    cout << endl
         << "Prueba de grafo dirigido y ponderado:" << endl;

    GrafoListaAdyImp *gDirPon = new GrafoListaAdyImp(10, true, true);
    gDirPon->addEdge(1, 3, 4);
    gDirPon->addEdge(3, 1, 8);
    gDirPon->addEdge(1, 2, -5);
    gDirPon->addEdge(4, 1, 10);

    gDirPon->print();

    cout << endl
         << "Prueba de grafo no dirigido y no ponderado:" << endl;
    GrafoListaAdyImp *gNoDirNoPon = new GrafoListaAdyImp(10, false, false);
    gNoDirNoPon->addEdge(1, 3);
    gNoDirNoPon->addEdge(1, 2);
    gNoDirNoPon->addEdge(4, 1);
    gNoDirNoPon->addEdge(5, 2);
    gNoDirNoPon->addEdge(8, 4);
    gNoDirNoPon->addEdge(4, 9);

    gNoDirNoPon->print();

    return 0;
}