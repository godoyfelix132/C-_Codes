#include "persona.h"
#include <sstream>

Persona::Persona()
{

}

void Persona::setDatos(string nombre,string aPaterno,string aMaterno,int dia,int mes, int anio, int hora, int minuto, int segundo,string fechaFormato, string horaFormato)
{
    this->nombre=nombre;
    this->aPaterno=aPaterno;
    this->aMaterno=aMaterno;
    this->anio=anio;
    this->mes=mes;
    this->dia=dia;
    this->hora=hora;
    this->minuto=minuto;
    this->segundo=segundo;
    this->fechaFormato=fechaFormato;
    this->horaFormato=horaFormato;
}
string Persona::getDatos()
{
    ostringstream s1;
    s1 << "Nombre: "<< nombre<< " Apellido Paterno: "<<aPaterno<<" Apellido Materno: "<<aMaterno<<"Fecha y hora: "<<fechaFormato<<" "<<horaFormato<< endl;
    string s2 = s1.str();
    return s2;
}
