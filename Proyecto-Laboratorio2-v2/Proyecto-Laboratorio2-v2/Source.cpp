#include <iostream>
#include <string>
#include "Windows.h"
#include "rlutil.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Sistema.h"
#include "Persona.h"
#include "Administrador.h"
#include <vector>


using namespace std;



int main() {

   /* 
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
    
    Persona p1;
    p1 = Persona();
    cout << p1.mostrarDatos() << endl;
    p1 = Persona(12,"Administrador", "Diego", "Gomez", "Admin", "1234asd");
    cout << p1.mostrarDatos() << endl;
    std::vector <Pelicula> vecPeliculas;
    Administrador admin1;
    admin1.cargarPeliculas( vecPeliculas);
    admin1.verPeliculasCargadas( vecPeliculas);
   
    */

    Sistema sistema;
    sistema = Sistema();
    sistema.login(sistema.getAdmin(), sistema.getVendedor());
    //sistema.mostrarMenuIniciarPrograma();

    return 0;
}