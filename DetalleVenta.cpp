#include "DetalleVenta.h"

// Constructor
DetalleVenta::DetalleVenta(int idVenta, int idProducto, int idFactura, int cantidad, float precioUnit, Fecha fecha)
    : _idVenta(idVenta), _idProducto(idProducto), _idFactura(idFactura), _cantidad(cantidad), _precioUnitario(precioUnit), _fecha(fecha) {}

// Getters
int DetalleVenta::getIdVenta() const { return _idVenta; }
int DetalleVenta::getIdProducto() const { return _idProducto; }
int DetalleVenta::getIdFactura() const { return _idFactura; }
int DetalleVenta::getCantidad() const { return _cantidad; }
float DetalleVenta::getPrecioUnit() const { return _precioUnitario; }
Fecha DetalleVenta::getFecha() const { return _fecha; }

// Setters
void DetalleVenta::setIdVenta(int idVenta) { _idVenta = idVenta; }
void DetalleVenta::setIdProducto(int idProducto) { _idProducto = idProducto; }
void DetalleVenta::setIdFactura(int idFactura) { _idFactura = idFactura; }
void DetalleVenta::setCantidad(int cantidad) { _cantidad = cantidad; }
void DetalleVenta::setPrecioUnit(float precioUnitario) { _precioUnitario = precioUnitario; }
void DetalleVenta::setFecha(Fecha fecha) { _fecha = fecha; }

