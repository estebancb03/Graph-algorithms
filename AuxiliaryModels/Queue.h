#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
template < class T >

class Queue {
    int first;
    int last;
    int size;
    int elementNumber;
    T *array;
    public:
        Queue(int s) { size = s; };
        void create();
        void destroy(); 
        void clear(); 
        bool add(T element);
        bool empty();
        bool full();
        T pop();
        T top();
};

/*
    EFECTO: crea e inicializa la cola circular
    REQUIERE: cola no creada o destruida
    MODIFICA: cola
*/
template < typename T >
void Queue< T > :: create() {
    array = new T[size];
    first = -1;
    last = -1; 
}

/*
    EFECTO: elimina la estructura de datos
    REQUIERE: cola creada
    MODIFICA: cola
*/
template < typename T >
void Queue< T > :: destroy() {
    delete []array;
}

/*
    EFECTO: elimina todos los elementos presentes en la cola
    REQUIERE: cola creada
    MODIFICA: cola
*/
template < typename T >
void Queue< T > :: clear() {
    this -> destroy();
    this -> create();
    first = -1;
    last = -1;
}

/*
    EFECTO: introduce un elemento al final de la cola
    REQUIERE: cola creada
    MODIFICA: cola
*/
template < typename T >
bool Queue< T > :: add(T element) {
    if(!this -> full()) {
        if(this -> empty()) {
            first = 0;
        }
        if(last == size - 1) {
            last = 0;
        }
        else {
            last++;
        }
        array[last] = element;
        ++elementNumber;
        return true;
    }
    else 
        return false;
}

/*
    EFECTO: devuelve un verdadero si la cola está vacía y un falso si no
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Queue< T > :: empty() {
    return last == -1 ? true : false;
}

/*
    EFECTO: devuelve un verdadero si la cola está llena y un falso si no
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Queue< T > :: full() {
    return this -> quantity() == size ? true : false;
}

/*
    EFECTO: devuelve el primer elemento y a la vez lo elimina de la cola
    REQUIERE: cola creada
    MODIFICA: cola
*/
template < typename T >
T Queue< T > :: pop() {
    if(!this -> empty()) {
        T temp = array[first];
        if(this -> quantity() == 1) 
            this -> create();
        if(first == size - 1)
            first = 0;
        else
            ++first;
        return temp;
    }
}

/*
    EFECTO: devuelve el primer elemento de la cola
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
T Queue< T > :: top() {
    if(!this -> empty())
        return array[first];
}

#endif //QUEUE_H