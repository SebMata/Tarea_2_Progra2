#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

#include "empleado.h"
#include "empleadoNomina.h"
#include "planilla.h"
#include <vector>
using namespace std;

int main() {

    Planilla *planilla = new Planilla();

    ifstream archivoPersonas("personas.txt", std::ifstream::in);

     if (!archivoPersonas.is_open())
    {
        std::cerr << "Error abriendo archivo categorias.txt" << std::endl;
        return -1;
    }

    archivoPersonas >> planilla;

    archivoPersonas.close();

    ifstream archivoNomina("nomina.txt", std::ifstream::in);

    if (!archivoNomina.is_open())
    {
        std::cerr << "Error abriendo archivo categorias.txt" << std::endl;
        return -1;
    }
    archivoNomina > planilla;

    archivoNomina.close();

    ifstream archivoHoras("horastrabajadas.txt", std::ifstream::in);

    if (!archivoHoras.is_open())
    {
        std::cerr << "Error abriendo archivo categorias.txt" << std::endl;
        return -1;
    }

    archivoHoras + planilla;

    archivoHoras.close();


    ofstream reporte("reporte.csv", std::ifstream::out); 

    if (!reporte.is_open())
    {
        std::cerr << "Error abriendo archivo reporteCatalogo.txt" << std::endl;
        return -1;
    }

    reporte << planilla;

    reporte.close();

    delete planilla;



}