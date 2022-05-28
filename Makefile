FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ $(FLAGS) src/empleadoHoras.cpp -o bin/empleadoHoras.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/planilla bin/empleado.o bin/empleadoNomina.o bin/empleadoHoras.o bin/planilla.o bin/main.o 
	
test:
	mkdir -p bin
	g++ $(FLAGS) tests/empleadoHoras_tests.cpp -o bin/empleadoHoras_tests.o
	g++ $(FLAGS) tests/empleadoNominas_tests.cpp -o bin/empleadoNominas_tests.o
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ $(FLAGS) src/empleadoHoras.cpp -o bin/empleadoHoras.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ -g -o bin/tests bin/empleadoHoras_tests.o bin/empleadoNominas_tests.o bin/empleado.o bin/empleadoNomina.o bin/empleadoHoras.o bin/planilla.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin

