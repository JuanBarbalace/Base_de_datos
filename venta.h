#ifndef VENTA_H
#define VENTA_H

#include <string>
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
    Venta(int idV, int idC, int idE, Fecha fecha, float total);

    // Getters
    int getIdVenta() const;
    int getIdCliente() const;
    int getIdEmpleado() const;
    Fecha getFecha() const;
    float getTotal() const;

    // Setters
    void setIdVenta(int idVenta);
    void setIdCliente(int idCliente);
    void setIdEmpleado(int idEmpleado);
    void setFecha(Fecha fecha);
    void setTotal(float total);

    // Método para calcular el total de ventas por mes
    static float totalVentasXMes(Venta* ventas, int numVentas, int mes, int anio);
};

#endif // VENTA_H
