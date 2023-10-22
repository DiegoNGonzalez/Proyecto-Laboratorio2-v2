#include "InformesMaker.h"
#include "funcionesGlobales.h"


InformesMaker::InformesMaker() {}

void InformesMaker::mostrarInfomeRecaXPelicula() {
	Administrador admin;

	int idPelicula;

	std::cout << "LISTADO DE PELICULAS DISPONIBLES " << std::endl << std::endl;
	admin.verPeliculasCargadas();

	/*std::cout << "Por favor ingrese el ID de la pelicula: ";
	std::cin >> idPelicula;*/
	idPelicula = funcionesGlobales::validarMinimo(1, "Por favor ingrese el ID de la pelicula: ", "ERROR. Ingrese un numero valido", "El numero debe ser mayor o igual a 1 ");


	Pelicula pelicula; // creo el obj pelicuila
	ArchivoPeliculas archivoPeliculas("pelicula.dat");

	Entrada entrada;
	ArchivoEntrada archivoEntrada("venta.dat");

	int cantidadPeliculas = archivoPeliculas.contarRegistros();
	int cantidadEntradas = archivoEntrada.contarRegistros();

	float recaudacion = 0;

	for (int i = 0; i < cantidadPeliculas; i++) {

		pelicula = archivoPeliculas.leerRegistro(i);
		int idPeliActual = pelicula.getId();

		if (idPeliActual == idPelicula) {
			for (int j = 0; j < cantidadEntradas; j++) {
				entrada = archivoEntrada.leerRegistro(j);
				int idPeliEntrada = entrada.getFuncion().getPelicula().getId();

				if (idPeliEntrada == idPelicula) {
					recaudacion += entrada.getImporte();
				}
			}
			if (recaudacion == 0) {
				std::cout << "No hay ventas para la pelicula " << pelicula.getTitulo() << std::endl;

			}
			else {
				//uso la libreria <iomanip> para que se muestre como una tabla
				std::cout << " " << std::left << std::setw(36) << "____________________________________" << "" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "TITULO" << "|" << std::setw(4) << "ID" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << pelicula.getTitulo() << "|" << std::setw(4) << idPelicula << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(4) << "____" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
				std::cout << std::endl;
			}

		}

	}


}

void InformesMaker::mostrarInformeRecaXDia() {

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;

	int cantEntradas = archiEntrada.contarRegistros();

	int dia;
	int mes;
	int anio;

	float recaudacion = 0;

	std::cout << "INGRESAR LA FECHA\n" << std::endl;

	dia = funcionesGlobales::validarRango(1, 31, "Ingrese el dia: ", "ERROR. Ingrese un numero valido: ", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 31");
	mes = funcionesGlobales::validarRango(1, 12, "Ingrese el mes: ", "ERROR. Ingrese un numero valido: ", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 12");
	anio = funcionesGlobales::validarRango(2020, 2023, "Ingrese el anio: ", "ERROR. Ingrese un numero valido: ", "El numero debe ser mayor o igual a 2020 ", "y menor o igual a 2021");

	Fecha fechaInforme(dia, mes, anio);

	for (int i = 0; i < cantEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);
		Fecha fechaEntrada = entrada.getFechaHora().getFecha();

		if (funcionesGlobales::compararFechas(fechaEntrada, fechaInforme)) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		system("cls");
		std::cout << "\nRECAUDACION POR DIA" << std::endl;
		std::cout << " " << std::left << std::setw(26) << "__________________________" << "" << std::endl;
		std::cout << "|" << std::left << std::setw(10) << "FECHA" << " |" << std::setw(14) << "  RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(0) << dia << "/" << mes << "/" << anio << " |" << std::setw(3) << "  $" << std::setw(11) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(26) << "__________________________" << "|" << std::endl;
		std::cout << std::endl;
	}
	else {
		fechaInforme.mostrarFecha();
		std::cout << "\nNo se vendieron entradas" << std::endl;
	}

}

void InformesMaker::mostrarInformeRecaXMes() {
	float recaudacion = 0;
	int mesInforme;
	mesInforme = funcionesGlobales::validarRango(1, 12, "Ingrese el mes: ", "ERROR. Ingrese un mes valido: ", "El numero debe ser mayor o igual a 1 ", "y menor o igual a 12");

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;
	int cantidadEntradas = archiEntrada.contarRegistros();

	for (int i = 0; i < cantidadEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);

		int mesEntrada = entrada.getFechaHora().getFecha().getMes();

		if (mesInforme == mesEntrada) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		system("cls");
		std::cout << "RECAUDACION MENSUAL " << std::endl;

		std::cout << " " << std::left << std::setw(15) << "_______________" << "_" << std::setw(15) << "_______________" << "" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "MES" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << funcionesGlobales::escribirMes(mesInforme) << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "_______________" << "_" << std::setw(15) << "_______________" << "|" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "No se vendieron entradas en " << funcionesGlobales::escribirMes(mesInforme) << std::endl;
	}

}

void InformesMaker::mostrarInformeRecaXAnio() {
	float recaudacion = 0;
	int anioInforme;
	anioInforme = funcionesGlobales::validarInt("Ingrese el anio", "ERROR. Ingrese un anio valido");

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;
	int cantidadEntradas = archiEntrada.contarRegistros();

	for (int i = 0; i < cantidadEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);
		int anioEntrada = entrada.getFechaHora().getFecha().getAnio();

		if (anioInforme == anioEntrada) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		std::cout << "LA RECAUDACION EN " << anioInforme << " FUE DE: " << recaudacion << std::endl;
	}
	else {
		std::cout << "No se vendieron entradas en " << anioInforme << std::endl;
	}
}

void InformesMaker::mostrarInformeFranjasHorarias() {
	// 
	std::cout << "INFORME DE FRANJAS HORARIAS" << std::endl;
}

