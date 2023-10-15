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

Sala::Sala()
{
	_idSala = 0;
	_estado = true;
	_precioAsiento = 0;
}

Sala::Sala(int idSala, float precioAsiento)
{
	_idSala = idSala;
	_precioAsiento = precioAsiento;
	_estado = true;
}


void Sala::mostrarDetalles() const
{
	cout << "||||| SALA # " << _idSala <<"|||||" << endl;
	cout << "Capacidad maxima de asientos: " << 100 << endl;
	cout << "Precio de entrada: $" << _precioAsiento << endl;
}


