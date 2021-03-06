#ifndef ADJACENCYMATRIXGRAPH_H
#define ADJACENCYMATRIXGRAPH_H
#include "../Vertex/Vertex2.h"
#include <vector>
using namespace std;

template < class T, class Q >
class Graph {
    int size = 10;
    int vertexNumber;
    Q adjacencyMatrix[10][10];
    Vertex< T, Q > *vertexArray[10];
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
        //Auxiliares
        Vertex< T, Q > *getVertexByNumber(int);
        int getVertexPosition(Vertex< T, Q >*);
};

/*
    EFECTO: crea la instancia del grafo
    REQUIERE: grafo sin crear o destruido
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: create() {
    vertexNumber = 0;
}

/*
    EFECTO: destruye el grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: destroy() {
    create();
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
    return vertexNumber == 0 ? true : false;
}

/*
    EFECTO: agrega un v??rtice al grafo
    REQUIERE: grafo creado
    MODIFICA: grafo
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: addVertex(T tag) {
    Vertex< T, Q > *temp = nullptr;
    Q invalid = 0;
    if(vertexNumber < size) {
        temp = new Vertex< T, Q >(tag, vertexNumber);
        vertexArray[vertexNumber] = temp;
        adjacencyMatrix[vertexNumber][vertexNumber] = invalid;
        ++vertexNumber;
    }
    return temp;
} 

/*
    EFECTO: elimina un v??rtice del grafo
    REQUIERE: grafo creado y no vac??o, v??rtice v??lido y aislado
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteVertex(Vertex< T, Q > *vertex) {
    if(vertexNumber > 1 && vertex -> getPosition() < vertexNumber - 1) {
        for(int i = vertex -> getPosition(); i < vertexNumber - 1; ++i) {
            vertexArray[i + 1] -> setPosition(vertexArray[i + 1] -> getPosition() - 1);
            vertexArray[i] = vertexArray[i + 1];
        }
    }
    else 
        delete vertexArray[vertex -> getPosition()];
    --vertexNumber;
}

/*
    EFECTO: modifica la etiqueta de un v??rtice
    REQUIERE: grafo creado y no vac??o, v??rtice v??lido y etiqueta v??lida
    MODIFICA: v??rtice, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyTag(Vertex< T, Q > *vertex, T newTag) {
    vertex -> setTag(newTag);
}

/*
    EFECTO: devuelve la etiqueta de un v??rtice
    REQUIERE: grafo creado y no vac??o, v??rtice v??lido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
T Graph< T, Q > :: tag(Vertex< T, Q > *vertex) {
    return vertex -> getTag();
}

/*
    EFECTO: agrega una arista al grafo
    REQUIERE: grafo creado, v??rtices v??lidos y peso v??lido
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: addArista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2, Q weight) {
    if(vertex != vertex2) {
        int position1 = vertex -> getPosition();
        int position2 = vertex2 -> getPosition();
        adjacencyMatrix[position1][position2] = weight;
    }
}

/*
    EFECTO: elimina arista
    REQUIERE: grafo creado y no vac??o, v??rtices v??lidos y la existencia de la arista entre ellos
    MODIFICA: grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: deleteArista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    int position1 = vertex -> getPosition();
    int position2 = vertex2 -> getPosition();
    adjacencyMatrix[position1][position2] = 0;
    adjacencyMatrix[position2][position1] = 0;
}

/*
    EFECTO: modifica el peso de una arista
    REQUIERE: grafo creado y no vac??o, v??rtices v??lidos, peso v??lido y la existencia de la arista entre ellos
    MODIFICA: arista, grafo
*/
template < typename T, typename Q >
void Graph< T, Q > :: modifyWeight(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2, Q newWeight) {
    if(vertex != vertex2) {
        int position1 = vertex -> getPosition();
        int position2 = vertex2 -> getPosition();
        adjacencyMatrix[position1][position2] = newWeight;
        adjacencyMatrix[position2][position1] = newWeight;
    }  
}

