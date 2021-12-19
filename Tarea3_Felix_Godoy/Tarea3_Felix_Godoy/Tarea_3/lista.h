#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"

using namespace std;

class Lista
{
public:

    Lista();
    virtual void insertar(string cancion);
    void insertar_en(string cancion, int posicion);
    string tomar(int index);
    int buscar(string dato);
    int eliminar(int posicion);
    void mostrarTodo();
    void modificar(int index,string cancion);
    bool vacio();
    void purga();
    int tamano();
    string tomarPrimero();

protected:
   Nodo *nodo;
   Nodo *nuevo;
   Nodo *temp = new Nodo();
   Nodo *aux = new Nodo();
   Nodo *aux2 = new Nodo();
   int size;
};

#endif // LISTA_H
