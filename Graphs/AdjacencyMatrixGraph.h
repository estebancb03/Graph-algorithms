#ifndef ADJACENCYMATRIXGRAPH_H
#define ADJACENCYMATRIXGRAPH_H
#include "../Vertex/Vertex.h"

template < class T, class Q >
class Graph {
    int size;
    Q **adjacencyMatrix;
    Vertex< T > *vertexArray;
    public:
        void create();
};

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
void Graph< T, Q > :: create() {
    size = 100;
    vertexArray = new Vertex< T >[size];
    adjacencyMatrix = new Q[size][size];
}

#endif //ADJACENCYMATRIXGRAPH_H