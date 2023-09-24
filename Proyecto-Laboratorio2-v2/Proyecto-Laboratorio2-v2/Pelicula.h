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
		int _id;
		std::string _titulo;
		std::string _director;
		std::string _clasificacionEdad;
		std::string _genero;
		int _hora, _minuto;
	public:
		void setId(int id);
		int getId() const;
		void setTitulo(std::string titulo);
		std::string getTitulo();
		void setDirector(std::string director);
		std::string getDirector();
		void setClasificacionEdad(std::string clasificacionEdad);
		std::string getClasificacionEdad();
		void setGenero(std::string genero);
		std::string getGenero();
		void setHora(int hora);
		int getHora() const;
		void setMinuto(int minuto);
		int getMinuto() const;
		Pelicula();
		Pelicula(int id, std::string titulo, std::string director, std::string clasificacionEdad, std::string genero,int hora, int minuto);
		void mostrarDetalles() const;
};

