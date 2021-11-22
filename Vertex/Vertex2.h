#ifndef VERTEX2_H
#define VERTEX2_H

template < class T, class Q >
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

#endif //VERTEX2_H