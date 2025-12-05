#pragma once
#include "Prerequisitos.h"

/**
 * @class PagoStrategy
 * @brief Interfaz base para los diferentes métodos de pago dentro del sistema.
 *
 * Esta clase aplica el patrón de diseño Strategy. Permite que el sistema
 * utilice distintos métodos de pago (efectivo, tarjeta de crédito, tarjeta de débito)
 * sin modificar la lógica principal. Cada método concreto deberá implementar sus
 * propias reglas y validaciones.
 */
class 
PagoStrategy {
public:

    /**
     * @brief Destructor virtual por defecto.
     *
     * Se utiliza para permitir eliminación polimórfica segura en clases derivadas.
     */
    virtual ~PagoStrategy() = default;

    /**
     * @brief Ejecuta el pago con el monto especificado.
     *
     * Cada estrategia de pago implementará sus propias reglas.
     *
     * @param monto Monto total que se desea pagar.
     * @return true si el pago fue exitoso, false si falló.
     */
    virtual bool Pagar(double monto) = 0;

    /**
     * @brief Devuelve el nombre del método de pago (por ejemplo, "Efectivo").
     *
     * @return Cadena con el nombre del método.
     */
    virtual std::string getNombreMetodo() const = 0;
};
