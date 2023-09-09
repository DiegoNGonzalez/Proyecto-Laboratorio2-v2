#include "Cine.h"
#include <iostream>
#include <string>
using namespace std;

//private:
//	std::vector<Pelicula> _peliculas;
//	std::vector<Sala> _salas;
//	std::vector<Funcion> _funciones;
//		public:
//			void agregarPelicula(Pelicula pelicula);
//			void agregarSala(Sala sala);
//			void programarFuncion(Funcion funcion);
//			void mostrarFunciones();
//			void venderEntradas(int idFuncion, int cantidadEntradas);
//			void mostrarEstadisticasOcupacionSalas();
//			Cine();
//			Cine(std::vector<Pelicula> peliculas, std::vector<Sala> salas, std::vector<Funcion> funciones);

void Cine::agregarPelicula(Pelicula pelicula)
{
	_peliculas.push_back(pelicula);
}

void Cine::agregarSala(Sala sala)
{
	_salas.push_back(sala);
}

void Cine::programarFuncion(Funcion funcion)
{
	_funciones.push_back(funcion);
}

void Cine::mostrarFunciones()
{
	for (int i = 0; i < _funciones.size(); i++)
	{
		_funciones[i].mostrarDetalles();
	}
}

void Cine::venderEntradas(int idFuncion, int cantidadEntradas)
{
	_funciones[idFuncion].reservarAsiento(cantidadEntradas);
}

void Cine::mostrarEstadisticasOcupacionSalas()
{
	for (int i = 0; i < _salas.size(); i++)
	{
		cout << "Sala " << _salas[i].getNumeroSala() << " esta ocupada en un : " << _salas[i].porcentajeOcupacion() << "%" << endl;
	}
}

int Cine::buscarFuncion(int idFuncion)
{
	for (int i = 0; i < _funciones.size(); i++)
	{
		if (_funciones[i].getIdFuncion() == idFuncion)
		{
			return i;
		}
	}
	return -1;
}

int Cine::obtenerCantidadEntradasVendidas(int idFuncion)
{
	int posicion = buscarFuncion(idFuncion);
	if (posicion != -1)
	{
		return _funciones[posicion].getAsientosReservados();
	}
	return -1;
}

float Cine::obtenerGananciasPorFuncion(int idFuncion)
{
	int posicion = buscarFuncion(idFuncion);
	if (posicion != -1)
	{
		return _funciones[posicion].getAsientosReservados() * _salas[posicion].getPrecioEntrada();
	}
	return -1;
}

Cine::Cine()
{
}

Cine::Cine(std::vector<Pelicula> peliculas, std::vector<Sala> salas, std::vector<Funcion> funciones)
{
	_peliculas = peliculas;
	_salas = salas;
	_funciones = funciones;
}
