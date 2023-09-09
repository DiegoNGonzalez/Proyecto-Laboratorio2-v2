#include "Sistema.h"
#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"
using namespace std;

Sistema::Sistema()
{
    std::vector<Pelicula> vecPeliculas;
    std::vector<Sala> vecSalas;
    std::vector<Funcion> vecFunciones;
    _admin1 = Administrador(01, "DT", "Carlos", "Tevez", "Admin", "qwerty");
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



void Sistema::mostrarMenuIniciarPrograma() {
    
    int op = 1, y=0;


    do {
        rlutil::setConsoleTitle("ADMIN CINE"); // establece el titulo de la consola
        rlutil::hidecursor(); // oculta el cursor
        //rlutil::cls(); // limpia la pantalla

        showItem(" OPCION 1 ", 30, 10, y == 0); //si  y  es igual a 0, la opcion 1 esta seleccionada, coloca alli el cursor y cambia el color de fondo con la funcion showItem
        showItem(" OPCION 2 ", 30, 11, y == 1);
        showItem(" OPCION 3 ", 30, 12, y == 2);
        showItem("  SALIR   ", 30, 13, y == 3);

        int key = rlutil::getkey(); // Lee una pulsación de tecla y devuelve un código ASCII de tecla.



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
            if(y>3) y=3;
            break;
        case 1: // ENTER
            switch (y)
            {      
            case 0:
                system("cls");
                _admin1.cargarPeliculas(vecPeliculas);                          
                system("cls");
                break;
            case 1:
                system("cls");
                _admin1.verPeliculasCargadas(vecPeliculas);
                system("pause");
                system("cls");
                break;
            case 2:
                break;
            case 3: // Si el cursor esta en la opcion SALIR
                   op = 0; // sale del programa
                   break;
            }
        }
    } while (op != 0);

}