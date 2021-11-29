#ifndef GENERICGRAPHALGORITHMS_H
#define GENERICGRAPHALGORITHMS_H
#include "../AuxiliaryModels/Dictionary.h"
#include "../AuxiliaryModels/Stack.h"
#include "../AuxiliaryModels/Queue.h"
#include "../Menus/Menu.h"

template < class T, class Q>
class GenericGraphAlgorithms {
    Graph< T, Q > *graph;
    public:
        GenericGraphAlgorithms(Graph< T, Q > *g) { this -> graph = g; };
        bool cycles();
        bool isConnected();
        void isConnectedRecursive(Vertex< T, Q >*, Dictionary< Vertex< T, Q >* >*, Dictionary< Vertex< T, Q >* >*);
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
    
    return result;
}

/*
    EFECTO: verifia si el grafo es conexo usando recorrido en profundidad primero
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
bool GenericGraphAlgorithms< T, Q > :: isConnected() {
    bool result = false;
    Vertex< T, Q > *temp = graph -> firstVertex();
    Dictionary< Vertex< T, Q >* > *dictionary = new Dictionary< Vertex< T, Q >* >(graph -> getVertexNumber());
    Dictionary< Vertex< T, Q >* > *adjacentDictionary = new Dictionary< Vertex< T, Q >* >(graph -> getVertexNumber());
    dictionary -> create();
    adjacentDictionary -> create();
    while(temp) {
        if(!dictionary -> elementExist(temp))
            isConnectedRecursive(temp, dictionary, adjacentDictionary);
        temp = graph -> nextVertex(temp);
    }
    if(adjacentDictionary -> getElementNumber() == graph -> getVertexNumber() - 1)
        result = true;
    dictionary -> destroy();
    adjacentDictionary -> destroy();
    return result;
}

/*
    EFECTO: verifia si el grafo es conexo usando recorrido de ancho primero
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: isConnectedRecursive(Vertex< T, Q > *vertex, Dictionary< Vertex< T, Q >* > *dictionary, Dictionary< Vertex< T, Q >* > *adjacentDictionary) {
    dictionary -> addElement(vertex);
    Vertex< T, Q > *adjacent = graph -> firstAdjacentVertex(vertex);
    while(adjacent) {
        if(!dictionary -> elementExist(adjacent)) {
            if(!adjacentDictionary -> elementExist(adjacent))
                adjacentDictionary -> addElement(adjacent);
            isConnectedRecursive(adjacent, dictionary, adjacentDictionary);
        }
        adjacent = graph -> nextAdjacentVertex(vertex, adjacent);
    }
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