#pragma once
#include "Fecha.h"

class Compra
{
    public:
        Compra();

        int getIdCompra() const;
        int getIdProveedor() const;
        float getTotal() const;
        Fecha getFechaCompra() const;

        void setIdCompra(const int idCompra);
        void setIdProveedor(const int idProveedor);
        void setTotal(const float total);
        void setFechaCompra(const Fecha& fechaCompra);

        void cargar(int idCompra);
        void mostrar();

    private:
        int _idCompra;
        int _idProveedor;
        float _total;
        Fecha _fechaCompra;
};
