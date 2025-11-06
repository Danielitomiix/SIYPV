#pragma once
#include "Prerequisitos.h"

/**
 * @class ProductoBase
 * @brief Clase base abstracta para todos los productos del sistema SIYPV.
 *
 * Esta clase define la estructura mínima que deben tener los productos
 * dentro del sistema de inventario y punto de venta.
 * Sirve como interfaz para clases derivadas como Medicamento, Bebida y Snack.
 */
class
ProductoBase {
public:

  /// Constructor por defecto
  ProductoBase() = default;

  /// Destructor virtual por defecto (permite destrucción polimórfica)
  ~ProductoBase() = default;

  /**
   * @brief Muestra la información completa del producto.
   *
   * Método virtual puro que debe ser implementado por cada clase derivada.
   */
  virtual void mostrarInfo() const = 0;

  /**
  * @brief Obtiene el código único del producto.
  * @return Código del producto como cadena.
  */
  virtual std::string getCodigo() const = 0;
};