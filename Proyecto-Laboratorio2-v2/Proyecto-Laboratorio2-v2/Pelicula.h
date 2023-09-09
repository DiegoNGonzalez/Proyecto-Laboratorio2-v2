#pragma once
#include <string>
#include "Horario.h"
class Pelicula
{
	/*Clase Pel�cula
		Esta clase representa una pel�cula y sus detalles.

		Propiedades:

	T�tulo
		Director
		Duraci�n
		Clasificaci�n de edad
		G�nero
		Funciones :

	Constructor para inicializar los atributos.
		M�todos para obtener y establecer los atributos.
		M�todo para mostrar los detalles de la pel�cula.*/
	private:
		std::string _titulo;
		std::string _director;
		std::string _clasificacionEdad;
		std::string _genero;
		Horario _duracion;
	public:
		void setTitulo(std::string titulo);
		std::string getTitulo();
		void setDirector(std::string director);
		std::string getDirector();
		void setClasificacionEdad(std::string clasificacionEdad);
		std::string getClasificacionEdad();
		void setGenero(std::string genero);
		std::string getGenero();
		void setDuracion(Horario duracion);
		Horario getDuracion();
		Pelicula();
		Pelicula(std::string titulo, std::string director, std::string clasificacionEdad, std::string genero, Horario duracion);
		void mostrarDetalles();
};

