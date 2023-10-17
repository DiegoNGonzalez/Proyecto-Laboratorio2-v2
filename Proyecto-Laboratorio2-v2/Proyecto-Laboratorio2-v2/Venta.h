#pragma once
#include "ArchivoFunciones.h"

class Venta{
private:
	int _idVenta;
	Funcion _funcion;
	float _importe;
public:
	Venta();
	Venta(int idVenta, Funcion funcion, float importe);
	int getIdVenta();
	void setIdVenta(int idVenta);
	void mostrarVenta();
	Funcion getFuncion();
	float getImporte();
	void setFuncion(Funcion funcion);
	void setImporte(float importe);
};

