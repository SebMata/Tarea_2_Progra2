#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"
#include "../src/empleado.h"
#include <string>

TEST(EmpleadoNominas_Tests, test_calcularPago){

    string test = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(test);
    EmpleadoNomina *empleado2 = new EmpleadoNomina();
    streamStringsEntrada >> empleado2;
    string NominaPago = "1 4600.98";
    istringstream streamStringsEntrada2(NominaPago);
    int id;
    float costo;
    streamStringsEntrada2 >> id >> costo;

    empleado2->AsignarMonto(costo);
    empleado2->CalculoPago();
    

    float actual = empleado2->ObtenerPago();
    float esperada = 4278.9114;

    EXPECT_FLOAT_EQ(actual, esperada);

}