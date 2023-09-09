#include "Administrador.h"
#include <iostream>
void Administrador::
cargarPeliculas(std::vector <Pelicula>& vecPeliculas) {
	std::string titulo;
	std::string director;
	std::string clasificacionEdad;
	std::string genero;
	int hora, minuto;
	Horario duracion;
	Pelicula pelicula;
	std::cout << "Ingrese el titulo: " << std::endl;
	std::cin >> titulo;
	std::cout << "Ingrese el director: " << std::endl;
	std::cin >> director;
	std::cout << "Ingrese la clasificacion de edad: " << std::endl;
	std::cin >> clasificacionEdad;
	std::cout << "Ingrese el genero: " << std::endl;
	std::cin >> genero;
	std::cout << "Ingrese las horas de duracion: " << std::endl;
	std::cin >> hora;
	std::cout << "Ingrese los minutos de duracion: " << std::endl;
	std::cin >> minuto;
	duracion = Horario(minuto, hora);
	pelicula = Pelicula(titulo, director, clasificacionEdad, genero, duracion);
	
	vecPeliculas.push_back(pelicula);
}

void Administrador::verPeliculasCargadas(std::vector <Pelicula>& vecPelicula) {
	for (Pelicula pelicula : vecPelicula) {
		pelicula.mostrarDetalles();
	}
}