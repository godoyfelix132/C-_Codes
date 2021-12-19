#include "animal.h"

Animal::Animal(string nombre)
{
    this->nombre=nombre;
}

Animal::~Animal()
{

}

string Animal::getNombre()
{
    return nombre;
}

string Animal::tipoAnimal()
{

}

void Animal::setFechaIngreso(int dia, int mes, int anio, int hora, int minuto, int segundo)
{
    this->fechaIngreso.setFechaHora(dia,mes,anio,hora,minuto,segundo);
}

void Animal::setFechaEgreso(int dia, int mes, int anio, int hora, int minuto, int segundo)
{
    this->fechaEgreso.setFechaHora(dia,mes,anio,hora,minuto,segundo);
}

void Animal::internar()
{
    this->internado=true;
}

void Animal::darDeAlta()
{
    this->internado=false;
}

bool Animal::estaInternado()
{
    return internado;
}



ostream & operator << (ostream &os, const Animal &e)
{
    os<< e.nombre;
    return os;
}
ostream & operator >> (ostream &os, const Animal &e)
{
    os<< e.nombre <<"\t"<<e.fechaIngreso;
    return os;
}
ostream & operator && (ostream &os, const Animal &e)
{
    os<< e.nombre <<"\t"<<e.fechaIngreso<<"\t"<<e.fechaEgreso;
    return os;
}

bool Animal::operator >(Animal &xAnimal)
{
    string nombrePrimero = this->nombre;
    string nombreSegundo = xAnimal.nombre;
    int a = nombrePrimero[0];
    int b = nombreSegundo[0];
    bool flag;
    if(a>b){
        flag=true;
    }else{
        flag=false;
    }
    return flag;
}
