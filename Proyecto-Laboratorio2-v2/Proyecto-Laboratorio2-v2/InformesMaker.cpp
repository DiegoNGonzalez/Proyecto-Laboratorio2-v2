#include "InformesMaker.h"
#include "funcionesGlobales.h"


InformesMaker::InformesMaker() {}

void InformesMaker::mostrarInfomeRecaXPelicula() {
	Administrador admin;

	int idPelicula;

	std::cout << "LISTADO DE PELICULAS DISPONIBLES " << std::endl << std::endl;
	admin.verPeliculasCargadas();

	idPelicula = funcionesGlobales::validarMinimo(1, "NRO DE PELICULA: ", "INGRESO NO VALIDO, REINGRESE NRO DE PELICULA: ", "EL NRO DE PELICULA DEBE SER MAYOR O IGUAL A 1");

	Pelicula pelicula;
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
				std::cout << "NO HUBO VENTAS PARA LA PELICULA " << pelicula.getTitulo() << std::endl;

			}
			else {

				system("cls");
				std::cout << "." << std::left << std::setw(31) << "_______________________________" << "." << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "TITULO" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << pelicula.getTitulo() << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
				std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
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

	std::cout << "INGRESE UNA FECHA PORFAVOR: \n" << std::endl;

	dia = funcionesGlobales::validarRango(1, 31, "DIA: ", "INGRESO NO VALIDO, REINGRESE DIA: ", "EL DIA INGRESADO TIENE QUE SER MAYOR A 0 ", "Y MENOR O IGUAL A 31 ");
	mes = funcionesGlobales::validarRango(1, 12, "MES: ", "INGRESO NO VALIDO, REINGRESE MES: ", "EL MES INGRESADO TIENE QUE SER MAYOR A 0 ", "Y MENOR O IGUAL A 12 ");
	anio = funcionesGlobales::validarRango(2020, 2023, "AÑO: ", "INGRESO NO VALIDO, REINGRESE AÑO: ", "EL AÑO DEBE SER MAYOR O IGUAL A 2020 ", "Y MENOR O IGUAL A 2023 ");

	Fecha fechaInforme(dia, mes, anio);

	for (int i = 0; i < cantEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);
		Fecha fechaEntrada = entrada.getFechaHora().getFecha();

		if (fechaEntrada == fechaInforme) {
			recaudacion += entrada.getImporte();
		}
	}

	if (recaudacion > 0) {
		system("cls");
		std::cout << "RECAUDACION POR DIA" << std::endl;
		std::cout << " " << std::left << std::setw(26) << "__________________________" << "" << std::endl;
		std::cout << "|" << std::left << std::setw(10) << "FECHA" << " |" << std::setw(14) << "  RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(0) << dia << "/" << mes << "/" << anio << " |" << std::setw(3) << "  $" << std::setw(11) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(26) << "__________________________" << "|" << std::endl;
		std::cout << std::endl;
	}
	else {
		system("cls");
		std::cout << "EN LA FECHA ";
		fechaInforme.mostrarFecha();
		std::cout << " NO HUBO VENTAS DE ENTRADAS." << std::endl;
	}
}

void InformesMaker::mostrarInformeRecaXMes() {
	float recaudacion = 0;
	int mesInforme;
	mesInforme = funcionesGlobales::validarRango(1, 12, "MES: ", "INGRESO NO VALIDO, REINGRESE MES: ", "EL MES INGRESADO DEBE SER MAYOR O IGUAL A 1 ", "Y MENOR O IGUAL A 12, REINGRESE MES: ");

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

		std::cout << "." << std::left << std::setw(15) << "_______________" << "_" << std::setw(15) << "_______________" << "." << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "MES" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << funcionesGlobales::escribirMes(mesInforme) << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
		std::cout << std::endl;
	}
	else {
		system("cls");
		std::cout << "NO HUBO VENTAS DE ENTRADA EN EL MES DE " << funcionesGlobales::escribirMes(mesInforme) << std::endl;
	}

}

void InformesMaker::mostrarInformeRecaXAnio() {
	float recaudacion = 0;
	int anioInforme = funcionesGlobales::validarRango(2020, 2023, "AÑO: ", "INGRESO NO VALIDO, REINGRESE UN AÑO: ", "EL AÑO DEBE SER MAYOR O IGUAL A 2020 ", "Y MENOR O IGUAL A 2023, REINGRESE AÑO: ");

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
		system("cls");
		std::cout << "RECAUDACION ANUAL" << std::endl;

		std::cout << "." << std::left << std::setw(15) << "_______________" << "_" << std::setw(15) << "_______________" << "." << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "AÑO" << "|" << std::setw(15) << "RECAUDACION" << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << anioInforme << "|" << std::setw(1) << "$" << std::setw(14) << recaudacion << "|" << std::endl;
		std::cout << "|" << std::left << std::setw(15) << "_______________" << "|" << std::setw(15) << "_______________" << "|" << std::endl;
		std::cout << std::endl;

	}
	else {
		system("cls");
		std::cout << "NO HUBO VENTAS DE ENTRADA EN EL AÑO " << anioInforme << std::endl;
	}
}

