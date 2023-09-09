#pragma once
#include "Persona.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Sala.h"
#include <vector>
class Administrador : public Persona
{
private:
	std::vector <Pelicula> _vecPeliculas;
	std::vector <Sala> _vecSalas;
	std::vector <Funcion> _vecFunciones;

public:
	void cargarPeliculas(std::vector <Pelicula> &vecPeliculas);
	void verPeliculasCargadas(std::vector <Pelicula>& vecPeliculas);
	void cargarSalas(std::vector <Sala> &vecSalas);
	void verSalasCargadas(std::vector <Sala>& vecSalas);
	void cargarFunciones();
	void verFuncionesCargadas();
	void verVentas();
	void generarReporte();
	Administrador();
	Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
};

