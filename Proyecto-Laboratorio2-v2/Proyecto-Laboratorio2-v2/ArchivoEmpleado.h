#pragma once
#include <cstring>
#include "Empleado.h"

class ArchivoEmpleado {
private:
	char _nombre[30];
public:
	ArchivoEmpleado(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	Empleado leerRegistro(int posicion);
	int contarRegistros();
	bool grabarRegistro(Empleado empleado);
	bool grabarRegistro(Empleado empleado, int posicionEmpleado);
	bool generarBackUp();
	bool restaurarBackUp();
	int validarId();
	int buscarPosEmpleadoxID(int valorBuscado);
};

