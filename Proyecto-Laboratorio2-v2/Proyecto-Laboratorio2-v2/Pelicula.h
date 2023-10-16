#pragma once
#include <string>
#include "Horario.h"
#include <cstring>
class Pelicula
{
private:
	int _id;
	char _titulo[30];
	char _director[30];
	char _clasificacionEdad[30];
	char _genero[30];
	int  _duracion;
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
	void setDuracion(int duracion);
	int getDuracion() const;
	void setEstado(bool estado);
	bool getEstado() const;
	Pelicula();
	Pelicula(int id, std::string titulo, std::string director, std::string clasificacionEdad, std::string genero, int duracion);
	void mostrarDetalles() const;
};

