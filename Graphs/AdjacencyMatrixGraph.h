#ifndef ADJACENCYMATRIXGRAPH_H
#define ADJACENCYMATRIXGRAPH_H
#include "../Vertex/Vertex2.h"

template < class T, class Q >
class Graph {
    int size = 5;
    int vertexNumber;
    Q adjacencyMatrix[5][5];
    Vertex< T > *vertexArray[5];
    public:
        void create();
        void destroy();
        void clear();
        bool empty();
        Vertex< T > *addVertex(T);
        void deleteVertex(Vertex< T >*);
        void modifyTag(Vertex< T >*, T);
        T tag(Vertex< T >*);
        Vertex< T > *firstVertex();
        Vertex< T > *nextVertex(Vertex< T >*);
        int getVertexNumber();
        Vertex< T > *searchTag(T); //Provisional, hay que hacerlo general para cualquier TDA
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
        temp = new Vertex< T >(tag, vertexNumber);
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
void Graph< T, Q > :: deleteVertex(Vertex< T > *vertex) {
    if(vertex -> getPosition() > 0 && vertex -> getPosition() < vertexNumber - 1) {
        for(int i = vertex -> getPosition(); i < vertexNumber; ++i)
            vertexArray[i] = vertexArray[i + 1];
    }
    else
        delete vertexArray[vertex -> getPosition()];
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

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: firstVertex() {
    return vertexArray[0];
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: nextVertex(Vertex< T > *vertex) {
    Vertex< T > *next = nullptr;
    if(vertexNumber < size - 1 && vertex -> getPosition() < vertexNumber);
        next = vertexArray[vertex -> getPosition() + 1];
    return next;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
int Graph< T, Q > :: getVertexNumber() {
    return vertexNumber;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: searchTag(T tag) {
    Vertex< T > *temp = nullptr;
    bool enabled = true;
    int i = 0;
    while(enabled) {
        if(i < size) {
            if(vertexArray[i] -> getTag() == tag) {
                enabled = false;
                temp = vertexArray[i];
            }
            ++i;
        }
        else
            enabled = false;
    }
    return temp;
}

#endif //ADJACENCYMATRIXGRAPH_H