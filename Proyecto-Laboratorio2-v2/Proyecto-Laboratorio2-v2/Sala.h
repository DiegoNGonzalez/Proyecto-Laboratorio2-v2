#pragma once
#include "Pelicula.h"
class Sala
{
	private:
		int _numeroSala;
		//int _capacidadMaximaAsientos;
		//int _filas;
		//int _columnas;
		bool _estado;
		
	public:

		void setNumeroSala(int numeroSala);
		int getNumeroSala();
		
		Sala();
		Sala(int numeroSala);
		void mostrarDetalles() const;
		void setEstado(bool estado);
		bool getEstado() const;

};

