#include "DiagramaSala.h"
#include <iostream>
#include "ArchivoFunciones.h"

DiagramaSala::DiagramaSala() {
	
}
DiagramaSala::DiagramaSala(int idFuncion) {
	_idFuncion = idFuncion;
	

}
void DiagramaSala::mostrarSalaDeCine(int idFuncion) {
	system("cls"); 
	ArchivoFunciones archiFunciones("funcion.dat");
	Funcion funcion;
	int cantidadRegistros = archiFunciones.contarRegistros();
	int matrizAux[10][10];
	for (int i = 0; i < cantidadRegistros; i++) {
		funcion = archiFunciones.leerRegistro(i);
		if (funcion.getIdFuncion() == idFuncion) {
			/*for (int f = 0; f < 10; f++) {
				for (int c = 0; c < 10; c++) {
					matrizAux[f][c] = funcion.getDiagramaSala().getSalaDeCine()[f][c];
				}
			}*/
			std::cout << "Estado actual de la sala de cine:\n";
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					if (matrizAux[i][j] == 0) {
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
		else {
						std::cout << "No se encontro la funcion" << std::endl;
		}
	}

	system("pause");
}

bool DiagramaSala::reservarAsiento(int idFuncion, int fila, int columna) {
	ArchivoFunciones archiFunciones("funcion.dat");
	Funcion funcion;
	int cantidadRegistros = archiFunciones.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		funcion = archiFunciones.leerRegistro(i);
		if (funcion.getIdFuncion() == idFuncion) {

			if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
				std::cout << "El asiento especificado no existe.\n";
				return false;
			}

			if (salaDeCine[fila - 1][columna - 1] == 1) {
				std::cout << "El asiento ya está reservado.\n";
				return false;
			}

			salaDeCine[fila - 1][columna - 1] = 1;
			std::cout << "¡Asiento reservado con éxito!\n";
			return true;
		}
	}
}

bool DiagramaSala::cancelarReserva(int idFuncion, int fila, int columna) {
	
	ArchivoFunciones archiFunciones("funcion.dat");
	Funcion funcion;
	int cantidadRegistros = archiFunciones.contarRegistros();

	for (int i = 0; i < cantidadRegistros; i++) {
		funcion = archiFunciones.leerRegistro(i);
		if (funcion.getIdFuncion() == idFuncion) {

			if (fila < 1 || fila > 10 || columna < 1 || columna > 10) {
				std::cout << "El asiento especificado no existe.\n";
				return false;
			}

			if (salaDeCine[fila - 1][columna - 1] == 0) {
				std::cout << "El asiento no está reservado.\n";
				return false;
			}

			salaDeCine[fila - 1][columna - 1] = 0;
			std::cout << "¡Reserva cancelada con éxito!\n";
			return true;
		}
	}
}

void DiagramaSala::setidFuncion(int idFuncion) {
	_idFuncion = idFuncion;
}

int DiagramaSala::getidFuncion() {
	return _idFuncion;
}

int DiagramaSala::getSalaDeCine() const{
	return **salaDeCine;
}