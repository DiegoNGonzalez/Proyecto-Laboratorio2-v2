#include "Administrador.h"
#include <iostream>
void Administrador::cargarPeliculas() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	std::string titulo;
	std::string director;
	std::string clasificacionEdad;
	std::string genero;
	int duracion, id = archiPeliculas.validarId();
	Pelicula pelicula;
	std::cout << "Pelicula nro: " << id << std::endl;
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
	while (duracion <= 0) {
		std::cout << "Ingrese la duracion en minutos: ";
		std::cin >> duracion;
	}
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
		if (registro.getEstado()) {
			registro.mostrarDetalles();
			std::cout << std::endl;
		}
	}

}
bool Administrador::darDeBajaPelicula() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	Pelicula pelicula;
	int id;
	int posicionPelicula;
	verPeliculasCargadas();
	std::cout << "Ingrese el id de la pelicula a dar de baja: ";
	std::cin >> id;
	if (confirmarAccion()) {

		system("cls");
		posicionPelicula = archiPeliculas.buscarPosPeliculaxID(id);
		if (posicionPelicula >= 0) {
			pelicula = archiPeliculas.leerRegistro(posicionPelicula);
			pelicula.mostrarDetalles();
			pelicula.setEstado(false);
			if (archiPeliculas.grabarRegistro(pelicula, posicionPelicula)) {
				std::cout << "La pelicula: " << pelicula.getTitulo() << " fue dada de baja exitosamente." << std::endl;
				return true;
			}
			else {
				std::cout << "No se pudo dar de baja la pelicula." << std::endl;
				return false;
			}

		}
	}
}
void Administrador::cargarSalas() {
	ArchivoSalas archiSalas("sala.dat");
	Sala sala;
	int idSala = archiSalas.validarId();
	std::cout << "Sala nro: " << idSala << std::endl;
	float precioEntrada;
	std::cout << "Ingrese el precio de la entrada: ";
	std::cin >> precioEntrada;
	while (precioEntrada <= 0) {
		std::cout << "Ingrese el precio de la entrada: ";
		std::cin >> precioEntrada;
	}
	sala = Sala(idSala, precioEntrada);
	archiSalas.grabarRegistro(sala);


}
void Administrador::verSalasCargadas() {
	ArchivoSalas archiSalas("sala.dat");
	Sala registro;
	int cantidadRegistros = archiSalas.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiSalas.leerRegistro(i);
		if (registro.getEstado()) {
			registro.mostrarDetalles();
			std::cout << std::endl;
		}
	}
}

