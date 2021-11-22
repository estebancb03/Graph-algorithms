#ifndef ARISTA_H
#define ARISTA_H
#include "../Vertex/Vertex.h"

template < class T, class Q >
class Arista {
    Q weight;
    Vertex< T > *originVertex;
    Vertex< T > *destinationVertex;
    public:
        Arista(Q w) { weight = w; originVertex = nullptr; destinationVertex = nullptr; };
        Q getWeight() { return weight; };
        Vertex< T > *getOriginVertex() { return originVertex; };
        Vertex< T > *getDestinationVertex() { return destinationVertex; };
        void setWeight(Q w) { weight = w; };
        void setOriginVertex(Vertex< T > *ov) { originVertex = ov; };
        void setDestinationVertex(Vertex< T > *dv) { destinationVertex = dv; };
};

#endif //ARISTA_H