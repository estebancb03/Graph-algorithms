#ifndef ADJACENCYLISTGRAPH_H
#define ADJACENCYLISTGRAPH_H
#include "../Arista/Arista.h"
#include "../Vertex/Vertex.h"
#include <List>
using namespace std;

template < class T, class Q >
class Graph {
    int vertexNumber;
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
        //Métodos auxiliares
        Arista< T, Q > *searchArista(Vertex< T, Q >*, Vertex< T, Q >*);
        Arista< T, Q > *searchArista2(Vertex< T, Q >*, Vertex< T, Q >*);
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
    vertexNumber = 0;
}

/*
    EFECTO: destruye el grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: destroy() {
    Vertex< T, Q > *temp;
    while(first) {
        temp = first;
        first = first -> getNext();
        delete(temp);
    }
    vertexNumber = 0;
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
    Vertex< T, Q > *vertex = new Vertex< T,Q >(tag);
    if(!empty()) 
        vertex -> setNext(first);
    first = vertex;
    ++vertexNumber;
} 

/*
    EFECTO: elimina un vértice del grafo
    REQUIERE: grafo creado y no vacío, vértice válido y aislado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteVertex(Vertex< T, Q > *vertex) {
    Vertex< T, Q > *past;
    Vertex< T, Q > *current = first;
    if(first == vertex)
        first = first -> getNext();
    else {
        while(current != vertex) {
            past = current;
            current = current -> getNext();
        } 
        past -> setNext(current -> getNext());
    }
    delete(current);
    --vertexNumber;
}

/*
    EFECTO: modifica la etiqueta de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido y etiqueta válida
    MODIFICA: vértice, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyTag(Vertex< T, Q > *vertex, T newTag) {
    vertex -> setTag(newTag);
}

/*
    EFECTO: devuelve la etiqueta de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
T Graph< T, Q > :: tag(Vertex< T, Q > *vertex) {
    return vertex -> getTag();
}

/*
    EFECTO: agrega una arista al grafo
    REQUIERE: grafo creado, vértices válidos y peso válido
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: addArista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2, Q weight) {
    Arista< T, Q > *arista = new Arista< T, Q >(weight);
    Arista< T, Q > *temp = vertex -> getAdjacent();
    arista -> setAdjacent(vertex2);
    vertex -> setAdjacent(arista); 
    if(temp)
        arista -> setNext(temp);
}

/*
    EFECTO: elimina arista
    REQUIERE: grafo creado y no vacío, vértices válidos y la existencia de la arista entre ellos
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteArista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    Arista< T, Q > *past;
    Arista< T, Q > *current = vertex -> getAdjacent();
    if(current -> getAdjacent() != vertex2) {
        while(current -> getAdjacent() != vertex2) {
            past = current;
            current = current -> getNext();
        }
        past -> setNext(current -> getNext());
    }
    else 
        vertex -> setAdjacent(current -> getNext());
    delete(current);
}

/*
    EFECTO: modifica el peso de una arista
    REQUIERE: grafo creado y no vacío, vértices válidos, peso válido y la existencia de la arista entre ellos
    MODIFICA: arista, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyWeight(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2, Q newWeight) {
    searchArista(vertex, vertex2) -> setWeight(newWeight);
}

/*
    EFECTO: devuelve el peso de una arista
    REQUIERE: grafo creado y no vacío, vértices válidos y la existencia de la arista entre ellos
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Q Graph< T, Q > :: weight(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    return searchArista(vertex, vertex2) -> getWeight();
}

/*
    EFECTO: devuelve el primer vértice agregado al grafo
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: firstVertex() {
    return first;
}

/*
    EFECTO: devuelve el siguiente vértice de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: nextVertex(Vertex< T, Q > *vertex) {
    return vertex -> getNext();
}

/*
    EFECTO: devuelve el primer vértice adyacente de un vértice
    REQUIERE: grafo creado y no vacío, vértice válido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: firstAdjacentVertex(Vertex< T, Q > *vertex) {
    return vertex -> getAdjacent() -> getAdjacent();
}

/*
    EFECTO: devuelve el siguiente vértice adyacente
    REQUIERE: grafo creado y no vacío, vértices válidos, y vértice adyacente
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: nextAdjacentVertex(Vertex< T, Q > *vertex, Vertex< T, Q > *adjacent) {
    Vertex< T, Q > *temp = nullptr;
    Arista< T, Q > *arista = searchArista(vertex, adjacent);
    if(arista -> getNext())
        temp = arista -> getNext() -> getAdjacent();
    return temp;
}

/*
    EFECTO: devuelve verdadero si hay arista entre dos vértices y falso si no
    REQUIERE: grafo creado y no vacío, vértices válidos
    MODIFICA: grafo
*/
template < typename T, typename Q >
bool Graph< T, Q > :: arista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    return searchArista(vertex, vertex2) ? true : false;
}

/*
    EFECTO: devuelve el número de vértices en el grafo
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
int Graph< T, Q > :: getVertexNumber() {
    return vertexNumber;
}

/*
    EFECTO: devuelve la arista existente entre dos vertices en el caso que existiera
    REQUIERE: grafo creado y no vacío, vértices válidos
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q>
Arista< T, Q >* Graph< T, Q > :: searchArista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    Arista< T, Q > *result = nullptr;
    result = searchArista2(vertex, vertex2);
    if(!result)
        result = searchArista2(vertex2, vertex);
    return result;
}

/*
    EFECTO: devuelve la arista existente entre dos vertices en el caso que existiera
    REQUIERE: grafo creado y no vacío, vértices válidos
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q>
Arista< T, Q >* Graph< T, Q > :: searchArista2(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    Arista< T, Q > *temp = nullptr;
    Arista< T, Q > *current = vertex -> getAdjacent();
    if(current) {
        if(current -> getAdjacent() == vertex2)
            temp = current;
        else {
            while(current) {
                if(current -> getAdjacent() == vertex2) 
                    temp = current;
                current = current -> getNext();
            }
        }
    }
    return temp;
}

/*
    EFECTO: busca un vértice en el grafo
    REQUIERE: grafo creado y etiqueta válida
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: searchTag(T tag) {
    Vertex< T, Q > *temp = first;
    Vertex< T, Q > *aux = nullptr;
    while(temp) {
        if(temp -> getTag() == tag)
            aux = temp;
        temp = temp -> getNext();
    }
    return aux;
}

/*
    EFECTO: imprime la matriz de adyacencia
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
void Graph< T, Q > :: print() {
    Arista< T, Q > *aTemp;
    Vertex< T, Q > *vTemp = first;
    while(vTemp) {
        cout << vTemp -> getTag() << " -> ";
        aTemp = vTemp -> getAdjacent();
        while(aTemp) {
            cout << aTemp -> getAdjacent() -> getTag() << " -> ";
            aTemp = aTemp -> getNext();
        }
        vTemp = vTemp -> getNext();
        cout << "nullptr" << endl;
    }
}

#endif //ADJACENCYLISTGRAPH_H