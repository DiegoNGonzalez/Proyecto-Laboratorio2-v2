#pragma once
#include <string>
#include "Horario.h"
class Pelicula
{
	/*Clase Película
		Esta clase representa una película y sus detalles.

		Propiedades:

	Título
		Director
		Duración
		Clasificación de edad
		Género
		Funciones :

	Constructor para inicializar los atributos.
		Métodos para obtener y establecer los atributos.
		Método para mostrar los detalles de la película.*/
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

