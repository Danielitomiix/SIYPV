#pragma once
#include "ProductoBase.h"

/**
 * @class Bebida
 * @brief Representa una bebida dentro del sistema de inventario y punto de venta.
 *
 * Clase derivada de **ProductoBase**, utilizada para definir productos
 * pertenecientes a la categoría "Bebida". Contiene la información principal
 * del producto (código, nombre, precio y cantidad) y redefine el método `mostrarInfo()`.
 */
class
Bebida : public ProductoBase {
public:

  /**
   * @brief Constructor parametrizado de la clase Bebida.
   * @param _codigo Código único de la bebida.
   * @param _nombre Nombre de la bebida.
   * @param _precio Precio unitario.
   * @param _cantidad Cantidad inicial disponible.
   */
  Bebida(const std::string& _codigo, const std::string& _nombre, float _precio, int _cantidad)
    : codigo(_codigo), nombre(_nombre), precio(_precio), cantidad(_cantidad) {}

  /// Destructor por defecto
  ~Bebida() = default;

  /**
   * @brief Muestra la información completa de la bebida.
   *
   * Imprime los datos principales del producto en formato legible para el usuario.
   */
  void 
  mostrarInfo() const override {
    std::cout << "[Bebida] " << nombre 
              << " | Codigo: " << codigo
              << " | Nombre: " << nombre
              << " | Precio: $" << precio
              << " | Stock: " << cantidad << std::endl;
  }

  /**
   * @brief Obtiene el código de la bebida.
   * @return Código del producto como cadena.
   */
  std::string getCodigo() const override {
    return codigo;
  }

private:
  std::string codigo; ///<Código único de la bebida
  std::string nombre; ///<Nombre de la bebida
  float precio;   ///<Precio unitario de la bebida
  int cantidad; ///<Cantidad disponible en inventario
};