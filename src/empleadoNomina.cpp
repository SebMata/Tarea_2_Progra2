#include "empleadoNomina.h"
#include <iostream>
#include <sstream>

EmpleadoNomina::EmpleadoNomina() {

}

void EmpleadoNomina::CalculoPago(){
    MontoNomina = MontoNomina - ((MontoNomina * 7)/100);
}


/*istream& operator >> (istream &i, EmpleadoNomina *empleadonomina)
{
    string linea;

    while (std::getline(i, linea)) {

        std::istringstream streamLinea(linea);
        empleadonomina->CalculoPago();
        
    }

    return i;
    
}*/