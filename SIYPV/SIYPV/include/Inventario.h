#pragma once
#include "Prerequisitos.h"
#include "Producto.h"
#include "FabricaProducto.h"
#include "Observer.h"

/**
 * @class Inventario
 * @brief Gestiona la colección de productos dentro del sistema.
 *
 * La clase Inventario permite cargar productos desde un archivo JSON,
 * mostrarlos en pantalla y realizar operaciones básicas de compra y venta.
 */
class 
Inventario {
public:
    // Constructor y destructor por defecto
    Inventario() = default;
    ~Inventario() = default;

    /**
     * @brief Carga los productos desde un archivo JSON.
     * @param nombreArchivo Ruta o nombre del archivo JSON.
     */
    void 
    cargarDesdeJSON(const std::string& nombreArchivo){
      std::ifstream archivo(nombreArchivo);
      if (!archivo.is_open()) {
          std::cout << "No se pudo abrir el archivo: "
            << nombreArchivo << std::endl;
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
      std::cout << "Productos cargados correctamente desde " 
                << nombreArchivo << std::endl;
    }

    /**
     * @brief Muestra todos los productos almacenados en el inventario.
     */
    void 
    mostrarInventario() const {
      if (productos.empty()) {
        std::cout << "No hay productos en el inventario." << std::endl;
        return;
      }
      std::cout << "\n=== Inventario Actual ===" << std::endl;
      for (const auto& producto : productos) {
        producto.mostrarInfo();
      }
    }

    /**
     * @brief Vende una cantidad específica de un producto.
     * @param codigo Código del producto a vender.
     * @param cantidad Cantidad a vender.
     */
    void 
    venderProducto(const std::string& codigo, int cantidad) {
      for (auto& producto : productos) {
        if (producto.getCodigo() == codigo) {
          producto.vender(cantidad);
          registrarTransaccion("VENTA", producto, cantidad);

          if (producto.getCantidad() < 5) { // Umbral de stock bajo
            notificarObservadores("El producto " + producto.getNombre() + 
                                  " tiene stock bajo: " + 
                                  std::to_string(producto.getCantidad()) +
                                  " unidades restantes.");
          }
          return;
        }
      }
      std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
    }

    /**
     * @brief Compra (aumenta stock) de un producto específico.
     * @param codigo Código del producto.
     * @param cantidad Cantidad comprada.
     */
    void 
    comprarProducto(const std::string& codigo, int cantidad) {
      for (auto& producto : productos) {
        if (producto.getCodigo() == codigo) {
          producto.comprar(cantidad);
          registrarTransaccion("COMPRA", producto, cantidad);
          return;
        }
      }
      std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
    }

    /**
     * @brief Guarda el inventario actual en el archivo JSON especificado.
     * @param nombreArchivo Nombre del archivo destino (por ejemplo, "productos.json").
     */
    void 
    guardarEnJSON(const std::string& nombreArchivo) const {
      json data = json::array(); //crea arreglo JSON vacío

      for (const auto& producto : productos) {
        json item;
        item["codigo"] = producto.getCodigo();
        item["nombre"] = producto.getNombre();
        item["precio"] = producto.getPrecio();
        item["cantidad"] = producto.getCantidad();
        data.push_back(item);
      }
      std::ofstream archivo(nombreArchivo);
      if (!archivo.is_open()) {
          std::cout << "Error: No se pudo abrir el archivo para guardar: " << nombreArchivo << std::endl;
          return;
      }
      archivo << std::setw(4) << data << std::endl; // Guarda con indentación de 4 espacios
      archivo.close();
      std::cout << "Inventario guardado correctamente en " << nombreArchivo << std::endl;
    }

    /**
     * @brief Agrega un nuevo producto al inventario solicitando datos al usuario.
     */
    void 
    agregarProducto() {
      std::string codigo, nombre, tipo;
      float precio;
      int cantidad;

      std::cout << "Ingrese el codigo del nuevo producto: ";
      std::cin >> codigo;

      // Verificar si el código ya existe
      for (const auto& producto : productos) {
        if (producto.getCodigo() == codigo) {
          std::cout << "Ya existe un producto con ese codigo en el inventario." << std::endl;
          return;
        }
      }

      std::cin.ignore();
      std::cout << "Ingrese el nombre del nuevo producto: ";
      std::getline(std::cin, nombre);

      std::cout << "Ingrese el precio : ";
      std::cin >> precio;

      std::cout << "Ingrese la cantidad: ";
      std::cin >> cantidad;

      std::cin.ignore();
      std::cout << "Ingrese el tipo de producto (Medicamento / Bebida / Snack): ";
      std::getline(std::cin, tipo);

      // Crear el producto usando la fábrica
      ProductoBase* nuevoProducto = FabricaProducto::crearProducto(tipo, codigo, nombre, precio, cantidad);
      if (!nuevoProducto) {
        std::cout << "Tipo de producto invalido. No se creo el producto." << std::endl;
        return;
      }
      // Convertir Producto base a Producto y agregar al inventario
      productos.emplace_back(codigo, nombre, precio, cantidad);
      std::cout << "Producto agregado correctamente al inventario (" << tipo << ")." << std::endl;

      delete nuevoProducto; // Liberar memoria
    }

    /**
     * @brief Edita los detalles de un producto existente.
     */
    void 
    editarProducto(const std::string& codigo) {
      for (auto& producto : productos) {
        if (producto.getCodigo() == codigo) {
          std::string nombre;
          float precio;
          int cantidad;

          std::cin.ignore();
          std::cout << "Ingrese el nuevo nombre del producto (" 
                    << producto.getNombre() << "): ";
          std::getline(std::cin, nombre);

          std::cout << "Ingrese el nuevo precio del producto (" 
                    << producto.getPrecio() << "): ";
          std::cin >> precio;

          std::cout << "Ingrese la nueva cantidad del producto (" 
                    << producto.getCantidad() << "): ";
          std::cin >> cantidad;

          producto.setNombre(nombre);
          producto.setPrecio(precio);
          producto.setCantidad(cantidad);
          std::cout << "Producto actualizado correctamente." << std::endl;
          return;
        }
      }
      std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
    }

    /**
     * @brief Elimina un producto del inventario por su código.
     */
    void 
    eliminarProducto(const std::string& codigo) {
      for (auto it = productos.begin(); it != productos.end(); ++it) {
        if(it->getCodigo() == codigo){
          productos.erase(it);
          std::cout << "Producto eliminado correctamente." << std::endl;
          return;
        }
      }
      std::cout << "No se encontro el producto con codigo " << codigo << std::endl;
    }

    /**
     * @brief Busca un producto en el inventario por su código o nombre.
     * @param clave Texto a buscar (puede ser el código o el nombre del producto).
     */
    void 
    buscarProducto(const std::string& clave) const {
      bool encontrado = false;

      for (const auto& producto : productos) {
        // Coincidencia exacta por código o parcial por nombre
        if (producto.getCodigo() == clave ||
          producto.getNombre().find(clave) != std::string::npos) {
          
          producto.mostrarInfo();
          encontrado = true;
        }
      }
      if (!encontrado) {
      std::cout << "Producto con codigo " << clave << " no encontrado." << std::endl;
      }
    }

    // Sistema de observadores
    void 
    agregarObservador(Observer* obs) {
      observadores.push_back(obs);
    }

    void 
    notificarObservadores(const std::string& mensaje) const{
      for (auto& obs : observadores) {
        obs->actualizar(mensaje);
      }
    }

    void 
    registrarTransaccion(const std::string& tipo, const Producto& producto, int cantidad) {
      FechaHora fecha;
      fecha.getFechaHora();

      std::ofstream archivo("historial.txt", std::ios::app);
      if (!archivo.is_open()) {
          std::cout << "Error: No se pudo abrir el archivo de historial." << std::endl;
          return;
      }
      archivo << "[" << fecha.toString() << "] "
              << tipo << " | " 
              << "Codigo: " << producto.getCodigo()
              << " | Producto: " << producto.getNombre()
              << " | Cantidad: " << cantidad
              << " | Stock actual: " << producto.getCantidad()
              << std::endl;

      archivo.close();
    }

private:
  std::vector<Producto> productos;  ///< Lista de productos en el inventario
  std::vector<Observer*> observadores; ///< Lista de observadores para notificaciones
};