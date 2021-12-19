#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
public:
    Fecha();
    bool validarFecha();
    static bool validarFecha(int dia,int mes,int anio);
    string getFecha();
    void setFecha(int dia,int mes,int anio);
protected:
    int dia=0;
    int mes=0;
    int anio=0;
};

#endif // FECHA_H
