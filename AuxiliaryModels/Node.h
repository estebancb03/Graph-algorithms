#ifndef NODE_H
#define NODE_H
template < class T >

class Node {
    T object;
    Node< T > *next;
    public:
        Node(T o) { object = o; next = nullptr; };
        Node< T > *getNext() { return next; };
        T getObject() { return object; };
        void setObject(T o) { object = o; };
        void setNext(Node< T > *n) { next = n; };
};

#endif //NODE