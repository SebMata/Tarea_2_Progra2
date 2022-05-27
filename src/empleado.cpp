#include "empleado.h"

Empleado::Empleado() {

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

string Empleado::ObtenerNombre()
{
    return this->nombre + " " + this->apellido;
}

ostream& operator << (ostream &o, const Empleado *empleado)
{
    o << empleado->id << "," << empleado->nombre << "," << empleado->apellido << "," << empleado->supervisor->ObtenerNombre() << "," << empleado->tipo;
    return o;
}

istream& operator >> (istream &i, Empleado *empleado)
{
    i >> empleado->id >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipo >> empleado->idSupervisor;
    return i;
}