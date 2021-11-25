#ifndef GENERICGRAPHALGORITHMS_H
#define GENERICGRAPHALGORITHMS_H
#include "../Menus/Menu.h"

template < class T, class Q>
class GenericGraphAlgorithms {
    Graph< T, Q > *graph;
    public:
        GenericGraphAlgorithms(Graph< T, Q > *g) { this -> graph = g; };
        Vertex< T, Q > *searchTag(T);
};

/*
    EFECTO: busca un vértice en el grafo
    REQUIERE: grafo creado y etiqueta válida
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
Vertex< T, Q >* GenericGraphAlgorithms< T, Q > :: searchTag(T tag) {
    Vertex< T, Q > *result = nullptr;
    Vertex< T, Q > *temp = graph -> firstVertex();
    while(temp) {
        if(temp -> getTag() == tag)
            result = temp;
        temp = graph -> nextVertex(temp);
    } 
    return result;
}

#endif //GENERICGRAPHALGORITHMS_H