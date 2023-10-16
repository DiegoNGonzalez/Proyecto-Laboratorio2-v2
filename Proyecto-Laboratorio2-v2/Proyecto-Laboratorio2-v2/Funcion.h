#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "FechaHorario.h"
class Funcion
{
private:
	int _idFuncion, _contadorEntrada;
	Pelicula _pelicula;
	Sala _sala;
	FechaHorario _fechaHoraFuncion;
	bool _estado;
public:
	void setPelicula(Pelicula pelicula);
	Pelicula getPelicula();
	void setSala(Sala sala);
	Sala getSala();
	void setFechaHoraFuncion(FechaHorario fechaHoraFuncion);
	FechaHorario getFechaHoraFuncion();
	void setIdFuncion(int idFuncion);
	int getIdFuncion() const;
	void setEstado(bool estado);
	bool getEstado() const;
	void setContadorEntrada(int contadorEntrada);
	int getContadorEntrada() const;
	Funcion();
	Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, int idFuncion);
	void mostrarDetalles();
	void mostrarDetallesEntradas();





};
