#include "Sistema.h"
#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"
#include <conio.h>
using namespace std;

Sistema::Sistema()
{
	Pelicula vecPeliculas[5];
	Sala vecSalas[5];
	Funcion vecFunciones[25];
	//int matrizSalasxFuncion[10][10]={0};
	_admin1 = Administrador(01, "DT", "Carlos", "Tevez", "Admin", "qwerty");
	_vendedor1 = Vendedor(02, "Vendedor", "Lionel", "Messi", "Vendedor", "1234");
}

Administrador Sistema::getAdmin() const {
	return _admin1;
}

Vendedor Sistema::getVendedor() const {
	return _vendedor1;
}

//funcion login

void Sistema::login(Administrador admin1, Vendedor vendedor1) {

	string usuario;
	string contrasenia;
	int intentos = 0;
	bool login = false;

	do {
		system("cls");
		cout << "Ingrese su usuario: ";
		cin >> usuario;
		cout << "Ingrese su contrasenia: ";
		//cin >> contrasenia;
		contrasenia = "";
		char caracter;
		while (true) {
			caracter = _getch(); // Capturamos un carácter sin mostrarlo en pantalla

			if (caracter == 13) // 13 es el código ASCII de la tecla Enter, terminamos cuando se presiona Enter
				break;
			else if (caracter == 8) { // 8 es el código ASCII de la tecla Retroceso, para borrar un carácter
				if (contrasenia.length() > 0) {
					cout << "\b \b"; // Borramos el carácter en pantalla y retrocedemos el cursor
					contrasenia.pop_back(); // Eliminamos el último carácter de la contraseña
				}
			}
			else {
				contrasenia += caracter; // Agregamos el carácter a la contraseña
				cout << "*"; // Mostramos un asterisco en lugar del carácter
			}
		}
		if (usuario == admin1.getUsuario() && contrasenia == admin1.getContrasenia()) {
			cout << endl;
			cout << "Bienvenido " << admin1.getNombre() << " " << admin1.getApellido() << endl;
			login = true;
			system("pause");
			system("cls");
			mostrarMenuAdmin();
		}
		else if (usuario == vendedor1.getUsuario() && contrasenia == vendedor1.getContrasenia()) {
			cout << endl;
			cout << "Bienvenido " << vendedor1.getNombre() << " " << vendedor1.getApellido() << endl;
			login = true;
			system("pause");
			system("cls");
			mostrarMenuVendedor();
		}
		else {
			cout << endl;
			cout << "Usuario o contrasenia incorrectos" << endl;
			intentos++;
			system("pause");
			system("cls");
		}
	} while (intentos < 3 && login == false);
}

// Funcion para mostrar las opciones del menu
void showItem(const char* text, int posx, int posy, bool selected) {

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



void Sistema::mostrarMenuAdmin() {

	int op = 1, y = 0;
	Funcion f1;

	do {
		rlutil::setConsoleTitle("MENU ADMIN CINE"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem(" Cargar peliculas ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem(" Ver peliculas cargadas ", 50, 11, y == 1);
		showItem(" Cargar salas ", 50, 12, y == 2);
		showItem(" Ver salas cargadas ", 50, 13, y == 3);
		showItem(" Cargar Funciones ", 50, 14, y == 4);
		showItem(" Ver Funciones cargadas ", 50, 15, y == 5);
		showItem(" Cerrar sesion ", 50, 16, y == 6);
		showItem("  SALIR   ", 50, 17, y == 7);

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
			if (y > 7) y = 7;
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				_admin1.cargarPeliculas();
				system("cls");
				break;
			}
			case 1:
				system("cls");
				_admin1.verPeliculasCargadas();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				_admin1.cargarSalas();
				system("cls");
				break;
			case 3:
				system("cls");
				_admin1.verSalasCargadas();
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				_admin1.cargarFunciones();
				system("pause");
				system("cls");
				break;

			case 5:
				system("cls");
				_admin1.verFuncionesCargadas();
				system("pause");
				system("cls");
				break;
			case 6:
				login(_admin1, _vendedor1);
				op = 0;
				break;
			case 7: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);



}

void Sistema::mostrarMenuVendedor() {
	DiagramaSala diagramaSala;
	ArchivoDiagrama archiDiagrama("diagrama.dat");
	int op = 1, y = 0;
	Funcion f1;
	int aux, fila, columna, contadorEntradas=0, contadorGeneralEntradas=0;
	do {
		rlutil::setConsoleTitle("MENU VENDEDOR CINE"); // establece el titulo de la consola
		rlutil::hidecursor(); // oculta el cursor
		//rlutil::cls(); // limpia la pantalla

		showItem(" FUNCIONES CARGADAS ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
		showItem(" MOSTRAR SALA, SE NECESITA ID DE FUNCION. ", 50, 11, y == 1);
		showItem(" RESERVAR ASIENTOS ", 50, 12, y == 2);
		showItem(" CANCELAR ASIENTOS ", 50, 13, y == 3);
		showItem(" VENTA DE ASIENTOS ", 50, 14, y == 4);
		showItem(" CERRAR SESION ", 50, 15, y == 5);
		showItem("  SALIR   ", 50, 16, y == 6);

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
			if (y > 6) y = 6;
			break;
		case 1: // ENTER
			switch (y)
			{
			case 0: {
				system("cls");
				_admin1.verFuncionesCargadas();
				system("pause");
				system("cls");
				break;
			}
			case 1: {
				system("cls");
				std::cout << "Ingrese el id de la funcion a mostrar sala:";
				std::cin >> aux;
				archiDiagrama.mostrarRegistro(aux);
				system("cls");

				break;
			}
			case 2:
				system("cls");	
				std::cout << "Ingrese el id de la funcion para la cual quiere reservar un asiento: ";
				std::cin >> aux;
				std::cout << "Ingrese fila: ";
				std::cin >> fila;
				std::cout << "Ingrese el nro de asiento: ";
				std::cin >> columna;
				archiDiagrama.reservarAsientoEnRegistro(aux, fila, columna);
				contadorEntradas++;
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				std::cout << "Ingrese el id de la funcion para la cual quiere cancelar un asiento: ";
				std::cin >> aux;
				std::cout << "Ingrese fila: ";
				std::cin >> fila;
				std::cout << "Ingrese el nro de asiento: ";
				std::cin >> columna;
				archiDiagrama.cancelarReservaEnRegistro(aux, fila, columna);
				contadorEntradas--;
				system("pause");
				system("cls");

				break;
			case 4:
				system("cls");
				_vendedor1.venderEntradas(contadorEntradas, aux, contadorGeneralEntradas);
				contadorEntradas = 0;
				system("pause");
				system("cls");
				break;
			case 5:
				login(_admin1, _vendedor1);
				op=0;
				break;
			case 6: // Si el cursor esta en la opcion SALIR
				op = 0; // sale del programa
				break;
			}
		}
	} while (op != 0);
}