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

Pelicula Administrador::seleccionarPelicula(Pelicula* vecPeliculas){

	int indicePeliculaElegida;
	Pelicula aux;
	// Pide al usuario que elija una película del vector
	std::cout << "Elija una película de la lista:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << ". ";
		vecPeliculas[i].mostrarDetalles(); // Muestra detalles de la película
	}
	std::cout << std::endl;
	std::cout << "Opcion: ";
	std::cin >> indicePeliculaElegida;

	// Asegúrate de que el índice elegido esté dentro de los límites
	if (indicePeliculaElegida >= 1 && indicePeliculaElegida <= 5) {
		// Asigna la película elegida al objeto f1
		aux = vecPeliculas[indicePeliculaElegida - 1];
	}
	else {
		std::cout << "Opción no válida" << std::endl;
	}
	return aux;
}

Sala Administrador::seleccionarSala(Sala* vecSalas) {
	int indiceSalaElegida;
	Sala aux;
	// Pide al usuario que elija una película del vector
	std::cout << "Elija una sala de la lista:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << ". ";
		vecSalas[i].mostrarDetalles(); 
	}
	std::cout << std::endl;
	std::cout << "Opcion: ";
	std::cin >> indiceSalaElegida;

	// valida de que el índice elegido esté dentro de los límites
	if (indiceSalaElegida >= 1 && indiceSalaElegida <= 5) {
		// Asigna la película elegida al objeto f1
		aux = vecSalas[indiceSalaElegida - 1];
	}
	else {
		std::cout << "Opción no válida" << std::endl;
	}
	return aux;
}

void Administrador::cargarFunciones(Funcion* vecFunciones,Pelicula* vecPeliculas, Sala* vecSalas) {
	for (int i = 0; i < 2; i++) {
		int idFuncion = i + 1;
		Pelicula pelicula;
		Sala sala;
		FechaHorario fechaHoraFuncion;
		int asientosDisponibles, dia , mes, anio, hora, minuto;
		int asientosReservados;
		Funcion funcion;
		pelicula = seleccionarPelicula(vecPeliculas);
		sala = seleccionarSala(vecSalas);
		std::cout << "Ingrese el día de la función: " << std::endl;
		std::cin >> dia;
		std::cout << "Ingrese el mes de la función: " << std::endl;
		std::cin >> mes;
		std::cout << "Ingrese el año de la función: " << std::endl;
		std::cin >> anio;
		std::cout << "Ingrese la hora de la función: " << std::endl;
		std::cin >> hora;
		std::cout << "Ingrese los minutos de la función: " << std::endl;
		std::cin >> minuto;
		fechaHoraFuncion = FechaHorario(dia, mes, anio, minuto, hora);
		std::cout << "Ingrese la cantidad de asientos disponibles: " << std::endl;
		std::cin >> asientosDisponibles;
		std::cout << "Ingrese la cantidad de asientos reservados: " << std::endl;
		std::cin >> asientosReservados;
		funcion = Funcion(pelicula, sala, fechaHoraFuncion, asientosDisponibles, asientosReservados);
		vecFunciones[i] = funcion;
	}
}

void Administrador::verFuncionesCargadas( Funcion* vecFunciones) {
	for (int i = 0; i < 2; i++) {
		vecFunciones[i].mostrarDetalles();
		std::cout << std::endl;
	}
}

Administrador::Administrador() : Persona() {

}

Administrador::Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}