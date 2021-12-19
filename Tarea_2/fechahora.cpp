#include "fechahora.h"
#include <sstream>

FechaHora::FechaHora()
{

}

bool FechaHora::validarFechaHora()
{

    if(!validarFecha()){
        cout<<"Fecha incorrecta"<<endl;
        return false;
    }

    if(hora>24 || minuto >60 || segundo>60 || hora<1 || minuto <1 || segundo<1){
        cout<<"Fecha incorrecta"<<endl;
        return false;
    }
    return true;
}

string FechaHora::getFechaHora()
{
    ostringstream s1;
    s1<<hora<<":"<<minuto<<":"<<segundo;
    string s2 = s1.str();
    return s2;

}

void FechaHora::setFechaHora(int dia,int mes,int anio, int hora, int minuto, int segundo)
{
    this->anio=anio;
    this->mes=mes;
    this->dia=dia;
    this->hora=hora;
    this->minuto=minuto;
    this->segundo=segundo;
}
