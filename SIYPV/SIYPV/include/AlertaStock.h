#pragma once
#include "Observer.h"

/**
 * @class AlertaStock
 * @brief Observador que alerta cuando el stock de un producto es bajo.
 *
 * Implementa la interfaz Observer para recibir notificaciones
 * sobre cambios en el inventario relacionados con el stock de productos.
 */
class
AlertaStock : public Observer {
public:
  AlertaStock() = default;
  ~AlertaStock() = default;
  /**
   * @brief Método llamado cuando el sujeto observado cambia.
   * @param mensaje Mensaje de alerta sobre el stock del producto.
   */
  void 
  actualizar(const std::string& mensaje) override {
    std::cout << "[ALERTA DE STOCK BAJO] " << mensaje << std::endl;
  }
};