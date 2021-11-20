#ifndef GENERICGRAPHALGORITHMS_H
#define GENERICGRAPHALGORITHMS_H
#include "../Menus/Menu.h"

template < class T, class Q>
class GenericGraphAlgorithms {
    Graph< T, Q > *graph;
    public:
        GenericGraphAlgorithms(Graph< T, Q > *g) { this -> graph = g; };

};

#endif //GENERICGRAPHALGORITHMS_H