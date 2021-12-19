#ifndef VETERINARIA_H
#define VETERINARIA_H
#include <lista.h>
#include <perro.h>
#include <gato.h>
#include <vector>
#include <map>

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
    void buscarAnimalInternado(string clave);
    void buscarAnimalAlta(string clave);
private:
    Estructuras::Lista<Animal*> *listaInternados;
    Estructuras::Lista<Animal*> *listaOrdenada;
    Estructuras::Lista<Animal*> *listaRecuperados;
    Estructuras::Cola<Animal*> *cola;
    int dia,mes,anio,hora,minuto,segundo;
    int tipo;
    int index;
    string nombre;
    string nombreMap;
    Perro *perro;
    Gato *gato;
    Animal *aux;
    Perro *perro1;
    Perro *perro2;
    Perro *perro3;
    Gato *gato1;
    Gato *gato2;
    Gato *gato3;
    Perro *cperro1;
    Perro *cperro2;
    Perro *cperro3;
    Gato *cgato1;
    Gato *cgato2;
    Gato *cgato3;
    vector<Animal*> *vect;
    map<string,Animal*> mapaInternados;
    map<string,Animal*> mapaAlta;
};

#endif // VETERINARIA_H
