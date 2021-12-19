#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
public:
    Fecha();
    bool validarFecha();
    static bool validarFecha(int,int,int);
    string getFecha();
    void setFecha(int,int,int);
protected:
    int dia;
    int mes;
    int anio;
};

#endif // FECHA_H
