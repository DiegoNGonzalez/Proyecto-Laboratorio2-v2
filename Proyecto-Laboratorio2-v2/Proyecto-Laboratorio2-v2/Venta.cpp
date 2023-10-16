#include "Venta.h"

void Venta::mostrarVenta()
{
	std::cout << "ID Venta: " << _idVenta << std::endl;
	std::cout << "Cantidad de entradas: " << _cantidadEntradas << std::endl;
	std::cout << "Importe: " << _importe << std::endl;
	_funcion.mostrarDetalles();
}

Venta::Venta()
{
}

Venta::Venta(int idVenta, int cantidadEntradas, Funcion funcion, float importe)
{
	_idVenta = idVenta;
	_cantidadEntradas = cantidadEntradas;
	_funcion = funcion;
	_importe = importe;
}

int Venta::getIdVenta()
{
	return _idVenta;
}

void Venta::setIdVenta(int idVenta)
{
	_idVenta = idVenta;
}

Funcion Venta::getFuncion()
{
	return _funcion;
}

float Venta::getImporte()
{
	return _importe;
}

void Venta::setFuncion(Funcion funcion)
{
	_funcion = funcion;
}

void Venta::setImporte(float importe)
{
	_importe = importe;
}