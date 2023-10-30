#pragma once
#include <iostream>
#include "FechaHorario.h"

namespace funcionesGlobales{
	/**
	* @brief Función para validar que lo ingresado es un numero entero, recibe por parametros el texto para solicitar el ingreso y el texto para el error.
	* @param textoCout, textoError
	* @return int, devuelve el numero ingresado.
	*/
	int validarInt(std::string textoCout, std::string textoError);
	/**
	* @brief Función para validar que lo ingresado sea un numero entero y a su vez sea mayor al minimo que recibe por parametros, tambien recibe el texto para solicitar el ingreso, el texto para el error y el texto para indicar cual es el minimo.
	* @param minimo, textoCout, textoError, textoMinimo
	* @return int, devuelve el numero ingresado.
	*/
	int validarMinimo(int minimo, std::string textoCout, std::string textoError, std::string textoMinimo);
	/**
	* @brief Función para validar que lo ingresado sea un numero entero y a su vez este dentro del rango que recibe por parametros, tambien recibe el texto para solicitar el ingreso, el texto para el error y el texto para indicar cual es el minimo y el maximo.
	* @param minimo, maximo, textoCout, textoError, textoMinimo, textoMaximo
	* @return int, devuelve el numero ingresado.
	*/
	int validarRango(int minimo, int maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo);
	/**
	* @brief Función de la libreria rlutil para mostrar un item en pantalla con un formato especifico.
	* @param text, posx, posy, selected
	* @return void
	*/
	void showItem(const char* text, int posx, int posy, bool selected);
	/**
	* @brief Función para validar que lo ingresado sea un numero float recibe por parametros el texto para solicitar el ingreso y el texto para el error.
	* @param textoCout, textoError
	* @return float, devuelve el numero ingresado.
	*/
	float validarFloat(std::string textoCout, std::string textoError);
	/**
	* @brief Función para validar que lo ingresado sea un numero float y a su vez sea mayor al minimo que recibe por parametros, tambien recibe el texto para solicitar el ingreso, el texto para el error y el texto para indicar cual es el minimo.
	* @param minimo, textoCout, textoError, textoMinimo
	* @return float, devuelve el numero ingresado.
	*/
	float validarMinimoFloat(float minimo, std::string textoCout, std::string textoError, std::string textoMinimo);
	/**
	* @brief Función para validar que lo ingresado sea un numero float y a su vez este dentro del rango que recibe por parametros, tambien recibe el texto para solicitar el ingreso, el texto para el error y el texto para indicar cual es el minimo y el maximo.
	* @param minimo, maximo, textoCout, textoError, textoMinimo, textoMaximo
	* @return float, devuelve el numero ingresado.
	*/
	float validarRangoFloat(float minimo, float maximo, std::string textoCout, std::string textoError, std::string textoMinimo, std::string textoMaximo);

	/**
	* @brief Funcion para mostrar por pantalla una carga de porcentaje. Si pudoEscribir es true, muestra el mensaje de carga exitosa, sino muestra el mensaje de carga fallida.
	* @param pudoEscribir, mensaje
	* @return void
	*/
	void mostrarPorcentaje(bool pudoEscribir, std::string mensaje);
	/**
	* @brief Función para cargar una cadena de caracteres, recibe por parametro la cadena y el tamaño de la misma.
	* @param pal, tam
	* @return void
	*/
	void cargarCadena(char* pal, int tam);
	/**
	*@brief Función para confirmar una acción, recibe por parametro el texto a mostrar.
	*@param textoCout
	* @return bool, true or false segun corresponda.
	*/
	bool confirmarAccion(std::string textoCout);
	/**
	* @brief Función para mostrar el mes en letras, se utiliza en informes.
	* @param mes
	* @return string, devuelve el mes en letras.
	*/
	std::string escribirMes(int mes);

}
