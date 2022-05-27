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
	g++ $(FLAGS) tests/tests_envio_postal.cpp -o bin/tests_envio_postal.o
	g++ $(FLAGS) tests/tests_envio_fedex.cpp -o bin/tests_envio_fedex.o
	g++ $(FLAGS) src/TipoEnvio.cpp -o bin/TipoEnvio.o 
	g++ $(FLAGS) src/EnvioPostal.cpp -o bin/EnvioPostal.o 
	g++ $(FLAGS) src/EnvioFedex.cpp -o bin/EnvioFedex.o
	g++ -g -o bin/tests bin/tests_envio_postal.o bin/tests_envio_fedex.o bin/TipoEnvio.o bin/EnvioPostal.o bin/EnvioFedex.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin

