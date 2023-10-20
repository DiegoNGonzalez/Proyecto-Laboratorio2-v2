#include "Administrador.h"
//#include <Windows.h>
//#include "rlutil.h"
//#include "Persona.h"
//#include "Funcion.h"
//#include "Pelicula.h"
//#include "Sala.h"
//#include "ArchivoFunciones.h"
//#include "ArchivoPeliculas.h"
//#include "ArchivoSalas.h"
//#include "ArchivoDiagrama.h"
//#include "DiagramaSala.h"
#include <iostream>
void Administrador::cargarPeliculas() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	std::string titulo;
	std::string director;
	std::string clasificacionEdad;
	std::string genero;
	int duracion, id = archiPeliculas.validarId();
	Pelicula pelicula;
	std::cout << "PELICULA NRO:" << id << std::endl;
	std::cout << "POR FAVOR INGRESE LOS SIGUIENTES CAMPOS OBLIGATORIOS:" << std::endl;
	std::cin.ignore();
	std::cout << "TITULO: ";
	std::getline(std::cin, titulo);
	std::cout << "DIRECTOR: ";
	std::getline(std::cin, director);
	std::cout << "CLASIFICACION DE EDAD: ";
	std::getline(std::cin, clasificacionEdad);
	std::cout << "GENERO: ";
	std::getline(std::cin, genero);
	std::cout << "DURACION: ";
	std::cin >> duracion;
	while (duracion <= 0) {
		std::cout << "DURACION: ";
		std::cin >> duracion;
	}
	std::cout << std::endl;
	pelicula = Pelicula(id, titulo, director, clasificacionEdad, genero, duracion);

	archiPeliculas.grabarRegistro(pelicula);

}
void Administrador::verPeliculasCargadas() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	Pelicula registro;
	int contador = 0;
	int cantidadRegistros = archiPeliculas.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiPeliculas.leerRegistro(i);
		if (registro.getEstado()) {
			registro.mostrarDetalles();
			std::cout << std::endl;
			contador++;
		}
	}
	if (contador == 0) {
		system("cls");
		std::cout << "NO HAY PELICULAS EN CARTELERA." << std::endl;
	}

}
bool Administrador::darDeBajaPelicula() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	Pelicula pelicula;
	int id;
	int posicionPelicula;
	verPeliculasCargadas();
	std::cout << "NRO DE PELICULA PARA ELIMINAR DE LA CARTELERA: ";
	std::cin >> id;
	if (confirmarAccion()) {

		system("cls");
		posicionPelicula = archiPeliculas.buscarPosPeliculaxID(id);
		if (posicionPelicula >= 0) {
			pelicula = archiPeliculas.leerRegistro(posicionPelicula);
			pelicula.mostrarDetalles();
			pelicula.setEstado(false);
			if (archiPeliculas.grabarRegistro(pelicula, posicionPelicula)) {
				std::cout << "LA PELICULA DE TITULO: " << pelicula.getTitulo() << " FUE ELIMINADA DE LA CARTELERA EXITOSAMENTE." << std::endl;
				return true;
			}
			else {
				std::cout << "ERROR AL QUERER ELIMINAR LA PELICULA DE LA CARTELERA." << std::endl;
				return false;
			}

		}
	}
}
void Administrador::cargarSalas() {
	ArchivoSalas archiSalas("sala.dat");
	Sala sala;
	int idSala = archiSalas.validarId();
	std::cout << "SALA #" << idSala << std::endl;
	float precioEntrada;
	std::cout << "PRECIO DE ENTRADA $";
	std::cin >> precioEntrada;
	while (precioEntrada <= 0) {
		std::cout << "EL PRECIO NO PUEDE SER NEGATIVO, POR FAVOR INGRESE UN NUEVO PRECIO DE ENTRADA $";
		std::cin >> precioEntrada;
	}
	sala = Sala(idSala, precioEntrada);
	archiSalas.grabarRegistro(sala);


}
void Administrador::verSalasCargadas() {
	ArchivoSalas archiSalas("sala.dat");
	Sala registro;
	int contador = 0;
	int cantidadRegistros = archiSalas.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiSalas.leerRegistro(i);
		if (registro.getEstado()) {
			registro.mostrarDetalles();
			std::cout << std::endl;
			contador++;
		}
	}
	if (contador == 0) {
		system("cls");
		std::cout << std::endl << "NO HAY SALAS." << std::endl;
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
	std::cout << "NUEVO IMPORTE DE ENTRADA $";
	std::cin >> precioNuevo;
	while (precioNuevo <= 0) {
		std::cout << "EL IMPORTE NO PUEDE SER NEGATIVO. POR FAVOR, INGRESE UN NUEVO IMPORTE DE ENTRADA $ ";
		std::cin >> precioNuevo;
	}
	if (confirmarAccion()) {

		sala.setPrecioAsiento(precioNuevo);
		if (archivoSalas.grabarRegistro(sala, posicionSala)) {
			std::cout << "PRECIO DE LA ENTRADA A LA SALA #" << sala.getIdSala() << " FUE MODIFICADA EXITOSAMENTE." << std::endl;
			return true;
		}
		else {
			std::cout << "ERROR AL QUERER MODIFICAR EL PRECIO DE LA SALA #" << sala.getIdSala() << std::endl;
			return false;
		}
	}

}
bool Administrador::darDeBajaSala() {
	ArchivoSalas archiSalas("sala.dat");
	Sala sala;
	int id;
	int posicionSala;
	std::cout << "NRO DE SALA A ELIMINAR #";
	std::cin >> id;
	if (confirmarAccion()) {

		system("cls");
		posicionSala = archiSalas.buscarPosSalaxID(id);
		if (posicionSala >= 0) {
			sala = archiSalas.leerRegistro(posicionSala);
			sala.mostrarDetalles();
			sala.setEstado(false);
			if (archiSalas.grabarRegistro(sala, posicionSala)) {
				std::cout << "LA SALA #" << sala.getIdSala() << " FUE ELIMINADA EXITOSAMENTE." << std::endl;
				return true;
			}
			else {
				std::cout << "ERROR AL QUERER ELIMINAR EL PRECIO DE LA SALA #" << sala.getIdSala() << std::endl;
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
		std::cout << "NRO DE PELICULA QUE DESEA ELEGIR: ";
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
			std::cout << "NRO DE PELICULA INEXISTENTE." << std::endl;
		}
	} while (contador == cantidadRegistros);

}
Pelicula Administrador::buscarPeliculaxID(int valorBuscado) {
	ArchivoPeliculas archivoPeliculas("pelicula.dat");
	int pos = archivoPeliculas.buscarPosPeliculaxID(valorBuscado);
	if (pos >= 0) {

		Pelicula pelicula;
		pelicula = archivoPeliculas.leerRegistro(pos);
		return pelicula;
	}
	else {
		std::cout << "NRO DE PELICULA INEXISTENTE." << std::endl;
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
			std::cout << "" << std::endl;
			rlutil::locate(50, 10);
			std::cout << "1. MODIFICAR PELICULA" << std::endl;
			rlutil::locate(50, 11);
			std::cout << "2. MODIFICAR SALA" << std::endl;
			rlutil::locate(50, 12);
			std::cout << "3. MODIFICAR FECHA Y HORA" << std::endl;
			rlutil::locate(50, 13);
			std::cout << "4. Volver" << std::endl;
			rlutil::locate(50, 14);
			std::cout << "INGRESE UN NRO: ";
			std::cin >> opcion;
			switch (opcion) {
			case 1: {
				system("cls");
				int posicionPelicula, idPelicula;
				verPeliculasCargadas();
				std::cout << "NRO DE PELICULA QUE DESEA CAMBIAR: ";
				std::cin >> idPelicula;
				if (confirmarAccion()) {
					posicionPelicula = archivoPeliculas.buscarPosPeliculaxID(idPelicula);
					pelicula = archivoPeliculas.leerRegistro(posicionPelicula);
					funcion.setPelicula(pelicula);
					archivoFunciones.grabarRegistro(funcion, posicionFuncion);
					rlutil::locate(50, 17);
					system("cls");
					std::cout << "LA PELICULA: " << pelicula.getTitulo() << " ASIGNADA CON EXITO A LA FUNCION #" << funcion.getIdFuncion() << std::endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				int posicionSala, idSala;
				verSalasCargadas();
				std::cout << "NRO DE SALA QUE DESEA CAMBIAR";
				std::cin >> idSala;
				if (confirmarAccion()) {
					posicionSala = archivoSalas.buscarPosSalaxID(idSala);
					sala = archivoSalas.leerRegistro(posicionSala);
					funcion.setSala(sala);
					archivoFunciones.grabarRegistro(funcion, posicionFuncion);
					rlutil::locate(50, 17);
					system("cls");
					std::cout << "SALA #" << sala.getIdSala() << " ASIGNADA CON EXITO A LA FUNCION #" << funcion.getIdFuncion() << std::endl;

				}
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				int dia, mes, anio, hora, minuto;
				std::cout << "POR FAVOR, INGRESE LOS SIGUIENTES CAMPOS:" << std::endl << std::endl;
				std::cout << "DIA: ";
				std::cin >> dia;
				while (dia <= 0 || dia > 31)
				{
					std::cout << "Dia no valido, reingrese el dia de la funcion: ";
					std::cin >> dia;
				}
				std::cout << "MES: ";
				std::cin >> mes;
				while (mes <= 0 || mes > 12)
				{
					std::cout << "Mes no valido, reingrese el mes de la funcion: ";
					std::cin >> mes;
				}
				std::cout << "AÑO: ";
				std::cin >> anio;
				while (anio < 2023)
				{
					std::cout << "Anio no valido, reingrese el anio de la funcion: ";
					std::cin >> anio;
				}
				std::cout << "HORA: ";
				std::cin >> hora;
				while (hora < 0 || hora > 23)
				{
					std::cout << "Hora no valida, reingrese la hora de la funcion: ";
					std::cin >> hora;
				}
				std::cout << "MINUTOS: ";
				std::cin >> minuto;
				while (minuto < 0 || minuto > 59)
				{
					std::cout << "Minutos no validos, reingrese los minutos: ";
					std::cin >> minuto;
				}
				if (confirmarAccion()) {

					fechaHorario = FechaHorario(dia, mes, anio, minuto, hora);
					funcion.setFechaHoraFuncion(fechaHorario);
					archivoFunciones.grabarRegistro(funcion, posicionFuncion);
					rlutil::locate(50, 17);
					system("cls");
					std::cout << "FECHA Y HORA MODIFICADA CON EXITO." << std::endl;
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
void Administrador::verVentas()
{
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
		for (int j = 0; j < cantidadRegistrosDiagrama; j++) {
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
				std::cout << "FUNCION #" << funcion.getIdFuncion() << " FUE DADA DE BAJA EXITOSAMENTE." << std::endl;
				return true;
			}
			else {
				std::cout << "ERROR AL QUERER DAR DE BAJA LA FUNCION #" << funcion.getIdFuncion() << std::endl;
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
		std::cout << "NRO DE SALA QUE DESEA SELECCIONAR: ";
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
			std::cout << "NRO DE SALA INEXISTENTE" << std::endl;
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
	std::cout << "FUNCION #" << idFuncion << std::endl << std::endl;
	std::cout << "POR FAVOR, INGRESE LOS SIGUIENTES CAMPOS:" << std::endl << std::endl;
	std::cout << "DIA: ";
	std::cin >> dia;
	while (dia <= 0 || dia > 31)
	{
		std::cout << "Dia no valido, reingrese el dia de la funcion: ";
		std::cin >> dia;
	}
	std::cout << "MES: ";
	std::cin >> mes;
	while (mes <= 0 || mes > 12)
	{
		std::cout << "Mes no valido, reingrese el mes de la funcion: ";
		std::cin >> mes;
	}
	std::cout << "AÑO: ";
	std::cin >> anio;
	while (anio < 2023)
	{
		std::cout << "Anio no valido, reingrese el anio de la funcion: ";
		std::cin >> anio;
	}
	std::cout << "HORA: ";
	std::cin >> hora;
	while (hora < 0 || hora > 23)
	{
		std::cout << "Hora no valida, reingrese la hora de la funcion: ";
		std::cin >> hora;
	}
	std::cout << "MINUTOS: ";
	std::cin >> minuto;
	while (minuto < 0 || minuto > 59)
	{
		std::cout << "Minutos no validos, reingrese los minutos: ";
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
	int contador = 0;
	int cantidadRegistros = archiFunciones.contarRegistros();
	for (int i = 0; i < cantidadRegistros; i++) {
		registro = archiFunciones.leerRegistro(i);
		if (registro.getEstado()) {

			registro.mostrarDetalles();
			std::cout << std::endl;
			contador++;
		}

	}
	if (contador == 0) {
		system("cls");
		std::cout << "NO HAY FUNCIONES." << std::endl;
	}

}
Administrador::Administrador() : Empleado() {

}
Administrador::Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Empleado(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}
void showItem1(const char* text, int posx, int posy, bool selected) {

	if (selected) {
		rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
		rlutil::locate(posx - 3, posy); // posiciona el cursor en la fila y columna que le pasamos por parametro (en este caso, -2 porque colocamos una flechita en la opcion seleccionada)
		std::cout << ">>" << "  " << text << "  " << "<<" << std::endl; // imprime una flechita a cada lado con el codigo ASCII, y el texto que le pasamos por parametro
	}
	else {
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		rlutil::locate(posx - 3, posy);
		std::cout << "   " << text << "   " << "   " << std::endl; // si no esta seleccionado, imprime el texto sin las flechitas
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

		showItem1(" INGRESAR NUEVA PELICULA A CARTELERA ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem1(" VER PELICULAS EN CARTELERA ", 50, 11, y == 1);
		showItem1(" BUSCAR PELICULA", 50, 12, y == 2);
		showItem1(" ELIMINAR PELICULA DE LA CARTELERA ", 50, 13, y == 3);
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
				std::cout << "NRO DE PELICULA A BUSCAR: ";
				std::cin >> id;
				pos = archiPeliculas.buscarPosPeliculaxID(id);
				if (pos >= 0) {
					buscarPeliculaxID(id).mostrarDetalles();
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

		showItem1(" INGRESAR SALA ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem1(" VER SALAS DISPONIBLES", 50, 11, y == 1);
		showItem1(" MODIFICAR PRECIO DE SALA ", 50, 12, y == 2);
		showItem1(" ELIMINAR SALA ", 50, 13, y == 3);
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
				std::cout << "NRO DE SALA A CAMBIAR PRECIO: ";
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

		showItem1(" INGRESAR FUNCION ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem1(" VER FUNCIONES DISPONIBLES ", 50, 11, y == 1);
		showItem1(" BUSCAR FUNCION ", 50, 12, y == 2);
		showItem1(" MODIFICAR FUNCION ", 50, 13, y == 3);
		showItem1(" ELIMINAR FUNCION ", 50, 14, y == 4);
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
				std::cout << "NRO DE FUNCION A BUSCAR: ";
				std::cin >> id;
				archiFunciones.buscarFuncionxID(id).mostrarDetalles();
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				int id;
				std::cout << "NRO DE FUNCION A MODIFICAR: ";
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
				std::cout << "NRO DE FUNCION A ELIMINAR: ";
				std::cin >> idFuncion;
				system("cls");
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

		showItem1(" GENERAR BACKUP PELICULAS ", 50, 10, y == 0);
		showItem1(" RECUPERAR BACKUP PELICULAS ", 50, 11, y == 1);
		showItem1(" GENERAR BACKUP SALAS ", 50, 12, y == 2);
		showItem1(" RECUPERAR BACKUP SALAS ", 50, 13, y == 3);
		showItem1(" GENERAR BACKUP FUNCIONES ", 50, 14, y == 4);
		showItem1(" RECUPERAR BACKUP FUNCIONES ", 50, 15, y == 5);
		showItem1(" GENERAR BACKUP GRAFICOS SALA ", 50, 16, y == 6);
		showItem1(" RECUPERAR BACKUP GRAFICOS SALA ", 50, 17, y == 7);
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