#pragma once
#include "PagoStrategy.h"

/**
 * @class PagoEfectivo
 * @brief Implementa el método de pago en efectivo.
 *
 * Esta clase concreta del patrón Strategy maneja los pagos realizados en efectivo.
 * Implementa las reglas específicas para validar y procesar pagos en efectivo.
 */
class 
PagoEfectivo : public PagoStrategy {
public:
    
  /**
  * @brief Constructor por defecto.
  */
  PagoEfectivo() = default;

  /**
  * @brief Destructor por defecto.
  */
  ~PagoEfectivo() override = default;

  /**
  * @brief Realiza el pago en efectivo.
  *
  * El efectivo siempre se considera válido.
  *
  * @param monto Monto total de la compra.
  * @return true (el pago siempre es aceptado).
  */
  bool Pagar(double monto) override;

  /**
  * @brief Devuelve el nombre del método de pago.
  *
  * @return Cadena "Efectivo".
  */
  std::string getNombreMetodo() const override;
};
       