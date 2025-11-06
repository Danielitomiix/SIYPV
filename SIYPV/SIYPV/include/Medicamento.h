#pragma once
#include "ProductoBase.h"

/**
 * @class Medicamento
 * @brief Representa un producto tipo medicamento dentro del sistema SIYPV.
 *
 * Clase derivada de **ProductoBase**, utilizada para definir productos
 * pertenecientes a la categoría "Medicamento". Contiene los datos principales
 * del producto (código, nombre, precio y cantidad) y redefine el método `mostrarInfo()`.
 */
class
Medicamento : public ProductoBase {
public:

  /**
   * @brief Constructor parametrizado de la clase Medicamento.
   * @param _codigo Código único del medicamento.
   * @param _nombre Nombre del medicamento.
   * @param _precio Precio unitario.
   * @param _cantidad Cantidad inicial disponible.
   */
  Medicamento(const std::string& _codigo, const std::string& _nombre, float _precio, int _cantidad)
    : codigo(_codigo), nombre(_nombre), precio(_precio), cantidad(_cantidad) {}

  /// Destructor por defecto
  ~Medicamento() = default;

  /**
   * @brief Muestra la información completa del medicamento.
   *
   * Imprime en consola los datos del producto con su categoría,
   * código, nombre, precio y cantidad en stock.
   */
  void 
  mostrarInfo() const override {
    std::cout << "[Medicamento] " << nombre 
              << " | Codigo: " << codigo
              << " | Nombre: " << nombre
              << " | Precio: $" << precio
              << " | Stock: " << cantidad << std::endl;
  }
  /**
   * @brief Obtiene el código del medicamento.
   * @return Código del producto como cadena.
   */
  std::string getCodigo() const override {
    return codigo;
  }

private:
  std::string codigo; ///<Código único del medicamento
  std::string nombre; ///<Nombre del medicamento
  float precio;  ///<Precio unitario del medicamento
  int cantidad; ///<Cantidad disponible en inventario
};
