#pragma once
#include <cstring>
#include "Sala.h"
class ArchivoSalas
{
	private:
	char _nombre[30];
	public:
		ArchivoSalas(const char* nombre) {
		strcpy(_nombre, nombre);
	}
		Sala leerRegistro(int posicion);
		int contarRegistros();
		bool grabarRegistro(Sala sala);
		void generarBackUp();
		void restaurarBackUp();

};

