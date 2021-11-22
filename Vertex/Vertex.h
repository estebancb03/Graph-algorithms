#ifndef VERTEX_H
#define VERTEX_H
#include "../Arista/Arista.h"

template < class T, class Q>
class Arista;

template < class T, class Q>
class Vertex {
    T tag;
    Vertex< T, Q > *next;
    Arista< T, Q > *adjacent;
    public:
        Vertex(T t) { tag = t; next = nullptr; adjacent = nullptr; }; 
        T getTag() { return tag; };
        Vertex< T, Q > *getNext() { return next; };
        Arista< T, Q > *getAdjacent() { return adjacent; };
        void setTag(T t) { tag = t; };
        void setNext(Vertex< T, Q > *n) { next = n; };
        void setAdjacent(Arista< T, Q > *a) { adjacent = a; };
};

#endif //VERTEX_H