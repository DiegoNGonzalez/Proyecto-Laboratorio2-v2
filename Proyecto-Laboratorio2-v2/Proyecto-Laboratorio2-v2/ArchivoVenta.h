#pragma once
#include "Venta.h"
class ArchivoVenta
{
private:
	char _nombre[30];
public:
	ArchivoVenta(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	Venta leerRegistro(int posicion);
	int contarRegistros();
	bool grabarRegistro(Venta venta);
	bool grabarRegistro(Venta venta, int posicion);
	bool generarBackUp();
	bool restaurarBackUp();
	int validarId();
	int buscarPosVentaxID(int valorBuscado);
	Venta buscarVentaxID(int valorBuscado);
};

