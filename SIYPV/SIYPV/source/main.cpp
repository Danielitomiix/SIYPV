/**
 * @file main.cpp
 * @brief Sistema de Inventario y Punto de Venta con carrito, gasolinera y ticket final.
 *
 * Menú basado en el proyecto del segundo parcial, ahora con:
 *  - Carrito de compras
 *  - Registro de gasolina
 *  - Pago final con Strategy
 *  - Ticket final que integra productos + gasolina + IVA.
 */

#include "Prerequisitos.h"
#include "Inventario.h"
#include "AlertaStock.h"
#include "PagoEfectivo.h"
#include "PagoCredito.h"
#include "PagoDebito.h"

int main()
{
  std::cout << "=== Sistema de Inventario y Punto de Venta (SIYPV) ===\n";

  Inventario inventario;
  AlertaStock alerta;

  // Vincular observador
  inventario.agregarObservador(&alerta);

  // Cargar inventario desde JSON
  inventario.cargarDesdeJSON("../source/productos.json");

  bool ejecutando = true;
  int opcion = 0;

  while (ejecutando)
  {
    std::cout << "\n==== Menu Principal ====\n";
    std::cout << "1. Mostrar inventario\n";
    std::cout << "2. Buscar producto\n";
    std::cout << "3. Comprar producto (agregar stock)\n";
    std::cout << "4. Agregar producto nuevo\n";
    std::cout << "5. Editar producto\n";
    std::cout << "6. Eliminar producto\n";
    std::cout << "7. Guardar inventario\n";
    std::cout << "8. Agregar producto al carrito\n";
    std::cout << "9. Registrar gasolina\n";
    std::cout << "10. Pagar y generar ticket final\n";
    std::cout << "11. Salir\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1: // Mostrar inventario
      inventario.mostrarInventario();
      break;

    case 2: // Buscar producto
    {
      std::cout << "Ingrese codigo o nombre del producto: ";
      std::cin.ignore();
      std::string clave;
      std::getline(std::cin, clave);
      inventario.buscarProducto(clave);
    }
    break;

    case 3: // Comprar producto (agregar stock)
    {
      std::string codigo;
      int cantidad;
      std::cout << "Codigo del producto a comprar (agregar stock): ";
      std::cin >> codigo;
      std::cout << "Cantidad a agregar: ";
      std::cin >> cantidad;
      inventario.comprarProducto(codigo, cantidad);
    }
    break;

    case 4: // Agregar producto nuevo
      inventario.agregarProducto();
      break;

    case 5: // Editar producto
    {
      std::string codigo;
      std::cout << "Ingrese codigo del producto a editar: ";
      std::cin >> codigo;
      inventario.editarProducto(codigo);
    }
    break;

    case 6: // Eliminar producto
    {
      std::string codigo;
      std::cout << "Ingrese codigo del producto a eliminar: ";
      std::cin >> codigo;
      inventario.eliminarProducto(codigo);
    }
    break;

    case 7: // Guardar inventario
      inventario.guardarEnJSON("../source/productos.json");
      break;

    case 8: // Agregar producto al carrito
    {
      std::string codigo;
      int cantidad;
      std::cout << "Ingrese codigo del producto a agregar al carrito: ";
      std::cin >> codigo;
      std::cout << "Cantidad: ";
      std::cin >> cantidad;
      inventario.agregarAlCarrito(codigo, cantidad);
    }
    break;

    case 9: // Registrar gasolina
    {
      int tipo;
      double litros;

      std::cout << "Tipo de combustible:\n";
      std::cout << "1. Magna\n";
      std::cout << "2. Premium\n";
      std::cout << "3. Diesel\n";
      std::cout << "Seleccione opcion: ";
      std::cin >> tipo;
      std::cout << "Litros a cargar: ";
      std::cin >> litros;

      inventario.registrarGasolina(static_cast<TipoCombustible>(tipo), litros);
    }
    break;

    case 10: // Pagar y generar ticket final
    {
      int metodo;
      std::cout << "\n=== Metodos de pago ===\n";
      std::cout << "1. Efectivo\n";
      std::cout << "2. Tarjeta de credito\n";
      std::cout << "3. Tarjeta de debito\n";
      std::cout << "Seleccione metodo: ";
      std::cin >> metodo;

      PagoStrategy* pago = nullptr;

      switch (metodo)
      {
      case 1:
        pago = new PagoEfectivo();
        break;
      case 2:
        pago = new PagoCredito();
        break;
      case 3:
        pago = new PagoDebito();
        break;
      default:
        std::cout << "Metodo invalido.\n";
        break;
      }

      if (pago != nullptr)
      {
        inventario.generarTicketFinal(pago);
        delete pago;
      }
    }
    break;

    case 11: // Salir
      std::cout << "Saliendo del sistema. Hasta luego!\n";
      ejecutando = false;
      break;

    default:
      std::cout << "Opcion invalida.\n";
      break;
    }
  }

  return 0;
}

