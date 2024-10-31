#include "Venta.h"

// Constructor
Venta::Venta(int idV, int idC, int idE, Fecha fecha, float total)
    : _idVenta(idV), _idCliente(idC), _idEmpleado(idE), _fecha(fecha), _total(total) {}

// Getters
int Venta::getIdVenta() const { return _idVenta; }
int Venta::getIdCliente() const { return _idCliente; }
int Venta::getIdEmpleado() const { return _idEmpleado; }
Fecha Venta::getFecha() const { return _fecha; }
float Venta::getTotal() const { return _total; }

// Setters
void Venta::setIdVenta(int idVenta) { _idVenta = idVenta; }
void Venta::setIdCliente(int idCliente) { _idCliente = idCliente; }
void Venta::setIdEmpleado(int idEmpleado) { _idEmpleado = idEmpleado; }
void Venta::setFecha(Fecha fecha) { _fecha = fecha; }
void Venta::setTotal(float total) { _total = total; }

// M‚todo para calcular el total de ventas por mes
float Venta::totalVentasXMes(Venta* ventas, int numVentas, int mes, int anio) {
    float totalVentas = 0.0;
    for (int i = 0; i < numVentas; ++i) {
        if (ventas[i].getFecha().getMes() == mes && ventas[i].getFecha().getAnio() == anio) {
            totalVentas += ventas[i].getTotal();
        }
    }
    return totalVentas;
}

