template <class T>

class Graph
{
public:
    // pre:
    //  - v y w son vertices validos del grafo
    //  - no existe la arista v w
    // pos: agrega la arista v w con su respectivo peso al grafo
    virtual void addEdge(int v, int w, int peso = 1) = 0;
     // pre: el vertice origen es un vertice valido del grafo
    // pos: retorna una lista de Arsitas las cuales tienen como origen al vertice parametro
    virtual T adjecentsTo(int origin) = 0;
    // pre:
    // pos: imprime el grafo
    virtual void print() = 0;
};