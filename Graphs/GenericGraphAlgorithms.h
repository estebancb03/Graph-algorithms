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
        void Dijkstra(Vertex< T, Q >*, int);
        void nDijkstra();
        int minimumDistance(Q*, bool*);
        void Floyd();
        void lowestCostHamiltonCircuit();
        void lowestCostHamiltonCircuitRecursive(int, Q, Set< int >**, Dictionary< int >*);
        void paintGraph();
        void paintGraphRecursive(int, Set< int >**, Set< int >*, Set< int >*);
        Set< int > **getAdjacentSetArray();
};

/*
    EFECTO: verifia si el grafo tiene ciclos usando recorrido de ancho primero
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
bool GenericGraphAlgorithms< T, Q > :: cycles() {
    int cont = 0;
    bool result = false;
    queue< Vertex< T, Q >* > queue;
    Vertex< T, Q > *aux = nullptr;
    Vertex< T, Q > *adjacent = nullptr;
    Vertex< T, Q > *temp = graph -> firstVertex();
    Dictionary< Vertex< T, Q >* > *dictionary = new Dictionary< Vertex< T, Q >* >(graph -> getVertexNumber());
    dictionary -> create();
    while(temp) {
        if(!dictionary -> elementExist(temp)) {
            queue.push(temp);
            dictionary -> addElement(temp);
            while (!queue.empty()) {
                aux = queue.front();
                queue.pop();
                adjacent = graph -> firstAdjacentVertex(aux);
                while(adjacent) {
                    if(!dictionary -> elementExist(adjacent)) {
                        queue.push(adjacent);
                        dictionary -> addElement(adjacent);
                    }
                    ++cont;
                    adjacent = graph -> nextAdjacentVertex(aux, adjacent);
                }
            }
        }
        temp = graph -> nextVertex(temp);
    }
    if(dictionary -> getElementNumber() <= cont)
        result = true;
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
void GenericGraphAlgorithms< T, Q > :: Dijkstra(Vertex< T, Q > *origin, int finalPosition) {
    int minimum;
    int vertexNumber = graph -> getVertexNumber();
    Q INF = INT64_MAX;
    Q matrix[vertexNumber][vertexNumber];
    Q distance[vertexNumber];
    bool viewed[vertexNumber];
    Vertex< T, Q > *temp;
    Vertex< T, Q > *temp2;
    Dictionary< T > *path[vertexNumber][vertexNumber];
    for(int i = 0; i < vertexNumber; ++i) {
        distance[i] = INF;
        viewed[i] = false;
        temp = graph -> getVertexByNumber(i);
        for(int j = 0; j < vertexNumber; ++j) {
            path[i][j] = new Dictionary< T >(vertexNumber);
            path[i][j] -> create();
            temp2 = graph -> getVertexByNumber(j);
            if(graph -> arista(temp, temp2))
                matrix[i][j] = graph -> weight(temp, temp2);
            else {
                if(i == j)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = INF;
            }
        }
    }
    distance[graph -> getVertexPosition(origin)] = 0;
    for(int i = 0; i < vertexNumber; ++i) {
        minimum = minimumDistance(distance, viewed);
        viewed[minimum] = true;
        for(int j = 0; j < vertexNumber; ++j) {
            if(minimum != finalPosition) {
                if(!viewed[j] && matrix[minimum][j] && distance[minimum] != INF && distance[minimum] + matrix[minimum][j] < distance[j]) {
                    distance[j] = distance[minimum] + matrix[minimum][j];
                    path[graph -> getVertexPosition(origin)][j] -> addElement(minimum);
                }
            }
            else
                i = vertexNumber;
        }   
    }
    for(int i = 0; i < finalPosition; ++i) {
        cout << "[" << origin -> getTag() << " -> " << graph -> getVertexByNumber(i) -> getTag() << "] ";
        if(distance[i] != INF)
            cout << "(costo: " << distance[i] << "): ";
        else
            cout << "(costo: Infinito): ";
        for(int j = 0; j < vertexNumber; ++j)
            path[graph -> getVertexPosition(origin)][j] -> print();
        cout << endl;
    }
}

/*
    EFECTO: calcula la distancia mínima entre értices
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
int GenericGraphAlgorithms< T, Q > :: minimumDistance(Q *distance, bool *viewed) {
    int index;
    Q minimum = INT64_MAX;
    for(int i = 0; i < graph -> getVertexNumber(); ++i) {
        if(!viewed[i] && distance[i] <= minimum) {
            index = i;
            minimum = distance[i];
        }
    }    
    return index;
}

/*
    EFECTO: encuentra el camino más corto entre todo par de vertices
    REQUIERE: grafo creado y no vacío
    MODIFICA: no hace modificaciones 
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: nDijkstra() {
    Vertex< T, Q > *temp;
    for(int i = 0; i < graph -> getVertexNumber(); ++i) {
        temp = graph -> getVertexByNumber(i);
        Dijkstra(temp, graph -> getVertexNumber());
    }
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
    Q INF = 100000;
    Vertex< T, Q > *vertexI = nullptr;
    Vertex< T, Q > *vertexJ = nullptr;
    int vertexNumber = graph -> getVertexNumber();
    Dictionary< T > *dictionary[vertexNumber][vertexNumber];
    Q distance[vertexNumber][vertexNumber];
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
    REQUIERE: grafo creado, no vacio y conexo
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: lowestCostHamiltonCircuit() {
    Q initialWeight;
    int vertexNumber = graph -> getVertexNumber();
    Vertex< T, Q > *origin;
    Vertex< T, Q > *destiny;
    Set< int > *adjacentSet[vertexNumber];
    Dictionary< int > *bestDictionary = new Dictionary< int >(vertexNumber+1);
    bestDictionary -> create();
    for(int i = 0; i < vertexNumber; ++i){
        adjacentSet[i] = new Set< int >(vertexNumber);
        adjacentSet[i] -> create();
        origin = graph -> getVertexByNumber(i);
        bestDictionary -> addElement(i);
        for(int j = 0; j < vertexNumber; ++j) {
            destiny = graph -> getVertexByNumber(j);
            if(graph -> arista(origin, destiny)) {
                initialWeight += graph -> weight(origin, destiny);
                adjacentSet[i] -> addElement(j);
            }
        }
    }
    lowestCostHamiltonCircuitRecursive(0,initialWeight,adjacentSet,bestDictionary);
    bestDictionary -> print();
    cout << endl;
}

/*
    EFECTO: encuentra el circuito Hamilton de menor costo
    REQUIERE: grafo creado, no vacio y conexo
    MODIFICA: no hace modificaciones
*/
template < typename T, typename Q >
void GenericGraphAlgorithms< T, Q > :: lowestCostHamiltonCircuitRecursive(int vertex, Q bestWeight,
                                                                          Set< int >** adjacentSet, 
                                                                          Dictionary< int >* bestDictionary){
    Set< int > *temp = new Set< int >(graph -> getVertexNumber());
    Dictionary< int >* currentDictionary = new Dictionary< int >(graph -> getVertexNumber());
    currentDictionary -> create();
    Q weight = 0;
    for(int i = 0; i < adjacentSet[vertex] -> getElementNumber()-1; ++i){
        temp = adjacentSet[vertex];
        if(currentDictionary -> getElementNumber() != graph -> getVertexNumber() 
           || adjacentSet[vertex] -> elementExist(0)){
            if(!currentDictionary -> elementExist(temp -> getElementByNumber(i)))
                currentDictionary -> addElement(temp -> getElementByNumber(i));

            if( currentDictionary -> getElementNumber() == graph -> getVertexNumber() 
                && adjacentSet[vertex] -> elementExist(0)){
                for(int j = 0 ; j < graph -> getVertexNumber()-1; j++){
                    weight += graph -> weight(graph -> getVertexByNumber(currentDictionary -> getElementByNumber(j))
                                             ,graph -> getVertexByNumber(currentDictionary -> getElementByNumber(j+1)));
                }
                if(weight < bestWeight){
                    bestWeight = weight;
                    bestDictionary = currentDictionary;
                }
            }
            else
                lowestCostHamiltonCircuitRecursive(temp -> getElementByNumber(i), bestWeight, adjacentSet, bestDictionary);
            if(currentDictionary -> elementExist(temp -> getElementByNumber(i)))
                currentDictionary -> deleteElement(temp -> getElementByNumber(i));
            weight = 0;
        }
    }
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

#endif //GENERICGRAPHALGORITHMS_H