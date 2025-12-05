#include "Inventario.h"
#include "Factura.h"

/**
 * @brief Constructor por defecto del inventario.
 */
Inventario::Inventario() {}

/**
 * @brief Destructor por defecto.
 */
Inventario::~Inventario() {}

void 
Inventario::cargarDesdeJSON(const std::string& nombreArchivo) {
  std::ifstream archivo(nombreArchivo);
  if (!archivo.is_open())
  {
    std::cout << "No se pudo abrir el archivo: " << nombreArchivo << "\n";
    return;
  }

  json data;
  archivo >> data;
  archivo.close();

  productos.clear();

  for (const auto& item : data)
  {
    productos.emplace_back(
      item["codigo"],
      item["nombre"],
      item["precio"],
      item["cantidad"]
    );
  }

  std::cout << "Productos cargados correctamente.\n";
}

void 
Inventario::mostrarInventario() const {
  if (productos.empty())
  {
    std::cout << "Inventario vacio.\n";
    return;
  }

  std::cout << "\n=== INVENTARIO ACTUAL ===\n";
  for (const auto& p : productos)
    p.mostrarInfo();
}

void 
Inventario::comprarProducto(const std::string& codigo, int cantidad) {
  for (auto& producto : productos)
  {
    if (producto.getCodigo() == codigo)
    {
      producto.comprar(cantidad);
      registrarTransaccion("COMPRA", producto, cantidad);
      return;
    }
  }

  std::cout << "Producto con codigo " << codigo << " no encontrado.\n";
}

void 
Inventario::guardarEnJSON(const std::string& nombreArchivo) const {
  json data = json::array();

  for (const auto& producto : productos)
  {
    json item;
    item["codigo"] = producto.getCodigo();
    item["nombre"] = producto.getNombre();
    item["precio"] = producto.getPrecio();
    item["cantidad"] = producto.getCantidad();
    data.push_back(item);
  }

  std::ofstream archivo(nombreArchivo);
  if (!archivo.is_open())
  {
    std::cout << "Error al guardar archivo: " << nombreArchivo << "\n";
    return;
  }

  archivo << data << std::endl;
  archivo.close();

  std::cout << "Inventario guardado correctamente.\n";
}

void 
Inventario::agregarProducto() {
  std::string codigo, nombre, tipo;
  float precio;
  int cantidad;

  std::cout << "Codigo del nuevo producto: ";
  std::cin >> codigo;

  for (const auto& producto : productos)
  {
    if (producto.getCodigo() == codigo)
    {
      std::cout << "Ya existe un producto con ese codigo.\n";
      return;
    }
  }

  std::cin.ignore();
  std::cout << "Nombre del producto: ";
  std::getline(std::cin, nombre);

  std::cout << "Precio: ";
  std::cin >> precio;

  std::cout << "Cantidad: ";
  std::cin >> cantidad;

  std::cin.ignore();
  std::cout << "Tipo de producto (Medicamento/Bebida/Snack): ";
  std::getline(std::cin, tipo);

  ProductoBase* nuevo = FabricaProducto::crearProducto
               (tipo, codigo, nombre, precio, cantidad);
  if (!nuevo)
  {
    std::cout << "Tipo invalido. No se creo el producto.\n";
    return;
  }

  productos.emplace_back(codigo, nombre, precio, cantidad);

  delete nuevo;

  std::cout << "Producto agregado correctamente.\n";
}

void 
Inventario::editarProducto(const std::string& codigo){
  for (auto& producto : productos)
  {
    if (producto.getCodigo() == codigo)
    {
      std::string nombre;
      float precio;
      int cantidad;

      std::cin.ignore();
      std::cout << "Nuevo nombre (" << producto.getNombre() << "): ";
      std::getline(std::cin, nombre);

      std::cout << "Nuevo precio (" << producto.getPrecio() << "): ";
      std::cin >> precio;

      std::cout << "Nueva cantidad (" << producto.getCantidad() << "): ";
      std::cin >> cantidad;

      producto.setNombre(nombre);
      producto.setPrecio(precio);
      producto.setCantidad(cantidad);

      std::cout << "Producto actualizado correctamente.\n";
      return;
    }
  }

  std::cout << "Producto no encontrado.\n";
}

void 
Inventario::eliminarProducto(const std::string& codigo){
  for (auto it = productos.begin(); it != productos.end(); ++it)
  {
    if (it->getCodigo() == codigo)
    {
      productos.erase(it);
      std::cout << "Producto eliminado.\n";
      return;
    }
  }

  std::cout << "Producto no encontrado.\n";
}

void 
Inventario::buscarProducto(const std::string& clave) const {
  bool encontrado = false;

  for (const auto& producto : productos)
  {
    if (producto.getCodigo() == clave ||
      producto.getNombre().find(clave) != std::string::npos)
    {
      producto.mostrarInfo();
      encontrado = true;
    }
  }

  if (!encontrado)
    std::cout << "Producto no encontrado.\n";
}

void 
Inventario::agregarObservador(Observer* obs){
  observadores.push_back(obs);
}

void 
Inventario::notificarObservadores(const std::string& mensaje) const {
  for (auto& obs : observadores)
    obs->actualizar(mensaje);
}

