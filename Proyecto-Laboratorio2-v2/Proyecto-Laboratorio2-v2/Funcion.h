#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "FechaHorario.h"

class Funcion
{
	/*Clase Función
		Esta clase representa una función específica de una película en una sala de cine.

		Propiedades:

	Película(objeto de tipo Película)
		Sala(objeto de tipo Sala)
		Fecha y hora de la función
		Lista de asientos disponibles / reservados
		Funciones :

	Constructor para inicializar los atributos.
		Métodos para obtener y establecer los atributos.
		Método para mostrar los detalles de la función.
		Método para reservar un asiento o pasar cantidad por parametros.
		Método para verificar la disponibilidad de asientos.
		metodo para vender entradas para una funcion especifica
;*/
	private:
	Pelicula _pelicula;
	Sala _sala;
	FechaHorario _fechaHoraFuncion;
	int _asientosDisponibles;
	int _asientosReservados;
	int _idFuncion;
	public:
		void setPelicula( const Pelicula& pelicula);
		Pelicula getPelicula();
		void setSala(Sala sala);
		Sala getSala();
		void setFechaHoraFuncion(FechaHorario fechaHoraFuncion);
		FechaHorario getFechaHoraFuncion();
		void setAsientosDisponibles(int asientosDisponibles);
		int getAsientosDisponibles();
		void setAsientosReservados(int asientosReservados);
		int getAsientosReservados();
		void setIdFuncion(int idFuncion);
		int getIdFuncion();
		Funcion();
		Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, int asientosDisponibles, int asientosReservados);
		void mostrarDetalles();
		void reservarAsiento();
		void reservarAsiento(int cantidad);
		bool hayAsientosDisponibles();
		

};
