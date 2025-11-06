#pragma once
#include "ProductoBase.h"

/**
 * @class Bebida
 * @brief Representa una bebida dentro del sistema de inventario y punto de venta.
 *
 * Contiene información básica de la bebida (código, nombre, precio y cantidad),
 * además de una operación para mostrar información.
 */
class
  Medicamento : public ProductoBase {
public:
  Medicamento(const std::string& _codigo, const std::string& _nombre, float _precio, int _cantidad)
    : codigo(_codigo), nombre(_nombre), precio(_precio), cantidad(_cantidad) {}
  ~Medicamento() = default;

  void mostrarInfo() const override {
    std::cout << "[Medicamento] " << nombre 
              << " | Codigo: " << codigo
              << " | Nombre: " << nombre
              << " | Precio: $" << precio
              << " | Stock: " << cantidad << std::endl;
  }
  std::string getCodigo() const override {
    return codigo;
  }

private:
  std::string codigo;
  std::string nombre;
  float precio;
  int cantidad;
};
