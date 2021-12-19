#include "lista.h"
#include "nodo.h"

Lista::Lista()
{
    nodo = NULL;
    size = 0;
}

void Lista::insertar(string cancion)
{
    if (nodo==NULL){
        delete(nodo);
        nodo = new Nodo();
        nodo->setDato(cancion);
        nodo->siguiente=NULL;
    }else{
        nuevo = new Nodo();
        temp = nodo;
        nuevo->siguiente = temp;
        nuevo->setDato(cancion);
        nodo = nuevo;
    }
    size++;
}

void Lista::insertar_en(string cancion, int posicion)
{
    if (nodo==NULL){
        delete(nodo);
        nodo = new Nodo();
        nodo->setDato(cancion);
        nodo->siguiente=NULL;
    }else{
        if (posicion==0){
            insertar(cancion);
        }
        else if(posicion==size){
          nuevo = new Nodo();
          nuevo->setDato(cancion);
          nuevo->siguiente = NULL;
          aux = nodo;
          while(aux->siguiente!=NULL){
              aux = aux->siguiente;
          }
          aux->siguiente=nuevo;
          size++;
        }
        else if(posicion>0 && posicion<size){
            nuevo = new Nodo();
            aux=nodo;
           for(int i=0;i<posicion; i++){
               aux2=aux;
               aux = aux->siguiente;
           }
           aux2->siguiente=nuevo;
           nuevo->siguiente=aux;
           nuevo->setDato(cancion);
           size++;
        }
        else{
            cout<<"Posicion erronea"<<endl;
        }
    }
}

string Lista::tomar(int index)
{
    int contador = 0;
    temp=nodo;
    while (contador<index){
        temp = temp->siguiente;
        contador++;
    }
     return temp->getDato();
}

int Lista::buscar(string dato)
{
    Nodo *temp = new Nodo();
    temp=nodo;
    for(int i=0;i<=size;i++){
        if(temp->getDato()==dato){
            return i+1;
        }
        temp=temp->siguiente;
    }
    return -1;
}

int Lista::eliminar(int posicion)
{
    if (nodo==NULL){
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
          while(aux->siguiente!=NULL){
              aux = aux->siguiente;
          }
          delete (aux->siguiente);
          size--;
          return 1;
        }
        else if(posicion>1 && posicion<size){
            aux=nodo;
           for(int i=0;i<posicion-1; i++){
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

void Lista::mostrarTodo()
{
    aux = nodo;
    for(int i=0;i<size;i++){
        cout<<i<<"- "<<aux->getDato()<<endl;
        aux=aux->siguiente;
    }
}

void Lista::modificar(int index, string cancion)
{
    temp=nodo;
    for(int i=0;i<size;i++){
        if(i==index-1){
            break;
        }
        temp=temp->siguiente;
    }
    temp->setDato(cancion);
}

bool Lista::vacio()
{
    if (nodo==NULL){
        return true;
    }else{
        return false;
    }
}

void Lista::purga()
{
    aux = nodo;
    while(aux->siguiente!=NULL){
        aux = aux->siguiente;
        delete(nodo);
        nodo=aux;
    }
    delete(aux);
    size=0;
    nodo=NULL;
}

int Lista::tamano()
{
    return size;
}

string Lista::tomarPrimero()
{
    return nodo->getDato();
}
