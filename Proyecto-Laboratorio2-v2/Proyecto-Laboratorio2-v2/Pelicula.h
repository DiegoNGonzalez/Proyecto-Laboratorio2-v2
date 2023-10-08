#pragma once
#include <string>
#include "Horario.h"
#include <cstring>
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
		char _titulo[30];
		char _director[30];
		char _clasificacionEdad[30];
		char _genero[30];
		int _hora, _minuto;
		bool _estado;
	public:
		void setId(int id);
		int getId();
		void setTitulo(std::string titulo);
		char* getTitulo();
		void setDirector(std::string director);
		char* getDirector();
		void setClasificacionEdad(std::string clasificacionEdad);
		char* getClasificacionEdad();
		void setGenero(std::string genero);
		char* getGenero();
		void setHora(int hora);
		int getHora() const;
		void setMinuto(int minuto);
		int getMinuto() const;
		void setEstado(bool estado);
		bool getEstado() const;
		Pelicula();
		Pelicula(int id, std::string titulo, std::string director, std::string clasificacionEdad, std::string genero,int hora, int minuto);
		void mostrarDetalles() const;
};

