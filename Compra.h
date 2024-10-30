#ifndef COMPRA_H
#define COMPRA_H
#include <iostream>
#include <string>
#include <vector>

class Compra

{   private:
    int idCompra;
    int idProveedor;
    Fecha fecha;
    float total;

    public:
        Compra();
        virtual ~Compra();
    protected:
};


#endif // COMPRA_H
