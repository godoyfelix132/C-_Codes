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
        nodo = new Nodo();
        nodo->setDato(cancion);
    }else{
        Nodo *temp = new Nodo();
        temp = nodo;
        Nodo *nuevo = new Nodo();
        nuevo->siguiente = temp;
        nuevo->setDato(cancion);
        nodo = nuevo;
    }
    cout<<"Se inserto la cancion  "<<nodo->getDato()<<endl;
    size++;
}

void Lista::insertar_en(string cancion, int posicion)
{
    Nodo *temp = new Nodo();
    Nodo *aux = new Nodo();
    Nodo *aux2 = new Nodo();
    if (nodo==NULL){
        nodo = new Nodo();
        nodo->setDato(cancion);
    }else{
        if (posicion==1){
            insertar(cancion);
        }
        else if(posicion==size+1){
          temp->setDato(cancion);
          temp->siguiente = NULL;
          aux = nodo;
          while(aux->siguiente!=NULL){
              aux = aux->siguiente;
          }
          aux->siguiente=temp;
        }
        else if(posicion>1 && posicion<size + 1){
            aux=nodo;
           for(int i=0;i<posicion-1; i++){
               aux2=aux;
               aux = aux->siguiente;
           }
           aux2->siguiente=temp;
           temp->siguiente=aux;
           temp->setDato(cancion);
        }
        else{
            cout<<"Posicion erronea"<<endl;
        }
    }
    cout<<"Se inserto la cancion:  "<<cancion<<endl;
    size++;
}

string Lista::tomar(int index)
{
    int contador = 1;
    Nodo *temporal = new Nodo();
    temporal=nodo;
    while (contador<index){
        temporal = temporal->siguiente;
        contador++;
    }
     return temporal->getDato();
}

int Lista::buscar(string dato)
{
    Nodo *temporal = new Nodo();
    temporal=nodo;
    for(int i=0;i<=size;i++){
        if(temporal->getDato()==dato){
            return i+1;
        }
        temporal=temporal->siguiente;
    }
    return -1;
}

int Lista::eliminar(int posicion)
{
    Nodo *aux = new Nodo();
    Nodo *aux2 = new Nodo();
    if (nodo==NULL){
        return -1;
    }else{
        if (posicion==1){
            nodo=nodo->siguiente;
            size--;
            return 1;
        }
        else if(posicion==size+1){
          aux = nodo;
          while(aux->siguiente!=NULL){
              aux = aux->siguiente;
          }
          aux->siguiente=NULL;
        }
        else if(posicion>1 && posicion<size + 1){
            aux=nodo;
           for(int i=0;i<posicion-1; i++){
               aux2=aux;
               aux = aux->siguiente;
           }
           aux2->siguiente=aux->siguiente;
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
    Nodo *auxiliar = nodo;
    cout<<endl;
    for(int i=1;i<=size;i++){
        cout<<i<<"- "<<auxiliar->getDato()<<endl;
        auxiliar=auxiliar->siguiente;
    }
    cout<<endl;
}
void Lista::modificar(int index, string cancion)
{
    Nodo *temporal = new Nodo();
    temporal=nodo;
    for(int i=0;i<=size;i++){
        if(i==index-1){
            break;
        }
        temporal=temporal->siguiente;
    }
    temporal->setDato(cancion);
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
    delete(nodo);
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
