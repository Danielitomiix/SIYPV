#pragma once
#include "Prerequisitos.h"
#include "ProductoBase.h"
#include "Medicamento.h"
#include "Bebida.h"
#include "Snack.h"

/**
 * @class FabricaProducto
 * @brief Fábrica para crear instancias de productos según su tipo.
 *
 * Utiliza el patrón de diseño Factory Method para instanciar objetos
 * de diferentes tipos de productos derivados de ProductoBase.
 */
class
FabricaProducto {
public:
  static ProductoBase* crearProducto(const std::string& tipo,
                                     const std::string& codigo,
                                     const std::string& nombre,
                                     float precio,
                                     int cantidad) {
    if (tipo == "Medicamento") {
      return new Medicamento(codigo, nombre, precio, cantidad);
    } else if (tipo == "Bebida") {
      return new Bebida(codigo, nombre, precio, cantidad);
    } else if (tipo == "Snack") {
      return new Snack(codigo, nombre, precio, cantidad);
    } else {
      std::cout << "Tipo de producto desconocido: " << tipo << std::endl;
      return nullptr;
    }
  }
};