bool Administrador::modificarSalaEnRegistro(int nroSala) {
	ArchivoSalas archivoSalas("sala.dat");
	Sala sala;
	int posicionSala = archivoSalas.buscarPosSalaxID(nroSala);
	sala = archivoSalas.leerRegistro(posicionSala);
	sala.mostrarDetalles();
	std::cout << std::endl;
	float precioNuevo;
	std::cout << "Nuevo valor de Entrada: ";
	std::cin >> precioNuevo;
	while (precioNuevo <= 0) {
		std::cout << "Monto incorrecto, reingrese el nuevo valor de Entrada: ";
		std::cin >> precioNuevo;
	}
	if (confirmarAccion()) {

		sala.setPrecioAsiento(precioNuevo);
		if (archivoSalas.grabarRegistro(sala, posicionSala)) {
			std::cout << "El precio de la Entrada a la sala #" << sala.getIdSala() << " fue modificado exitosamente." << std::endl;
			return true;
		}
		else {
			std::cout << "No se pudo modificar el precio de la sala" << std::endl;
			return false;
		}
	}

}
bool Administrador::darDeBajaSala() {
	ArchivoSalas archiSalas("sala.dat");
	Sala sala;
	int id;
	int posicionSala;
	std::cout << "Ingrese el id de la sala a dar de baja: ";
	std::cin >> id;
	if (confirmarAccion()) {

		system("cls");
		posicionSala = archiSalas.buscarPosSalaxID(id);
		if (posicionSala >= 0) {
			sala = archiSalas.leerRegistro(posicionSala);
			sala.mostrarDetalles();
			sala.setEstado(false);
			if (archiSalas.grabarRegistro(sala, posicionSala)) {
				std::cout << "La sala #" << sala.getIdSala() << " fue dada de baja exitosamente." << std::endl;
				return true;
			}
			else {
				std::cout << "No se pudo dar de baja la sala." << std::endl;
				return false;
			}

		}
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
		if (registro.getEstado()) {
			registro.mostrarDetalles();
			std::cout << std::endl;
		}
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
Pelicula Administrador::buscarPeliculaxID(int valorBuscado) {
	ArchivoPeliculas archivoPeliculas("pelicula.dat");
	Pelicula pelicula;
	int pos = archivoPeliculas.buscarPosPeliculaxID(valorBuscado);
	if (pos >= 0) {
		pelicula = archivoPeliculas.leerRegistro(pos);
		return pelicula;
	}
	else {
		return pelicula;
	}

}

bool Administrador::modificarFuncionEnRegistro(int idFuncion) {
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoPeliculas archivoPeliculas("pelicula.dat");
	ArchivoSalas archivoSalas("sala.dat");
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	bool pudoEscribir = false;
	Funcion funcion;
	Pelicula pelicula;
	Sala sala;
	FechaHorario fechaHorario;
	DiagramaSala diagrama;
	int opcion;
	int posicionFuncion = archivoFunciones.buscarPosFuncionxID(idFuncion);
	if (posicionFuncion >= 0) {
		funcion = archivoFunciones.leerRegistro(posicionFuncion);
		do {
			funcion.mostrarDetalles();
			rlutil::locate(50, 10);
			std::cout << "Que desea modificar?" << std::endl;
			rlutil::locate(50, 11);
			std::cout << "1. Pelicula" << std::endl;
			rlutil::locate(50, 12);
			std::cout << "2. Sala" << std::endl;
			rlutil::locate(50, 13);
			std::cout << "3. Fecha Y Hora" << std::endl;
			rlutil::locate(50, 14);
			std::cout << "4. Volver" << std::endl;
			rlutil::locate(50, 15);
			std::cout << "Ingrese una opcion: ";
			std::cin >> opcion;
			switch (opcion) {
			case 1: {
				system("cls");
				int posicionPelicula, idPelicula;
				verPeliculasCargadas();
				std::cout << "Ingrese el id de la pelicula seleccionada: ";
				std::cin >> idPelicula;
				if (confirmarAccion()) {
					posicionPelicula = archivoPeliculas.buscarPosPeliculaxID(idPelicula);
					pelicula = archivoPeliculas.leerRegistro(posicionPelicula);
					funcion.setPelicula(pelicula);
					archivoFunciones.grabarRegistro(funcion, posicionFuncion);
					rlutil::locate(50, 17);
					system("cls");
					std::cout << "Pelicula " << pelicula.getTitulo() << " asignada con exito" << std::endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				int posicionSala, idSala;
				verSalasCargadas();
				std::cout << "Ingrese el id de la sala seleccionada: ";
				std::cin >> idSala;
				if (confirmarAccion()) {
					posicionSala = archivoSalas.buscarPosSalaxID(idSala);
					sala = archivoSalas.leerRegistro(posicionSala);
					funcion.setSala(sala);
					archivoFunciones.grabarRegistro(funcion, posicionFuncion);
					rlutil::locate(50, 17);
					system("cls");
					std::cout << "Sala " << sala.getIdSala() << " asignada con exito" << std::endl;

				}
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				int dia, mes, anio, hora, minuto;
				std::cout << "Ingrese el dia de la funcion: ";
				std::cin >> dia;
				while (dia <= 0 || dia > 31)
				{
					std::cout << "Dia no valido, reingrese el dia de la funcion: ";
					std::cin >> dia;
				}
				std::cout << "Ingrese el mes de la funcion: ";
				std::cin >> mes;
				while (mes <= 0 || mes > 12)
				{
					std::cout << "Mes no valido, reingrese el mes de la funcion: ";
					std::cin >> mes;
				}
				std::cout << "Ingrese el anio de la funcion: ";
				std::cin >> anio;
				while (anio < 2023)
				{
					std::cout << "Anio no valido, reingrese el anio de la funcion: ";
					std::cin >> anio;
				}
				std::cout << "Ingrese la hora de la funcion: ";
				std::cin >> hora;
				while (hora < 0 || hora > 23)
				{
					std::cout << "Hora no valida, reingrese la hora de la funcion: ";
					std::cin >> hora;
				}
				std::cout << "Ingrese los minutos de la funcion: ";
				std::cin >> minuto;
				while (minuto < 0 || minuto > 59)
				{
					std::cout << "Minutos no validos, reingrese los minutos de la funcion: ";
					std::cin >> minuto;
				}
				if (confirmarAccion()) {

					fechaHorario = FechaHorario(dia, mes, anio, minuto, hora);
					funcion.setFechaHoraFuncion(fechaHorario);
					archivoFunciones.grabarRegistro(funcion, posicionFuncion);
					rlutil::locate(50, 17);
					system("cls");
					std::cout << "Fecha y hora modificada con exito" << std::endl;
				}
				system("pause");
				system("cls");
				break;

			}


			}
		} while (opcion != 4);
		pudoEscribir = true;
	}
	return pudoEscribir;
}

bool Administrador::verificarEstadoPeliculas(int idPelicula)
{
	ArchivoPeliculas archivoPeliculas("pelicula.dat");
	Pelicula pelicula;
	int posicionPelicula = archivoPeliculas.buscarPosPeliculaxID(idPelicula);
	if (posicionPelicula >= 0) {
		pelicula = archivoPeliculas.leerRegistro(posicionPelicula);
		if (pelicula.getEstado()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

bool Administrador::verificarEstadoSalas(int idSala)
{
	ArchivoSalas archivoSalas("sala.dat");
	Sala sala;
	int posicionSala = archivoSalas.buscarPosSalaxID(idSala);
	if (posicionSala >= 0) {
		sala = archivoSalas.leerRegistro(posicionSala);
		if (sala.getEstado()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

void Administrador::darDeBajaFuncionxSalaOxPelicula()
{
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	ArchivoSalas archivoSalas("sala.dat");
	ArchivoPeliculas archivoPeliculas("pelicula.dat");
	Funcion funcion;
	DiagramaSala diagrama;
	Sala sala;
	Pelicula pelicula;
	int idSala, idPelicula;
	int posicionFuncion, posicionDiagrama, posicionPelicula, posicionSala;
	int cantidaRegistrosFunciones = archivoFunciones.contarRegistros();
	int cantidadRegistrosDiagrama = archivoDiagrama.contarRegistros();

	for (int i = 0; i < cantidaRegistrosFunciones; i++) {
		funcion = archivoFunciones.leerRegistro(i);
		for (int j = 0;j < cantidadRegistrosDiagrama;j++) {
			diagrama = archivoDiagrama.leerRegistro(j);
			idPelicula = funcion.getPelicula().getId();
			idSala = funcion.getSala().getIdSala();
			posicionSala = archivoSalas.buscarPosSalaxID(idSala);
			posicionPelicula = archivoPeliculas.buscarPosPeliculaxID(idPelicula);
			sala = archivoSalas.leerRegistro(posicionSala);
			pelicula = archivoPeliculas.leerRegistro(posicionPelicula);
			if (sala.getEstado() == false || pelicula.getEstado() == false) {
				funcion.setEstado(false);
				diagrama.setEstado(false);
				archivoFunciones.grabarRegistro(funcion, i);
				archivoDiagrama.grabarRegistro(diagrama, j);
			}

		}
	}

}

bool Administrador::darDeBajaFuncion(int idFuncion)
{
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	Funcion funcion;
	DiagramaSala diagrama;
	int posicionFuncion, posicionDiagrama;
	posicionFuncion = archivoFunciones.buscarPosFuncionxID(idFuncion);
	posicionDiagrama = archivoDiagrama.buscarPosDiagramaxID(idFuncion);

	if (confirmarAccion()) {

		if (posicionFuncion >= 0 && posicionDiagrama >= 0) {
			funcion = archivoFunciones.leerRegistro(posicionFuncion);
			diagrama = archivoDiagrama.leerRegistro(posicionDiagrama);
			funcion.setEstado(false);
			diagrama.setEstado(false);
			if (archivoFunciones.grabarRegistro(funcion, posicionFuncion) && archivoDiagrama.grabarRegistro(diagrama, posicionDiagrama)) {
				std::cout << "La funcion #" << funcion.getIdFuncion() << " fue dada de baja exitosamente." << std::endl;
				return true;
			}
			else {
				std::cout << "No se pudo dar de baja la funcion." << std::endl;
				return false;
			}

		}
	}


}

Sala Administrador::seleccionarSala() {
	ArchivoSalas archiSalas("sala.dat");
	Sala registro;
	int numeroSala;
	int contador;
	int cantidadRegistros = archiSalas.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiSalas.leerRegistro(i);
		if (registro.getEstado()) {
			registro.mostrarDetalles();
			std::cout << std::endl;

		}
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

Sala Administrador::buscarSalaxID(int valorBuscado) {
	ArchivoSalas archivoSalas("sala.dat");
	Sala sala;
	int pos = archivoSalas.buscarPosSalaxID(valorBuscado);
	if (pos >= 0) {
		sala = archivoSalas.leerRegistro(pos);
		return sala;
	}
	else {
		return sala;
	}

}
void Administrador::cargarFunciones() {
	ArchivoFunciones archiFunciones("funcion.dat");
	ArchivoDiagrama archiDiagrama("diagrama.dat");
	Funcion funcion;
	int idFuncion = archiFunciones.validarId();
	const int filas = 10;
	const int columnas = 10;
	Pelicula pelicula;
	Sala sala;
	FechaHorario fechaHoraFuncion;
	DiagramaSala diagramaSala;
	int  dia, mes, anio, hora, minuto;
	pelicula = seleccionarPelicula();
	sala = seleccionarSala();
	std::cout << "Funcion nro: " << idFuncion << std::endl;
	std::cout << "Ingrese el dia de la funcion: ";
	std::cin >> dia;
	while (dia <= 0 || dia > 31)
	{
		std::cout << "Dia no valido, reingrese el dia de la funcion: ";
		std::cin >> dia;
	}
	std::cout << "Ingrese el mes de la funcion: ";
	std::cin >> mes;
	while (mes <= 0 || mes > 12)
	{
		std::cout << "Mes no valido, reingrese el mes de la funcion: ";
		std::cin >> mes;
	}
	std::cout << "Ingrese el anio de la funcion: ";
	std::cin >> anio;
	while (anio < 2023)
	{
		std::cout << "Anio no valido, reingrese el anio de la funcion: ";
		std::cin >> anio;
	}
	std::cout << "Ingrese la hora de la funcion: ";
	std::cin >> hora;
	while (hora < 0 || hora > 23)
	{
		std::cout << "Hora no valida, reingrese la hora de la funcion: ";
		std::cin >> hora;
	}
	std::cout << "Ingrese los minutos de la funcion: ";
	std::cin >> minuto;
	while (minuto < 0 || minuto > 59)
	{
		std::cout << "Minutos no validos, reingrese los minutos de la funcion: ";
		std::cin >> minuto;
	}
	diagramaSala = DiagramaSala(idFuncion);
	archiDiagrama.grabarRegistro(diagramaSala);
	fechaHoraFuncion = FechaHorario(dia, mes, anio, minuto, hora);
	funcion = Funcion(pelicula, sala, fechaHoraFuncion, idFuncion);
	archiFunciones.grabarRegistro(funcion);
}

void Administrador::verFuncionesCargadas() {
	darDeBajaFuncionxSalaOxPelicula();
	ArchivoFunciones archiFunciones("funcion.dat");
	Funcion registro;
	int cantidadRegistros = archiFunciones.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiFunciones.leerRegistro(i);
		if (registro.getEstado()) {

			registro.mostrarDetalles();
			std::cout << std::endl;
		}

	}

}

Administrador::Administrador() : Persona() {

}

Administrador::Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}
void showItem1(const char* text, int posx, int posy, bool selected) {

	if (selected) {
		rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
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
	ArchivoPeliculas archiPeliculas("pelicula.dat");

	do {
		rlutil::setConsoleTitle("MENU PELICULAS"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem1(" Cargar peliculas ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem1(" Ver peliculas cargadas ", 50, 11, y == 1);
		showItem1(" Buscar pelicula x ID", 50, 12, y == 2);
		showItem1(" Eliminar Pelicula ", 50, 13, y == 3);
		showItem1(" Volver ", 50, 14, y == 4);

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
			if (y > 4) y = 4;
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

			case 2: {
				system("cls");
				int id, pos;
				std::cout << "Ingrese el id de la pelicula a buscar: ";
				std::cin >> id;
				pos = archiPeliculas.buscarPosPeliculaxID(id);
				if (pos >= 0) {
					archiPeliculas.leerRegistro(pos).mostrarDetalles();
				}
				else {
					std::cout << "No se encontro el id." << std::endl;
				}

				system("pause");
				system("cls");
				break;
			}
			case 3:
				system("cls");
				darDeBajaPelicula();
				system("pause");
				system("cls");
				break;
			case 4: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);
}

void Administrador::menuSalas() {
	int op = 1, y = 0;

	do {
		rlutil::setConsoleTitle("MENU SALAS"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem1(" Cargar salas ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem1(" Ver salas cargadas ", 50, 11, y == 1);
		showItem1(" Modificar Precio Sala ", 50, 12, y == 2);
		showItem1(" Eliminar Sala ", 50, 13, y == 3);
		showItem1(" Volver ", 50, 14, y == 4);

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
			if (y > 4)y = 4;
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				cargarSalas();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				verSalasCargadas();
				system("pause");
				system("cls");
				break;
			case 2: {
				system("cls");
				int nroSala;
				verSalasCargadas();
				std::cout << "Ingrese el Nro de sala a modificar el precio: ";
				std::cin >> nroSala;
				system("cls");
				modificarSalaEnRegistro(nroSala);
				system("pause");
				system("cls");
				break;
			}
			case 3:
				system("cls");
				verSalasCargadas();
				darDeBajaSala();
				system("pause");
				system("cls");
				break;
			case 4: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);
}

void Administrador::menuFunciones() {
	ArchivoFunciones archiFunciones("funcion.dat");
	int op = 1, y = 0;

	do {
		rlutil::setConsoleTitle("MENU FUNCIONES"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem1(" Cargar funciones ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem1(" Ver funciones cargadas ", 50, 11, y == 1);
		showItem1(" Buscar funcion x ID ", 50, 12, y == 2);
		showItem1(" Modificar funcion ", 50, 13, y == 3);
		showItem1(" Eliminar funcion ", 50, 14, y == 4);
		showItem1(" Volver ", 50, 15, y == 5);

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
			if (y > 5) y = 5;
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				cargarFunciones();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				verFuncionesCargadas();
				system("pause");
				system("cls");
				break;
			case 2: {
				system("cls");
				int id;
				std::cout << "Ingrese el id de la funcion a buscar: ";
				std::cin >> id;
				archiFunciones.buscarFuncionxID(id).mostrarDetalles();
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				int id;
				std::cout << "Ingrese el id de la funcion a modificar: ";
				std::cin >> id;
				modificarFuncionEnRegistro(id);
				system("cls");
				Sleep(1000);
				break;
			}
			case 4: {
				system("cls");
				verFuncionesCargadas();
				int idFuncion;
				std::cout << "Ingrese el id de la funcion a eliminar: ";
				std::cin >> idFuncion;
				darDeBajaFuncion(idFuncion);
				system("pause");
				system("cls");
				break;
			}
			case 5: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);



}

void Administrador::menuBackUp() {
	int op = 1, y = 0;
	ArchivoDiagrama archiDiagrama("diagrama.dat");
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	ArchivoSalas archiSalas("sala.dat");
	ArchivoFunciones archiFunciones("funcion.dat");
	do {
		rlutil::setConsoleTitle("MENU BACKUP"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem1(" Generar BackUp peliculas ", 50, 10, y == 0);
		showItem1(" Cargar BackUp peliculas ", 50, 11, y == 1);
		showItem1(" Generar BackUp salas ", 50, 12, y == 2);
		showItem1(" Cargar BackUp salas ", 50, 13, y == 3);
		showItem1(" Generar BackUp funciones ", 50, 14, y == 4);
		showItem1(" Cargar BackUp funciones ", 50, 15, y == 5);
		showItem1(" Generar BackUp Diagrama Sala ", 50, 16, y == 6);
		showItem1(" Cargar BackUp Diagrama Sala ", 50, 17, y == 7);
		showItem1(" Volver ", 50, 18, y == 8);

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
			if (y > 8) y = 8;
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				archiPeliculas.generarBackUp();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				archiPeliculas.restaurarBackUp();
				system("cls");
				break;
			case 2:
				system("cls");
				archiSalas.generarBackUp();
				system("cls");
				break;
			case 3:
				system("cls");
				archiSalas.restaurarBackUp();
				system("cls");
				break;
			case 4:
				system("cls");
				archiFunciones.generarBackUp();
				system("cls");
				break;
			case 5:
				system("cls");
				archiFunciones.restaurarBackUp();
				system("cls");
				break;
			case 6:
				system("cls");
				archiDiagrama.generarBackUp();
				system("cls");
				break;
			case 7:
				system("cls");
				archiDiagrama.restaurarBackUp();
				system("cls");
				break;
			case 8: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}

		}
	} while (op != 0);
}

bool Administrador::confirmarAccion()
{
	char siONo;
	std::cout << "Esta seguro que desea modificar o eliminar? (s/n): ";
	std::cin >> siONo;
	while (siONo != 's' && siONo != 'S' && siONo != 'n' && siONo != 'N') {
		std::cout << "Opcion no valida, reingrese (s/n): ";
		std::cin >> siONo;
	}
	if (siONo == 's' || siONo == 'S') {
		return true;
	}
	else {
		std::cout << "Accion cancelada." << std::endl;
		return false;
	}
}
