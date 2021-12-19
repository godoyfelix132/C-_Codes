#ifndef ANIMAL_H
#define ANIMAL_H

#include "fechahora.h"
#include <iostream>

using namespace std;



class Animal
{
    friend ostream & operator << (ostream &os, const Animal &e);
    friend ostream & operator >> (ostream &os, const Animal &e);
    friend ostream & operator && (ostream &os, const Animal &e);

public:
    Animal(string nombre);
    virtual ~Animal();
    string getNombre();
    virtual string tipoAnimal();
    void setFechaIngreso(int dia, int mes, int anio, int hora, int minuto, int segundo);
    void setFechaEgreso(int dia, int mes, int anio, int hora, int minuto, int segundo);
    void internar();
    void darDeAlta();
    bool estaInternado();
    bool operator >(Animal &xAnimal);

protected:
    string nombre;
    FechaHora fechaIngreso;
    FechaHora   fechaEgreso;
    bool internado;

};


#endif // ANIMAL_H
