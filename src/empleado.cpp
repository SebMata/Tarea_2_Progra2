#include "empleado.h"

Empleado::Empleado() {

}

Empleado::~Empleado() {
    
}

void Empleado::InsertarSubordinado(Empleado *subordinado)
{
    this->subordinados.push_back(subordinado);
}

void Empleado::AsigneSupervisor(Empleado *supervisor)
{
    this->supervisor=supervisor;
}

int Empleado::ObtenerIdSupervisor()
{
    return this->idSupervisor;
}

int Empleado::ObtenerId()
{
    return this->id;
}

double Empleado::ObtenerPago()
{
    return this->monto;
}

double Empleado::ObtenerImpuestos()
{
    return this->impuestos;
}

void Empleado::AsignarMonto(double EntradaMonto)
{
    this->monto=EntradaMonto;
}

void Empleado::AsignarHoras(int horasEntrada)
{
    this->horas=horasEntrada;
}

string Empleado::ObtenerNombre()
{
    return this->nombre + " " + this->apellido;
}

ostream& operator << (ostream &o, const Empleado *empleado)
{
    o << empleado->id << "," << empleado->nombre << "," << empleado->apellido << "," << empleado->supervisor->ObtenerNombre() << "," << empleado->monto;
    return o;
}

istream& operator >> (istream &i, Empleado *empleado)
{
    i >> empleado->id >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipo >> empleado->idSupervisor;
    return i;
}