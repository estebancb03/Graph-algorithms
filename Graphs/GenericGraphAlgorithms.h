#ifndef GENERICGRAPHALGORITHMS_H
#define GENERICGRAPHALGORITHMS_H
#include "../AuxiliaryModels/Dictionary.h"
#include "../AuxiliaryModels/Queue.h"
#include "../Menus/Menu.h"
#include <stack>

template < class T, class Q>
class GenericGraphAlgorithms {
    Graph< T, Q > *graph;
    public:
        GenericGraphAlgorithms(Graph< T, Q > *g) { this -> graph = g; };
        bool cycles();
        Vertex< T, Q > *searchTag(T);
        void Dijkstra(Vertex< T, Q >*);
};

/*
    EFECTO: verifia si el grafo tiene ciclos usando recorrido de ancho primero
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
bool GenericGraphAlgorithms< T, Q > :: cycles() {
    bool result = false;
    Vertex< T, Q > *adjacent;
    Vertex< T, Q > *temp = graph -> firstVertex();
    Queue< Vertex< T, Q >* > *queue = new Queue< Vertex< T, Q >* >(graph -> getVertexNumber());
    Dictionary< Vertex< T, Q >* > *dictionary = new Dictionary< Vertex< T, Q >* >(graph -> getVertexNumber());
    queue -> create();
    dictionary -> create();
    while(temp) {
        if(!dictionary -> elementExist(temp)) {
            queue -> add(temp);
            while(!queue -> empty()) {
                temp = queue -> pop();
                dictionary -> addElement(temp);
                adjacent = graph -> firstAdjacentVertex(temp);
                while(adjacent) {
                    if(!dictionary -> elementExist(adjacent))
                        queue -> add(adjacent);
                    adjacent = graph -> nextAdjacentVertex(temp, adjacent);
                }
            }
        }
        temp = graph -> nextVertex(temp);
    }
    queue -> destroy();
    dictionary -> destroy();
    return result;
}

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
void GenericGraphAlgorithms< T, Q > :: Dijkstra(Vertex< T, Q > *vertex) {
    
}

#endif //GENERICGRAPHALGORITHMS_H