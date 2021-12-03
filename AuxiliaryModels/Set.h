#ifndef SET_H
#define SET_H

template < class T >
class Set {
    int size;
    T *elementArray; 
    int elementNumber;
    public:
        Set(int s) { size = s; };
        void create();
        void destroy();
        void clear();
        bool empty();
        bool full();
        void addElement(T);
        void deleteElement(T);
        bool elementExist(T);
        bool isSubSet(Set< T >*);
        int getSize();
        int getElementNumber();
        T *getElementArray();
        int getElementPosition(T);
        int getRepeatedNumber(Set< T >*);
        Set< T > *setUnion(Set< T >*);
        Set< T > *setIntersection(Set< T >*);
};

/*
    EFECTO: crea el conjunto
    REQUIERE: conjunto no creado o destruido
    MODIFICA: conjunto
*/
template < typename T >
void Set< T > :: create() {
    elementNumber = 0;
    elementArray = new T[size];
}

/*
    EFECTO: destruye el conjunto
    REQUIERE: conjunto creado
    MODIFICA: conjunto
*/
template < typename T >
void Set< T > :: destroy() {
    delete []elementArray;
}

/*
    EFECTO: elimina todos los elementos del conjunto
    REQUIERE: conjunto creado
    MODIFICA: conjunto
*/
template < typename T >
void Set< T > :: clear() {
    destroy();
    create();
}

/*
    EFECTO: verifica si el conjunto está vacío
    REQUIERE: conjunto creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Set< T > :: empty() {
    return elementNumber > 0 ? false : true;
}

/*
    EFECTO: verifica si el conjunto está lleno
    REQUIERE: conjunto creado
    MODIFICA: conjunto
*/
template < typename T >
bool Set< T > :: full() {
    return elementNumber == size ? true : false;
}

/*
    EFECTO: agrega elementos al conjunto
    REQUIERE: conjunto creado y elemento válido
    MODIFICA: conjunto
*/
template < typename T >
void Set< T > :: addElement(T element) {
    if(!full() && !elementExist(element)) {
        elementArray[elementNumber] = element;
        ++elementNumber;
    }
}

/*
    EFECTO: elimina un elemento del conjunto
    REQUIERE: conjunto creado y elemento válido
    MODIFICA: conjunto
*/
template < typename T >
void Set< T > :: deleteElement(T element) {
    int position = getElementPosition(element);
    if(elementExist(element)) {
        if(position < elementNumber - 1) {
            for(int i = position; i < elementNumber; ++i)
                elementArray[i] = elementArray[i + 1];
        }
        --elementNumber;
    }
}

/*
    EFECTO: verifica si un elemento pertenece al conjunto
    REQUIERE: conjunto creado y elemento válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Set< T > :: elementExist(T element) {
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
    EFECTO: devuelve el tamaño del conjunto
    REQUIERE: conjunto creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Set< T > :: getSize() {
    return size;
}

/*
    EFECTO: devuelve el numero de elementos en el conjunto
    REQUIERE: conjunto creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Set< T > :: getElementNumber() {
    return elementNumber;
}

/*
    EFECTO: devuelve el array del conjunto
    REQUIERE: conjunto creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
T* Set< T > :: getElementArray() {
    return elementArray;
}

/*
    EFECTO: devuelve la posición de un elemento en el array
    REQUIERE: conjunto creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Set< T > :: getElementPosition(T element) {
    int i = 0;
    int position = 0;
    bool enabled = true;
    while(enabled) {
        if(element == elementArray[i]) {
            position = i;
            enabled = false;
        }
        if(i > elementNumber)
            enabled = false;
        i++;
    }
    return position;
}

/*
    EFECTO: devuelve el numero de elementos repetidos entre dos conjuntos
    REQUIERE: conjuntos creados
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Set< T > :: getRepeatedNumber(Set< T > *otherSet) {
    int counter = 0;
    T *thisSetArray = getElementArray();
    T *otherSetArray = otherSet -> getElementArray();
    for(int i = 0; i < otherSet -> getElementNumber(); ++i) {
        for(int j = 0; j < elementNumber; ++j) {
            if(otherSetArray[i] == thisSetArray[j])
                ++counter;
        }
    }
    return counter;
}

/*
    EFECTO: devuelve verdadero si otro conjunto es subconjunto de este
    REQUIERE: conjuntos creados
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Set< T > :: isSubSet(Set< T > *otherSet) {
    bool result = false;
    int otherSetElementNumber = otherSet -> getElementNumber();
    if(elementNumber >= otherSetElementNumber && getRepeatedNumber(otherSet) == otherSetElementNumber)
        result = true;
    return result;
}

/*
    EFECTO: devuelve el conjunto unón de dos conjuntos
    REQUIERE: conjuntos creados
    MODIFICA: no hace modificaciones
*/
template < typename T >
Set< T >* Set< T > :: setUnion(Set< T > *otherSet) {
    T *thisSetArray = getElementArray();
    T *otherSetArray = otherSet -> getElementArray();
    int unionSize = elementNumber + otherSet -> getElementNumber() - getRepeatedNumber(otherSet);
    Set< T > *unionSet = new Set< T > (unionSize);
    unionSet -> create();
    for(int i = 0; i < elementNumber; ++i) 
        unionSet -> addElement(thisSetArray[i]);
    for(int j = 0; j < otherSet -> getElementNumber(); ++j) 
        unionSet -> addElement(otherSetArray[j]);
    return unionSet;
}

/*
    EFECTO: devuelve el conjunto intercepción de dos conjuntos
    REQUIERE: conjuntos creados
    MODIFICA: no hace modificaciones
*/
template < typename T >
Set< T >* Set< T > :: setIntersection(Set< T > *otherSet) {
    T *thisSetArray = getElementArray();
    T *otherSetArray = otherSet -> getElementArray();
    int intersectionSize = getRepeatedNumber(otherSet);
    Set< T > *intersectionSet = new Set< T > (intersectionSize);
    intersectionSet -> create();
    for(int i = 0; i < otherSet -> getElementNumber(); ++i) {
        for(int j = 0; j < elementNumber; ++j) {
            if(otherSetArray[i] == thisSetArray[j])
                intersectionSet -> addElement(thisSetArray[j]);
        }
    }
    for(int k = 0; k < intersectionSize; ++k) {
                cout << intersectionSet -> getElementArray()[k];
    }
    return intersectionSet;
}

#endif //SET