#pragma once
#include "ProductoBase.h"

/**
 * @class Snack
 * @brief Representa un snack dentro del sistema de inventario y punto de venta.
 *
 * Contiene información básica del snack (código, nombre, precio y cantidad),
 * además de una operación para mostrar información.
 */
class
Snack : public ProductoBase {
public:
  Snack(const std::string& _codigo, const std::string& _nombre, float _precio, int _cantidad)
    : codigo(_codigo), nombre(_nombre), precio(_precio), cantidad(_cantidad) {}
  ~Snack() = default;
  void mostrarInfo() const override {
    std::cout << "[Snack] " << nombre 
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