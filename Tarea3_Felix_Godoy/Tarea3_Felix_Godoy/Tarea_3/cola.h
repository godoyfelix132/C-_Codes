#ifndef COLA_H
#define COLA_H
#include "lista.h"

class Cola : public Lista
{
public:
    Cola();
    void insertar(string cancion);
    void descolar();
    string cima();
};

#endif // COLA_H
