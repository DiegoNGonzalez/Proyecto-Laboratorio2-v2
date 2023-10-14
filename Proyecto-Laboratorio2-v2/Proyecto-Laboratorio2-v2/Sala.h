#pragma once
#include "Pelicula.h"
class Sala
{
	private:
		int _idSala;
		float _precioAsiento;
		bool _estado;
		
	public:

		void setIdSala(int numeroSala);
		int getIdSala();
		void setPrecioAsiento(float precioAsiento);
		float getPrecioAsiento();
		
		Sala();
		Sala(int idSala, float precioAsiento);
		void mostrarDetalles() const;
		void setEstado(bool estado);
		bool getEstado() const;

};

