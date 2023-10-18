#pragma once
#include "ArchivoFunciones.h"

class Venta{
private:
	int _idVenta;
	Funcion _funcion;
	float _importe;
	bool _estado;
	FechaHorario _fechaHora;
	int _filaAsiento;
	int _columnaAsiento;
public:
	Venta();
	Venta(int idVenta, Funcion funcion, float importe, int fila,int columna);
	int getIdVenta();
	void setIdVenta(int idVenta);
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

