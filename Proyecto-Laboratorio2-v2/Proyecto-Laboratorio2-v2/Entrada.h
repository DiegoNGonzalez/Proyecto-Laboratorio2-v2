#pragma once
#include "ArchivoFunciones.h"

class Entrada{
private:
	int _idEntrada;
	Funcion _funcion;
	float _importe;
	bool _estado;
	FechaHorario _fechaHora;
	int _filaAsiento;
	int _columnaAsiento;
public:
	Entrada();
	Entrada(int idEntrada, Funcion funcion, float importe, int fila,int columna);
	int getidEntrada();
	void setidEntrada(int idEntrada);
	void mostrarVenta();
	Funcion getFuncion();
	float getImporte();
	void setFuncion(Funcion funcion);
	void setImporte(float importe);
	bool getEstado();
	void setEstado(bool estado);
	FechaHorario getFechaHora();
	void setFechaHora(FechaHorario fechaHora);
	int getFilaAsiento();
	void setFilaAsiento(int filaAsiento);
	int getColumnaAsiento();
	void setColumnaAsiento(int columnaAsiento);


};

