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
    DetalleVenta(int idVenta, int idProducto, int idFactura, int cantidad, float precioUnit, Fecha fecha);

    // Getters
    int getIdVenta() const;
    int getIdProducto() const;
    int getIdFactura() const;
    int getCantidad() const;
    float getPrecioUnit() const;
    Fecha getFecha() const;

    // Setters
    void setIdVenta(int idVenta);
    void setIdProducto(int idProducto);
    void setIdFactura(int idFactura);
    void setCantidad(int cantidad);
    void setPrecioUnit(float precioUnitario);
    void setFecha(Fecha fecha);
};

#endif // DETALLEVENTA_H
