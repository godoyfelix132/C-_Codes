#include "veterinaria.h"

int main()
{
    Veterinaria *veterinaria = new Veterinaria();
    int opc=0;
    while(opc!=15){
        veterinaria->imprimirMenu();
        opc = veterinaria->obtenerOpcion();
        veterinaria->ejecutar(opc);
    }
    cout <<endl;
    return 0;
}


