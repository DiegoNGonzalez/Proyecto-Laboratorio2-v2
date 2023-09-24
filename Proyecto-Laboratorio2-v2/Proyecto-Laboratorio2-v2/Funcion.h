#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "FechaHorario.h"

class Funcion
{
	/*Clase Funci�n
		Esta clase representa una funci�n espec�fica de una pel�cula en una sala de cine.

		Propiedades:

	Pel�cula(objeto de tipo Pel�cula)
		Sala(objeto de tipo Sala)
		Fecha y hora de la funci�n
		Lista de asientos disponibles / reservados
		Funciones :

	Constructor para inicializar los atributos.
		M�todos para obtener y establecer los atributos.
		M�todo para mostrar los detalles de la funci�n.
		M�todo para reservar un asiento o pasar cantidad por parametros.
		M�todo para verificar la disponibilidad de asientos.
		metodo para vender entradas para una funcion especifica
;*/
private:
	Pelicula _pelicula;
	Sala _sala;
	FechaHorario _fechaHoraFuncion;
	int _idFuncion;
	float _precioEntrada;
public:
		int matrizSala[1][10][10] = {0};
		void setPelicula( Pelicula pelicula);
		Pelicula getPelicula();
		void setSala(Sala sala);
		Sala getSala();
		void setFechaHoraFuncion(FechaHorario fechaHoraFuncion);
		FechaHorario getFechaHoraFuncion();
		void setIdFuncion(int idFuncion);
		int getIdFuncion() const;
		Funcion();
		Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, float precioEntrada);
		void mostrarDetalles();
		bool hayAsientosDisponibles();
		void setPrecioEntrada(float precioEntrada);
		float getPrecioEntrada() const;
		
		

};
