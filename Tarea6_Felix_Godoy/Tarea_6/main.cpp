#include "veterinaria.h"
#include <exception>

int main()
{
    int opc=0;
    while(opc!=11){
        try
        {
            Veterinaria *veterinaria = new Veterinaria();
            veterinaria->imprimirMenu();
            opc = veterinaria->obtenerOpcion();
            veterinaria->ejecutar(opc);

        }catch(int e) {
            if (e==0)cout<<"Ingresa un numero correcto: ";
        }
        catch (std::bad_alloc)
        {
            std::cerr << "Error al crear objeto "<<endl;
        }
    }
    return 0;
}

