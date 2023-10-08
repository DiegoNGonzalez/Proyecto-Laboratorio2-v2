#include "Sala.h"
#include <iostream>
#include <string>

using namespace std;

//private:
//	int _numeroSala;
//	int _capacidadMaximaAsientos;
//	float _precioEntrada;
//	Pelicula _pelicula;
//	public:
//
//		void setNumeroSala(int numeroSala);
//		int getNumeroSala();
//		void setCapacidadMaximaAsientos(int capacidadMaximaAsientos);
//		int getCapacidadMaximaAsientos();
//		void setPrecioEntrada(float precioEntrada);
//		float getPrecioEntrada();
//		void setPelicula(Pelicula pelicula);
//		Pelicula getPelicula();
//		Sala();
//		Sala(int numeroSala, int capacidadMaximaAsientos, float precioEntrada);
//		void asignarPelicula(Pelicula pelicula);
//		void mostrarDetalles();
//};

void Sala::setNumeroSala(int numeroSala)
{
	_numeroSala = numeroSala;
}

int Sala::getNumeroSala()
{
	return _numeroSala;
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
	_numeroSala = 0;
	_estado = true;
}

Sala::Sala(int numeroSala)
{
	_numeroSala = numeroSala;
	_estado = true;
}


void Sala::mostrarDetalles() const
{
	cout << "Numero de sala: " << _numeroSala << endl;
	cout << "Capacidad maxima de asientos: " << 100 << endl;
}


