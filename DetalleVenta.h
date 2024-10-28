// DetalleVenta.h
#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H

#include <iostream>
using namespace std;

class DetalleVenta {
    private:
    int _idVenta;
    int _idProducto;
    int _idFactura;
    int _cantidad;
    float _precioUnitario;

    public:
    // Constructor
    DetalleVenta(int idVenta, int idProducto, int idFactura, int cantidad, float precioUnit)
        : _idVenta(idVenta), _idProducto(idProducto), _idFactura(idFactura), _cantidad(cantidad), _precioUnit(precioUnit) {}

    // Getters
    int getIdVenta()        { return _idVenta;}
    int getIdProducto()     { return _idProducto;}
    int getIdFactura()      { return _idFactura;}
    int getCantidad()       { return _cantidad;}
    float getPrecioUnit()   { return _precioUnit;}

    // Setters
    void setIdVenta(int idVenta)               { _idVenta = idVenta; }
    void setIdProducto(int idProducto)         { _idProducto=idProducto;}
    void setIdFactura(int idFactura)           { _idFactura=idFactura;}
    void setCantidad(int cantidad)             { _cantidad=cantidad;}
    void setPrecioUnit(float precioUnitario)   { _precioUnit=precioUnitario;}
};



#endif // DETALLEVENTA_H
