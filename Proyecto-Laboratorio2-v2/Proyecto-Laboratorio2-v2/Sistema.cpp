#include "Sistema.h"
#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"
using namespace std;

Sistema::Sistema()
{
    Pelicula vecPeliculas[5];
    Sala vecSalas[5];
    Funcion vecFunciones[25];
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
		cin >> contrasenia;
        if (usuario == admin1.getUsuario() && contrasenia == admin1.getContrasenia()) {
			cout << "Bienvenido " << admin1.getNombre() << " " << admin1.getApellido() << endl;
			login = true;
			system("pause");
			system("cls");
			mostrarMenuAdmin();
		}
        else if (usuario == vendedor1.getUsuario() && contrasenia == vendedor1.getContrasenia()) {
			cout << "Bienvenido " << vendedor1.getNombre() << " " << vendedor1.getApellido() << endl;
			login = true;
			system("pause");
			system("cls");
			mostrarMenuVendedor();
		}
        else {
			cout << "Usuario o contrasenia incorrectos" << endl;
			intentos++;
			system("pause");
			system("cls");
		}
	} while (intentos < 3 && login == false);
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
		cin >> contrasenia;
        if (usuario == admin1.getUsuario() && contrasenia == admin1.getContrasenia()) {
			cout << "Bienvenido " << admin1.getNombre() << " " << admin1.getApellido() << endl;
			login = true;
			system("pause");
			system("cls");
			mostrarMenuAdmin();
		}
        else if (usuario == vendedor1.getUsuario() && contrasenia == vendedor1.getContrasenia()) {
			cout << "Bienvenido " << vendedor1.getNombre() << " " << vendedor1.getApellido() << endl;
			login = true;
			system("pause");
			system("cls");
			mostrarMenuAdmin();
		}
        else {
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
        std::cout << (char) 175 << "  " << text << "  " << (char) 174 << std::endl; // imprime una flechita a cada lado con el codigo ASCII, y el texto que le pasamos por parametro
    }
    else {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(posx-3, posy);
        std::cout << "   " << text << "   " <<  std::endl; // si no esta seleccionado, imprime el texto sin las flechitas
    }
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK); // cuando llega a la ultima opcion, cambia el color del cursor al color normal
}



void Sistema::mostrarMenuAdmin() {
    
    int op = 1, y=0;
    Funcion f1;

    do {
        rlutil::setConsoleTitle("MENU ADMIN CINE"); // establece el titulo de la consola
        rlutil::hidecursor(); // oculta el cursor
        //rlutil::cls(); // limpia la pantalla

        showItem(" Cargar peliculas ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
        showItem(" Ver peliculas cargadas ", 50, 11, y == 1);
        showItem(" Cargar salas ", 50, 12, y == 2);
        showItem(" Ver salas cargadas ", 50, 13, y == 3);
        showItem(" OPCION 5 ", 50, 14, y == 4);
        showItem("  SALIR   ", 50, 15, y == 5);

        int key = rlutil::getkey(); // Lee una pulsaci�n de tecla y devuelve un c�digo ASCII de tecla.



        switch (key) // evalua el codigo de tecla
        {
        case 14: // flecha ARRIBA
            rlutil::locate(28, 10 + y);
            std::cout << " " << std::endl; // imprime un espacio para borrar la flecha cuando cambie de posicion
            y--;
            if(y<0) y=0; // validacion para que no se salga de las opciones
            break;
        case 15: // flecha ABAJO
            rlutil::locate(28, 10 + y);
            std::cout << " " << std::endl;
            y++;
            if(y>5) y=5;
            break;
        case 1: // ENTER
            switch (y)
            {      
            case 0:{
                system("cls");
                _admin1.cargarPeliculas(vecPeliculas);                          
                system("cls");
                break;
            }
            case 1:
                system("cls");
                _admin1.verPeliculasCargadas(vecPeliculas);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                _admin1.cargarSalas(vecSalas);
                system("cls");
                break;
                case 3:
                    system("cls");
                    _admin1.verSalasCargadas(vecSalas);
                    system("pause");
                    system("cls");
                    break;
                    case 4:
                    system("cls");
                    int indicePeliculaElegida;

                    // Pide al usuario que elija una pel�cula del vector
                    cout << "Elija una pel�cula de la lista:" << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << i + 1 << ". ";
                        vecPeliculas[i].mostrarDetalles(); // Muestra detalles de la pel�cula
                    }
                    cout << endl;
                    cout << "Opcion: ";
                    cin >> indicePeliculaElegida;

                    // Aseg�rate de que el �ndice elegido est� dentro de los l�mites
                    if (indicePeliculaElegida >= 1 && indicePeliculaElegida <= 5) {
                        // Asigna la pel�cula elegida al objeto f1
                        f1.setPelicula(vecPeliculas[indicePeliculaElegida - 1]);
                        f1.getPelicula().mostrarDetalles();
                    }
                    else {
                        cout << "Opci�n no v�lida" << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
						

            case 5: // Si el cursor esta en la opcion SALIR
                   op = 0; // sale del programa
                   break;
            }
        }
    } while (op != 0);



}

void Sistema::mostrarMenuVendedor() {

    int op = 1, y = 0;
    Funcion f1;

    do {
        rlutil::setConsoleTitle("MENU VENDEDOR CINE"); // establece el titulo de la consola
        rlutil::hidecursor(); // oculta el cursor
        //rlutil::cls(); // limpia la pantalla

        showItem(" OPCION 1 ", 50, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
        showItem(" OPCION 2 ", 50, 11, y == 1);
        showItem(" OPCION 3 ", 50, 12, y == 2);
        showItem(" OPCION 4 ", 50, 13, y == 3);
        showItem(" OPCION 5 ", 50, 14, y == 4);
        showItem("  SALIR   ", 50, 15, y == 5);

        int key = rlutil::getkey(); // Lee una pulsaci�n de tecla y devuelve un c�digo ASCII de tecla.



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
                
                break;
            }
            case 1:
              
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
              
                break;
            case 5: // Si el cursor esta en la opcion SALIR
                op = 0; // sale del programa
                break;
            }
        }
    } while (op != 0);
}