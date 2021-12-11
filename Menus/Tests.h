#ifndef TESTS_H
#define TESTS_H
#include <chrono>
#include <time.h>
#include "Menu.h"

template < class T, class Q >
class Tests {
    Graph< T, Q > *graph;
    GenericGraphAlgorithms< T, Q > *graphAlgoritms;
    public:
        void test();
        void createBigGraph();
        void createSmallGraph();
        void createMediumGraph();
};

/*
    EFECTO: mide el tiempo en ejecución de un algoritmo
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
void Tests< T, Q > :: test() {
    createMediumGraph();
    auto start = std :: chrono :: system_clock :: now();
    graphAlgoritms -> cycles();
    auto end = std :: chrono :: system_clock :: now();
    std :: chrono :: duration< float > enlapsed_seconds = end - start;
    std :: cout << endl << endl << "Tiempo: " << enlapsed_seconds.count() << " segundos" << endl;
}

/*
    EFECTO: crea grafo de tamaño grande
    REQUIERE: grafo no creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Tests< T, Q > :: createBigGraph() {
    char character;
    Vertex< T, Q > *origin;
    Vertex< T, Q > *destiny;
    Q randomWeightNumber;
    int randomAristaNumber;
    graph = new Graph< T, Q >();
    graph -> create();
    srand(time(NULL));
    graphAlgoritms = new GenericGraphAlgorithms< T, Q >(graph);
    for(int i = 0; i < 125; ++i) {
        character = i;
        graph -> addVertex(character);
    }
    for(int i = 0; i < 20000; ++i) {
        randomAristaNumber = rand() % 125;
        randomWeightNumber = rand() % 101;
        if(i < 125) {
            origin = graph -> getVertexByNumber(i);
            destiny = graph -> getVertexByNumber(randomAristaNumber);
            if(!graph -> arista(origin, destiny) && randomAristaNumber != i)
                graph -> addArista(origin, destiny, randomWeightNumber);
        }
    }
    cout << "Vertices: " << graph -> getVertexNumber();
}

/*
    EFECTO: crea grafo de tamaño pequeño
    REQUIERE: grafo no creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Tests< T, Q > :: createSmallGraph() {
    char character;
    Vertex< T, Q > *origin;
    Vertex< T, Q > *destiny;
    Q randomWeightNumber;
    int randomAristaNumber;
    graph = new Graph< T, Q >();
    graph -> create();
    srand(time(NULL));
    graphAlgoritms = new GenericGraphAlgorithms< T, Q >(graph);
    for(int i = 0; i < 10; ++i) {
        character = i;
        graph -> addVertex(character);
    }
    for(int i = 0; i < 10; ++i) {
        randomAristaNumber = rand() % 10;
        randomWeightNumber = rand() % 101;
        if(i < 10) {
            origin = graph -> getVertexByNumber(i);
            destiny = graph -> getVertexByNumber(randomAristaNumber);
            if(!graph -> arista(origin, destiny) && randomAristaNumber != i)
                graph -> addArista(origin, destiny, randomWeightNumber);
        }
    }
    cout << "Vertices: " << graph -> getVertexNumber();
}

/*
    EFECTO: crea grafo de tamaño medio
    REQUIERE: grafo no creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Tests< T, Q > :: createMediumGraph() {
    char character;
    Vertex< T, Q > *origin;
    Vertex< T, Q > *destiny;
    Q randomWeightNumber;
    int randomAristaNumber;
    graph = new Graph< T, Q >();
    graph -> create();
    srand(time(NULL));
    graphAlgoritms = new GenericGraphAlgorithms< T, Q >(graph);
    for(int i = 0; i < 75; ++i) {
        character = i;
        graph -> addVertex(character);
    }
    for(int i = 0; i < 75; ++i) {
        randomAristaNumber = rand() % 75;
        randomWeightNumber = rand() % 101;
        if(i < 75) {
            origin = graph -> getVertexByNumber(i);
            destiny = graph -> getVertexByNumber(randomAristaNumber);
            if(!graph -> arista(origin, destiny) && randomAristaNumber != i)
                graph -> addArista(origin, destiny, randomWeightNumber);
        }
    }
    cout << "Vertices: " << graph -> getVertexNumber();
}

#endif //TESTS_H