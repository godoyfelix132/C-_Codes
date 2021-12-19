#ifndef GATO_H
#define GATO_H

#include "animal.h"

class Gato : public Animal
{
public:
    Gato(string nombre);
    string tipoAnimal();
};

#endif // GATO_H
