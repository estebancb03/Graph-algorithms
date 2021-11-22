#ifndef ADJACENCYMATRIXGRAPH_H
#define ADJACENCYMATRIXGRAPH_H
#include "../Vertex/Vertex2.h"
using namespace std;

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
        void addArista(Vertex< T >*, Vertex< T >*, Q);
        void deleteArista(Vertex< T >*, Vertex< T >*);
        Q weight(Vertex< T >*, Vertex< T >*);
        Vertex< T > *firstVertex();
        Vertex< T > *nextVertex(Vertex< T >*);
        bool arista(Vertex< T >*, Vertex< T >*);
        int getVertexNumber();
        Vertex< T > *searchTag(T); //Provisional, hay que hacerlo general para cualquier TDA
        void print(); //Provisional
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
    delete this;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
void Graph< T, Q > :: clear() {
    destroy();
    create();
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
        adjacencyMatrix[vertexNumber][vertexNumber] = invalid;
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
    if(vertexNumber > 1 && vertex -> getPosition() < vertexNumber - 1) {
        for(int i = vertex -> getPosition(); i < vertexNumber - 1; ++i) {
            vertexArray[i + 1] -> setPosition(vertexArray[i + 1] -> getPosition() - 1);
            vertexArray[i] = vertexArray[i + 1];
        }
    }
    else 
        delete vertexArray[vertex -> getPosition()];
    --vertexNumber;
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
void Graph< T, Q > :: addArista(Vertex< T > *vertex, Vertex< T > *vertex2, Q weight) {
    if(vertex != vertex2) {
        int position1 = vertex -> getPosition();
        int position2 = vertex2 -> getPosition();
        adjacencyMatrix[position1][position2] = weight;
        adjacencyMatrix[position2][position1] = weight;  
    }
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteArista(Vertex< T > *vertex, Vertex< T > *vertex2) {
    int position1 = vertex -> getPosition();
    int position2 = vertex2 -> getPosition();
    adjacencyMatrix[position1][position2] = 0;
    adjacencyMatrix[position2][position1] = 0;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
Q Graph< T, Q > :: weight(Vertex< T > *vertex, Vertex< T > *vertex2) {
    return adjacencyMatrix[vertex -> getPosition()][vertex2 -> getPosition()];
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
    return vertex -> getPosition() != vertexNumber - 1 ? vertexArray[vertex -> getPosition() + 1] : nullptr;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
bool Graph< T, Q > :: arista(Vertex< T > *vertex, Vertex< T > *vertex2) {
    bool result = false;
    if(vertex != vertex2 && adjacencyMatrix[vertex -> getPosition()][vertex2 -> getPosition()]) 
        result = true;
    return result;
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

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T, typename Q >
void Graph< T, Q > :: print() {
    for(int i = 0; i < vertexNumber; ++i) {
        for (int j = 0; j < vertexNumber; ++j)
            cout << adjacencyMatrix[i][j] << " ";
        cout << endl << endl;
    }
    cout << endl << endl;   
}

#endif //ADJACENCYMATRIXGRAPH_H