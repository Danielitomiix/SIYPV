📘 README.md — SIYPV071125
Sistema Integral de Inventario, Punto de Venta y Gasolinera
Proyecto final — Programación Orientada a Objetos • 2025

Autor: Daniel Vargas
Lenguaje: C++
Paradigma: Programación Orientada a Objetos (POO)
Patrones de diseño: Strategy, Facade, Observer, Singleton

🔎 Descripción general del proyecto

Este proyecto implementa un sistema tipo Costco, integrando inventario, carrito de compras, módulo de gasolinera, métodos de pago, generación de tickets y facturación electrónica simulada.

Es la evolución del sistema desarrollado en el segundo parcial, incorporando lógica avanzada, arquitectura modular y patrones de diseño profesionales.

🧩 Características principales
🟦 Inventario

Carga y guardado desde archivo JSON

Agregar, editar, eliminar y buscar productos

Control de stock

Notificaciones de bajo inventario (Observer)

🛒 Carrito de compras

El usuario puede agregar múltiples productos

Se calcula subtotal por producto y subtotal general

⛽ Módulo de gasolinera

Registro de litros y tipo de combustible

Precios fijos por litro

Validación de monto y litros

Se integra al ticket final

💳 Métodos de pago (Strategy Pattern)

Implementación de estrategias:

Pago en efectivo

Pago con tarjeta de crédito

Pago con tarjeta de débito

Esto permite cambiar la forma de pago dinámicamente sin alterar el código del sistema principal.

🧾 Ticket final

Generación de ticket.txt que incluye:

Fecha y cajero

Productos comprados

Subtotal tienda

Subtotal gasolina

IVA

Total final

Método de pago utilizado

📄 Factura electrónica simulada

Genera factura.txt incluyendo:

Datos del comercio

Nombre del cliente

RFC del cliente

Correo del cliente

Detalle de productos y gasolina

Totales e IVA

Además simula el envío de factura por correo mediante salida en consola.

🛠️ Patrones de diseño utilizados
🔹 Strategy

Para manejar diferentes tipos de pago sin modificar la lógica del sistema.

🔹 Observer

Genera alertas cuando el stock de un producto es bajo.

🔹 Facade

Simplifica el flujo completo de compra, pago y facturación.

🔹 Singleton (si aplica en tu estructura final)

Uso opcional para gestionar control central del sistema.

📁 Estructura del proyecto
/include (Archivos .h)
│── AlertaStock.h
│── Bebida.h
│── FabricaProducto.h
│── Factura.h
│── Inventario.h
│── Observer.h
│── PagoStrategy.h
│── PagoCredito.h
│── PagoDebito.h
│── PagoEfectivo.h
│── Prerequisitos.h
│── Producto.h
│── ProductoBase.h
│── Medicamento.h
│── Snack.h
│── json.hpp

/src (Archivos .cpp)
│── main.cpp
│── Inventario.cpp
│── Factura.cpp
│── PagoEfectivo.cpp
│── PagoDebito.cpp
│── PagoCredito.cpp

/data (Archivos generados o externos)
│── productos.json
│── ticket.txt
│── factura.txt
│── historial.txt
Los archivos .txt y .json NO deben estar como archivos de código dentro del proyecto (solo en carpeta).

▶️ Cómo compilar y ejecutar

Abrir la solución en Visual Studio

Compilar con Ctrl + Shift + B

Ejecutar con Ctrl + F5

Navegar por el menú interactivo

🎯 Objetivo académico del proyecto

Este proyecto demuestra dominio en:

Encapsulamiento

Herencia

Polimorfismo

Manejo de archivos

Modularidad

Aplicación de patrones de diseño

Integración de múltiples módulos en un mismo sistema

Flujo realista de compra tipo Costco (tienda + gasolinera)

📝 Notas finales

El proyecto cumple con todos los requisitos del parcial final:

✔ Inventario funcional
✔ Carrito de compras
✔ Gasolinera integrada
✔ Métodos de pago con Strategy
✔ Ticket .txt
✔ Factura con datos del comercio y del cliente
✔ Simulación de envío por correo
✔ Arquitectura modular y profesional
