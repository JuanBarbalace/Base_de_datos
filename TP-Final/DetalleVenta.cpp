#include "DetalleVenta.h"
#include <iostream>

using namespace std;

DetalleVenta::DetalleVenta()
{
    _idVenta = 0;
    _idProducto = 0;
    _idFactura = 0;
    _cantidad = 0;
    _precioUnit = 0.0f;
}

int DetalleVenta::getIdVenta() const
{
    return _idVenta;
}

int DetalleVenta::getIdProducto() const
{
    return _idProducto;
}

int DetalleVenta::getIdFactura() const
{
    return _idFactura;
}

int DetalleVenta::getCantidad() const
{
    return _cantidad;
}

float DetalleVenta::getPrecioUnit() const
{
    return _precioUnit;
}

float DetalleVenta::getSubTotal() const
{
    return _cantidad * _precioUnit;
}

void DetalleVenta::setIdVenta(int idVenta)
{
    _idVenta = idVenta;
}

void DetalleVenta::setIdProducto(int idProducto)
{
    _idProducto = idProducto;
}

void DetalleVenta::setIdFactura(int idFactura)
{
    _idFactura = idFactura;
}

void DetalleVenta::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}

void DetalleVenta::setPrecioUnit(float precioUnit)
{
    _precioUnit = precioUnit;
}

void DetalleVenta::cargar(int idVenta, int idProducto, ArchivoProductos& archivoProductos)
{
    _idVenta = idVenta;
    _idProducto = idProducto;

    cout << "Ingrese el ID Factura: ";
    cin >> _idFactura;

    cout << "Ingrese la cantidad: ";
    cin >> _cantidad;

    Producto producto;

    int posicion;

    posicion = archivoProductos.buscarPorId(_idProducto);

    producto = archivoProductos.buscarProducto(posicion);

    _precioUnit = producto.getPrecioVenta();

    cout << "Precio unitario: " << _precioUnit;

    cout << "---------------------------" << endl << endl;

    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl << endl;
}

void DetalleVenta::mostrar()
{
    cout << "---------------------------" << endl;
    cout << "ID Venta: " << _idVenta << endl;
    cout << "ID Producto: " << _idProducto << endl;
    cout << "ID Factura: " << _idFactura << endl;
    cout << "Cantidad: " << _cantidad << endl;
    cout << "Precio Unitario: " << _precioUnit << endl;
    cout << "---------------------------" << endl << endl;
}
