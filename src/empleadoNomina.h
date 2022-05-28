#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include "empleado.h"

#include <string>
#include <iostream>

using namespace std;

class EmpleadoNomina : public Empleado{
    public:
    EmpleadoNomina();

    virtual void CalculoPago();
};

#endif