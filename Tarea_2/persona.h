#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

#include "fechahora.h"

class Persona
{
public:
    Persona();
    void setDatos(string,string,string,int,int,int,int,int,int,string,string);
    string getDatos();
private:
    string nombre;
    string aPaterno;
    string aMaterno;
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;
    string fechaFormato;
    string horaFormato;

};

#endif // PERSONA_H
