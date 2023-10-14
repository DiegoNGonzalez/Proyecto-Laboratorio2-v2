#include "DiagramaSala.h"
#include <iostream>
#include "ArchivoFunciones.h"
#include "ArchivoDiagrama.h"

DiagramaSala::DiagramaSala() {
	
}
DiagramaSala::DiagramaSala(int idFuncion) {
	_idFuncion = idFuncion;
	

}

bool DiagramaSala::reservarAsiento(int fila, int columna) {

			if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
				std::cout << "El asiento especificado no existe.\n";
				return false;
			}

			if (salaDeCine[fila - 1][columna - 1] == 1) {
				std::cout << "El asiento ya está reservado.\n";
				return false;
			}

			std::cout << "¡Asiento reservado con éxito!\n";
			return true;
		}


bool DiagramaSala::cancelarReserva( int fila, int columna) {
	

			if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
				std::cout << "El asiento especificado no existe.\n";
				return false;
			}

			if (salaDeCine[fila - 1][columna - 1] == 0) {
				std::cout << "El asiento no está reservado.\n";
				return false;
			}

			std::cout << "¡Reserva cancelada con éxito!\n";
			return true;
	}


void DiagramaSala::setIdFuncion(int idFuncion) {
	_idFuncion = idFuncion;
}

int DiagramaSala::getIdFuncion() {
	return _idFuncion;
}


 void DiagramaSala::mostrarSala() {
	 std::cout << "ID de la función: " << _idFuncion << std::endl;
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
		 }

	 }
	 std::cout << std::endl;
	 system("pause");
 }

 void DiagramaSala::setSalaDeCine(int fila, int columna, int estado) {
	 salaDeCine[fila-1][columna-1] = estado;
 }