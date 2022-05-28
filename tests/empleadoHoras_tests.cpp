#include <gtest/gtest.h>
#include "../src/empleadoHoras.h"
#include "../src/empleado.h"
#include <string>

TEST(EmpleadoHoras_Tests, test_calcularPago){
    
    string test = "451 Ryan Webster Ryan_Webster6612@hourpy.biz 2 214";
    istringstream streamStringsEntrada(test);
    EmpleadoHoras *empleado = new EmpleadoHoras();
    streamStringsEntrada >> empleado;
    string horasPago = "451 42.26 55";
    istringstream streamStringsEntrada2(horasPago);
    float costo;
    int id;
    int horas;
    streamStringsEntrada2 >> id >> costo >> horas;

    empleado->AsignarMonto(costo);
    empleado->AsignarHoras(horas);
    empleado->CalculoPago();
    

    float actual = empleado->ObtenerPago();
    float esperada = 2324.3;

    EXPECT_FLOAT_EQ(actual, esperada);

}