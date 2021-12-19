#ifndef ANIMAL_H
#define ANIMAL_H

#include "fechahora.h"
#include <iostream>
#include <cstring>

using namespace std;



class Animal
{
    friend ostream & operator << (ostream &os, const Animal &e);
    friend ostream & operator >> (ostream &os, const Animal &e);
    friend ostream & operator && (ostream &os, const Animal &e);

public:
    Animal();
    //Animal(char *nombre);
    Animal(string nombre);
    virtual ~Animal();
    string getNombre();
    FechaHora getFechaEgreso();
    FechaHora getFechaIngreso();
    void setNombre(string nombrex);
    virtual string tipoAnimal();
    void setFechaEgreso(FechaHora fechaHora);
    void setFechaIngreso(FechaHora fechaHora);
    void setFechaIngreso(int dia, int mes, int anio, int hora, int minuto, int segundo);
    void setFechaEgreso(int dia, int mes, int anio, int hora, int minuto, int segundo);
    void internar();
    void darDeAlta();
    bool estaInternado();
    bool operator >(Animal &xAnimal);

protected:
    char nombre[20];
    FechaHora fechaIngreso;
    FechaHora   fechaEgreso;
    bool internado;

};


#endif // ANIMAL_H
