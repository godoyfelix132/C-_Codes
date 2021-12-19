#ifndef FECHAHORA_H
#define FECHAHORA_H
#include "fecha.h"

class FechaHora : public Fecha
{
public:
    FechaHora();
    bool validarFechaHora();
    static bool validarFechaHora(int,int,int);
    string getFechaHora();
    void setFechaHora(int,int,int,int,int,int);
private:
    int hora;
    int minuto;
    int segundo;
};

#endif // FECHAHORA_H
