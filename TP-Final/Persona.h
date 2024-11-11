#pragma once
#include "Fecha.h"

class Persona
{
    public:
        Persona();

        const char* getNombre() const;
        const char* getApellido() const;
        const char* getNroDoc() const;
        const char* getDireccion() const;
        const char* getTelefono() const;
        const char* getEmail() const;
        Fecha getFechaNac() const;

        void setNombre(const char* nombre);
        void setApellido(const char* apellido);
        void setNroDoc(const char* nroDoc);
        void setDireccion(const char* direccion);
        void setTelefono(const char* telefono);
        void setEmail(const char* email);
        void setFechaNac(const Fecha& fechaNac);

        void cargar();
        void mostrar();

    protected:
        char _nombre[20];
        char _apellido[20];
        char _nroDoc[15];
        char _direccion[50];
        char _telefono[20];
        char _email[20];
        Fecha _fechaNac;
};
