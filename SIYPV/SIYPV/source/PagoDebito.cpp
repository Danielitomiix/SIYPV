#include "PagoDebito.h"

/**
 * @brief Realiza el pago usando tarjeta de débito.
 *
 * En este sistema se simula que el usuario tiene un saldo base
 * y debe ser suficiente para cubrir el monto.
 *
 * Supondremos un saldo fijo para la simulación:
 * - Saldo disponible: $5,000
 *
 * @param monto Monto total a pagar.
 * @return true si hay saldo suficiente, false en caso contrario.
 */
bool
PagoDebito::Pagar(double monto) {
    std::cout << "[Pago con Tarjeta de debito] Monto a pagar: $" << monto << std::endl;
   const double saldoDisponible = 5000.0;
    if (monto <= saldoDisponible) {
    std::cout << "Pago autorizado. Saldo suficiente." << std::endl;
    return true;
    } else {
    std::cout << "Pago rechazado: saldo insuficiente." << std::endl;
    return false;
    }
}

/**
 * @brief Devuelve el nombre del método de pago.
 *
 * @return Cadena "Tarjeta de Débito".
 */
std::string
PagoDebito::getNombreMetodo() const {
  return "Tarjeta de Debito";
}