#include "Entrada.h"

void Entrada::mostrarVenta()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "VENTA # " << _idEntrada << std::endl;
	std::cout << "IMPORTE $" << _importe << std::endl;
	std::cout << "FECHA Y HORA: ";
	_fechaHora.mostrarFechaHora();
	std::cout <<"FUNCION #"<< _funcion.getIdFuncion() << std::endl;
	std::cout <<"PELICULA: "<< _funcion.getPelicula().getTitulo() << std::endl;
	std::cout << "SALA: " << _funcion.getSala().getIdSala() << std::endl;
	std::cout << "FILA DEL ASIENTO: " << _filaAsiento << std::endl;
	std::cout << "NRO DEL ASIENTO: " << _columnaAsiento << std::endl;
	std::cout << "-------------------------------------" << std::endl;
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