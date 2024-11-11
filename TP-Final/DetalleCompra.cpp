#include "DetalleCompra.h"
#include <iostream>

using namespace std;

DetalleCompra::DetalleCompra()
{
    _idCompra = 0;
    _idProducto = 0;
    _idFactura = 0;
    _cantidad = 0;
    _precioUnit = 0.0f;
}

int DetalleCompra::getIdCompra() const
{
    return _idCompra;
}

int DetalleCompra::getIdProducto() const
{
    return _idProducto;
}

int DetalleCompra::getIdFactura() const
{
    return _idFactura;
}

int DetalleCompra::getCantidad() const
{
    return _cantidad;
}

float DetalleCompra::getPrecioUnit() const
{
    return _precioUnit;
}

float DetalleCompra::getSubTotal() const
{
    return _cantidad * _precioUnit;
}

void DetalleCompra::setIdCompra(int idCompra)
{
    _idCompra = idCompra;
}

void DetalleCompra::setIdProducto(int idProducto)
{
    _idProducto = idProducto;
}

void DetalleCompra::setIdFactura(int idFactura)
{
    _idFactura = idFactura;
}

void DetalleCompra::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}

void DetalleCompra::setPrecioUnit(float precioUnit)
{
    _precioUnit = precioUnit;
}

void DetalleCompra::cargar(int idCompra, int idProducto)
{
    _idCompra = idCompra;
    _idProducto = idProducto;

    cout << "Ingrese el ID Factura: ";
    cin >> _idFactura;

    cout << "Ingrese la cantidad: ";
    cin >> _cantidad;

    cout << "Ingrese el precio unitario: ";
    cin >> _precioUnit;
    cout << "---------------------------" << endl << endl;

    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl << endl;
}

void DetalleCompra::mostrar()
{
    cout << "---------------------------" << endl;
    cout << "ID Compra: " << _idCompra << endl;
    cout << "ID Producto: " << _idProducto << endl;
    cout << "ID Factura: " << _idFactura << endl;
    cout << "Cantidad: " << _cantidad << endl;
    cout << "Precio Unitario: " << _precioUnit << endl;
    cout << "---------------------------" << endl << endl;
}
