#ifndef DICTIONARY_H
#define DICTIONARY_H

template < class T >
class Dictionary {
    int elementNumber;
    public:
        void create();
        void destroy();
        void clear();
        bool empty();
        void addElement(T);
        void deleteElement(T);
        bool elementBelongs(T);
};

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: create() {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: destroy() {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: clear() {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
bool Dictionary< T > :: empty() {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: addElement(T element) {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Dictionary< T > :: deleteElement(T element) {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
bool Dictionary< T > :: elementBelongs(T element) {
    
}

#endif //DICTIONARY_H