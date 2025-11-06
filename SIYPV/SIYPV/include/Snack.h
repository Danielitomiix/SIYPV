#pragma once
#include "ProductoBase.h"

/**
 * @class Snack
 * @brief Representa un snack dentro del sistema del SIYPV.
 *
 * Clase derivada de **ProductoBase**, usada para identificar productos
 * que pertenecen a la categoría "Snack". Contiene la información básica del producto
 * (código, nombre, precio y cantidad) y redefine el método `mostrarInfo()`.
 */
class
Snack : public ProductoBase {
public:

  /**
  * @brief Constructor parametrizado de la clase Snack.
  *  @param _codigo Código único del producto.
   * @param _nombre Nombre del snack.
   * @param _precio Precio unitario.
   * @param _cantidad Cantidad inicial disponible.
   */

  Snack(const std::string& _codigo, const std::string& _nombre, float _precio, int _cantidad)
    : codigo(_codigo), nombre(_nombre), precio(_precio), cantidad(_cantidad) {}

  // Destructor por defecto
  ~Snack() = default;

  /**
   * @brief Muestra la información completa del snack.
   *
   * Imprime los datos principales del producto en formato legible para el usuario.
   */
  void mostrarInfo() const override {
    std::cout << "[Snack] " << nombre 
              << " | Codigo: " << codigo
              << " | Nombre: " << nombre
              << " | Precio: $" << precio
              << " | Stock: " << cantidad << std::endl;
  }

  /**
   * @brief Obtiene el código del producto.
   * @return Código del snack como cadena.
   */
  std::string getCodigo() const override {
    return codigo;
  }


private:
  std::string codigo; ///<Código único del snack
  std::string nombre; ///<Nombre del snack
  float precio;    ///<Precio unitario del snack
  int cantidad;  ///<Cantidad disponible en inventario
};