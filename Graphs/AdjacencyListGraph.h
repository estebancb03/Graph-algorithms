#ifndef ADJACENCYLISTGRAPH_H
#define ADJACENCYLISTGRAPH_H
#include "../Arista/Arista.h"
#include "../Vertex/Vertex.h"
#include <List>
using namespace std;

template < class T, class Q >
class Graph {
    int veretxNumber;
    Vertex< T > **vertexArray;
    list< Arista< T, Q >* > adjacencyList;
    public:
        void create();
        void destroy();
        void clear();
        bool empty();
        Vertex< T > *addVertex(T);
        void deleteVertex(Vertex< T >*);
        void modifyTag(Vertex< T >*, T);
        T tag(Vertex< T >*);
        void addArista(Vertex< T >*, Vertex< T >*, Q);
        void deleteArista(Vertex< T >*, Vertex< T >*);
        void modifyWeight(Vertex< T >*, Vertex< T >*, Q);
        Q weight(Vertex< T >*, Vertex< T >*);
        Vertex< T > *firstVertex();
        Vertex< T > *nextVertex(Vertex< T >*);
        Vertex< T > *firstAdjacentVertex(Vertex< T >*);
        Vertex< T > *nextAdjacentVertex(Vertex< T >*, Vertex< T >*);
        bool arista(Vertex< T >*, Vertex< T >*);
        int getVertexNumber();
        Vertex< T > *searchTag(T); //Provisional, hay que hacerlo general para cualquier TDA
        void print(); //Provisional
};

/*
    EFECTO: crea la instancia del grafo
    REQUIERE: grafo sin crear o destruido
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: create() {
    
}

/*
    EFECTO: destruye el grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: destroy() {
    
}

/*
    EFECTO: elimina los elementos del grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: clear() {
    
}

/*
    EFECTO: devuelve el verdadero si el grafo tiene elementos y falso si no
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
bool Graph< T, Q > :: empty() {
    
}

/*
    EFECTO: agrega un vértice al grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: addVertex(T tag) {
    
} 

/*
    EFECTO: elimina un vértice del grafo
    REQUIERE: grafo creado y no vacío, vértice válido y aislado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteVertex(Vertex< T > *vertex) {
    
}

/*
    EFECTO: modifica la etiqueta de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido y etiqueta válida
    MODIFICA: vértice, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyTag(Vertex< T > *vertex, T newTag) {
    
}

/*
    EFECTO: devuelve la etiqueta de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
T Graph< T, Q > :: tag(Vertex< T > *vertex) {
    
}

/*
    EFECTO: agrega una arista al grafo
    REQUIERE: grafo creado, vértices válidos y peso válido
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: addArista(Vertex< T > *vertex, Vertex< T > *vertex2, Q weight) {
    
}

/*
    EFECTO: elimina arista
    REQUIERE: grafo creado y no vacío, vértices válidos y la existencia de la arista entre ellos
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteArista(Vertex< T > *vertex, Vertex< T > *vertex2) {
    
}

/*
    EFECTO: modifica el peso de una arista
    REQUIERE: grafo creado y no vacío, vértices válidos, peso válido y la existencia de la arista entre ellos
    MODIFICA: arista, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyWeight(Vertex< T > *vertex, Vertex< T > *vertex2, Q newWeight) {
    
}

/*
    EFECTO: devuelve el peso de una arista
    REQUIERE: grafo creado y no vacío, vértices válidos y la existencia de la arista entre ellos
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Q Graph< T, Q > :: weight(Vertex< T > *vertex, Vertex< T > *vertex2) {
    
}

/*
    EFECTO: devuelve el primer vértice agregado al grafo
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: firstVertex() {
    
}

/*
    EFECTO: devuelve el siguiente vértice de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: nextVertex(Vertex< T > *vertex) {
    
}

/*
    EFECTO: devuelve el primer vértice adyacente de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: firstAdjacentVertex(Vertex< T > *vertex) {
    
}

/*
    EFECTO: devuelve el siguiente vértice adyacente
    REQUIERE: grafo creado y no vacío, vértices válidos, y vértice adyacente
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T >* Graph< T, Q > :: nextAdjacentVertex(Vertex< T > *vertex, Vertex< T > *adjacent) {
    
}

/*
    EFECTO: devuelve verdadero si hay arista entre dos vértices y falso si no
    REQUIERE: grafo creado y no vacío, vértices válidos
    MODIFICA: grafo
*/
template < typename T, typename Q >
bool Graph< T, Q > :: arista(Vertex< T > *vertex, Vertex< T > *vertex2) {
    
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
Vertex< T >* Graph< T, Q > :: searchTag(T tag) {
    
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