void 
Inventario::registrarTransaccion(const std::string& tipo,
  const Producto& producto,
  int cantidad)
{
  FechaHora fecha;
  fecha.getFechaHora();

  std::ofstream archivo("historial.txt", std::ios::app);

  if (!archivo.is_open())
  {
    std::cout << "Error al abrir historial.\n";
    return;
  }

  archivo << "[" << fecha.toString() << "] "
    << tipo << " | "
    << "Código: " << producto.getCodigo()
    << " | Producto: " << producto.getNombre()
    << " | Cantidad: " << cantidad
    << " | Stock actual: " << producto.getCantidad()
    << "\n";

  archivo.close();
}

void
Inventario::agregarAlCarrito(const std::string& codigo, int cantidad){
  for (auto& p : productos)
  {
    if (p.getCodigo() == codigo)
    {
      if (p.getCantidad() < cantidad)
      {
        std::cout << "Stock insuficiente.\n";
        return;
      }

      p.vender(cantidad);

      carrito.emplace_back(p.getCodigo(), p.getNombre(), p.getPrecio(), cantidad);
      totalTienda += p.getPrecio() * cantidad;

      std::cout << "Producto agregado al carrito.\n";
      return;
    }
  }

  std::cout << "Producto no encontrado.\n";
}

void 
Inventario::registrarGasolina(TipoCombustible tipo, double litros){
  gasolinaPendiente = true;
  tipoGasolina = tipo;
  litrosGasolina = litros;

  switch (tipo)
  {
  case TipoCombustible::GasolinaMagna:
    precioPorLitroGasolina = 24.50;
    break;
  case TipoCombustible::GasolinaPremium:
    precioPorLitroGasolina = 26.70;
    break;
  case TipoCombustible::Diesel:
    precioPorLitroGasolina = 25.00;
    break;
  }

  totalGasolina = litrosGasolina * precioPorLitroGasolina;

  std::cout << "Gasolina registrada: $" << totalGasolina << "\n";
}

void 
Inventario::generarTicketFinal(PagoStrategy* metodoPago){
  if (!metodoPago)
  {
    std::cout << "Error: Método de pago inválido.\n";
    return;
  }

  double subtotalGeneral = totalTienda + totalGasolina;
  double iva = subtotalGeneral * 0.16;
  double totalFinal = subtotalGeneral + iva;

  if (!metodoPago->Pagar(totalFinal))
  {
    std::cout << "Pago rechazado.\n";
    return;
  }

  std::ofstream ticket("ticket.txt");
  FechaHora fecha;
  fecha.getFechaHora();

  ticket << "COSTCO – TICKET FINAL\n";
  ticket << "========================================\n";
  ticket << "Fecha: " << fecha.toString() << "\n";
  ticket << "Cajero: Daniel Vargas\n";
  ticket << "===== PRODUCTOS EN CARRITO =====\n";
  for (const auto& p : carrito)
  {
    ticket << p.getNombre()
      << " | Cant: " << p.getCantidad()
      << " | Precio: $" << p.getPrecio()
      << " | Subtotal: $" << p.getPrecio() * p.getCantidad()
      << "\n";
  }

  ticket << "\nSubtotal tienda: $" << totalTienda << "\n\n";

  if (gasolinaPendiente)
  {
    std::string tipo;
    switch (tipoGasolina)
    {
    case TipoCombustible::GasolinaMagna:   tipo = "Magna"; 
    break;
    case TipoCombustible::GasolinaPremium: tipo = "Premium"; 
    break;
    case TipoCombustible::Diesel:          tipo = "Diesel"; 
    break;
    }

    ticket << "===== GASOLINA =====\n";
    ticket << "Tipo: " << tipo << "\n";
    ticket << "Litros: " << litrosGasolina << "\n";
    ticket << "Precio/Litro: $" << precioPorLitroGasolina << "\n";
    ticket << "Subtotal gasolina: $" << totalGasolina << "\n";
  }

  ticket << "IVA (16%): $" << iva << "\n";
  ticket << "TOTAL FINAL: $" << totalFinal << "\n";
  ticket << "Método de pago: " << metodoPago->getNombreMetodo() << "\n";
  ticket << "========================================\n";
  ticket << "¡Gracias por su compra!\n";

  ticket.close();

  std::cout << "Ticket generado exitosamente.\n";

  /* 
  * Generar factura
  */
  char opcionFactura;
  std::cout << "¿Desea generar una factura? (s/n): ";
  std::cin >> opcionFactura;

  if (opcionFactura == 's' || opcionFactura == 'S')
  {
    std::string nombreCliente;
    std::string rfc;
    std::string correo;

    std::cin.ignore();
    std::cout << "Ingrese su nombre completo: ";
    std::getline(std::cin, nombreCliente);

    std::cout << "Ingrese su RFC: ";
    std::cin >> rfc;

    std::cout << "Ingrese su correo electrónico: ";
    std::cin >> correo;

    Factura factura;

    factura.generarFactura(
            nombreCliente,
            rfc, 
            correo, 
            carrito,
            totalTienda,
            totalGasolina,
            iva,
            totalFinal
    );
    factura.enviarFactura(correo);
  }

  // limpiar datos para siguiente compra
  carrito.clear();
  totalTienda = 0.0;
  gasolinaPendiente = false;
  litrosGasolina = 0.0;
  totalGasolina = 0.0;
}
