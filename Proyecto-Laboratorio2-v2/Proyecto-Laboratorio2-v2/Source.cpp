#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Cine.h"


using namespace std;

/*
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
*/

int main() {
    
    Pelicula pelicula1("El señor de los anillos", "Peter Jackson", "Mayores de 13 a�os", "Fantasia", Horario(00, 30, 03));
    Pelicula pelicula2("Bomba vs tomy", "Agustin damonte", "menores de 12", "Porno gay", Horario(10, 30, 01));
    Sala sala1(1, 100, 5.5, pelicula1);
    Sala sala2(2, 200, 100.5, pelicula2);
    Funcion funcion1(pelicula1, sala1, FechaHorario(26, 06, 2011, 12, 12, 12), 100, 50);
    Funcion funcion2(pelicula2, sala2, FechaHorario(26, 06, 2011, 12, 12, 12), 200, 100);
    Cine cine1;
    cine1.agregarPelicula(pelicula1);
    cine1.agregarPelicula(pelicula2);
    cine1.agregarSala(sala1);
    cine1.agregarSala(sala2);
    cine1.programarFuncion(funcion1);
    cine1.programarFuncion(funcion2);

    cine1.mostrarFunciones();
    cine1.venderEntradas(0, 50);
    cine1.venderEntradas(1, 100);

    cout << "Cantidad de entradas vendidas por la funcion 1: " << cine1.obtenerCantidadEntradasVendidas(1) << endl;
    cout << "Cantidad de entradas vendidas por la funcion 2: " << cine1.obtenerCantidadEntradasVendidas(2) << endl;
    cout << "Dinero recaudado funcion 1: " << cine1.obtenerGananciasPorFuncion(1) << endl;
    cout << "Dinero recaudado funcion 2: " << cine1.obtenerGananciasPorFuncion(2);

    cout << "Soy Bomba" << endl;
    
    
    
    
    
    /*
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
                break;
            case 1:
                break;
            case 2:
                break;
            case 3: // Si el cursor esta en la opcion SALIR
                   op = 0; // sale del programa
                   break;
            }
        }
    } while (op != 0);
    */
    return 0;
}