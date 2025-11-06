#pragma once
#include "Prerequisitos.h"

/**
 * @class Producto
 * @brief Representa un producto dentro del sistema de inventario y punto de venta.
 *
 * Contiene información básica del producto (código, nombre, precio y cantidad),
 * además de operaciones para vender, comprar y mostrar información.
 */
class 
Producto {
public:
    // Constructor por defecto
    Producto() = default;
    // Constructor parametrizado
    Producto(const std::string& _codigo, const std::string& _nombre, float _precio, int _cantidad) 
            : codigo(_codigo), nombre(_nombre), precio(_precio), cantidad(_cantidad) {}

    // Destructor
    ~Producto() = default;

    // Getters
    std::string getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    //Setters
    void 
    setNombre(const std::string& _nombre) { nombre = _nombre; }

    void 
    setPrecio(float _precio) { precio = _precio; }

    void 
    setCantidad(int _cantidad) { cantidad = _cantidad; }

    /**
    * @brief Muestra en consola la información completa del producto.
    */
    void 
    mostrarInfo() const {
         std::cout << "Codigo: "     << codigo 
                   << " | Nombre: "  << nombre
                   << " | Precio: $" << precio  
                   << " | Stock: "   << cantidad 
                   << std::endl;
    }

    /**
     * @brief Reduce el stock del producto al realizar una venta.
     * @param cantidadVendida Cantidad de unidades vendidas.
     */
    void 
    vender(int cantidadVendida) {
           if (cantidad >= cantidadVendida) {
               cantidad -= cantidadVendida;
           std::cout << "Venta realizada: - " << cantidadVendida << " unidades." << std::endl;
           } else {
           std::cout << "Stock insuficiente para la venta. " << std::endl;
           }
    }
    /**
     * @brief Aumenta el stock del producto al realizar una compra.
     * @param cantidadComprada Cantidad de unidades compradas.
     */
    void 
    comprar(int cantidadComprada) {
         cantidad += cantidadComprada;
         std::cout << "Compra registrada: + " << cantidadComprada << " unidades." << std::endl;
    }
    // Método para actualizar el precio del producto
private:
    std::string codigo;  // Código único del producto
    std::string nombre;  // Nombre del producto
    float precio;       // Precio del producto
    int cantidad;       // Cantidad en stock
};