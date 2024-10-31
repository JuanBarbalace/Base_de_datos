// DetalleVenta.h
#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H

#include <iostream>
#include "Fecha.h"

using namespace std;

class DetalleVenta {
private:
    int _idVenta;
    int _idProducto;
    int _idFactura;
    int _cantidad;
    float _precioUnitario;
    Fecha _fecha;

public:
    // Constructor
    DetalleVenta(int idVenta, int idProducto, int idFactura, int cantidad, float precioUnit, Fecha fecha)
        : _idVenta(idVenta), _idProducto(idProducto), _idFactura(idFactura), _cantidad(cantidad), _precioUnitario(precioUnit), _fecha(fecha) {}

    // Getters
    int getIdVenta() const { return _idVenta; }
    int getIdProducto() const { return _idProducto; }
    int getIdFactura() const { return _idFactura; }
    int getCantidad() const { return _cantidad; }
    float getPrecioUnit() const { return _precioUnitario; }
    Fecha getFecha() const { return _fecha; }

    // Setters
    void setIdVenta(int idVenta) { _idVenta = idVenta; }
    void setIdProducto(int idProducto) { _idProducto = idProducto; }
    void setIdFactura(int idFactura) { _idFactura = idFactura; }
    void setCantidad(int cantidad) { _cantidad = cantidad; }
    void setPrecioUnit(float precioUnitario) { _precioUnitario = precioUnitario; }
    void setFecha(Fecha fecha) { _fecha = fecha; }
};

#endif // DETALLEVENTA_H
