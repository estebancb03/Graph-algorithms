#ifndef ARISTA_H
#define ARISTA_H
#include "../Vertex/Vertex.h"

template < class T, class Q >
class Arista {
    Q weight;
    Arista< T, Q > *next;
    Vertex< T, Q > *adjacent;
    public:
        Arista(Q w) { weight = w; next = nullptr; adjacent = nullptr; };
        Q getWeight() { return weight; };
        Arista< T, Q > *getNext() { return next; };
        Vertex< T, Q > *getAdjacent() { return adjacent; };
        void setWeight(Q w) { weight = w; };
        void setNext(Arista< T, Q > *n) { next = n; };
        void setAdjacent(Vertex< T,Q > *a) { adjacent = a; };
};

#endif //ARISTA_H