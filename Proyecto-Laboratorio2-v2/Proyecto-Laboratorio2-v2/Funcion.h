#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "FechaHorario.h"
#include "DiagramaSala.h"
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
	DiagramaSala _diagramaSalas;
	int _idFuncion;
	float _precioEntrada;
	bool _estado;
public:
		void setPelicula( Pelicula pelicula);
		Pelicula getPelicula();
		void setSala(Sala sala);
		Sala getSala();
		void setFechaHoraFuncion(FechaHorario fechaHoraFuncion);
		FechaHorario getFechaHoraFuncion();
		void setIdFuncion(int idFuncion);
		int getIdFuncion() const;
		void setEstado(bool estado);
		bool getEstado() const;
		Funcion();
		Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, float precioEntrada, DiagramaSala diagramaSala);
		void mostrarDetalles();
		bool hayAsientosDisponibles();
		void setPrecioEntrada(float precioEntrada);
		float getPrecioEntrada() const;
		DiagramaSala getDiagramaSala() const;
		void setDiagramaSala(DiagramaSala diagramaSala);
		
		

};
