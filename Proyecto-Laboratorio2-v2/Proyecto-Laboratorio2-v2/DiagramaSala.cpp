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
		std::cout << std::endl << "El asiento no existe.\n";
		return false;
	}

	if (salaDeCine[fila - 1][columna - 1] == 1) {
		std::cout << std::endl << "El asiento ya está vendido!.\n";
		return false;
	}

	std::cout << std::endl << "¡Venta del asiento realizada con exito!\n";
	return true;
}


bool DiagramaSala::cancelarReserva(int fila, int columna) {


	if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
		std::cout << std::endl << "El asiento no existe.\n";
		return false;
	}

	if (salaDeCine[fila - 1][columna - 1] == 0) {
		std::cout << std::endl << "El asiento esta disponible.\n";
		return false;
	}

	std::cout << std::endl << "¡Venta del asiento cancelada con éxito!\n";
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
	std::cout << "------- SALA DE CINE DE LA FUNCION #" << _idFuncion <<  " -------\n";
	for (int f = 0; f < 10; f++) {
		std::cout << std::endl;
		for (int c = 0; c < 10; c++) {
			if (salaDeCine[f][c] == 0) {
				std::cout << "\033[47m "; // Asiento disponible
			}
			else {
				std::cout << "\033[44m "; // Asiento reservado
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

void DiagramaSala::mostrarAsientosPorFilaDisponible(int fila) {
	for (int i = 0; i < 10; i++) {
		if (salaDeCine[fila - 1][i] == 0) {
			std::cout << "EL ASIENTO " <<  i + 1 << " ESTA DISPONIBLE" << std::endl;
		}
	}
}