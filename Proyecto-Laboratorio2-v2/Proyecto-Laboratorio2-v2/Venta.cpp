#include "Venta.h"

void Venta::mostrarVenta()
{
	std::cout << "ID Venta: " << _idVenta << std::endl;
	std::cout << "Importe: $" << _importe << std::endl;
	std::cout << "Fecha y hora de la venta" << std::endl;
	_fechaHora.mostrarFechaHora();
	std::cout <<"Funcion nro# "<< _funcion.getIdFuncion() << std::endl;
	std::cout <<"Pelicula: "<< _funcion.getPelicula().getTitulo() << std::endl;
	std::cout << "Sala: " << _funcion.getSala().getIdSala() << std::endl;
	std::cout << "Fila del asiento: " << _filaAsiento << std::endl;
	std::cout << "Nro de asiento: " << _columnaAsiento << std::endl;

	//_funcion.mostrarDetalles();
}

Venta::Venta()
{
}

Venta::Venta(int idVenta, Funcion funcion, float importe, int fila, int columna)
{
	_idVenta = idVenta;
	_funcion = funcion;
	_importe = importe;
	_estado = true;
	_fechaHora = FechaHorario();
	_filaAsiento = fila;
	_columnaAsiento = columna;
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

bool Venta::getEstado()
{
	return _estado;
}

void Venta::setEstado(bool estado)
{
		_estado = estado;
}

FechaHorario Venta::getFechaHora()
{
	return _fechaHora;
}

void Venta::setFechaHora(FechaHorario fechaHora)
{
		_fechaHora = fechaHora;
}

int Venta::getFilaAsiento()
{
	return _filaAsiento ;
}

void Venta::setFilaAsiento(int filaAsiento)
{
	_filaAsiento = filaAsiento;
}

int Venta::getColumnaAsiento()
{
	return _columnaAsiento ;
}

void Venta::setColumnaAsiento(int columnaAsiento)
{
	_columnaAsiento = columnaAsiento;
}