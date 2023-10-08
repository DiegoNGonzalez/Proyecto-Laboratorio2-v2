#include "Administrador.h"
#include <iostream>
void Administrador::
cargarPeliculas() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	std::string titulo;
	std::string director;
	std::string clasificacionEdad;
	std::string genero;
	int hora, minuto, id;
	Pelicula pelicula;
	std::cin.ignore();
	std::cout << "Ingrese el titulo: ";
	std::getline(std::cin, titulo);
	std::cout << "Ingrese el director: ";
	std::getline(std::cin, director);
	std::cout << "Ingrese la clasificacion de edad: ";
	std::getline(std::cin, clasificacionEdad);
	std::cout << "Ingrese el genero: ";
	std::getline(std::cin, genero);
	std::cout << "Ingrese las horas de duracion: ";
	std::cin >> hora;
	std::cout << "Ingrese los minutos de duracion: ";
	std::cin >> minuto;
	std::cout << "Ingrese el id: ";
	std::cin >> id;
	std::cout << std::endl;
	pelicula = Pelicula(id, titulo, director, clasificacionEdad, genero, hora, minuto);

	archiPeliculas.grabarRegistro(pelicula);

}

void Administrador::verPeliculasCargadas() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	Pelicula registro;
	int cantidadRegistros = archiPeliculas.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiPeliculas.leerRegistro(i);
		std::cout << "////////  PELICULA  #" << i + 1 << "  ////////" << std::endl;
		registro.mostrarDetalles();
		std::cout << std::endl;
	}

}
void Administrador::cargarSalas() {
	ArchivoSalas archiSalas("sala.dat");
	int numeroSala;
	Sala sala;
	std::cout << "Ingrese el numero de sala: ";
	std::cin >> numeroSala;
	sala = Sala(numeroSala);
	archiSalas.grabarRegistro(sala);


}
void Administrador::verSalasCargadas() {
	ArchivoSalas archiSalas("sala.dat");
	Sala registro;
	int cantidadRegistros = archiSalas.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiSalas.leerRegistro(i);
		std::cout << "////////  SALA  #" << i + 1 << "  ////////" << std::endl;
		registro.mostrarDetalles();
		std::cout << std::endl;
	}
}

Pelicula Administrador::seleccionarPelicula() {

	ArchivoPeliculas archiPeliculas("pelicula.dat");
	Pelicula registro;

	int id;
	int cantidadRegistros = archiPeliculas.contarRegistros();
	int contador;
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiPeliculas.leerRegistro(i);
		std::cout << "////////  PELICULA  #" << i + 1 << "  ////////" << std::endl;
		registro.mostrarDetalles();
		std::cout << std::endl;
	}
	do {
		contador = 0;
		std::cout << "Ingrese el id de la pelicula seleccionada: ";
		std::cin >> id;
		for (int i = 0; i < cantidadRegistros; i++) {
			registro = archiPeliculas.leerRegistro(i);
			if (registro.getId() == id) {

				return registro;
			}
			else {
				contador++;
			}
		}
		if (contador == cantidadRegistros) {
			std::cout << "No se encontro la pelicula" << std::endl;
		}
	} while (contador == cantidadRegistros);

}

Sala Administrador::seleccionarSala() {
	ArchivoSalas archiSalas("sala.dat");
	Sala registro;
	int numeroSala;
	int contador;
	int cantidadRegistros = archiSalas.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiSalas.leerRegistro(i);
		std::cout << "////////  SALA  #" << i + 1 << "  ////////" << std::endl;
		registro.mostrarDetalles();
		std::cout << std::endl;
	}
	do {
		contador = 0;
		std::cout << "Ingrese el numero de la sala seleccionada: ";
		std::cin >> numeroSala;
		for (int i = 0; i < cantidadRegistros; i++) {
			registro = archiSalas.leerRegistro(i);
			if (registro.getNumeroSala() == numeroSala) {

				return registro;
			}
			else {
				contador++;
			}

		}
		if (contador == cantidadRegistros) {
			std::cout << "No se encontro la sala" << std::endl;
		}
	} while (contador == cantidadRegistros);

}

void Administrador::cargarFunciones() {
	ArchivoFunciones archiFunciones("funcion.dat");
	Funcion funcion;
	int idFuncion;
	const int filas = 10;
	const int columnas = 10;
	Pelicula pelicula;
	Sala sala;
	FechaHorario fechaHoraFuncion;
	DiagramaSala diagramaSala;
	int  dia, mes, anio, hora, minuto;
	float valorEntrada;
	pelicula = seleccionarPelicula();
	sala = seleccionarSala();
	std::cout << "Ingrese el id de la funcion: ";
	std::cin >> idFuncion;
	std::cout << "Ingrese el dia de la funcion: ";
	std::cin >> dia;
	std::cout << "Ingrese el mes de la funcion: ";
	std::cin >> mes;
	std::cout << "Ingrese el anio de la funcion: ";
	std::cin >> anio;
	std::cout << "Ingrese la hora de la funcion: ";
	std::cin >> hora;
	std::cout << "Ingrese los minutos de la funcion: ";
	std::cin >> minuto;
	std::cout << "Ingrese el valor de la entrada: ";
	std::cin >> valorEntrada;
	diagramaSala = DiagramaSala(idFuncion);
	fechaHoraFuncion = FechaHorario(dia, mes, anio, minuto, hora);
	funcion = Funcion(pelicula, sala, fechaHoraFuncion, valorEntrada, diagramaSala);
	archiFunciones.grabarRegistro(funcion);
}

void Administrador::verFuncionesCargadas() {
	ArchivoFunciones archiFunciones("funcion.dat");
	Funcion registro;
	int cantidadRegistros = archiFunciones.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiFunciones.leerRegistro(i);
		std::cout << "////////  FUNCION  #" << i + 1 << "  ////////" << std::endl;
		registro.mostrarDetalles();
		std::cout << std::endl;
	}

}

Administrador::Administrador() : Persona() {

}

Administrador::Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}