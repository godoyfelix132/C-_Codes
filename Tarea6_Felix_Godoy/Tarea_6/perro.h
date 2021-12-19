#ifndef PERRO_H
#define PERRO_H

#include "animal.h"

class Perro : public Animal
{
public:
    Perro(string nombre);
    string tipoAnimal();
};

#endif // PERRO_H
