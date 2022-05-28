#include "empleadoHoras.h"
#include <iostream>
#include <sstream>

EmpleadoHoras::EmpleadoHoras() {

}

void EmpleadoHoras::CalculoPago(){
   monto = monto * horas;
}
