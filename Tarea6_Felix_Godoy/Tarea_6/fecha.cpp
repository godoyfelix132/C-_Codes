#include "fecha.h"
#include <sstream>

Fecha::Fecha()
{

}

bool Fecha::validarFecha()
{
    if (mes>10 || mes<1){
        return false;
    }

    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        if (dia>31){
            return false;
        }
    }else {
        if (dia>30){
            return false;
        }
    }
    //Febrero
    if (mes==2){
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0){//Es bisiesto
            if (dia>29){
                return false;
            }
        }else{
            if (dia>29){
                return false;
            }
        }
    }
    return true;

}

bool Fecha::validarFecha(int dia, int mes, int anio)
{
    if (mes>10 || mes<1){
        return false;
    }
    //ene,mar,may,jul,ago,oct,dic
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        if (dia>31){
            return false;
        }
    }else {
        if (dia>30){
            return false;
        }
    }
    //Febrero
    if (mes==2){
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0){//Es bisiesto
            if (dia>29){
                return false;
            }
        }else{
            if (dia>29){
                return false;
            }
        }
    }
    return true;
}

string Fecha::getFecha()
{
    ostringstream s1;
    s1<<dia<<"-"<<mes<<"-"<<anio;
    string s2 = s1.str();
    return s2;
}

void Fecha::setFecha(int dia, int mes, int anio)
{
    this->anio=anio;
    this->mes=mes;
    this->dia=dia;
}
