#include "PagoCredito.h"

/**
 * @brief Realiza el pago mediante tarjeta de crédito.
 *
 * Esta implementación simula una autorización bancaria.
 * Para efectos del parcial podemos asumir:
 * - Si el monto es menor a 10,000 se autoriza.
 * - Si es mayor, se rechaza (simulación simple).
 *
 * @param monto Monto de la compra.
 * @return true si se autoriza, false si es rechazado.
 */
bool 
PagoCredito::Pagar(double monto) {
  std::cout << "[Pago con Tarjeta de credito] Monto a pagar: $" << monto << std::endl;
  if (monto < 10000.0)
  {
    std::cout << "Pago autorizado por el banco." << std::endl;
    return true;
  } else {
    std::cout << "Pago rechazado: monto excede limite." << std::endl;
    return false;
  }
}

/**
 * @brief Devuelve el nombre del método de pago.
 *
 * @return Cadena "Tarjeta de Crédito".
 */
std::string
PagoCredito::getNombreMetodo() const {
  return "Tarjeta de Credito";
}