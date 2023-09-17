#include "Administrador.h"
#include <iostream>
void Administrador::
cargarPeliculas(Pelicula* vecPelicula) {
	for (int i = 0; i < 5; i++) {
		std::string titulo;
		std::string director;
		std::string clasificacionEdad;
		std::string genero;
		int hora, minuto, id;
		Horario duracion;
		Pelicula pelicula;
		id = i + 1;
		std::cin.ignore();
		std::cout << "Ingrese el titulo: " << std::endl;
		std::getline(std::cin, titulo);
		std::cout << "Ingrese el director: " << std::endl;
		std::getline(std::cin, director);
		std::cout << "Ingrese la clasificacion de edad: " << std::endl;
		std::getline(std::cin, clasificacionEdad);
		std::cout << "Ingrese el genero: " << std::endl;
		std::getline(std::cin, genero);
		std::cout << "Ingrese las horas de duracion: " << std::endl;
		std::cin >> hora;
		std::cout << "Ingrese los minutos de duracion: " << std::endl;
		std::cin >> minuto;
		std::cout << std::endl;
		duracion = Horario(minuto, hora);
		pelicula = Pelicula(id, titulo, director, clasificacionEdad, genero, duracion);
		vecPelicula[i] =  pelicula;
	}
	
	
}

void Administrador::verPeliculasCargadas(const Pelicula* vecPelicula) {
	for (int i = 0; i < 5; i++) {
		vecPelicula[i].mostrarDetalles();
		std::cout << std::endl;
	}
}
void Administrador::cargarSalas(Sala* vecSalas) {
	for (int i = 0;i < 5;i++) {
		int numeroSala=i+1;
		int capacidadMaximaAsientos;
		std::cout<< "Numero de sala: "<< numeroSala << std::endl;
		std::cout << "Ingrese la capacidad maxima de asientos: " << std::endl;
		std::cin >> capacidadMaximaAsientos;
		Sala sala = Sala(numeroSala, capacidadMaximaAsientos);
		vecSalas[i] = sala;
	}
}
void Administrador::verSalasCargadas(const Sala* vecSalas) {
	for (int i = 0; i < 5; i++) {
		vecSalas[i].mostrarDetalles();
		std::cout << std::endl;
	}
}
Administrador::Administrador() : Persona() {
	
}

Administrador::Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}