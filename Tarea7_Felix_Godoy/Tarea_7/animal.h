#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <QDateTime>
class Animal
{
public:
    Animal();
    QString getNombre() const;
    void setNombre(const QString &value);

    QString getAnimal() const;
    void setAnimal(const QString &value);

    QString getDuenio() const;
    void setDuenio(const QString &value);

    QDateTime getF_ingreso() const;
    void setF_ingreso(const QDateTime &value);

    QDateTime getF_alta() const;
    void setF_alta(const QDateTime &value);

protected:
    QString nombre;
    QString animal;
    QString duenio;
    QDateTime f_ingreso;
    QDateTime f_alta;
};

#endif // ANIMAL_H
