#pragma once
#include "Prerequisitos.h"
#include "ProductoBase.h"
#include "Medicamento.h"
#include "Bebida.h"
#include "Snack.h"

/**
 * @class FabricaProducto
 * @brief Fábrica para crear productos específicos según su tipo.
 *
 * Implementa el patrón de diseño **Factory Method**, permitiendo instanciar
 * diferentes clases de productos (Medicamento, Bebida o Snack) a partir
 * de un tipo de producto especificado por el usuario.
 */
class
FabricaProducto {
public:

  /**
   * @class Crea un producto del tipo específicado.
   *
   * Este metodo genera una instancia de la clase derivada correspondiente
   * de **ProductoBase** según el tipo proporcionado.
   * 
   * @param tipo Tipo de producto a crear ("Medicamento", "Bebida" o "Snack").
   * @param codigo Código único del producto.
   * @param nombre Nombre del producto.
   * @param precio Precio del producto.
   * @param cantidad Cantidad inicial en inventario.
   * @return Puntero al objeto ProductoBase o nullptr si el tipo invalido.
   */
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
