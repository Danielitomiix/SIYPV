#pragma once
#include "Prerequisitos.h"
#include "Producto.h"

/**
 * @class Factura
 * @brief Genera una factura digital y simula su envío por correo electrónico.
 */
class 
Factura {
public:

    /**
     * @brief Genera un archivo de factura con los datos de compra.
     * @param rfc RFC del cliente.
     * @param correo Correo del cliente.
     * @param productos Lista de productos comprados.
     * @param subtotalTienda Subtotal de productos.
     * @param subtotalGasolina Subtotal de gasolina.
     * @param iva IVA aplicado.
     * @param total Total final de la compra.
     */
    void
    generarFactura(const std::string& nombreCliente,
                   const std::string& rfc,
                   const std::string& correo,
                   const std::vector<Producto>& productos,
                   double subtotalTienda,
                   double subtotalGasolina,
                   double iva,
                   double total);
    /**
     * @brief Simula el envío de la factura al correo del cliente.
     * @param correo Correo electrónico destino.
     */
    void 
    enviarFactura(const std::string& correo);
};