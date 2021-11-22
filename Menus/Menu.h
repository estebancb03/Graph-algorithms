#ifndef MENU_H
#define MENU_H
#include <iostream>
//#include "../Graphs/AdjacencyListGraph.h"
#include "../Graphs/AdjacencyMatrixGraph.h"
#include "../Graphs/GenericGraphAlgorithms.h"
using namespace std;

template < class T, class Q >
class Menu {
    Graph< T, Q > *graph;
    GenericGraphAlgorithms< T, Q > *graphAlgoritms;
    public: void principalManu();
};

/*
	EFECTO: maneja el uso de los métodos para grafos
	REQUIERE: ninguno
	MODIFICACIONES: varias modificaciones en el grafo de acuerdo a las opciones elegidas
*/
template < typename T, typename Q >
void Menu< T, Q > :: principalManu() {
    int option;
    bool enabled = true;
    while(enabled) {
        system("cls");
        cout << "M E N U  D E  O P C I O N E S  D E  G R A F O" << endl << endl;
        cout << "1. Crear" << endl;
        cout << "2. Destruir" << endl;
        cout << "3. Vaciar" << endl;
        cout << "4. Vacio?" << endl;
        cout << "5. Agregar vertice" << endl;
        cout << "6. Elimina vertice" << endl;
        cout << "7. Modificar etiqueta" << endl;
        cout << "8. Etiqueta?" << endl;
        cout << "9. Agregar arista" << endl;
        cout << "10. Eliminar arista" << endl;
        cout << "11. Modificar arista" << endl;
        cout << "12. Modifica peso" << endl;
        cout << "13. Peso?" << endl;
        cout << "14. Primer vertice?" << endl;
        cout << "15. Siguiente vertice?" << endl;
        cout << "16. Primer vertice adyacente?" << endl;
        cout << "17. Siguiente vertice adyacente?" << endl;
        cout << "18. Existe arista?" << endl;
        cout << "19. Numero de vertices" << endl;
        cout << "20. Averiguar si el grafo tiene ciclos" << endl;
        cout << "21. Averiguar si un grafo es conexo" << endl;
        cout << "22. Averiguar si un grafo es conexo (Warshall)" << endl;
        cout << "23. Buscar un vertice por su etiqueta" << endl;
        cout << "24. Encontrar el camino mas corto de un vertice a todos los demas" << endl;
        cout << "25. Encontrar el camino mas corto entre un par de vertices (Floyd)" << endl;
        cout << "26. Encontrar el camino mas corto entre un par de vertices (Dijkstra)" << endl;
        cout << "27. Encontrar el circuito Hamilton de menor costo" << endl;
        cout << "28. Colorear el grafo" << endl;
        cout << "29. Salir" << endl << endl;
        cout << "Opcion: "; cin >> option;
        system("cls");
        switch (option) {
            case 1: {
                graph = new Graph< T, Q >();
                graph -> create();
                graphAlgoritms = new GenericGraphAlgorithms< T, Q>(graph);
                cout << "Grafo creado correctamente" << endl << endl;
            }   break;
            case 2: {
                graph -> destroy();
                cout << "Grafo destruido correctamente" << endl << endl;
            }   break;
            case 3: {
                
            }   break;
            case 4: {
                cout << "Estado del grafo: ";
                graph -> empty() ? cout << "vacio" : cout << "no vacio";
                cout << endl << endl;
            }   break;
            case 5: {
                T tag;
                cout << "Etiqueta: "; cin >> tag;
                Vertex< T > *newVertex = graph -> addVertex(tag);
                if(newVertex)
                    cout << "Vertice agregado correctamente" << endl << endl;
                else
                    cout << "Error: el vertice no pudo ser agregado al grafo" << endl << endl;
            }   break;
            case 6: {
                if(!graph -> empty()) {
                    T tag;
                    cout << "Vertice: "; cin >> tag;
                    Vertex< T > *vertex = graph -> searchTag(tag);
                    if(vertex) {
                        graph -> deleteVertex(vertex);
                        cout << "Vertice eliminado correctamente" << endl << endl;
                    }
                    else
                        cout << "Error: vertice no existe" << endl << endl;
                }
                else
                    cout << "Error: grafo vacio" << endl << endl;
            }   break;
            case 7: {
                if(!graph -> empty()) {
                    T tag;
                    cout << "Vertice: "; cin >> tag;
                    Vertex< T > *vertex = graph -> searchTag(tag);
                    if(vertex) {
                        T newTag;
                        cout << "Nueva etiqueta: "; cin >> newTag;
                        graph -> modifyTag(vertex, newTag);
                        cout << "Etiqueta modificada correctamente" << endl << endl; 
                    }
                    else
                        cout << "Error: vertice no existe" << endl << endl;
                }
                else
                    cout << "Error: grafo vacio" << endl << endl;
            }   break;
            case 8: {
                if(!graph -> empty()) {
                    T tag;
                    cout << "Vertice: "; cin >> tag;
                    Vertex< T > *vertex = graph -> searchTag(tag);
                    if(vertex) {
                        tag = vertex -> getTag();
                        cout << "Etiqueta: " << tag << endl << endl;
                    }
                    else
                        cout << "Error: vertice no existe" << endl << endl;
                }
                else
                    cout << "Error: grafo vacio" << endl << endl;
            }   break;
            case 9: {
                if(!graph -> empty()) {
                    T tag1, tag2;
                    cout << "Vertice1: "; cin >> tag1;
                    cout << "Vertice2: "; cin >> tag2;
                    Vertex< T > *vertex1 = graph -> searchTag(tag1);
                    Vertex< T > *vertex2 = graph -> searchTag(tag2);
                    if(vertex1 && vertex2) {
                        Q weight;
                        cout << "Peso: "; cin >> weight;
                        graph -> addArista(vertex1, vertex2, weight);
                        cout << "Arista agregada correctamente" << endl << endl;
                    }
                    else
                        cout << "Error: vertice no existe" << endl << endl;
                }
                else 
                    cout << "Error: grafo vacio" << endl << endl;
            }   break;
            case 10: {
                
            }   break;
            case 11: {
                graph -> print();
            }   break;
            case 12: {
                
            }   break;
            case 13: {
                
            }   break;
            case 14: {
                if(!graph -> empty()) {
                    Vertex< T > *vertex = graph -> firstVertex();
                    T tag = graph -> tag(vertex);
                    cout << "Primer vertice: " << tag << endl << endl; 
                }
                else
                    cout << "Error: grafo vacio" << endl << endl;
            }   break;
            case 15: {
                if(!graph -> empty()) {
                    T tag;
                    cout << "Vertice: "; cin >> tag;
                    Vertex< T > *vertex = graph -> searchTag(tag);
                    if(vertex) {
                        Vertex< T > *next = graph -> nextVertex(vertex);
                        cout << "Siguiente vertice: ";
                        next ? cout << next -> getTag() : cout << "nullptr";
                        cout << endl << endl;
                    }
                    else
                        cout << "Error: vertice no existe" << endl << endl;
                }
                else
                    cout << "Error: grafo vacio" << endl << endl;
            }   break;
            case 16: {
                
            }   break;
            case 17: {
                
            }   break;
            case 18: {
                if(!graph -> empty()) {
                    T tag1, tag2;
                    cout << "Vertice1: "; cin >> tag1;
                    cout << "Vertice2: "; cin >> tag2;
                    Vertex< T > *vertex1 = graph -> searchTag(tag1);
                    Vertex< T > *vertex2 = graph -> searchTag(tag2);
                    if(vertex1 && vertex2) {
                        bool result = graph -> arista(vertex1, vertex2);
                        cout << "Estado de arista: ";
                        result ? cout << "existe" : cout << "no existe";
                        cout << endl << endl;
                    }
                    else
                        cout << "Error: vertice no existe" << endl << endl;
                }
                else 
                    cout << "Error: grafo vacio" << endl << endl;
            }   break;
            case 19: {
                int number = graph -> getVertexNumber();
                cout << "Numero de vertices: " << number << endl << endl;
            }   break;
            case 20: {
                
            }   break;
            case 21: {
                
            }   break;
            case 22: {
                
            }   break;
            case 23: {
                
            }   break;
            case 24: {
                
            }   break;
            case 25: {
                
            }   break;
            case 26: {
                
            }   break;
            case 27: {
                
            }   break;
            case 28: {
                
            }   break;
            case 29: {
                enabled = false;    
            }   break;
        }
        if(option > 0 || option < 30)
            system("pause");
    }
}

#endif //MENU_H