#include "cola.h"


Cola::Cola()
{

}

void Cola::insertar(string cancion)
{
    Nodo *temp = new Nodo();
    Nodo *aux = new Nodo();

    if (nodo==NULL){
        nodo = new Nodo();
        nodo->setDato(cancion);
    }else{
        temp->setDato(cancion);
        temp->siguiente = NULL;
        aux = nodo;
        while(aux->siguiente!=NULL){
            aux = aux->siguiente;
        }
        aux->siguiente=temp;
    }
    size++;
}

void Cola::descolar()
{
    nodo=nodo->siguiente;
    size--;
//    Nodo *aux = new Nodo();
//    Nodo *aux2 = new Nodo();
//    if (nodo==NULL){
//      cout<<"Lista vacia"<<endl;
//    }else{
//      aux = nodo;
//      while(aux->siguiente!=NULL){
//          aux2 = aux;
//          aux = aux->siguiente;
//      }
//      aux2->siguiente=NULL;
//      size--;
//    }
}

string Cola::cima()
{
    return Lista::tomarPrimero();
//    Nodo *aux = new Nodo();
//    if (nodo==NULL){
//      return "Lista vacia";
//    }else{
//      aux = nodo;
//      while(aux->siguiente!=NULL){
//          aux = aux->siguiente;
//      }
//      //cout<<"dato: "<<aux2->getDato()<<en
//      return aux->getDato();
//    }
}
