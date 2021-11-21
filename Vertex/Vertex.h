#ifndef VERTEX_H
#define VERTEX_H

template < class T >
class Vertex {
    T tag;
    public:
        Vertex(T t) { tag = t; };
        T getTag() { return tag; };
        void setTag(T t) { tag = t; };
};

#endif //VERTEX_H