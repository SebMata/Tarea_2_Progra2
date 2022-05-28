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
        this->jefe=nuevoEmpleado;
        nuevoEmpleado->AsigneSupervisor(nuevoEmpleado);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(nuevoEmpleado->ObtenerId(), jefe));
    }else{
        Empleado* supervisor = this->indiceEmpleados.at(nuevoEmpleado->ObtenerIdSupervisor());
        nuevoEmpleado->AsigneSupervisor(supervisor);
        supervisor->InsertarSubordinado(nuevoEmpleado);
        this->indiceEmpleados.insert( std::pair<int, Empleado *>(nuevoEmpleado->ObtenerId(), nuevoEmpleado));
    }
}

void Planilla::CalculeSubTotal()
{
    for (Empleado *empleado : this->empleados)
    {
        this->subTotal+=empleado->ObtenerPago();
    }
}

void Planilla::CalculeImpuestos()
{
    for (Empleado *empleado : this->empleados)
    {
        this->impuestos+=empleado->ObtenerImpuestos();
    }
}

ostream& operator << (ostream &o, const Planilla *planilla)
{
    for (Empleado *empleado : planilla->empleados)
    {
        o << empleado << endl;
    }
    o << fixed;
    o << "Subtotal= " << planilla->subTotal << endl;
    o << "Impuestos= " << planilla->impuestos << endl;
    o << "Total= " << planilla->subTotal + planilla->impuestos << endl;
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

istream& operator > (istream &i, Planilla *planilla)
{
    string linea;
    while (std::getline(i, linea)) {
        int idNomina;
        float pagoNomina;
        std::istringstream streamLineaNomina(linea);  
        streamLineaNomina >> idNomina >> pagoNomina;
        Empleado *pagoEmpleadoN = planilla->indiceEmpleados.at(idNomina);
        pagoEmpleadoN->AsignarMonto(pagoNomina);
        pagoEmpleadoN->CalculoPago();
        
    }   
        return i;
}

istream& operator + (istream &i, Planilla *planilla)
{
    string linea;
    while (std::getline(i, linea)) {
        int idHoras;
        float pagoHoras;
        int horasTrabajadas;
        std::istringstream streamLineaHoras(linea);  
        streamLineaHoras >> idHoras >> pagoHoras >> horasTrabajadas;
        Empleado *pagoEmpleadoH = planilla->indiceEmpleados.at(idHoras);
        pagoEmpleadoH->AsignarMonto(pagoHoras);
        pagoEmpleadoH->AsignarHoras(horasTrabajadas);
        pagoEmpleadoH->CalculoPago();
        
    }
        planilla->CalculeSubTotal();
        planilla->CalculeImpuestos();
        return i;
}