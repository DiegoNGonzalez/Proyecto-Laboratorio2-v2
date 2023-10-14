#include "Administrador.h"
#include <iostream>
void Administrador::
cargarPeliculas() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	std::string titulo;
	std::string director;
	std::string clasificacionEdad;
	std::string genero;
	int duracion, id;
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
	std::cout << "Ingrese la duracion en minutos: ";
	std::cin >> duracion;
	std::cout << "Ingrese el id: ";
	std::cin >> id;
	std::cout << std::endl;
	pelicula = Pelicula(id, titulo, director, clasificacionEdad, genero, duracion);

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
	int idSala;
	Sala sala;
	float precioEntrada;
	std::cout << "Ingrese el numero de sala: ";
	std::cin >> idSala;
	std::cout << "Ingrese el precio de la entrada: ";
	std::cin >> precioEntrada;
	sala = Sala(idSala, precioEntrada);
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
			if (registro.getIdSala() == numeroSala) {

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
	ArchivoDiagrama archiDiagrama("diagrama.dat");
	Funcion funcion;
	int idFuncion;
	const int filas = 10;
	const int columnas = 10;
	Pelicula pelicula;
	Sala sala;
	FechaHorario fechaHoraFuncion;
	DiagramaSala diagramaSala;
	int  dia, mes, anio, hora, minuto;
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
	diagramaSala = DiagramaSala(idFuncion);
	archiDiagrama.grabarRegistro(diagramaSala);
	fechaHoraFuncion = FechaHorario(dia, mes, anio, minuto, hora);
	funcion = Funcion(pelicula, sala, fechaHoraFuncion,idFuncion );
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
void showItem1(const char* text, int posx, int posy, bool selected) {

	if (selected) {
		rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
		rlutil::locate(posx - 3, posy); // posiciona el cursor en la fila y columna que le pasamos por parametro (en este caso, -2 porque colocamos una flechita en la opcion seleccionada)
		std::cout << (char)175 << "  " << text << "  " << (char)174 << std::endl; // imprime una flechita a cada lado con el codigo ASCII, y el texto que le pasamos por parametro
	}
	else {
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		rlutil::locate(posx - 3, posy);
		std::cout << "   " << text << "   " << std::endl; // si no esta seleccionado, imprime el texto sin las flechitas
	}
	rlutil::setBackgroundColor(rlutil::COLOR::BLACK); // cuando llega a la ultima opcion, cambia el color del cursor al color normal
}
void Administrador::menuPeliculas() {
	int op = 1, y = 0;

	do {
		rlutil::setConsoleTitle("MENU PELICULAS"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem1(" Cargar peliculas ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem1(" Ver peliculas cargadas ", 50, 11, y == 1);
		showItem1(" Volver ", 50, 12, y == 2);

		int key = rlutil::getkey(); // Lee una pulsación de tecla y devuelve un código ASCII de tecla.



		switch (key) // evalua el codigo de tecla
		{
		case 14: // flecha ARRIBA
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl; // imprime un espacio para borrar la flecha cuando cambie de posicion
			y--;
			if (y < 0) y = 0; // validacion para que no se salga de las opciones
			break;
		case 15: // flecha ABAJO
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 2) y = 2;
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				cargarPeliculas();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				verPeliculasCargadas();
				system("pause");
				system("cls");
				break;
			case 2: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);
}
