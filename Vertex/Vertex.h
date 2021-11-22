#ifndef VERTEX_H
#define VERTEX_H

template < class T >
class Vertex {
    T tag;
    int position;
    public:
        Vertex(T t, int p) { tag = t; position = p; };
        T getTag() { return tag; };
        int getPosition() { return position; };
        void setTag(T t) { tag = t; };
        void setPosition(int p) { position = p; };
};

#endif //VERTEX_H