#include "Administrador.h"
#include <iostream>
void Administrador::
cargarPeliculas(Pelicula* vecPelicula) {
	FILE* p;
	p = fopen("pelicula.dat", "ab");
	if (p == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE PELICULAS" << std::endl;
	}
	for (int i = 0; i < 5; i++) {
		std::string titulo;
		std::string director;
		std::string clasificacionEdad;
		std::string genero;
		int hora, minuto, id;
		Pelicula pelicula;
		id = i + 1;
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
		std::cout << std::endl;
		pelicula = Pelicula(id, titulo, director, clasificacionEdad, genero, hora, minuto);
		vecPelicula[i] =  pelicula;
		fwrite(&vecPelicula[i], sizeof(Pelicula), 1, p);
	}
	fclose(p);
}

void Administrador::verPeliculasCargadas(Pelicula* vecPeliculas) {
	FILE* p;
	p = fopen("pelicula.dat", "rb");
	if (p == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE PELICULAS" << std::endl;
	}
	for (int i = 0; i < 5; i++) {
		if (fread(&vecPeliculas[i], sizeof(Pelicula), 1, p) == 1) {
			std::cout << "////////  PELICULA  #" << i + 1 << "  ////////" << std::endl;
			vecPeliculas[i].mostrarDetalles();
			std::cout << std::endl;
		}
	}
	fclose(p);
}
/*
	for (int i = 0; i < 5; i++) {
		vecPelicula[i].mostrarDetalles();
		std::cout << std::endl;
	}
}
*/
void Administrador::cargarSalas(Sala* vecSalas) {
	FILE* s;
	s = fopen("sala.dat", "ab");
	if (s == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE SALAS" << std::endl;
	}
	for (int i = 0;i < 5;i++) {
		//int numeroSala=i+1;
		int capacidadMaximaAsientos;
		//std::cout<< "Numero de sala: "<< numeroSala << std::endl;
		std::cout << "////////  SALA  #" << i + 1 << "  ////////" << std::endl;
		std::cout << "Ingrese la capacidad maxima de asientos: ";
		std::cin >> capacidadMaximaAsientos;
		Sala sala = Sala(i+1, capacidadMaximaAsientos);
		vecSalas[i] = sala;
		fwrite(&vecSalas[i], sizeof(Sala), 1, s);
	}
	fclose(s);
}
void Administrador::verSalasCargadas(Sala* vecSalas) {
	FILE* s;
	s = fopen("sala.dat", "rb");
	if (s == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE SALAS" << std::endl;
	}
	for (int i = 0; i < 5;i++) {
		if (fread(&vecSalas[i], sizeof(Sala), 1, s) == 1) {
			vecSalas[i].mostrarDetalles();
			std::cout << std::endl;
		}
	}
	fclose(s);
}

	/*
	for (int i = 0; i < 5; i++) {
		vecSalas[i].mostrarDetalles();
		std::cout << std::endl;
	}
	*/

Pelicula Administrador::seleccionarPelicula(Pelicula* vecPeliculas){

	int indicePeliculaElegida;
	Pelicula aux;
	FILE* p;
	p = fopen("pelicula.dat", "rb");
	if (p == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE PELICULAS" << std::endl;
	}
	// Pide al usuario que elija una película del vector
	std::cout << "Elija una pelicula de la lista:" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		if (fread(&vecPeliculas[i], sizeof(Pelicula), 1, p) == 1) {
			std::cout << "////////  PELICULA  #" << i + 1 << "  ////////" << std::endl;
			vecPeliculas[i].mostrarDetalles();
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Opcion: ";
	std::cin >> indicePeliculaElegida;
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	// Asegúrate de que el índice elegido esté dentro de los límites
	if (indicePeliculaElegida >= 1 && indicePeliculaElegida <= 5) {
		// Asigna la película elegida al objeto f1
		aux = vecPeliculas[indicePeliculaElegida - 1];
	}
	else {
		std::cout << "Opción no válida" << std::endl;
	}
	return aux;
	fclose(p);
}

Sala Administrador::seleccionarSala(Sala* vecSalas) {
	int indiceSalaElegida;
	Sala aux;
	FILE* s;
	s = fopen("sala.dat", "rb");
	if (s == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE SALAS" << std::endl;
	}
	// Pide al usuario que elija una película del vector
	std::cout << "Elija una sala de la lista:" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		if (fread(&vecSalas[i], sizeof(Sala), 1, s) == 1) {
			vecSalas[i].mostrarDetalles();
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Opcion: ";
	std::cin >> indiceSalaElegida;
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	// valida de que el índice elegido esté dentro de los límites
	if (indiceSalaElegida >= 1 && indiceSalaElegida <= 5) {
		// Asigna la película elegida al objeto f1
		aux = vecSalas[indiceSalaElegida - 1];
	}
	else {
		std::cout << "Opción no válida" << std::endl;
	}
	return aux;
	fclose(s);
}

void Administrador::cargarFunciones(Funcion* vecFunciones,Pelicula* vecPeliculas, Sala* vecSalas) {
	FILE* f;
	f = fopen("funcion.dat", "ab");
	if (f == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE LAS FUNCIONES" << std::endl;
	}
	for (int i = 0; i < 2; i++) {
		int idFuncion = i + 1;
		const int filas = 10;
		const int columnas = 10;
		Pelicula pelicula;
		Sala sala;
		FechaHorario fechaHoraFuncion;
		int  dia , mes, anio, hora, minuto;
		float valorEntrada;
		Funcion funcion;
		pelicula = seleccionarPelicula(vecPeliculas);
		sala = seleccionarSala(vecSalas);
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
		fechaHoraFuncion = FechaHorario(dia, mes, anio, minuto, hora);
		funcion = Funcion(pelicula, sala, fechaHoraFuncion, valorEntrada);
		vecFunciones[i] = funcion;
		fwrite(&vecFunciones[i], sizeof(Funcion), 1, f);
	}
	fclose(f);
}

void Administrador::verFuncionesCargadas( Funcion* vecFunciones) {
	FILE* f;
	f = fopen("funcion.dat", "rb");
	if (f == NULL) {
		std::cout << "ERROR AL QUERER ABRIR EL ARCHIVO DE LAS FUNCIONES" << std::endl;
	}
	for (int i = 0; i < 2; i++) {
		if (fread(&vecFunciones[i], sizeof(Funcion), 1, f) == 1) {
			std::cout << "////////  FUNCION  #" << i + 1 << "  ////////" << std::endl;
			vecFunciones[i].mostrarDetalles();
			std::cout << std::endl;
		}
	}
	fclose(f);

	/*
	for (int i = 0; i < 2; i++) {
		vecFunciones[i].mostrarDetalles();
		std::cout << std::endl;
	}
	*/
}

Administrador::Administrador() : Persona() {

}

Administrador::Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}

