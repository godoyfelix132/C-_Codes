#ifndef FECHAHORA_H
#define FECHAHORA_H
#include "fecha.h"

class FechaHora : public Fecha
{
public:
    FechaHora();
    friend ostream & operator << (ostream &os, const FechaHora &e);
    bool validarFechaHora();
    static bool validarFechaHora(int dia,int mes,int anio,int hora,int minuto,int segundo);
    string getFechaHora();
    void setFechaHora(int dia,int mes,int anio,int hora,int minuto,int segundo);
private:
    int hora=0;
    int minuto=0;
    int segundo=0;
};

#endif // FECHAHORA_H
