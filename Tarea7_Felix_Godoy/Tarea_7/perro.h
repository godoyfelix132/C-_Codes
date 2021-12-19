#ifndef PERRO_H
#define PERRO_H

#include "animal.h"

class Perro : public Animal
{
public:
    Perro();
    QString getRaza() const;
    void setRaza(const QString &value);

private:
    QString raza;
};

#endif // PERRO_H
