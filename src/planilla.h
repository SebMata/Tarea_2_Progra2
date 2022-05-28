#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include <vector>
#include <map>

using namespace std;

class Planilla {

    Empleado *jefe=nullptr;
    vector<Empleado *> empleados;
    map<int, Empleado *> indiceEmpleados;
    double subTotal = 0;
    double impuestos;

    public:
    Planilla();
    ~Planilla();

    void AgregarEmpleado(Empleado *nuevoEmpleado);
    void CalculeSubTotal();
    void CalculeImpuestos();
    void CalculeTotal();

    friend istream& operator >> (istream &o, Planilla *planilla);
    friend ostream& operator << (ostream &o, const Planilla *planilla);
    friend istream& operator > (istream &o, Planilla *planilla);
    friend istream& operator + (istream &o, Planilla *planilla);
    

};


#endif