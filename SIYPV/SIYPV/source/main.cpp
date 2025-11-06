#include "Prerequisitos.h"
#include "Inventario.h"
#include "AlertaStock.h"


int main() {
  std::cout << "=== Sistema de Inventario y Punto de Venta (SIYPV) ===" << std::endl;

  Inventario inventario;
  AlertaStock alerta;

  //Vincular el observador al inventario
  inventario.agregarObservador(&alerta);

  // Cargar inventario desde archivo JSON
  inventario.cargarDesdeJSON("productos.json");

  int opcion = 0;
  std::string codigo, nombre;
  int cantidad;
  bool ejecutando = true;

  while (ejecutando) {
    std::cout << "\n==== Menu Principal ====" << std::endl;
    std::cout << "1. Mostrar Inventario" << std::endl;
    std::cout << "2. Buscar Producto" << std::endl;
    std::cout << "3. Vender Producto" << std::endl;
    std::cout << "4. Comprar Producto" << std::endl;
    std::cout << "5. Agregar Producto" << std::endl;
    std::cout << "6. Editar Producto" << std::endl;
    std::cout << "7. Eliminar Producto" << std::endl;
    std::cout << "8. Guardar Inventario" << std::endl;
    std::cout << "9. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
      inventario.mostrarInventario();
      break;
    case 2:
      std::cout << "Ingrese codigo o nombre del producto: ";
      std::cin.ignore();
      std::getline(std::cin, nombre);
      inventario.buscarProducto(nombre);
      break;
    case 3:
      std::cout << "Ingrese codigo del producto a vender: ";
      std::cin >> codigo;
      std::cout << "Ingrese cantidad a vender: ";
      std::cin >> cantidad;
      inventario.venderProducto(codigo, cantidad);
      break;
    case 4:
      std::cout << "Ingrese codigo del producto a comprar: ";
      std::cin >> codigo;
      std::cout << "Ingrese cantidad a comprar: ";
      std::cin >> cantidad;
      inventario.comprarProducto(codigo, cantidad);
      break;
    case 5:
      inventario.agregarProducto();
      break;
    case 6:
      std::cout << "Ingrese codigo del producto a editar: ";
      std::cin >> codigo;
      inventario.editarProducto(codigo);
      break;
    case 7:
      std::cout << "Ingrese codigo del producto a eliminar: ";
      std::cin >> codigo;
      inventario.eliminarProducto(codigo);
      break;
    case 8:
      inventario.guardarEnJSON("productos.json");
      break;
    case 9:
      std::cout << "Saliendo del sistema. Hasta luego!" << std::endl;
      ejecutando = false;
      break;
    }
  }
    return 0;
}