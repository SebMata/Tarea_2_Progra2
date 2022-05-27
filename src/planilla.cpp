#include "planilla.h"
#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoHoras.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Planilla::Planilla() {

}

Planilla::~Planilla() {
    for (Empleado *empleado : this->empleados)
    {
        delete empleado;
    }
}

void Planilla::AgregarEmpleado(Empleado *nuevoEmpleado) {
    this->empleados.push_back(nuevoEmpleado);
    if(jefe==nullptr){
        
    }
}

ostream& operator << (ostream &o, const Planilla *planilla)
{
    for (Empleado *empleado : planilla->empleados)
    {
        o << empleado << endl;
    }

    return o;
}

istream& operator >> (istream &i, Planilla *planilla)
{
    
    string linea;

    while (std::getline(i, linea)) {
        string nulo;
        int tipoPago;

        std::istringstream streamLinea(linea);
        streamLinea >> nulo >> nulo >> nulo >> nulo >> tipoPago >> nulo;

        std::istringstream streamLineaEmpleado(linea);
        if(tipoPago==1){
            EmpleadoNomina *empleado1 = new EmpleadoNomina();
            streamLineaEmpleado >> empleado1;

            planilla->AgregarEmpleado(empleado1);
        }else{
            EmpleadoHoras *empleado2 = new EmpleadoHoras();
            streamLineaEmpleado >> empleado2;

            planilla->AgregarEmpleado(empleado2);

        }
    }

    return i;
}