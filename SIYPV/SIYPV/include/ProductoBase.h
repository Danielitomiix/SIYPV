#pragma once
#include "Prerequisitos.h"

/**
 * @class ProductoBase
 * @brief Representa un producto básico dentro del sistema de inventario y punto de venta.
 *
 * Contiene información esencial del producto (código, nombre, precio y cantidad).
 */
class
ProductoBase {
public:
  ProductoBase() = default;
  ~ProductoBase() = default;

  virtual void mostrarInfo() const = 0;
  virtual std::string getCodigo() const = 0;
};