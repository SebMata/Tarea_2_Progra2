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

ostream& operator << (ostream &o, const Empleado *empleado)
{
    o << empleado->id << "," << empleado->nombre << "," << empleado->apellido << "," << empleado->tipo << "," << empleado->idSupervisor;
    return o;
}

istream& operator >> (istream &i, Empleado *empleado)
{
    i >> empleado->id >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipo >> empleado->idSupervisor;
    return i;
}