#pragma once
#include <Windows.h>
#include "rlutil.h"
#include "Persona.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Sala.h"
#include <vector>
#include "ArchivoFunciones.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
#include "ArchivoDiagrama.h"
#include "DiagramaSala.h"


class Administrador : public Persona
{
private:

public:
	void cargarPeliculas();
	void verPeliculasCargadas();
	void cargarSalas();
	void verSalasCargadas();
	Pelicula seleccionarPelicula();
	Pelicula buscarPeliculaxID(int valorBuscado);
	bool darDeBajaPelicula();
	Sala seleccionarSala();
	Sala buscarSalaxID(int valorBuscado);
	bool modificarSalaEnRegistro(int nroSala);
	bool darDeBajaSala();
	void cargarFunciones();
	void verFuncionesCargadas();
	void verFuncionesCargadasEntradas();
	bool modificarFuncionEnRegistro(int idFuncion);
	bool verificarEstadoPeliculas(int idPelicula);
	bool verificarEstadoSalas(int idSaLa);
	void darDeBajaFuncionxSalaOxPelicula();
	bool darDeBajaFuncion(int idFuncion);
	void verVentas();
	void generarReporte();
	Administrador();
	Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
	void menuPeliculas();
	void menuSalas();
	void menuFunciones();
	void menuBackUp();
	bool confirmarAccion();


};