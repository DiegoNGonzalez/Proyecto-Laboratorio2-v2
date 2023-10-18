#include "DiagramaSala.h"
#include <iostream>
#include "ArchivoFunciones.h"
#include "ArchivoDiagrama.h"

DiagramaSala::DiagramaSala() {

}
DiagramaSala::DiagramaSala(int idFuncion) {
	_idFuncion = idFuncion;
	_estado = true;
}

bool DiagramaSala::reservarAsiento(int fila, int columna) {

	if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
		std::cout << "El asiento especificado no existe.\n";
		return false;
	}

	if (salaDeCine[fila - 1][columna - 1] == 1) {
		std::cout << "El asiento ya est� reservado.\n";
		return false;
	}

	std::cout << "�Asiento reservado con �xito!\n";
	return true;
}


bool DiagramaSala::cancelarReserva(int fila, int columna) {


	if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
		std::cout << "El asiento especificado no existe.\n";
		return false;
	}

	if (salaDeCine[fila - 1][columna - 1] == 0) {
		std::cout << "El asiento no est� vendido.\n";
		return false;
	}

	std::cout << "�Venta cancelada con �xito!\n";
	return true;
}

void DiagramaSala::setEstado(bool est)
{
		_estado = est;
}

bool DiagramaSala::getEstado()
{
	return _estado;
}


void DiagramaSala::setIdFuncion(int idFuncion) {
	_idFuncion = idFuncion;
}

int DiagramaSala::getIdFuncion() {
	return _idFuncion;
}


void DiagramaSala::mostrarSala() {
	std::cout << "ID de la funci�n: " << _idFuncion << std::endl;
	std::cout << "Estado actual de la sala de cine:\n";
	for (int f = 0; f < 10; f++) {
		std::cout << std::endl;
		for (int c = 0; c < 10; c++) {
			if (salaDeCine[f][c] == 0) {
				std::cout << "\033[47m "; // Asiento disponible
			}
			else {
				std::cout << "\033[41m "; // Asiento reservado
			}
			std::cout << "\033[0m ";
			rlutil::setColor(rlutil::LIGHTBLUE);
		}

	}
	std::cout << std::endl;
	system("pause");
}

void DiagramaSala::setSalaDeCine(int fila, int columna, int estado) {
	salaDeCine[fila - 1][columna - 1] = estado;
}