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

    public:
    Planilla();
    ~Planilla();

    void AgregarEmpleado(Empleado *nuevoEmpleado);

    friend istream& operator >> (istream &o, Planilla *planilla);
    friend ostream& operator << (ostream &o, const Planilla *planilla);

};


#endif