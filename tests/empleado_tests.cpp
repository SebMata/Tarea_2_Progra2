#include <gtest/gtest.h>
#include "../src/empleado.h"
#include "../src/empleadoHoras.h"
#include <string>

namespace{

    TEST(Empleado_Tests, test_ObtenerInformacion){

        int id;
        string nombre;
        string apellido;
        string email;
        int tipo;
        int idSupervisor;
        string test = "451 Ryan Webster Ryan_Webster6612@hourpy.biz 2 214";
        istringstream streamStringsEntrada(test);
        EmpleadoHoras *empleado = new EmpleadoHoras();
        streamStringsEntrada >> empleado;
        streamStringsEntrada >> id >> nombre >> apellido >> email >> tipo >> idSupervisor;
        

        float actual = empleado->ObtenerIdSupervisor();
        float esperada = 214;

        float actual1 = empleado->ObtenerId();
        float esperada1 = 451;

        string actual2 = empleado->ObtenerNombre();
        string esperada2 = "Ryan Webster";


        EXPECT_FLOAT_EQ(actual, esperada);

        EXPECT_FLOAT_EQ(actual1, esperada1);

        EXPECT_EQ(actual2, esperada2);

    }
}