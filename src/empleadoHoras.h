#ifndef EMPLEADOHORAS_H
#define EMPLEADOHORAS_H

#include "empleado.h"

#include <string>
#include <iostream>

class EmpleadoHoras : public Empleado{
    

    public:
    EmpleadoHoras();

    virtual void CalculoPago();

};



#endif