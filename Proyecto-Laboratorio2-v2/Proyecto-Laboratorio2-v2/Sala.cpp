#include "Sala.h"
#include <iostream>
#include <string>

using namespace std;


void Sala::setIdSala(int idSala)
{
	_idSala = idSala;
}

int Sala::getIdSala()
{
	return _idSala;
}

void Sala::setPrecioAsiento(float precioAsiento)
{
	_precioAsiento = precioAsiento;
}

float Sala::getPrecioAsiento()
{
	return _precioAsiento;
}


void Sala::setEstado(bool estado)
{
	_estado = estado;
}

bool Sala::getEstado() const
{
	return _estado;
}

void Sala::setAsientosDisponibles(int asientosDisponibles)
{
	_asientosDisponibles = asientosDisponibles;
}

int Sala::getAsientosDisponibles()
{
	return _asientosDisponibles;
}

Sala::Sala()
{
	_idSala = 0;
	_estado = true;
	_precioAsiento = 0;
	_asientosDisponibles = 0;
}

Sala::Sala(int idSala, float precioAsiento)
{
	_idSala = idSala;
	_precioAsiento = precioAsiento;
	_estado = true;
	_asientosDisponibles = 100;
}


void Sala::mostrarDetalles() const
{
	cout << "------- SALA #" << _idSala << " -------" << endl;
	cout << "CAPACIDAD MAXIMA: " << 100 << endl;
	cout << "ASIENTOS DISPONIBLES: " << _asientosDisponibles << endl;
	cout << "PRECIO ENTRADA $" << _precioAsiento << endl;
}


