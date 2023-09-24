#pragma once
#include "Persona.h"
#include "Funcion.h"
class Vendedor : public Persona
{
public:
	Vendedor();
	Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
	void venderEntradas(int contadorEntradas, Funcion* vecFunciones, int idFuncion, int contadorGeneralEntradas);
	void mostrarCapacidadSala(int matrizSalasxFuncion[25][10][10], int aux);
	bool reservarAsiento(int fila, int columna, int matrizSalasxFuncion[25][10][10], int idFuncion);
	bool cancelarReserva(int fila, int columna, int matrizSalasxFuncion[25][10][10], int idFuncion);

};

