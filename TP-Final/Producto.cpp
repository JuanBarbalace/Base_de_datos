#include "Producto.h"
#include <cstring>
#include <iostream>

using namespace std;

Producto::Producto()
{
    _idProducto = 0;
    strcpy(_nombre, "");
    strcpy(_categoria, "");
    strcpy(_descripcion, "");
    _precioCompra = 0.0f;
    _precioVenta = 0.0f;
    _stock = 0;
    _stockMinimo = 0;
    _stockMaximo = 0;
}

int Producto::getIdProducto() const
{
    return _idProducto;
}

const char* Producto::getNombre() const
{
    return _nombre;
}

const char* Producto::getCategoria() const
{
    return _categoria;
}

const char* Producto::getDescripcion() const
{
    return _descripcion;
}

float Producto::getPrecioCompra() const
{
    return _precioCompra;
}

float Producto::getPrecioVenta() const
{
    return _precioVenta;
}

int Producto::getStock() const
{
    return _stock;
}

int Producto::getStockMinimo() const
{
    return _stockMinimo;
}

int Producto::getStockMaximo() const
{
    return _stockMaximo;
}

void Producto::setIdProducto(int idProducto)
{
    _idProducto = idProducto;
}

void Producto::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}

void Producto::setCategoria(const char* categoria)
{
    strcpy(_categoria, categoria);
}

void Producto::setDescripcion(const char* descripcion)
{
    strcpy(_descripcion, descripcion);
}

void Producto::setPrecioCompra(float precioCompra)
{
    _precioCompra = precioCompra;
}

void Producto::setPrecioVenta(float precioVenta)
{
    _precioVenta = precioVenta;
}

void Producto::setStock(int stock)
{
    _stock = stock;
}

void Producto::setStockMinimo(int stockMinimo)
{
    _stockMinimo = stockMinimo;
}

void Producto::setStockMaximo(int stockMaximo)
{
    _stockMaximo = stockMaximo;
}

void Producto::cargar()
{
    cout << "Ingrese el ID del Producto: ";
    cin >> _idProducto;

    cout << "Ingrese el Nombre: ";
    cin.ignore();
    cin.getline(_nombre, sizeof(_nombre));

    cout << "Ingrese la Categoria: ";
    cin.getline(_categoria, sizeof(_categoria));

    cout << "Ingrese la Descripcion: ";
    cin.getline(_descripcion, sizeof(_descripcion));

    cout << "Ingrese el Precio de Compra: ";
    cin >> _precioCompra;

    cout << "Ingrese el Precio de Venta: ";
    cin >> _precioVenta;

    cout << "Ingrese el Stock: ";
    cin >> _stock;

    cout << "Ingrese el Stock Minimo: ";
    cin >> _stockMinimo;

    cout << "Ingrese el Stock Maximo: ";
    cin >> _stockMaximo;

    system("cls");
    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl;
    system("pause");
    system("cls");
}

void Producto::mostrar()
{
    cout << "---------------------------------" << endl;
    cout << "ID del Producto: " << _idProducto << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Categoria: " << _categoria << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Precio de Compra: " << _precioCompra << endl;
    cout << "Precio de Venta: " << _precioVenta << endl;
    cout << "Stock: " << _stock << endl;
    cout << "Stock Minimo: " << _stockMinimo << endl;
    cout << "Stock Maximo: " << _stockMaximo << endl;
    cout << "---------------------------------" << endl;
}
