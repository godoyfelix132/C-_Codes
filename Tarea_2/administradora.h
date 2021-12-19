#ifndef ADMINISTRADORA_H
#define ADMINISTRADORA_H

#include <iostream>
using namespace std;

class Administradora
{
public:
    Administradora();
    void imprimirMenu();
    void administrarMenu();
    void obtenerDatos();
private:
    string nombre,aPaterno,aMaterno;
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;
    string fechaFormato;
    string HoraFormato;
};

#endif // ADMINISTRADORA_H
