#ifndef ADJACENCYLISTGRAPH_H
#define ADJACENCYLISTGRAPH_H
#include "../Arista/Arista.h"
#include "../Vertex/Vertex.h"
#include <List>
using namespace std;

template < class T, class Q >
class Graph {
    int veretexNumber;
    Vertex< T, Q > *first;
    public:
        void create();
        void destroy();
        void clear();
        bool empty();
        Vertex< T, Q > *addVertex(T);
        void deleteVertex(Vertex< T, Q >*);
        void modifyTag(Vertex< T, Q >*, T);
        T tag(Vertex< T, Q >*);
        void addArista(Vertex< T, Q >*, Vertex< T, Q >*, Q);
        void deleteArista(Vertex< T, Q >*, Vertex< T, Q >*);
        void modifyWeight(Vertex< T, Q >*, Vertex< T, Q >*, Q);
        Q weight(Vertex< T, Q >*, Vertex< T, Q >*);
        Vertex< T, Q > *firstVertex();
        Vertex< T, Q > *nextVertex(Vertex< T, Q >*);
        Vertex< T, Q > *firstAdjacentVertex(Vertex< T, Q >*);
        Vertex< T, Q > *nextAdjacentVertex(Vertex< T, Q >*, Vertex< T, Q >*);
        bool arista(Vertex< T, Q >*, Vertex< T, Q >*);
        int getVertexNumber();
        Vertex< T, Q > *searchTag(T); //Provisional, hay que hacerlo general para cualquier TDA
        void print(); //Provisional
};

/*
    EFECTO: crea la instancia del grafo
    REQUIERE: grafo sin crear o destruido
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: create() {
    first = nullptr;
    veretexNumber = 0;
}

/*
    EFECTO: destruye el grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: destroy() {
    delete first;
}

/*
    EFECTO: elimina los elementos del grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: clear() {
    destroy();
    create();
}

/*
    EFECTO: devuelve el verdadero si el grafo tiene elementos y falso si no
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
bool Graph< T, Q > :: empty() {
    return !first ? true : false;
}

/*
    EFECTO: agrega un vértice al grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: addVertex(T tag) {
    
} 

/*
    EFECTO: elimina un vértice del grafo
    REQUIERE: grafo creado y no vacío, vértice válido y aislado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteVertex(Vertex< T, Q > *vertex) {
    
}

/*
    EFECTO: modifica la etiqueta de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido y etiqueta válida
    MODIFICA: vértice, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyTag(Vertex< T, Q > *vertex, T newTag) {
    
}

/*
    EFECTO: devuelve la etiqueta de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
T Graph< T, Q > :: tag(Vertex< T, Q > *vertex) {
    
}

/*
    EFECTO: agrega una arista al grafo
    REQUIERE: grafo creado, vértices válidos y peso válido
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: addArista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2, Q weight) {
    
}

/*
    EFECTO: elimina arista
    REQUIERE: grafo creado y no vacío, vértices válidos y la existencia de la arista entre ellos
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteArista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    
}

/*
    EFECTO: modifica el peso de una arista
    REQUIERE: grafo creado y no vacío, vértices válidos, peso válido y la existencia de la arista entre ellos
    MODIFICA: arista, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyWeight(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2, Q newWeight) {
    
}

/*
    EFECTO: devuelve el peso de una arista
    REQUIERE: grafo creado y no vacío, vértices válidos y la existencia de la arista entre ellos
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Q Graph< T, Q > :: weight(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    
}

/*
    EFECTO: devuelve el primer vértice agregado al grafo
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: firstVertex() {
    
}

/*
    EFECTO: devuelve el siguiente vértice de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: nextVertex(Vertex< T, Q > *vertex) {
    
}

/*
    EFECTO: devuelve el primer vértice adyacente de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: firstAdjacentVertex(Vertex< T, Q > *vertex) {
    
}

/*
    EFECTO: devuelve el siguiente vértice adyacente
    REQUIERE: grafo creado y no vacío, vértices válidos, y vértice adyacente
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: nextAdjacentVertex(Vertex< T, Q > *vertex, Vertex< T, Q > *adjacent) {
    
}

/*
    EFECTO: devuelve verdadero si hay arista entre dos vértices y falso si no
    REQUIERE: grafo creado y no vacío, vértices válidos
    MODIFICA: grafo
*/
template < typename T, typename Q >
bool Graph< T, Q > :: arista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    
}

/*
    EFECTO: devuelve el número de vértices en el grafo
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
int Graph< T, Q > :: getVertexNumber() {
    
}

/*
    EFECTO: busca un vértice en el grafo
    REQUIERE: grafo creado y etiqueta válida
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: searchTag(T tag) {
    
}

/*
    EFECTO: imprime la matriz de adyacencia
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
void Graph< T, Q > :: print() {
      
}

#endif //ADJACENCYLISTGRAPH_H