void InformesMaker::mostrarInformeFranjasHorarias() {
	//primera franja 12 a 15hs
	//segunda franja 15 a 17hs
	//tercera franja 17 a 20hs
	//cuarta franja 20 a 23hs
	//quinta franja 23 a 1hs

	ArchivoEntrada archiEntrada("venta.dat");
	Entrada entrada;

	int cantidadEntradas = archiEntrada.contarRegistros();

	std::string mensaje = "";

	int cantEntradasFranja1 = 0;
	int cantEntradasFranja2 = 0;
	int cantEntradasFranja3 = 0;
	int cantEntradasFranja4 = 0;
	int cantEntradasFranja5 = 0;

	float recaudacionFranja1 = 0;
	float recaudacionFranja2 = 0;
	float recaudacionFranja3 = 0;
	float recaudacionFranja4 = 0;
	float recaudacionFranja5 = 0;

	int fhMax = -1;
	float recaudacionMax = -1;

	for (int i = 0; i < cantidadEntradas; i++) {
		entrada = archiEntrada.leerRegistro(i);
		int horaFuncion = entrada.getFuncion().getFechaHoraFuncion().getHorario().getHora();

		if (horaFuncion >= 12 && horaFuncion < 15) {
			cantEntradasFranja1++;
			recaudacionFranja1 += entrada.getImporte();
		}
		else if (horaFuncion >= 15 && horaFuncion < 17) {
			cantEntradasFranja2++;
			recaudacionFranja2 += entrada.getImporte();
		}
		else if (horaFuncion >= 17 && horaFuncion < 20) {
			cantEntradasFranja3++;
			recaudacionFranja3 += entrada.getImporte();
		}
		else if (horaFuncion >= 20 && horaFuncion < 23) {
			cantEntradasFranja4++;
			recaudacionFranja4 += entrada.getImporte();
		}
		else if (horaFuncion >= 23 || horaFuncion <= 1) {
			cantEntradasFranja5++;
			recaudacionFranja5 += entrada.getImporte();
		}
	}

	float porcentajeFranja1 = float(cantEntradasFranja1 * 100) / cantidadEntradas;
	float porcentajeFranja2 = float(cantEntradasFranja2 * 100) / cantidadEntradas;
	float porcentajeFranja3 = float(cantEntradasFranja3 * 100) / cantidadEntradas;
	float porcentajeFranja4 = float(cantEntradasFranja4 * 100) / cantidadEntradas;
	float porcentajeFranja5 = float(cantEntradasFranja5 * 100) / cantidadEntradas;



	if (fhMax == -1) {
		fhMax = 1;
		recaudacionMax = recaudacionFranja1;
	}
	if (recaudacionMax < recaudacionFranja2) {
		fhMax = 2;
		recaudacionMax = recaudacionFranja2;
	}
	if (recaudacionMax < recaudacionFranja3) {
		fhMax = 3;
		recaudacionMax = recaudacionFranja3;
	}
	if (recaudacionMax < recaudacionFranja4) {
		fhMax = 4;
		recaudacionMax = recaudacionFranja4;
	}
	if (recaudacionMax < recaudacionFranja5) {
		fhMax = 5;
	}

	if (recaudacionMax > 0) { // para que no muestre nada si todavia no se vendieron entradas
		mensaje = "<- Franja horaria con mayor concurrencia";
	}

	std::cout << "INFORME DE FRANJAS HORARIAS - Concurrencia" << std::endl;

	std::cout << "." << std::left << std::setw(16) << "________________" << "_" << std::setw(15) << "_______________" << "_" << std::setw(12) << "____________" << "_" << std::setw(8) << "________" << "." << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "FRANJA HORARIA" << "|" << std::setw(15) << "CANT ENTRADAS" << "|" << std::setw(12) << "RECAUDACION" << "|" << std::setw(8) << "% CONC" << "|" << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "12hs - 15 hs" << "|" << std::setw(15) << std::setprecision(0) << cantEntradasFranja1 << "|" << std::setw(12) << recaudacionFranja1 << "|" << std::setw(8) << std::fixed << std::setprecision(2) << porcentajeFranja1 << "|" << (fhMax == 1 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "15hs - 17 hs" << "|" << std::setw(15) << std::setprecision(0) << cantEntradasFranja2 << "|" << std::setw(12) << recaudacionFranja2 << "|" << std::setw(8) << std::fixed << std::setprecision(2) << porcentajeFranja2 << "|" << (fhMax == 2 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "17hs - 20 hs" << "|" << std::setw(15) << std::setprecision(0) << cantEntradasFranja3 << "|" << std::setw(12) << recaudacionFranja3 << "|" << std::setw(8) << std::fixed << std::setprecision(2) << porcentajeFranja3 << "|" << (fhMax == 3 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "20hs - 23 hs" << "|" << std::setw(15) << std::setprecision(0) << cantEntradasFranja4 << "|" << std::setw(12) << recaudacionFranja4 << "|" << std::setw(8) << std::fixed << std::setprecision(2) << porcentajeFranja4 << "|" << (fhMax == 4 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "23hs - 01 hs" << "|" << std::setw(15) << std::setprecision(0) << cantEntradasFranja5 << "|" << std::setw(12) << recaudacionFranja5 << "|" << std::setw(8) << std::fixed << std::setprecision(2) << porcentajeFranja5 << "|" << (fhMax == 5 ? mensaje : "") << std::endl;
	std::cout << "|" << std::left << std::setw(16) << "________________" << "|" << std::setw(15) << "_______________" << "|" << std::setw(12) << "____________" << "|" << std::setw(8) << "________" << "|" << std::endl;
	std::cout << std::endl;
}
