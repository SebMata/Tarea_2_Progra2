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
    double monto;
    Empleado *supervisor;
    vector<Empleado *> subordinados;
    int horas;
    double impuestos;

    public:
    Empleado();

    void InsertarSubordinado(Empleado *subordinado);
    void AsigneSupervisor(Empleado *supervisor);
    virtual void CalculoPago() = 0;
    virtual int ObtenerIdSupervisor();
    virtual int ObtenerId();
    virtual void AsignarMonto(double EntradaMonto);
    virtual string ObtenerNombre();
    virtual double ObtenerPago();
    virtual double ObtenerImpuestos();
    virtual void AsignarHoras(int horasEntrada);
    

    friend istream& operator >> (istream &o, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
};


#endif