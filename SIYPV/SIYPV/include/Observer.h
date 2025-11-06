#pragma once
#include "Prerequisitos.h"

/**
 * @class Observer
 * @brief Interfaz para el patrón de diseño Observer.
 *
 * Define el método que deben implementar los observadores para recibir notificaciones
 * de cambios en el sujeto observado.
 */
class
Observer {
public:
  virtual ~Observer() = default;
  /**
   * @brief Método llamado cuando el sujeto observado cambia.
   */
  virtual void actualizar(const std::string& mensaje) = 0;
};
