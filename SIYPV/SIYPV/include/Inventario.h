#pragma once
#include "Prerequisitos.h"
#include "Producto.h"
#include "FabricaProducto.h"
#include "Observer.h"
#include "PagoStrategy.h"

/**
 * @class Inventario
 * @brief Gestiona productos, carrito de compras, gasolina y generación del ticket final.
 *
 * Esta clase integra:
 * - Inventario de productos (cargar, mostrar, buscar, comprar, editar, eliminar, guardar).
 * - Carrito de compras para acumular varios productos antes de pagar.
 * - Módulo de gasolinera con precio fijo por tipo de combustible.
 * - Sistema de notificaciones (Observer) para stock bajo.
 * - Generación de ticket final en archivo .txt con IVA y Strategy para el pago.
 */
class Inventario
{
public:

  /**
   * @brief Constructor por defecto.
   */
  Inventario();

  /**
   * @brief Destructor por defecto.
   */
  ~Inventario();

  // ====== MÓDULO INVENTARIO BASE (del parcial pasado) ======

  /**
   * @brief Carga los productos desde un archivo JSON.
   * @param nombreArchivo Ruta o nombre del archivo JSON.
   */
  void 
  cargarDesdeJSON(const std::string& nombreArchivo);

  /**
   * @brief Muestra todos los productos del inventario.
   */
  void 
  mostrarInventario() const;

  /**
   * @brief Compra (aumenta stock) de un producto específico.
   * @param codigo Código del producto.
   * @param cantidad Cantidad a agregar.
   */
  void 
  comprarProducto(const std::string& codigo, int cantidad);

  /**
   * @brief Guarda el inventario actual en un archivo JSON.
   * @param nombreArchivo Nombre del archivo destino.
   */
  void 
  guardarEnJSON(const std::string& nombreArchivo) const;

  /**
   * @brief Agrega un nuevo producto al inventario usando la fábrica.
   */
  void 
  agregarProducto();

  /**
   * @brief Edita los datos de un producto existente.
   * @param codigo Código del producto a editar.
   */
  void 
  editarProducto(const std::string& codigo);

  /**
   * @brief Elimina un producto del inventario.
   * @param codigo Código del producto a eliminar.
   */
  void 
  eliminarProducto(const std::string& codigo);

  /**
   * @brief Busca un producto por código o nombre parcial.
   * @param clave Código o parte del nombre del producto.
   */
  void 
  buscarProducto(const std::string& clave) const;

  /**
   * @brief Agrega un observador para recibir notificaciones del inventario.
   * @param obs Puntero al observador.
   */
  void 
  agregarObservador(Observer* obs);

  /**
   * @brief Notifica a todos los observadores con un mensaje.
   * @param mensaje Texto a enviar a los observadores.
   */
  void 
  notificarObservadores(const std::string& mensaje) const;

  /**
   * @brief Agrega un producto del inventario al carrito de compras.
   *
   * También descuenta el stock del inventario.
   *
   * @param codigo Código del producto.
   * @param cantidad Cantidad a agregar al carrito.
   */
  void 
  agregarAlCarrito(const std::string& codigo, int cantidad);

  /**
   * @brief Registra una carga de gasolina que se pagará al final.
   * @param tipo Tipo de combustible (Magna, Premium, Diesel).
   * @param litros Litros cargados.
   */
  void 
  registrarGasolina(TipoCombustible tipo, double litros);

  /**
   * @brief Genera el ticket final y procesa el pago con Strategy.
   *
   * Incluye:
   * - Productos del carrito.
   * - Gasolina (si existe).
   * - IVA (16%).
   * - Total final.
   * - Nombre del método de pago.
   *
   * @param metodoPago Estrategia de pago a utilizar.
   */
  void 
  generarTicketFinal(PagoStrategy* metodoPago);

private:
  // Inventario de productos
  std::vector<Producto> productos;
  std::vector<Observer*> observadores;

  // Carrito de compras
  std::vector<Producto> carrito;
  double totalTienda = 0.0;

  // Datos de gasolina
  bool gasolinaPendiente = false;
  TipoCombustible tipoGasolina;
  double litrosGasolina = 0.0;
  double precioPorLitroGasolina = 0.0;
  double totalGasolina = 0.0;

  /**
   * @brief Registra una transacción en el historial (COMPRA).
   *
   * @param tipo Tipo de transacción (por ejemplo, "COMPRA").
   * @param producto Producto afectado.
   * @param cantidad Cantidad involucrada.
   */
  void 
  registrarTransaccion(const std::string& tipo,
    const Producto& producto,
    int cantidad);
};