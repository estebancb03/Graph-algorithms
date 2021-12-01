#ifndef DICTIONARY_H
#define DICTIONARY_H

template < class T >
class Dictionary {
    int size;
    T *elementArray; 
    int elementNumber;
    public:
        Dictionary(int s) { size = s; };
        void create();
        void destroy();
        void clear();
        bool empty();
        bool full();
        void addElement(T);
        void deleteElement();
        bool elementExist(T);
        int getElementNumber();
        void print();
};

/*
    EFECTO: crea el diccionario
    REQUIERE: diccionario no creado o destruido
    MODIFICA: diccionario
*/
template < typename T >
void Dictionary< T > :: create() {
    elementNumber = 0;
    elementArray = new T[size];
}

/*
    EFECTO: destruye el diccionario
    REQUIERE: diccionario creado
    MODIFICA: diccionario
*/
template < typename T >
void Dictionary< T > :: destroy() {
    delete []elementArray;
}

/*
    EFECTO: elimina todos los elementos del diccionario
    REQUIERE: diccionario creado
    MODIFICA: diccionario
*/
template < typename T >
void Dictionary< T > :: clear() {
    destroy();
    create();
}

/*
    EFECTO: verifica si el diccionario está vacío
    REQUIERE: diccionario creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Dictionary< T > :: empty() {
    return elementNumber > 0 ? false : true;
}

/*
    EFECTO: verifica si el diccionario está lleno
    REQUIERE: diccionario creado
    MODIFICA: diccionario
*/
template < typename T >
bool Dictionary< T > :: full() {
    return elementNumber == size - 1 ? true : false;
}

/*
    EFECTO: agrega elementos al diccionario
    REQUIERE: diccionario creado y elemento válido
    MODIFICA: diccionario
*/
template < typename T >
void Dictionary< T > :: addElement(T element) {
    if(!full()) {
        elementArray[elementNumber] = element;
    }
    ++elementNumber;
}

/*
    EFECTO: elimina un elemento del diccionario
    REQUIERE: diccionario creado y elemento válido
    MODIFICA: diccionario
*/
template < typename T >
void Dictionary< T > :: deleteElement() {
    delete[elementNumber];
    --elementNumber;
}

/*
    EFECTO: verifica si un elemento pertenece al diccionario
    REQUIERE: diccionario creado y elemento válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Dictionary< T > :: elementExist(T element) {
    int i = 0;
    bool exist = false;
    while(i < elementNumber && exist == false) {
        if(elementArray[i] == element) 
            exist = true;
        ++i;
    }
    return exist;
}

/*
    EFECTO: devuelve el numero de elementos en el diccionario
    REQUIERE: diccionario creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Dictionary< T > :: getElementNumber() {
    return elementNumber;
}

template < typename T >
void Dictionary< T > :: print() {
    for(int i = 0; i < elementNumber; ++i)
        cout << elementArray[i] << " -> ";
}

#endif //DICTIONARY_H