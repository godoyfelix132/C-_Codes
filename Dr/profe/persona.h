#ifndef PERSONA_H
#define PERSONA_H

#include <QString>
#include <QDateTime>
#include <QJsonObject>

class Persona
{
public:
    Persona();
    Persona(QString nombre, QString apellidoPaterno,
            QString apelidoMaternom, QString genero,
            QDateTime registro);

    Persona(const QJsonObject &object);

    QString getNombre() const;
    void setNombre(const QString &value);

    QString getApellidoPaterno() const;
    void setApellidoPaterno(const QString &value);

    QString getApellidoMaterno() const;
    void setApellidoMaterno(const QString &value);

    QString getGenero() const;
    void setGenero(const QString &value);

    QDateTime getRegistro() const;
    void setRegistro(const QDateTime &value);

    QJsonObject toJson();

private:
    QString nombre;
    QString apellidoPaterno;
    QString apellidoMaterno;
    QString genero;
    QDateTime registro;
};

#endif // PERSONA_H
