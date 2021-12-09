#ifndef TESTS_H
#define TESTS_H
#include "Menu.h"

template < class T, class Q >
class Tests {
    Graph graph;
    GenericGraphAlgorithms< T, Q > *graphAlgoritms;
    public:
        void test();
        void createBigGraph();
        void createSmallGraph();
        void createMiddleGraph();
};

void Tests< T, Q > :: test() {
    
}

void Tests< T, Q > :: createBigGraph() {
    
}

void Tests< T, Q > :: createSmallGraph() {
    
}

void Tests< T, Q > :: createMiddleGraph() {
    
}

#endif //TESTS_H