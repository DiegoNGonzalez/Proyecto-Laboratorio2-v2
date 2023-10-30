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
	const char* getTitulo();
	void setDirector(std::string director);
	const char* getDirector();
	void setClasificacionEdad(std::string clasificacionEdad);
	const char* getClasificacionEdad();
	void setGenero(std::string genero);
	const char* getGenero();
	void setDuracion(int duracion);
	int getDuracion() const;
	void setEstado(bool estado);
	bool getEstado() const;
	Pelicula();
	Pelicula(int id, const char *titulo, const char *director, const char *clasificacionEdad, const char *genero, int duracion);
	void mostrarDetalles() const;
};

