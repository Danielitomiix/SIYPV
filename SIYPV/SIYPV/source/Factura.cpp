#include "Factura.h"

void
Factura::generarFactura(const std::string& nombreCliente,
                        const std::string& rfc,
                        const std::string& correo,
                        const std::vector<Producto>& productos,
                        double subtotalTienda,
                        double subtotalGasolina,
                        double iva,
                        double total)
{
    std::ofstream factura("factura.txt");
    FechaHora fecha;
    fecha.getFechaHora();

    factura << "======= Factura Electronica =====\n";

    //-------- Datos del comercio --------
    factura << "COSTCO WHOLESALE MEXICO\n";
    factura << "RFC: COWM800101XXX\n";
    factura << "Direccion: Av. central 123, col Mexico, CDMX\n";
    factura << "Telefono: 55-1234-5678\n";
    factura << "Correo: atencion@costco.com\n";
    factura << "----------------------------------\n";

    //-------- Datos del cliente --------
    factura << "Fecha: " << fecha.toString() << "\n";
    factura << "Cliente: " << nombreCliente << "\n";
    factura << "RFC: " << rfc << "\n";
    factura << "Correo: " << correo << "\n";
    factura << "----------------------------------\n";

    if (!productos.empty())
    {
        factura << "Productos Comprados:\n";
        for (const auto& p : productos)
        {
            factura << p.getNombre()
                    << " | Cantidad: " << p.getCantidad()
                    << " | Precio: $" << p.getPrecio()
                    << " | Subtotal: $" << p.getPrecio() * p.getCantidad()
                    << "\n";
        }
        factura << "Subtotal Tienda: $" << subtotalTienda << "\n";
    }
    if (subtotalGasolina > 0.0)
    {
      factura << "----- Gasolina ----- $" << subtotalGasolina << "\n";
      factura << "Subtotal Gasolina: $" << subtotalGasolina << "\n";
    }
    factura << "IVA (16%): $" << iva << "\n";
    factura << "Total: $" << total << "\n";
    factura << "==================================\n";
    factura.close();
}

void 
Factura::enviarFactura(const std::string& correo) {
    std::cout << "Enviando factura al correo: " << correo << "...\n";
    std::cout << "Factura enviada con exito.\n";
}