#ifndef VETERINARIA_H
#define VETERINARIA_H
#include <lista.h>
#include <perro.h>
#include <gato.h>
#include <fstream>
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
    void imprimirLista(Estructuras::Lista<Animal*> _lista, int flag);
    void ordenarLista();
    void writeInternadosTxt(Estructuras::Lista<Animal*> *_lista);
    void readInternadosTxt();
    void writeColaTxt();
    void readColaTxt();
    void writeAltaTxt();
    void readAltaTxt();
    void llenarListaInternadosInicial();
    void llenarListaColaInicial();

private:
    Estructuras::Lista<Animal*> listaInternados();
    //Estructuras::Lista<Animal*> *listaOrdenada = new Estructuras::Lista<Animal*>();
    Estructuras::Lista<Animal*> *listaRecuperados = new Estructuras::Lista<Animal*>();
    Estructuras::Cola<Animal*> *cola = new Estructuras::Cola<Animal*>();
    int dia,mes,anio,hora,minuto,segundo;
    int tipo;
    int index;
    int sizeFileInternados;
    int sizeFileCola;
    int sizeFileAlta;
    int sizeAnimal = sizeof (Animal);
    string nombre;
    Perro *perro;
    Gato *gato;
    Animal *aux;
    //Animal temp;

    char a[20] = "loo3";
    char b[20] = "f";
    fstream file;

};

#endif // VETERINARIA_H
