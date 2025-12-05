#pragma once
//Librerias estandar
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream> 
//Libreria json
#include "json.hpp"
using json = nlohmann::json;
/**
 * @struct FechaHora
 * @brief Representa la fecha y hora completa (dia, mes, año, hora, minuto, segundo).
 *
 * Permite obtener la fecha y hora actual del sistema y convertirla a cadena para mostrarla.
 */
struct  
FechaHora {
	int dia;      /**< Día del mes */
	int mes;      /**< Mes del año */
	int anio;     /**< Año */
	int hora;     /**< Hora (24h) */
	int minuto;   /**< Minuto */
	int segundo;  /**< Segundo */
	/**
	 * @brief Obtiene la fecha y hora actual del sistema.
	 */
	void
	getFechaHora() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		dia = ltm->tm_mday;
		mes = 1 + ltm->tm_mon;
		anio = 1900 + ltm->tm_year;
		hora = ltm->tm_hour;
		minuto = ltm->tm_min;
		segundo = ltm->tm_sec;
	}
	/**
	* @brief Convierte la fecha y hora a una cadena legible.
	* @return Cadena con formato "dd/mm/yyyy hh:mm:ss".
	*/
	std::string toString() const {
		return std::to_string(dia) + "/" +
			std::to_string(mes) + "/" +
			std::to_string(anio) + " " +
			std::to_string(hora) + ":" +
			std::to_string(minuto) + ":" +
			std::to_string(segundo);
	}
};

/// Enum para los métodos de pago disponibles
enum class MetodoPago {
	Efectivo = 1, // 1 para efectivo
	TarjetaCredito = 2, // 2 para tarjeta de crédito
	TarjetaDebito = 3 // 3 para tarjeta de débito
};

//Tipos de combustible para gasolinera
enum class TipoCombustible {
	GasolinaMagna = 1,   // Gasolina Magna
	GasolinaPremium = 2,   // Gasolina Premium
	Diesel = 3,   // Diesel 
};
