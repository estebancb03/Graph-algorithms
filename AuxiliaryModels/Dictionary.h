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
        void addElement(T*);
        void deleteElement(T*);
        bool elementBelongs(T*);
};

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: create() {
    elementNumber = 0;
    elementArray = new T*[size];
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: destroy() {
    delete []elementArray;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: clear() {
    destroy();
    create();
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
bool Dictionary< T > :: empty() {
    return elementNumber > 0 ? false : true;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
bool Dictionary< T > :: full() {
    return elementNumber == size - 1 ? true : false;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: addElement(T *element) {
    if(!full()) {
        elementArray[elementNumber] = element;
        ++elementNumber;
    }
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: deleteElement(T *element) {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
bool Dictionary< T > :: elementBelongs(T *element) {

}

#endif //DICTIONARY_H