#pragma once

class Menu
{
    public:
        Menu();
        void menuPrincipal();
        void areaVentas();
        void areaCompras();
        void areaAdministrativa();
        void areaInventario();

    private:
        void menuClientes();
        void menuEmpleados();
        void menuProveedores();
};
