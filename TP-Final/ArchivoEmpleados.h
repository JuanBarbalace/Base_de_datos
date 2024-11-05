#pragma once
#include "Empleado.h"
#include <string>

class ArchivoEmpleados
{
    public:
        ArchivoEmpleados();

        bool agregarEmpleado(const Empleado &empleado);
        void mostrarEmpleado(int idEmpleado);
        void modificarEmpleado(int idEmpleado, const Empleado &empleadoAModificar);
        void listaEmpleados();
        int buscarPorId(int idEmpleado);

    private:
        std::string _fileName;

        Empleado buscarEmpleado(int posicion);
        bool modificar(int posicion, const Empleado &empleado);
        int getCantidadRegistros();
};
