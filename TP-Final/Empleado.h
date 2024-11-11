#pragma once
#include "Persona.h"

class Empleado : public Persona
{
    public:
        Empleado();
        int getIdEmpleado() const;
        Fecha getFechaContratacion() const;

        void setIdEmpleado(const int idEmpleado);
        void setFechaContratacion(const Fecha& fechaContratacion);

        void cargar();
        void mostrar();

    private:
        int _idEmpleado;
        Fecha _fechaContratacion;
};
