#include "Entrada.h"

void Entrada::mostrarVenta()
{
	std::cout << "ID Venta: " << _idEntrada << std::endl;
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

Entrada::Entrada()
{
}

Entrada::Entrada(int idEntrada, Funcion funcion, float importe, int fila, int columna)
{
	_idEntrada = idEntrada;
	_funcion = funcion;
	_importe = importe;
	_estado = true;
	_fechaHora = FechaHorario();
	_filaAsiento = fila;
	_columnaAsiento = columna;
}

int Entrada::getidEntrada()
{
	return _idEntrada;
}

void Entrada::setidEntrada(int idEntrada)
{
	_idEntrada = idEntrada;
}

Funcion Entrada::getFuncion()
{
	return _funcion;
}

float Entrada::getImporte()
{
	return _importe;
}

void Entrada::setFuncion(Funcion funcion)
{
	_funcion = funcion;
}

void Entrada::setImporte(float importe)
{
	_importe = importe;
}

bool Entrada::getEstado()
{
	return _estado;
}

void Entrada::setEstado(bool estado)
{
		_estado = estado;
}

FechaHorario Entrada::getFechaHora()
{
	return _fechaHora;
}

void Entrada::setFechaHora(FechaHorario fechaHora)
{
		_fechaHora = fechaHora;
}

int Entrada::getFilaAsiento()
{
	return _filaAsiento ;
}

void Entrada::setFilaAsiento(int filaAsiento)
{
	_filaAsiento = filaAsiento;
}

int Entrada::getColumnaAsiento()
{
	return _columnaAsiento ;
}

void Entrada::setColumnaAsiento(int columnaAsiento)
{
	_columnaAsiento = columnaAsiento;
}