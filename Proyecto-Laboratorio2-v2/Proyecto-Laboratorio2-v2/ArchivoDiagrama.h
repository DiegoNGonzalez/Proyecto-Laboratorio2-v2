#pragma once
#include "DiagramaSala.h"
#include <cstring>
class ArchivoDiagrama
{
private:
	char _nombre[30];
	public:
		ArchivoDiagrama(const char* nombre) {
			strcpy(_nombre, nombre);
		}
		DiagramaSala leerRegistro(int posicion);
		int contarRegistros();
		bool grabarRegistro(DiagramaSala diagrama);
		bool grabarRegistro(DiagramaSala diagrama, int posicion);
		void mostrarRegistro(int idFuncion);
		bool reservarAsientoEnRegistro(int idFuncion, int fila, int columna);
		bool cancelarReservaEnRegistro(int idFuncion, int fila, int columna);
		int buscarDiagrama(int valorBuscado);
};

