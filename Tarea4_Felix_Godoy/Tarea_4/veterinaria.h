#ifndef VETERINARIA_H
#define VETERINARIA_H
#include <lista.h>
#include <perro.h>
#include <gato.h>

#include <iostream>
using namespace std;

class Veterinaria
{
public:
    Veterinaria();
    void imprimirMenu();
    void submenuAtender();
    int obtenerOpcion();
    void ejecutar(int opc);
    void internarAnimal(Animal*);
    Animal siguienteAnimal();
    void mostrarAnimal(int index);
    void atenderSiguiente();
    void darDeAlta(int index);
    void imprimirLista(Estructuras::Lista<Animal*> *_lista);
    void imprimirListaAltas(Estructuras::Lista<Animal*> *_lista);
    void inprimirListaOrdenada(Estructuras::Lista<Animal *> *_lista);
    void ordenarLista();
private:
    Estructuras::Lista<Animal*> *listaInternados = new Estructuras::Lista<Animal*>();
    //Estructuras::Lista<Animal*> *listaOrdenada = new Estructuras::Lista<Animal*>();
    Estructuras::Lista<Animal*> *listaRecuperados = new Estructuras::Lista<Animal*>();
    Estructuras::Cola<Animal*> *cola = new Estructuras::Cola<Animal*>();
    int dia,mes,anio,hora,minuto,segundo;
    int tipo;
    int index;
    string nombre;
    Perro *perro;
    Gato *gato;
    Animal *aux;
};

#endif // VETERINARIA_H
