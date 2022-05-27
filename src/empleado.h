#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Empleado{
    protected:
    int id;
    string nombre;
    string apellido;
    string email;
    int tipo;
    int idSupervisor;
    Empleado *supervisor;
    vector<Empleado *> subordinados;

    public:
    Empleado();

    void InsertarSubordinado(Empleado *subordinado);
    void AsigneSupervisor(Empleado *supervisor);
    virtual void CalculoPago() = 0;
    virtual int ObtenerIdSupervisor();
    virtual int ObtenerId();
    virtual string ObtenerNombre();

    friend istream& operator >> (istream &o, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
};


#endif