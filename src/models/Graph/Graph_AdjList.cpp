#include <climits>
#include <string>
#include <iostream>
#include "Edge.cpp"
#include "../List/List.cpp"
#include "Graph.h"

using namespace std;

// uso un NodoLista generico

typedef ListImplementation<GraphEdge> *EdgeList;

class GrafoListaAdyImp : public Graph<EdgeList>
{
private:
    EdgeList *listaAdy; // representacion del grafo con listas
    int V;              // cantidad de vertices
    int A;              // cantidad de arsitas

    bool esDirigido;  // indica si el grafo es dirigido
    bool esPonderado; // indica si el grafo es ponderado

public:
    // Crea un grafo con V vertices (del 1 al V)
    // O(V)
    GrafoListaAdyImp(int cantidadDeVertices, bool esDirigido = true, bool esPonderado = true)
    {
        this->V = cantidadDeVertices;
        this->A = 0;
        this->esDirigido = esDirigido;
        this->esPonderado = esPonderado;

        listaAdy = new EdgeList[V+1];

        int* algo = new int[6];
        for (int i = 1; i <= V; i++)
        {
            listaAdy[i] = new ListImplementation<GraphEdge>(); // inicializa todas las listas como vacias
        }
    }
    // O(1)
    void addEdge(int v, int w, int peso = 1)
    {
        // cout << "Se Crea Edge" << endl;

        int pesoArista = this->esPonderado ? peso : 1; // en el caso de ser ponderado se toma en cuenta el parametro
        GraphEdge a1(v, w, pesoArista);
        // cout << "Se Crea Edge" << endl;

        if(listaAdy[v] == NULL){
            listaAdy[v] = new ListImplementation<GraphEdge>();
        }
        listaAdy[v]->insertInHead(a1); // se agrega al ppio de la lista de los adyacentes al veritce v
        // cout << "Se insertó edge" << endl;

        this->A++;
        if (!esDirigido)                                      // en caso de no ser dirigido podemos duplicar la arista hacia el otro sentido w->v
        {
            GraphEdge a2(w, v, pesoArista);
            listaAdy[w]->insertInHead(a2);
        }
    }
    // O(V) pc
    // si bien esta funcion podria ser O(1) si retornamos la lista original, es peligroso si la manipulan => corrompiendo el grafo
    EdgeList adjecentsTo(int origen)
    {
        // copio la lista
        EdgeList listaRetorno = new ListImplementation<GraphEdge>();
        EdgeList listaAuxiliar = listaAdy[origen];

        int listSize = listaAuxiliar->getSize();
        // cout << "Largo de la lista de adyacentes " << listSize << endl;


        Iterator<GraphEdge> *iterator = listaAuxiliar->getIterator();

        while (iterator->hasNext())
        {
            GraphEdge aristaAuxiliar = iterator->next();
            listaRetorno->insertInHead(aristaAuxiliar);
        }

        return listaRetorno;
    }
    // O(V + A)
    void print()
    {
        // por cada vertice del 1 al V, imprimo sus adyacentes
        for (int i = 1; i <= V; i++)
        {
            cout << "Adyacentes al vertice " << i << endl;
            EdgeList adyacentes = this->adjecentsTo(i);
            Iterator<GraphEdge> *iterator = adyacentes->getIterator();

            while (iterator->hasNext())
            {
                GraphEdge arista = iterator->next();
                cout << i << "-";
                if (this->esPonderado) // en caso de ser ponderado, imprimo el peso
                {
                    cout << arista.weight;
                }
                cout << "->" << arista.destiny << endl;
            }
        }
    }
};