//Venta.h
#pragma once
#include <string>
#include <vector>
#include "Fecha.h"

using namespace std;

class Venta {
private:
    int _idVenta;
    int _idCliente;
    int _idEmpleado;
    Fecha _fecha;
    float _total;

public:
    // Constructor
    Venta(int idV, int idC, int idE, Fecha fecha, float total)
        : _idVenta(idV), _idCliente(idC), _idEmpleado(idE), _fecha(fecha), _total(total) {}

    // Getters
    int getIdVenta() const { return _idVenta; }
    int getIdCliente() const { return _idCliente; }
    int getIdEmpleado() const { return _idEmpleado; }
    Fecha getFecha() const { return _fecha; }
    float getTotal() const { return _total; }

    // Setters
    void setIdVenta(int idVenta) { _idVenta = idVenta; }
    void setIdCliente(int idCliente) { _idCliente = idCliente; }
    void setIdEmpleado(int idEmpleado) { _idEmpleado = idEmpleado; }
    void setFecha(Fecha fecha) { _fecha = fecha; }
    void setTotal(float total) { _total = total; }

    //calcular el total de ventas por mes
    static float totalVentasXMes(Venta* ventas, int numVentas, int mes, int anio) {
        float totalVentas = 0.0;
        for (int i = 0; i < numVentas; ++i) {
            if (ventas[i].getFecha().getMes() == mes && ventas[i].getFecha().getAnio() == anio) {
                totalVentas += ventas[i].getTotal();
            }
        }
        return totalVentas;
    }
};

#endif // VENTA_H
