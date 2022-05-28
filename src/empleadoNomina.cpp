#include "empleadoNomina.h"
#include <iostream>
#include <sstream>


EmpleadoNomina::EmpleadoNomina() {

}

void EmpleadoNomina::CalculoPago(){
    impuestos+=((this->monto * 7)/100);
    this->monto = this->monto - ((this->monto * 7)/100);
}

