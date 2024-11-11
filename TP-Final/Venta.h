#pragma once
#include "Fecha.h"

class Venta
{
    public:
        Venta();

        int getIdVenta() const;
        int getIdCliente() const;
        int getIdEmpleado() const;
        float getTotal() const;
        Fecha getFechaVenta() const;

        void setIdVenta(const int idVenta);
        void setIdCliente(const int IdCliente);
        void setIdEmpleado(const int IdEmpleado);
        void setTotal(const float total);
        void setFechaVenta(const Fecha& fechaVenta);

        void cargar(int idVenta);
        void mostrar();

    private:
        int _idVenta;
        int _idCliente;
        int _idEmpleado;
        float _total;
        Fecha _fechaVenta;
};
