#include "perro.h"

Perro::Perro()
{

}

QString Perro::getRaza() const
{
    return raza;
}

void Perro::setRaza(const QString &value)
{
    raza = value;
}
