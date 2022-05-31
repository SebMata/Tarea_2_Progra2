#include <gtest/gtest.h>
#include "../src/planilla.h"
#include "../src/empleado.h"
#include "../src/empleadoHoras.h"
#include "../src/empleadoNomina.h"
#include <string>

namespace{

    TEST(Planilla_Tests, test_AgregarEmpleado){

        Planilla *planilla = new Planilla();

        string test = "1 Denis Tyler denis_tyler@biz.com 1 1";
        istringstream streamStringsEntrada3(test);
        EmpleadoNomina *empleado = new EmpleadoNomina();
        streamStringsEntrada3 >> empleado;
        planilla->AgregarEmpleado(empleado);

        string test2 = "2 Clarissa Parker clarissa_parker@biz.com 1 1";
        istringstream streamStringsEntrada(test2);
        EmpleadoNomina *empleado2 = new EmpleadoNomina();
        streamStringsEntrada >> empleado2;
        planilla->AgregarEmpleado(empleado2);

        int actual = planilla->TotalEmpleados();
        int esperada = 2;

        EXPECT_EQ(actual, esperada);
    }

    TEST(Planilla_Tests, test_CalcularImpuestosSubtotalTotal){

        Planilla *planilla = new Planilla();
        float monto;
        int id;

        string test = "1 Denis Tyler denis_tyler@biz.com 1 1";
        istringstream streamStringsEntrada3(test);
        EmpleadoNomina *empleado = new EmpleadoNomina();
        streamStringsEntrada3 >> empleado;
        string NominaPago = "1 4600.98";
        istringstream streamStringsEntrada4(NominaPago);
        streamStringsEntrada4 >> id >> monto;
        empleado->AsignarMonto(monto);
        empleado->CalculoPago();
        planilla->AgregarEmpleado(empleado);
        
        string test2 = "2 Clarissa Parker clarissa_parker@biz.com 1 1";
        istringstream streamStringsEntrada(test2);
        EmpleadoNomina *empleado2 = new EmpleadoNomina();
        streamStringsEntrada >> empleado2;
        string horasPago = "2 3097.50";
        istringstream streamStringsEntrada2(horasPago);
        int horas;
        streamStringsEntrada2 >> id >> monto >> horas;
        empleado2->AsignarMonto(monto);
        empleado2->AsignarHoras(horas);
        empleado2->CalculoPago();
        planilla->AgregarEmpleado(empleado2);

        planilla->CalculeSubTotal();
        planilla->CalculeImpuestos();


        double actual = planilla->ObtenerSubtotal();
        double esperada = 7159.5864;

        double actual1 = planilla->ObtenerImpuestosTotales();
        double esperada1 = 538.8936;

        double actual2= planilla->ObtenerTotal();
        double esperada2 = 7698.48;

        EXPECT_FLOAT_EQ(actual, esperada);
        EXPECT_FLOAT_EQ(actual1, esperada1);
        EXPECT_FLOAT_EQ(actual2, esperada2);
    }

}