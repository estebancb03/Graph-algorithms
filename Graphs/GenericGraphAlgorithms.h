#ifndef GENERICGRAPHALGORITHMS_H
#define GENERICGRAPHALGORITHMS_H
#include "../AuxiliaryModels/Dictionary.h"
#include "../AuxiliaryModels/Stack.h"
#include "../AuxiliaryModels/Set.h"
#include "../Menus/Menu.h"
#include <queue>

template < class T, class Q>
class GenericGraphAlgorithms {
    Graph< T, Q > *graph;
    public:
        GenericGraphAlgorithms(Graph< T, Q > *g) { this -> graph = g; };
        bool cycles();
        bool isConnected();
        bool isConnectedUsingWarshall();
        void isConnectedRecursive(Vertex< T, Q >*, Dictionary< Vertex< T, Q >* >*, Dictionary< Vertex< T, Q >* >*);
        Vertex< T, Q > *searchTag(T);
        void Dijkstra(Vertex< T, Q >*, Vertex< T, Q >*);
        void Floyd();
        void lowestCostHamiltonCircuit();
        void lowestCostHamiltonCircuitRecursive();
        void paintGraph();
        void paintGraphRecursive(int,Set< int >**,Set< int >*,Set< int >*);
        Set< int > **getAdjacentSetArray();
};

