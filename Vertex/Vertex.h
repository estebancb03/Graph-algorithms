#ifndef VERTEX_H
#define VERTEX_H

template < class Q >
class Vertex {
    Q weight;
    Vertex< Q > *originVertex;
    Vertex< Q > *destinationVertex;
    public:
        Vertex(Q w) { weight = w; originVertex = nullptr; destinationVertex = nullptr; };
        Q getWeight() { return weight; };
        Vertex< Q > *getOriginVertex() { return originVertex; };
        Vertex< Q > *getDestinationVertex() { return destinationVertex; };
        void setWeight(Q w) { weight = w; };
        void setOriginVertex(Vertex< Q > *ov) { originVertex = ov; };
        void setDestinationVertex(Vertex< Q > *dv) { destinationVertex = dv; };
};

#endif //VERTEX_H