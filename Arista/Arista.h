#ifndef ARISTA_H
#define ARISTA_H
#include "../Vertex/Vertex.h"

template < class Q >
class Arista {
    Q weight;
    Vertex< Q > *originVertex;
    Vertex< Q > *destinationVertex;
    public:
        Arista(Q w) { weight = w; originVertex = nullptr; destinationVertex = nullptr; };
        Q getWeight() { return weight; };
        Vertex< Q > *getOriginVertex() { return originVertex; };
        Vertex< Q > *getDestinationVertex() { return destinationVertex; };
        void setWeight(Q w) { weight = w; };
        void setOriginVertex(Vertex< Q > *ov) { originVertex = ov; };
        void setDestinationVertex(Vertex< Q > *dv) { destinationVertex = dv; };
};

#endif //ARISTA_H