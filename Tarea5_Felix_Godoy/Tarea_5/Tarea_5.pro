TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        animal.cpp \
        fecha.cpp \
        fechahora.cpp \
        gato.cpp \
        main.cpp \
        perro.cpp \
        veterinaria.cpp

HEADERS += \
    administradora.h \
    animal.h \
    fecha.h \
    fechahora.h \
    gato.h \
    lista.h \
    perro.h \
    veterinaria.h

DISTFILES += \
    ../build-Tarea_5-Desktop_Qt_5_14_0_MinGW_64_bit-Debug/fecha.txt \
    ../build-Tarea_5-Desktop_Qt_5_14_0_MinGW_64_bit-Debug/texto.txt
