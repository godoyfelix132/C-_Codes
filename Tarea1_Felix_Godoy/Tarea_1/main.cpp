#include <iostream>
#include <lista.h>
#include "nodo.h"
#include "administradora.h"
using namespace std;
int opc;
int main()
{

    Administradora administradora;
    do {
        administradora.imprimirMenu();
        opc = administradora.obtenerOpcion();
        administradora.ejecutar(opc);
    } while (opc!=12);

    cout << "Adios" << endl;
    return 0;
}
