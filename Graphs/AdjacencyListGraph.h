#ifndef ADJACENCYLISTGRAPH_H
#define ADJACENCYLISTGRAPH_H
#include <List>
#include "../Arista/Arista.h"
#include "../Vertex/Vertex.h"
using namespace std;

template < class T, class Q >
class Graph {
    int veretxNumber;
    Vertex< T > **vertexArray;
    list< Arista< T, Q >* > adjacencyList;
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
        void modifyWeight(Vertex< T >*, Vertex< T >*, Q);
        Q weight(Vertex< T >*, Vertex< T >*);
        Vertex< T > *firstVertex();
        Vertex< T > *nextVertex(Vertex< T >*);
        Vertex< T > *firstAdjacentVertex(Vertex< T >*);
        Vertex< T > *nextAdjacentVertex(Vertex< T >*, Vertex< T >*);
        bool arista(Vertex< T >*, Vertex< T >*);
        int getVertexNumber();
        Vertex< T > *searchTag(T); //Provisional, hay que hacerlo general para cualquier TDA
        void print(); //Provisional
};

#endif //ADJACENCYLISTGRAPH_H