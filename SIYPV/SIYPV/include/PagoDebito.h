#pragma once
#include "PagoStrategy.h"

/**
 * @class PagoDebito
 * @brief Estrategia concreta para procesar pagos con tarjeta de débito.
 *
 * Esta clase implementa el patrón Strategy para manejar el método de pago
 * mediante tarjeta de débito. El sistema puede cambiar entre diferentes
 * estrategias de pago (efectivo, crédito, débito) sin modificar la lógica
 * del flujo principal.
 */
class 
PagoDebito : public PagoStrategy {
public:

  /**
   * @brief Constructor por defecto.
   */
  PagoDebito() = default;

  /**
   * @brief Destructor por defecto.
   */
  ~PagoDebito() override = default;

  /**
   * @brief Procesa el pago usando tarjeta de débito.
   *
   * Simula la validación del banco y confirma si el monto fue cobrado
   * correctamente.
   *
   * @param monto Monto total a cobrar.
   * @return true si el pago fue exitoso, false en caso contrario.
   */
  bool 
  Pagar(double monto) override;

  /**
   * @brief Devuelve el nombre del método de pago utilizado.
   *
   * @return Cadena con el nombre del método: "Tarjeta de Débito".
   */
  std::string getNombreMetodo() const override;
};