/*
    EFECTO: verifia si el grafo tiene ciclos usando recorrido de ancho primero
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
bool GenericGraphAlgorithms< T, Q > :: cycles() {
    bool result = false;
    queue< Vertex< T, Q >* > queue;
    Vertex< T, Q > *aux = nullptr;
    Vertex< T, Q > *adjacent = nullptr;
    Vertex< T, Q > *temp = graph -> firstVertex();
    Dictionary< Vertex< T, Q >* > *global = new Dictionary< Vertex< T, Q >* >(graph -> getVertexNumber());
    Dictionary< Vertex< T, Q >* > *dictionary = new Dictionary< Vertex< T, Q >* >(graph -> getVertexNumber());
    global -> create();
    dictionary -> create();
    while(temp) {
        if(!dictionary -> elementExist(temp)) {
            queue.push(temp);
            while (!queue.empty()) {
                aux = queue.front();
                queue.pop();
                adjacent = graph -> firstAdjacentVertex(aux);
                while(adjacent) {
                    if(!dictionary -> elementExist(adjacent)) {
                        queue.push(adjacent);
                        dictionary -> addElement(adjacent);
                    }
                    global -> addElement(adjacent);
                    adjacent = graph -> nextAdjacentVertex(aux, adjacent);
                }
            }
        }
        temp = graph -> nextVertex(temp);
    }
    if(global -> getElementNumber() > dictionary -> getElementNumber())
        result = true;
    global -> destroy();
    dictionary -> destroy();
    return result;
}

/*
    EFECTO: verifica si el grafo es conexo usando recorrido en profundidad primero
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
        if(!adjacentDictionary -> elementExist(adjacent))
                adjacentDictionary -> addElement(adjacent);
        if(!dictionary -> elementExist(adjacent)) 
            isConnectedRecursive(adjacent, dictionary, adjacentDictionary);
        adjacent = graph -> nextAdjacentVertex(vertex, adjacent);
    }
}

/*
    EFECTO: verifica si el grafo es conexo usando Warshall
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
bool GenericGraphAlgorithms< T, Q > :: isConnectedUsingWarshall() {
    int i = 0;
    int j = 0;
    int k = 0;
    int middle = 0;
    int destiny = 0;
    int beginning = 0;
    bool result = true;
    Vertex< T, Q > *vertexI = nullptr;
    Vertex< T, Q > *vertexJ = nullptr;
    int vertexNumber = graph -> getVertexNumber();
    bool matrix[vertexNumber][vertexNumber];
    for(i = 0; i < vertexNumber; ++i) {
        vertexI = graph -> getVertexByNumber(i);
        for(j = 0; j < vertexNumber; ++j) {
            vertexJ = graph -> getVertexByNumber(j);
            if(graph -> arista(vertexI, vertexJ) || i == j) 
                matrix[i][j] = true;
            else 
                matrix[i][j] = false;
        }
    }
    for(middle = 0; middle < vertexNumber; ++middle) {
        for(beginning = 0; beginning < vertexNumber; ++beginning) {
            for(destiny = 0; destiny < vertexNumber; ++destiny) {
                if(!matrix[beginning][destiny] && matrix[beginning][middle] && matrix[middle][destiny])
                    matrix[beginning][destiny] = true;
            }
        }
    }
    for(i = 0; i < vertexNumber; ++i) {
        for(j = 0; j < vertexNumber; ++j) {
            if(!matrix[i][j])
                result = false;
        }
    }
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
void GenericGraphAlgorithms< T, Q > :: Dijkstra(Vertex< T, Q > *origin, Vertex< T, Q > *destiny) {
    
}

/*
    EFECTO: encuentra el camino más corto entre todo par de vertices
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: Floyd() {
    int i = 0;
    int j = 0;
    int k = 0;
    int middle = 0;
    int destiny = 0;
    int beginning = 0;
    double INF = 100000;
    Vertex< T, Q > *vertexI = nullptr;
    Vertex< T, Q > *vertexJ = nullptr;
    int vertexNumber = graph -> getVertexNumber();
    Dictionary< T > *dictionary[vertexNumber][vertexNumber];
    double distance[vertexNumber][vertexNumber];
    for(i = 0; i < vertexNumber; ++i) {
        vertexI = graph -> getVertexByNumber(i);
        for(j = 0; j < vertexNumber; ++j) {
            vertexJ = graph -> getVertexByNumber(j);
            dictionary[i][j] = new Dictionary< T >(vertexNumber);
            dictionary[i][j] -> create();
            if(graph -> arista(vertexI, vertexJ)) 
                distance[i][j] = graph -> weight(vertexI, vertexJ);
            else {
                if(i == j) 
                    distance[i][j] = 0;
                else 
                    distance[i][j] = INF;
            }
        }
    }
    for(middle = 0; middle < vertexNumber; ++middle) {
        for(beginning = 0; beginning < vertexNumber; ++beginning) {
            for(destiny = 0; destiny < vertexNumber; ++destiny) {
                if(distance[beginning][destiny] > distance[beginning][middle] + distance[middle][destiny]) {
                    distance[beginning][destiny] = distance[beginning][middle] + distance[middle][destiny];
                    for(k = beginning + 1; k < destiny; ++k)
                        dictionary[beginning][destiny] -> addElement(graph -> getVertexByNumber(k) -> getTag());
                    for(k = destiny - 1; k > beginning; --k)
                        dictionary[destiny][beginning] -> addElement(graph -> getVertexByNumber(k) -> getTag());
                }
            }
        }
    }
    for(i = 0; i < vertexNumber; ++i) {
        vertexI = graph -> getVertexByNumber(i);
        for(j = 0; j < vertexNumber; ++j) {
            vertexJ = graph -> getVertexByNumber(j);
            cout << "[" << vertexI -> getTag() << " -> " << vertexJ -> getTag() << "] (costo: ";
            distance[i][j] != INF ? cout << distance[i][j] : cout << "Infinito";
            cout << "): ";
            if(vertexI != vertexJ && distance[i][j] != INF) {
                cout << vertexI -> getTag() << " -> ";
                dictionary[i][j] -> print(); 
                cout << vertexJ -> getTag();
            }
            cout << endl;
        }
    }
}

/*
    EFECTO: encuentra el circuito Hamilton de menor costo
    REQUIERE: grafo creado y no vacio
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: lowestCostHamiltonCircuit() {

}

/*
    EFECTO: encuentra el circuito Hamilton de menor costo
    REQUIERE: grafo creado y no vacio
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: lowestCostHamiltonCircuitRecursive() {
    
}

/*
    EFECTO: colorea el grafo con la menor cantidad de colores posibles
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: paintGraph() {
    Set< int > *answer[graph -> getVertexNumber()]; 
    Vertex< T, Q > *origin;
    Vertex< T, Q > *destiny;
    Vertex< T, Q > *temp;
    int vertexNumber = graph -> getVertexNumber() - 1;
    Set< int > *adjacentSets[vertexNumber]; //cada espacio contiene los vertices adyacentes de un vertice N
    Set< int > *minimumUsedColors = new Set< int >(vertexNumber);
    Set< int > *usedColors = new Set< int >(vertexNumber);
    usedColors -> create();
    minimumUsedColors -> create();
    for(int i = 0; i < vertexNumber; ++i) {
        adjacentSets[i] = new Set< int >(vertexNumber);
        adjacentSets[i] -> create();
        origin = graph -> getVertexByNumber(i);
        minimumUsedColors -> addElement(i);
        for(int j = 0; j < vertexNumber; ++j) {
            destiny = graph -> getVertexByNumber(j);
            if(graph -> arista(origin, destiny))
                adjacentSets[i] -> addElement(j);
        }
    }
    paintGraphRecursive(0,adjacentSets,usedColors,minimumUsedColors);
    cout << minimumUsedColors -> getElementNumber() << endl;
}

/*
    EFECTO: colorea el grafo con la menor cantidad de colores posibles
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: paintGraphRecursive(int number, Set< int >**adjacentSets, Set< int >*usedColors, Set< int >*minimumUsedColors) {
    int vertexNumber = graph -> getVertexNumber() - 1;
    Set< int > *paintedSets[vertexNumber]; //cada espacio contiene los vertices pintados de un color N
    for(int i = 0; i < vertexNumber; ++i) {
        paintedSets[i] = new Set< int >(vertexNumber);
        paintedSets[i] -> create();
    }
    //--------------------------------------------------------
    for(int i = 0; i < vertexNumber; ++i) {
        if(adjacentSets[number] -> getRepeatedNumber(paintedSets[i]) == 0) {
            paintedSets[i] -> addElement(number);
            if(!usedColors -> elementExist(i))
                usedColors -> addElement(i);
            if(number == vertexNumber) {
                if(usedColors -> getElementNumber() < minimumUsedColors -> getElementNumber()) {
                    minimumUsedColors -> copySet(usedColors); //Actualiza
                }
            }
            else
                paintGraphRecursive(number + 1,adjacentSets,usedColors,minimumUsedColors);
            if(paintedSets[i] -> getElementNumber() == 1)
                usedColors -> deleteElement(i);
            paintedSets[i] -> deleteElement(number);
        }
    }
    cout << "Colores minimos actualizados[" << number << "] :";
    minimumUsedColors -> print();
    cout << endl;
}

/*
    EFECTO: crea un arreglo de conjuntos con los adyacentes de cada vertice indexado
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
/*template < typename T, typename Q >
Set< int >** GenericGraphAlgorithms< T, Q > :: getAdjacentSetArray() {
    Vertex< T, Q > *origin;
    Vertex< T, Q > *destiny;
    int vertexNumber = graph -> getVertexNumber();
    Set< int > *array[vertexNumber];
    for(int i = 0; i < vertexNumber; ++i) {
        array[i] = new Set< int >(vertexNumber);
        array[i] -> create();
    }
    for(int i = 0; i < vertexNumber; ++i) {
        origin = graph -> getVertexByNumber(i);
        for(int j = 0; j < vertexNumber; ++j) {
            destiny = graph -> getVertexByNumber(j);
            if(graph -> arista(origin, destiny))
                array[i] -> addElement(j);
        }
    }
    return array;
}*/ 

#endif //GENERICGRAPHALGORITHMS_H