#ifndef ESTACIONDESERVICIO_H
#define ESTACIONDESERVICIO_H

#include "Surtidor.h"
#include "Tanque.h"

class EstacionDeServicio {
private:
    int id;
    string nombre;
    string ubicacion;
    Surtidor* surtidores[12]; // Máximo 12 surtidores
    int numSurtidores;
    Tanque* tanque;

public:
    EstacionDeServicio(int _id, string _nombre, string _ubicacion, Tanque* _tanque);
    void agregarSurtidor(Surtidor* nuevoSurtidor);
    void mostrarSurtidores() const;
    bool verificarFugas() const;

    // Agrega este getter para el ID
    int getId() const;
};

#endif // ESTACIONDESERVICIO_H
