#pragma once
#include "Prerequisitos.h"
#include "Producto.h"

/**
 * @class Inventario
 * @brief Gestiona una colección de productos dentro del sistema de inventario y punto de venta.
 *
 * Permite agregar, eliminar, buscar y mostrar productos, así como gestionar el stock.
 */
class 
Inventario {
public:
    // Constructor y destructor por defecto
    Inventario() = default;
    ~Inventario() = default;

    /**
     * @brief Agrega un nuevo producto al inventario.
     * @param producto Producto a agregar.
     */
    void cargarDesdeJSON(const std::string& nombreArchivo){
      std::ifstream archivo(nombreArchivo);
      if (!archivo.is_open()) {
          std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
          return;
      }

      json data;
      archivo >> data;
      archivo.close();
      productos.clear();
      for (const auto& item : data) {
        std::string codigo = item["codigo"];
        std::string nombre = item["nombre"];
        float precio = item["precio"];
        int cantidad = item["cantidad"];
        productos.emplace_back(codigo, nombre, precio, cantidad);
      }
      std::cout << "Productos cargados correctamente desde " << nombreArchivo << std::endl;
    }

    void mostrarInventario() const {
      if (productos.empty()) {
        std::cout << "No hay productos en el inventario." << std::endl;
        return;
      }
      std::cout << "\n=== Inventario Actual ===" << std::endl;
      for (const auto& producto : productos) {
        producto.mostrarInfo();
      }
    }

    void venderProducto(const std::string& codigo, int cantidad) {
      for (auto& producto : productos) {
        if (producto.getCodigo() == codigo) {
          producto.vender(cantidad);
          return;
        }
      }
      std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
    }

    void comprarProducto(const std::string& codigo, int cantidad) {
      for (auto& producto : productos) {
        if (producto.getCodigo() == codigo) {
          producto.comprar(cantidad);
          return;
        }
      }
      std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
    }

private:
  std::vector<Producto> productos;  ///< Lista de productos en el inventario
};