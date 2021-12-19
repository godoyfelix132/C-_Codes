#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "animal.h"

using namespace std;

namespace Estructuras {


/////////////////////////////////////////////////////////////////////////////
template<class T>
class Nodo
{
private:
    T dato;
public:
    Nodo();
    virtual ~Nodo();
    Nodo *siguiente;
    void setDato(T dato);
    T getDato();
};

template <class T>
class Lista
{
public:
    Lista();
    virtual ~Lista();
    virtual void insertar(T dato);
    void insertar_en(T dato, int posicion);
    T tomar(int index);
    int buscar(T dato);
    int eliminar(int posicion);
    void mostrarTodo();
    void modificar(int index,T dato);
    bool vacio();
    void purga();
    int tamano();
    T tomarPrimero();

protected:
   Nodo<T> *nodo;
   Nodo<T> *nuevo;
   Nodo<T> *temp = new Nodo<T>();
   Nodo<T> *aux = new Nodo<T>();
   Nodo<T> *aux2 = new Nodo<T>();
   int size;
};

template <class T>
class Cola : public Lista<T>
{
public:
    Cola();
    void insertar(T dato);
    void descolar();
    T cima();
};

template <class T>
class Pila : public Lista<T>
{
public:
    Pila();
    void insertar(T dato);// override;
    void desapilar();
    T cima();
};

//////////////////////////////////NODO/////////////////////////////////////////
template <class T>
Nodo<T>::Nodo()
{
    //this -> siguiente=NULL;
}

template<class T>
Nodo<T>::~Nodo()
{

}

template <class T>
void Nodo<T>::setDato(T dato)
{
    this->dato = dato;
}

template <class T>
T Nodo<T>::getDato()
{
    return this->dato;
}


//////////////////////////////////LISTA///////////////////////////////////////
template <class T>
Lista<T>::Lista()
{
    nodo = nullptr;
    size = 0;
}

template<class T>
Lista<T>::~Lista()
{

}

template <class T>
void Lista<T>::insertar(T dato)
{
    if (nodo==nullptr){
        delete(nodo);
        nodo = new Nodo<T>();
        nodo->setDato(dato);
        nodo->siguiente=nullptr;
        size++;
    }else{
        nuevo = new Nodo<T>();
        temp = nodo;
        nuevo->siguiente = temp;
        nuevo->setDato(dato);
        nodo = nuevo;
        size++;
    }

}

template <class T>
void Lista<T>::insertar_en(T dato, int posicion)
{
    if (nodo==nullptr){
        delete(nodo);
        nodo = new Nodo<T>();
        nodo->setDato(dato);
        nodo->siguiente=nullptr;
    }else{
        if (posicion==0){
            insertar(dato);
        }
        else if(posicion==size){
          nuevo = new Nodo<T>();
          nuevo->setDato(dato);
          nuevo->siguiente = nullptr;
          aux = nodo;
          while(aux->siguiente!=nullptr){
              aux = aux->siguiente;
          }
          aux->siguiente=nuevo;
          size++;
        }
        else if(posicion>0 && posicion<size){
            nuevo = new Nodo<T>();
            aux=nodo;
           for(int i=0;i<posicion; i++){
               aux2=aux;
               aux = aux->siguiente;
           }
           aux2->siguiente=nuevo;
           nuevo->siguiente=aux;
           nuevo->setDato(dato);
           size++;
        }
        else{
            cout<<"Posicion erronea"<<endl;
        }
    }
}

template <class T>
T Lista<T>::tomar(int index)
{
    int contador = 0;
    temp=nodo;
    while (contador<index){
        temp = temp->siguiente;
        contador++;
    }
     return temp->getDato();
}

template <class T>
int Lista<T>::buscar(T dato)
{
    //Nodo<T> *temp = new Nodo<T>();
    temp=nodo;
    for(int i=0;i<=size;i++){
        if(temp->getDato()==dato){
            return i+1;
        }
        temp=temp->siguiente;
    }
    return -1;
}

template <class T>
int Lista<T>::eliminar(int posicion)
{
    if (nodo==nullptr){
        return -1;
    }else{
        if (posicion==0){
            temp = nodo;
            nodo=nodo->siguiente;
            delete (temp);
            size--;
            return 1;
        }
        else if(posicion==size){
          aux = nodo;
          while(aux->siguiente!=nullptr){
              aux = aux->siguiente;
          }
          delete (aux->siguiente);
          size--;
          return 1;
        }
        else if(posicion>0 && posicion<size){
            aux=nodo;
           for(int i=0;i<posicion; i++){
               aux2=aux;
               aux = aux->siguiente;
           }
           aux2->siguiente=aux->siguiente;
           delete(aux);
           size--;
           return 1;
        }
        else{
            return -1;
        }
    }
    return 0;
}

template <class T>
void Lista<T>::mostrarTodo()
{
    aux = nodo;
    for(int i=0;i<size;i++){
        T dato = aux->getDato();
        cout<<i<<"- "<<aux->getDato()<<endl;
        aux=aux->siguiente;
    }
}

template <class T>
void Lista<T>::modificar(int index, T dato)
{
    temp=nodo;
    for(int i=0;i<size;i++){
        if(i==index-1){
            break;
        }
        temp=temp->siguiente;
    }
    temp->setDato(dato);
}

template <class T>
bool Lista<T>::vacio()
{
    if (nodo==nullptr){
        return true;
    }else{
        return false;
    }
}

template <class T>
void Lista<T>::purga()
{
    aux = nodo;
    while(aux->siguiente!=nullptr){
        aux = aux->siguiente;
        delete(nodo);
        nodo=aux;
    }
    delete(aux);
    size=0;
    nodo=nullptr;
}

template <class T>
int Lista<T>::tamano()
{
    return size;
}

template <class T>
T Lista<T>::tomarPrimero()
{
    return nodo->getDato();
}



///////////////////////////////////////COLA///////////////////////////////////
template <class T>
Cola<T>::Cola()
{

}

template <class T>
void Cola<T>::insertar(T dato)
{
    if (this->nodo==nullptr){
        this->nodo = new Nodo<T>();
        this->nodo->setDato(dato);
        this->nodo->siguiente = nullptr;
    }else{  
        this->nuevo = new Nodo<T>();
        this->nuevo->setDato(dato);
        this->nuevo->siguiente = nullptr;
        this->aux = this->nodo;
        while(this->aux->siguiente!=nullptr){
            this->aux = this->aux->siguiente;
        }
        this->aux->siguiente=this->nuevo;
    }
    this->size++;
}

template <class T>
void Cola<T>::descolar()
{
    if (this->nodo!=0){
        this->temp = this->nodo;
        this->nodo=this->nodo->siguiente;
        delete (this->temp);
        this->size--;
    }
}

template <class T>
T Cola<T>::cima()
{
    return Lista<T>::tomarPrimero();

}


/////////////////////////////////////////PILA////////////////////////////////
template <class T>
Pila<T>::Pila()
{

}
template <class T>
void Pila<T>::insertar(T dato)
{
    Lista<T>::insertar(dato);
}

template <class T>
void Pila<T>::desapilar()
{
    if (this->nodo!=0){
        this->temp = this->nodo;
        this->nodo=this->nodo->siguiente;
        delete (this->temp);
        this->size--;
    }
}

template <class T>
T Pila<T>::cima()
{
    return Lista<T>::tomarPrimero();
}






}//Fin namespace

#endif // LISTA_H

