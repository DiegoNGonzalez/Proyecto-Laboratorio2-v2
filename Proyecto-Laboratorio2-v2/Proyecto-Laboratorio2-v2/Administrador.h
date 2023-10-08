#pragma once
#include "Persona.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Sala.h"
#include <vector>
#include "ArchivoFunciones.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
class Administrador : public Persona
{
private:
	/*Pelicula _vecPeliculas[5];
	Sala _vecSalas[5];
	Funcion _vecFunciones[25];*/

public:
	void cargarPeliculas();
	void verPeliculasCargadas();
	void cargarSalas();
	void verSalasCargadas();
	Pelicula seleccionarPelicula();
	Sala seleccionarSala();
	void cargarFunciones();
	void verFuncionesCargadas();
	void verVentas();
	void generarReporte();
	Administrador();
	Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
};

