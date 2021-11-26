#ifndef GENERICGRAPHALGORITHMS_H
#define GENERICGRAPHALGORITHMS_H
#include "../Menus/Menu.h"

template < class T, class Q>
class GenericGraphAlgorithms {
    Graph< T, Q > *graph;
    public:
        GenericGraphAlgorithms(Graph< T, Q > *g) { this -> graph = g; };
        Vertex< T, Q > *searchTag(T);
        void Dijkstra(Vertex< T, Q >*, Vertex< T, Q >*);
};

/*
    EFECTO: busca un vértice en el grafo
    REQUIERE: grafo creado y etiqueta válida
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
Vertex< T, Q >* GenericGraphAlgorithms< T, Q > :: searchTag(T tag) {
    bool enabled = true;
    Vertex< T, Q > *result = nullptr;
    Vertex< T, Q > *temp = graph -> firstVertex();
    while(temp && enabled) {
        if(temp -> getTag() == tag) {
            result = temp;
            enabled = false;
        }
        temp = graph -> nextVertex(temp);
    } 
    return result;
}

/*
    EFECTO: imprime el camino más corto de un vertice a otro
    REQUIERE: grafo creado y no vacío, vertices válidos
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: Dijkstra(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {

}

#endif //GENERICGRAPHALGORITHMS_H