/*
    EFECTO: devuelve el peso de una arista
    REQUIERE: grafo creado y no vac??o, v??rtices v??lidos y la existencia de la arista entre ellos
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Q Graph< T, Q > :: weight(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    Q result;
    if(adjacencyMatrix[vertex -> getPosition()][vertex2 -> getPosition()])
        result = adjacencyMatrix[vertex -> getPosition()][vertex2 -> getPosition()];
    else
        result = adjacencyMatrix[vertex2 -> getPosition()][vertex -> getPosition()];
    return result;
}

/*
    EFECTO: devuelve el primer v??rtice agregado al grafo
    REQUIERE: grafo creado y no vac??o
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: firstVertex() {
    return vertexArray[0];
}

/*
    EFECTO: devuelve el siguiente v??rtice de un v??rtice
    REQUIERE: grafo creado y no vac??o, v??rtice v??lido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: nextVertex(Vertex< T, Q > *vertex) {
    Vertex< T, Q > *next = nullptr;
    return vertex -> getPosition() != vertexNumber - 1 ? vertexArray[vertex -> getPosition() + 1] : nullptr;
}

/*
    EFECTO: devuelve el primer v??rtice adyacente de un v??rtice
    REQUIERE: grafo creado y no vac??o, v??rtice v??lido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: firstAdjacentVertex(Vertex< T, Q > *vertex) {
    int i = 0;
    bool enabled = true;
    Vertex< T, Q > *temp = nullptr;
    int position = vertex -> getPosition();
    while(enabled) {
        if(i < size) {
            if(adjacencyMatrix[position][i] > 0) {
                enabled = false;
                temp =  vertexArray[i];
            }
            ++i;
        }
        else
            enabled = false;
    }
    return temp;
}

/*
    EFECTO: devuelve el siguiente v??rtice adyacente
    REQUIERE: grafo creado y no vac??o, v??rtices v??lidos, y v??rtice adyacente
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: nextAdjacentVertex(Vertex< T, Q > *vertex, Vertex< T, Q > *adjacent) {
    int i = adjacent -> getPosition() + 1;
    bool enabled = true;
    Vertex< T, Q > *temp = nullptr;
    int position = vertex -> getPosition();
    while(enabled) {
        if(i < size) {
            if(adjacencyMatrix[position][i] > 0) {
                enabled = false;
                temp =  vertexArray[i];
            }
            ++i;
        }
        else
            enabled = false;
    }
    return temp;
}

/*
    EFECTO: devuelve verdadero si hay arista entre dos v??rtices y falso si no
    REQUIERE: grafo creado y no vac??o, v??rtices v??lidos
    MODIFICA: grafo
*/
template < typename T, typename Q >
bool Graph< T, Q > :: arista(Vertex< T, Q > *vertex, Vertex< T, Q > *vertex2) {
    bool result = false;
    int position1 = vertex -> getPosition();
    int position2 = vertex2 -> getPosition();
    if(vertex != vertex2) {
        if(adjacencyMatrix[position1][position2] || adjacencyMatrix[position2][position1])
            result = true;
    } 
    return result;
}

/*
    EFECTO: devuelve el n??mero de v??rtices en el grafo
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
int Graph< T, Q > :: getVertexNumber() {
    return vertexNumber;
}

/*
    EFECTO: devuelve el vertice de acuerdo a su numero
    REQUIERE: grafo creado
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
Vertex< T, Q >* Graph< T, Q > :: getVertexByNumber(int number) {
    return vertexArray[number];
}

/*
    EFECTO: devuelve la posici??n de un v??rtice
    REQUIERE: grafo creado, v??rtice v??lido
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
int Graph< T, Q > :: getVertexPosition(Vertex< T, Q > *vertex) {
    int number = 0;
    Vertex< T, Q > *temp = firstVertex();
    while(temp && temp != vertex) {
        ++number;
        temp = vertexArray[number];
    }
    return number;
}

#endif //ADJACENCYMATRIXGRAPH_H