#include "PagoEfectivo.h"

/**
 * @brief Realiza el pago en efectivo.
 *
 * En un sistema real se confirmaría la entrega del dinero, pero aquí
 * se considera siempre exitoso.
 *
 * @param monto Monto total a pagar.
 * @return true El pago siempre se acepta.
 */
bool 
PagoEfectivo::Pagar(double monto) {

  std::cout << "[Pago en Efectivo] Monto recibido: $" << monto << std::endl;
  std::cout << "Pago en efectivo realizado con exito." << std::endl;
    return true; 
}

/**
 * @brief Devuelve el nombre del método de pago.
 *
 * @return Cadena "Efectivo".
 */
std::string 
PagoEfectivo::getNombreMetodo() const {
  return "Efectivo";
}