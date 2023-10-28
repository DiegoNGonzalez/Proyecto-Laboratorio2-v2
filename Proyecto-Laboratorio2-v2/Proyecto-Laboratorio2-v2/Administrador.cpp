#include <iostream>
#include "Administrador.h"
#include "funcionesGlobales.h"
#include "ArchivoEntrada.h"

void Administrador::cargarPeliculas() {
	ArchivoPeliculas archiPeliculas("pelicula.dat");
	char titulo[30];
	char director[30];
	char clasificacionEdad[30];
	char genero[30];
	int duracion, id = archiPeliculas.validarId();
	Pelicula pelicula;
	std::cout << "PELICULA NRO:" << id << std::endl;
	std::cout << "POR FAVOR INGRESE LOS SIGUIENTES CAMPOS OBLIGATORIOS:" << std::endl;
	std::cin.ignore();
	std::cout << "TITULO: ";
	funcionesGlobales::cargarCadena(titulo, 29);
	std::cout << "DIRECTOR: ";
	funcionesGlobales::cargarCadena(director, 29);
	std::cout << "CLASIFICACION DE EDAD: ";
	funcionesGlobales::cargarCadena(clasificacionEdad, 29);
	std::cout << "GENERO: ";
	funcionesGlobales::cargarCadena(genero, 29);
	duracion = funcionesGlobales::validarMinimo(0, "DURACION: ", "INGRESO NO VALIDO, REINGRESE LA DURACION: ", "LA DURACION TIENE QUE SER MAYOR A 0, REINGRESE LA DURACION: ");
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
	id = funcionesGlobales::validarMinimo(0, "NRO DE PELICULA PARA ELIMINAR DE LA CARTELERA: ", "INGRESO NO VALIDO, REINGRESE NRO DE PELICULA: ", "EL NRO DE PELICULA TIENE QUE SER MAYOR A 0, REINGRESE NRO DE PELICULA: ");
	posicionPelicula = archiPeliculas.buscarPosPeliculaxID(id);
	if (posicionPelicula != -1) {
		if (funcionesGlobales::confirmarAccion("¿DESEA ELIMINAR LA PELICULA? (S/N): ")) {

			system("cls");
			if (posicionPelicula >= 0) {
				pelicula = archiPeliculas.leerRegistro(posicionPelicula);
				pelicula.mostrarDetalles();
				pelicula.setEstado(false);
				if (archiPeliculas.grabarRegistro(pelicula, posicionPelicula)) {
					std::cout << std::endl << "LA PELICULA DE TITULO: " << pelicula.getTitulo() << " FUE ELIMINADA DE LA CARTELERA EXITOSAMENTE." << std::endl;
					return true;
				}
				else {
					std::cout << "ERROR AL QUERER ELIMINAR LA PELICULA DE LA CARTELERA." << std::endl;
					return false;
				}

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
	precioEntrada = funcionesGlobales::validarMinimoFloat(0, "PRECIO DE ENTRADA $", "INGRESO NO VALIDO, REINGRESE PRECIO DE ENTRADA $", "EL PRECIO DE ENTRADA DEBE SER MAYOR A 0, REINGRESE PRECIO DE ENTRADA $");
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
	precioNuevo = funcionesGlobales::validarMinimoFloat(0, "NUEVO IMPORTE DE ENTRADA $", "INGRESO NO VALIDO, REINGRESE NUEVO IMPORTE DE ENTRADA $", "EL NUEVO IMPORTE DEBE SER MAYOR A 0, REINGRESE UN NUEVO IMPORTE DE ENTRADA $");
	if (funcionesGlobales::confirmarAccion("¿DESEA CAMBIAR EL IMPORTE DE ENTRADA? (S/N): ")) {

		sala.setPrecioAsiento(precioNuevo);
		if (archivoSalas.grabarRegistro(sala, posicionSala)) {
			std::cout << std::endl << "PRECIO DE LA ENTRADA A LA SALA #" << sala.getIdSala() << " FUE MODIFICADA EXITOSAMENTE." << std::endl;
			modificarSalaEnFuncion(sala.getIdSala(), precioNuevo);
			return true;
		}
		else {
			std::cout << "ERROR AL QUERER MODIFICAR EL PRECIO DE LA SALA #" << sala.getIdSala() << std::endl;
			return false;
		}
	}

}
void Administrador::modificarSalaEnFuncion(int idSala, int precioNuevo) {
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoSalas archivoSalas("sala.dat");
	Funcion funcionAux;
	Sala salaAux;
	int cantidadRegistrosFuncion = archivoFunciones.contarRegistros();
	for (int i = 0; i < cantidadRegistrosFuncion; i++) {
		funcionAux = archivoFunciones.leerRegistro(i);
		if (funcionAux.getSala().getIdSala() == idSala) {
			salaAux = funcionAux.getSala();
			salaAux.setPrecioAsiento(precioNuevo);
			funcionAux.setSala(salaAux);
			archivoFunciones.grabarRegistro(funcionAux, i);
		}
	}
}
bool Administrador::darDeBajaSala() {
	ArchivoSalas archiSalas("sala.dat");
	Sala sala;
	int id;
	int posicionSala;
	id = funcionesGlobales::validarInt("NRO DE SALA A ELIMINAR #", "INGRESO NO VALIDO, REINGRESE NRO DE SALA A ELIMINAR # ");
	posicionSala = archiSalas.buscarPosSalaxID(id);
	if (posicionSala != -1) {
		if (funcionesGlobales::confirmarAccion("¿DESEA ELIMINAR LA SALA? (S/N): ")) {

			system("cls");
			if (posicionSala >= 0) {
				sala = archiSalas.leerRegistro(posicionSala);
				sala.mostrarDetalles();
				sala.setEstado(false);
				if (archiSalas.grabarRegistro(sala, posicionSala)) {
					std::cout << std::endl << "LA SALA #" << sala.getIdSala() << " FUE ELIMINADA EXITOSAMENTE." << std::endl;
					return true;
				}
				else {
					std::cout << "ERROR AL QUERER ELIMINAR EL PRECIO DE LA SALA #" << sala.getIdSala() << std::endl;
					return false;
				}

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
		id = funcionesGlobales::validarInt("NRO DE PELICULA QUE DESEA ELEGIR: ", "Lo ingresado no es un numero, reingrese un numero: ");
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

// este metodo se pasa a archivos
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
	FechaHorario _fechaYHoraSistema = FechaHorario();
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
			opcion = funcionesGlobales::validarRango(1, 4, "INGRESE UNA OPCION: ", "INGRESO NO VALIDO, REINGRESE UNA OPCION: ", "EL NUMERO A INGRESAR DEBE SER MAYOR A 1, REINGRESE UNA OPCION: ", "EL NUMERO A INGRESAR DEBE SER MENOR A 4, REINGRESE UNA OPCION: ");
			switch (opcion) {
			case 1: {
				system("cls");
				int posicionPelicula, idPelicula;
				verPeliculasCargadas();
				std::cin >> idPelicula;
				idPelicula = funcionesGlobales::validarMinimo(1, "NRO DE PELICULA QUE DESEA CAMBIAR: ", "INGRESO NO VALIDO, REINGRESE UN NRO DE PELICULA A CAMBIAR: ", "EL NUMERO A INGRESAR DEBE SER MAYOR A 0, REINGRESE NRO DE PELICULA A CAMBIAR: ");
				if (funcionesGlobales::confirmarAccion("¿DESEA ASIGNAR ESTA PELICULA? (S/N): ")) {
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
				idSala = funcionesGlobales::validarMinimo(1, "NRO DE SALA QUE DESEA CAMBIAR: ", "INGRESO NO VALIDO, REINGRESE UN NRO DE SALA A CAMBIAR: ", "EL NRO DE SALA TIENE QUE SER MAYOR A 0, REINGRESE UN NRO DE SALA A CAMBIAR: ");
				if (funcionesGlobales::confirmarAccion("¿DESEA ASIGNAR LA SALA? (S/N): ")) {
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
				dia = funcionesGlobales::validarRango(1, 31, "DIA: ", "INGRESO NO VALIDO, REINGRESE DIA: ", "EL DIA INGRESADO TIENE QUE SER MAYOR A 0 ", " Y MENOR O IGUAL A 31, REINGRESE DIA: ");
				mes = funcionesGlobales::validarRango(1, 12, "MES: ", "INGRESO NO VALIDO, REINGRESE MES: ", "EL MES INGRESADO TIENE QUE SER MAYOR A 0 ", " Y MENOR O IGUAL 12, REINGRESE MES: ");
				anio = funcionesGlobales::validarMinimo(2023, "AÑO: ", "INGRESO NO VALIDO, REINGRESE AÑO: ", "EL AÑO TIENE QUE SER IGUAL A 2023, AUN NO AGENDAMOS FUNCIONES PARA AÑOS PROXIMOS, REINGRESE AÑO: ");
				hora = funcionesGlobales::validarRango(0, 24, "HORA: ", "INGRESO NO VALIDO, REINGRESE HORA: ", "LA HORA TIENE QUE SER MAYOR A 00", " Y MENOR O IGUAL A 24, REINGRESE HORA: ");
				minuto = funcionesGlobales::validarRango(0, 60, "MINUTOS: ", "INGRESO NO VALIDO, REINGRESE MINUTOS:  ", "LOS MINUTOS TIENEN QUE SER MAYOR O IGUAL A 00 ", " Y MENOR A 60, REINGRESE MINUTOS: ");

				fechaHorario = FechaHorario(dia, mes, anio, minuto, hora);

				validarFechaHoraFuncion(dia, mes, anio, hora, minuto, fechaHorario, _fechaYHoraSistema);

				if (funcionesGlobales::confirmarAccion("¿DESEA MODIFICAR LA FECHA Y HORA? (S/N): ")) {
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
	std::system("pause");
	return pudoEscribir;
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
bool Administrador::darDeBajaFuncion()
{
	ArchivoFunciones archivoFunciones("funcion.dat");
	ArchivoDiagrama archivoDiagrama("diagrama.dat");
	Funcion funcion;
	DiagramaSala diagrama;
	int posicionFuncion, posicionDiagrama;
	int idFuncion;
	do {
		idFuncion = funcionesGlobales::validarMinimo(1, "NRO DE FUNCION A ELIMINAR: ", "INGRESO NO VALIDO, REINGRESE UN NRO DE FUNCION A ELIMINAR: ", "EL NUMERO DE FUNCION TIENE QUE SER MAYOR A 0.");
		posicionFuncion = archivoFunciones.buscarPosFuncionxID(idFuncion);
	} while (posicionFuncion == -1);
	posicionDiagrama = archivoDiagrama.buscarPosDiagramaxID(idFuncion);
	if (funcionesGlobales::confirmarAccion("¿DESEA ELIMINAR LA FUNCION? (S/N): ")) {

		if (posicionFuncion >= 0 && posicionDiagrama >= 0) {
			funcion = archivoFunciones.leerRegistro(posicionFuncion);
			diagrama = archivoDiagrama.leerRegistro(posicionDiagrama);
			funcion.setEstado(false);
			diagrama.setEstado(false);
			if (archivoFunciones.grabarRegistro(funcion, posicionFuncion) && archivoDiagrama.grabarRegistro(diagrama, posicionDiagrama)) {
				std::cout << "FUNCION #" << funcion.getIdFuncion() << " FUE ELIMINADA EXITOSAMENTE." << std::endl;
				return true;
			}
			else {
				std::cout << "ERROR AL ELIMINAR LA FUNCION #" << funcion.getIdFuncion() << std::endl;
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
		numeroSala = funcionesGlobales::validarMinimo(1, "NRO DE SALA QUE DESEA SELECCIONAR: ", "Lo ingresado no es un numero, reingrese un numero: ", "El numero tiene que ser mayor o igual a 1, reingrese: ");
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
	FechaHorario _fechaYHoraSistema = FechaHorario();
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
	int  dia, mes, anio, hora, minuto, contador = 0;
	pelicula = seleccionarPelicula();
	sala = seleccionarSala();
	std::cout << "FUNCION #" << idFuncion << std::endl << std::endl;
	std::cout << "POR FAVOR, INGRESE LOS SIGUIENTES CAMPOS:" << std::endl << std::endl;

	dia = funcionesGlobales::validarRango(1, 31, "DIA: ", "INGRESO NO VALIDO, REINGRESE DIA: ", "EL DIA INGRESADO TIENE QUE SER MAYOR A 0 ", " Y MENOR A 32, REINGRESE DIA: ");
	mes = funcionesGlobales::validarRango(1, 12, "MES: ", "INGRESO NO VALIDO, REINGRESE MES: ", "EL MES INGRESADO TIENE QUE SER MAYOR A 0 ", " Y MENOR A 13, REINGRESE MES: ");
	anio = funcionesGlobales::validarMinimo(2023, "AÑO: ", "INGRESO NO VALIDO, REINGRESE AÑO: ", "EL AÑO TIENE QUE SER IGUAL A 2023, AUN NO AGENDAMOS FUNCIONES PARA AÑOS PROXIMOS, REINGRESE AÑO: ");
	hora = funcionesGlobales::validarRango(0, 24, "HORA: ", "INGRESO NO VALIDO, REINGRESE HORA: ", "LA HORA TIENE QUE SER MAYOR A 00", " Y MENOR A 25, REINGRESE HORA: ");
	minuto = funcionesGlobales::validarRango(0, 60, "MINUTOS: ", "INGRESO NO VALIDO, REINGRESE MINUTOS:  ", "LOS MINUTOS TIENEN QUE SER MAYOR O IGUAL A 00 ", " Y MENOR A 60, REINGRESE MINUTOS: ");
	fechaHoraFuncion = FechaHorario(dia, mes, anio, minuto, hora);

	validarFechaHoraFuncion(dia, mes, anio, hora, minuto, fechaHoraFuncion, _fechaYHoraSistema);

	diagramaSala = DiagramaSala(idFuncion);
	archiDiagrama.grabarRegistro(diagramaSala);
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

void Administrador::validarFechaHoraFuncion(int& dia, int& mes, int& anio, int& hora, int& minuto, FechaHorario& fechaHoraFuncion, FechaHorario& _fechaHorarioSistema) {
	while (fechaHoraFuncion < _fechaHorarioSistema) {
		std::cout << "HORARIO Y/O FECHA INCORRECTO, REINGRESE: " << std::endl;
		dia = funcionesGlobales::validarRango(1, 31, "DIA: ", "INGRESO NO VALIDO, REINGRESE DIA: ", "EL DIA INGRESADO TIENE QUE SER MAYOR A 0 ", " Y MENOR O IGUAL A 31, REINGRESE DIA: ");
		mes = funcionesGlobales::validarRango(1, 12, "MES: ", "INGRESO NO VALIDO, REINGRESE MES: ", "EL MES INGRESADO TIENE QUE SER MAYOR A 0 ", " Y MENOR O IGUAL 12, REINGRESE MES: ");
		anio = funcionesGlobales::validarMinimo(2023, "AÑO: ", "INGRESO NO VALIDO, REINGRESE AÑO: ", "EL AÑO TIENE QUE SER IGUAL A 2023, AUN NO AGENDAMOS FUNCIONES PARA AÑOS PROXIMOS, REINGRESE AÑO: ");
		hora = funcionesGlobales::validarRango(0, 24, "HORA: ", "INGRESO NO VALIDO, REINGRESE HORA: ", "LA HORA TIENE QUE SER MAYOR A 00", " Y MENOR O IGUAL A 24, REINGRESE HORA: ");
		minuto = funcionesGlobales::validarRango(0, 60, "MINUTOS: ", "INGRESO NO VALIDO, REINGRESE MINUTOS:  ", "LOS MINUTOS TIENEN QUE SER MAYOR O IGUAL A 00 ", " Y MENOR A 60, REINGRESE MINUTOS: ");
		fechaHoraFuncion = FechaHorario(dia, mes, anio, minuto, hora);
	}
}

