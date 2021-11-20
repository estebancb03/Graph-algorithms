#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;
template < class T, class Q >
class Menu {
    public: 
        void principalManu();
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

            }   break;
            case 2: {
                
            }   break;
            case 3: {
                
            }   break;
            case 4: {
                
            }   break;
            case 5: {
                
            }   break;
            case 6: {
                
            }   break;
            case 7: {
                
            }   break;
            case 8: {
                
            }   break;
            case 9: {
                
            }   break;
            case 10: {
                
            }   break;
            case 11: {
                
            }   break;
            case 12: {
                
            }   break;
            case 13: {
                
            }   break;
            case 14: {
                
            }   break;
            case 15: {
                
            }   break;
            case 16: {
                
            }   break;
            case 17: {
                
            }   break;
            case 18: {
                
            }   break;
            case 19: {
                
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
        system("pause");
    }
}

#endif //MENU_H