#include <iostream>
#include <vector>
#include "Compra.h" // Incluir el encabezado de Compra
#include "Fecha.h"  // Incluir el encabezado de Fecha

int main() {
    // Crear algunas compras como ejemplo
    Fecha fecha1(15, 4, 2023);
    Fecha fecha2(20, 4, 2023);
    Compra compra1(1, 101, fecha1, 1500.75);
    Compra compra2(2, 102, fecha2, 2000.50);

    std::vector<Compra> compras = {compra1, compra2};

    // Mostrar detalles de las compras
    compra1.mostrarCompra();
    compra2.mostrarCompra();

    // Calcular el total de compras en abril de 2023
    float totalAbril = Compra::totalComprasXMes(compras, 4, 2023);
    std::cout << "Total de compras en abril de 2023: $" << totalAbril << std::endl;

    return 0;
}
