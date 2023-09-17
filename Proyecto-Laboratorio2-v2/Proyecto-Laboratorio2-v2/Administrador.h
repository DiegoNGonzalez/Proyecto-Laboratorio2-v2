#pragma once
#include "Persona.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Sala.h"
#include <vector>
class Administrador : public Persona
{
private:
	/*Pelicula _vecPeliculas[5];
	Sala _vecSalas[5];
	Funcion _vecFunciones[25];*/

public:
	void cargarPeliculas(Pelicula* vecPeliculas);
	void verPeliculasCargadas(const Pelicula* vecPeliculas);
	void cargarSalas(Sala* vecSalas);
	void verSalasCargadas(const Sala* vecSalas);
	Pelicula seleccionarPelicula(Pelicula* vecPeliculas);
	Sala seleccionarSala(Sala* vecSalas);
	void cargarFunciones(Funcion* vecFunciones, Pelicula* vecPeliculas, Sala* vecSalas);
	void verFuncionesCargadas( Funcion* vecFunciones);
	void verVentas();
	void generarReporte();
	Administrador();
	Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
};

