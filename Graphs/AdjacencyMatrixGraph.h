#ifndef ADJACENCYMATRIXGRAPH_H
#define ADJACENCYMATRIXGRAPH_H
#include "../Vertex/Vertex.h"

template < class T, class Q >
class Graph {
    int size = 10;
    int vertexNumber;
    Q adjacencyMatrix[10][10];
    Vertex< T > *vertexArray[10];
    public:
        void create();
        void destroy();
        void clear();
        bool empty();
        Vertex< T > *addVertex(T);
        void modifyTag(Vertex< T >*, T);
        T tag(Vertex< T >*);
};

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
void Graph< T, Q > :: create() {
    vertexNumber = 0;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
void Graph< T, Q > :: destroy() {
    delete []adjacencyMatrix;
    delete []vertexArray;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
bool Graph< T, Q > :: empty() {
    return vertexNumber == 0 ? true : false;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: addVertex(T tag) {
    Vertex< T > *temp = nullptr;
    Q invalid = -1.0;
    if(vertexNumber < size) {
        temp = new Vertex< T >(tag);
        vertexArray[vertexNumber] = temp;
        for(int i = 0; i < vertexNumber; ++i) {
            for(int j = 0; j < vertexNumber; ++j)
                adjacencyMatrix[i][j] = invalid;
        }
        ++vertexNumber;
    }
    return temp;
} 

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyTag(Vertex< T > *vertex, T newTag) {
    vertex -> setTag(newTag);
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
T Graph< T, Q > :: tag(Vertex< T > *vertex) {
    return vertex -> getTag();
}

#endif //ADJACENCYMATRIXGRAPH_H