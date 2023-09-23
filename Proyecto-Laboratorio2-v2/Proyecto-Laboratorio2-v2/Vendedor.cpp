#include "Vendedor.h"
#include <iostream>
Vendedor::Vendedor() : Persona() {
	
}

Vendedor::Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}

void Vendedor::mostrarCapacidadSala(int matrizSalasxFuncion[25][10][10], int idFuncion) {
	
	system("cls");

	std::cout << "Estado actual de la sala de cine:\n";
	for (int i = idFuncion; i <= idFuncion; i++) {
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			if (matrizSalasxFuncion[idFuncion-1][j][k] == 0) {
				std::cout << "\033[47m "; // Fondo blanco
			}
			else {
				std::cout << "\033[41m "; // Fondo rojo
			}
			std::cout << "\033[0m "; // Restaurar color
		}
		std::cout << "\n";
	}
	}
	system("pause");
}
bool Vendedor::reservarAsiento(int fila, int columna, int matrizSalasxFuncion[25][10][10], int idFuncion) {
	if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
		std::cout << "El asiento especificado no existe.\n";
		return false;
	}

	if (matrizSalasxFuncion[idFuncion - 1][fila - 1][columna - 1] == 1) {
		std::cout << "El asiento ya está reservado.\n";
		return false;
	}

	matrizSalasxFuncion[idFuncion - 1][fila - 1][columna - 1] = 1;
	std::cout << "¡Asiento reservado con éxito!\n";
	return true;
}

bool Vendedor::cancelarReserva(int fila, int columna, int matrizSalasxFuncion[25][10][10], int idFuncion) {
	if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
		std::cout << "El asiento especificado no existe.\n";
		return false;
	}

	if (matrizSalasxFuncion[idFuncion-1][fila - 1][columna - 1] == 0) {
		std::cout << "El asiento no está reservado.\n";
		return false;
	}

	matrizSalasxFuncion[idFuncion - 1][fila - 1][columna - 1] = 0;
	std::cout << "¡Reserva cancelada con éxito!\n";
	return true;
}