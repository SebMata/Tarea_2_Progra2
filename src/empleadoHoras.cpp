#include "empleadoHoras.h"
#include <iostream>
#include <sstream>

EmpleadoHoras::EmpleadoHoras() {

}

void EmpleadoHoras::CalculoPago(){
    MontoHoras = MontoHoras - ((MontoHoras * 7)/100);
}