#pragma once
#include "Entrada.h"
class ArchivoEntrada
{
private:
	char _nombre[30];
public:
	ArchivoEntrada(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	Entrada leerRegistro(int posicion);
	int contarRegistros();
	bool grabarRegistro(Entrada entrada);
	bool grabarRegistro(Entrada entrada, int posicion);
	bool generarBackUp();
	bool restaurarBackUp();
	int validarId();
	int buscarPosEntradaxID(int valorBuscado);
	Entrada buscarEntradaxID(int valorBuscado);
	int buscarPosVentaxAsientoVendido(int idFuncion, int fila, int columna);
	Entrada buscarVentaxAsientoVendido(int idFuncion, int fila, int columna);
	void verVentasCargadas();
};

