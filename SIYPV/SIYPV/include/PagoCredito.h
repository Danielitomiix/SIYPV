#pragma once
#include "PagoStrategy.h"

/**
 * @class PagoCredito
 * @brief Implementación del método de pago con tarjeta de crédito.
 *
 * Este método simula la validación de una tarjeta de crédito.
 * Para fines del proyecto, la validación será básica y simbólica.
 */
class 
PagoCredito : public PagoStrategy {
public:
    
  /**
  * @brief Constructor por defecto.
  */
  PagoCredito() = default;

  /**
  * @brief Destructor por defecto.
  */
  ~PagoCredito() override = default;

  /**
  * @brief Realiza el pago usando tarjeta de crédito.
  *
  * Puede simular validaciones como fondos, autorizaciones, etc.
  *
  * @param monto Monto total a pagar.
  * @return true si el pago se autoriza, false si falla.
  */
  bool Pagar(double monto) override;

  /**
  * @brief Devuelve el nombre del método de pago.
  *
  * @return Cadena "Tarjeta de Crédito".
  */
  std::string getNombreMetodo() const override;
};