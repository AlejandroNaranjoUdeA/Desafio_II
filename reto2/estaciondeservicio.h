#ifndef ESTACIONDESERVICIO_H
#define ESTACIONDESERVICIO_H

#include "Surtidor.h"
#include "Tanque.h"

class EstacionDeServicio {
private:
    int id;
    std::string nombre;
    std::string ubicacion;
    Surtidor** surtidores; // Puntero doble para un arreglo dinámico de surtidores
    int numSurtidores;
    int capacidadSurtidores; // Capacidad dinámica para surtidores
    Tanque* tanque;

public:
    EstacionDeServicio(int _id, std::string _nombre, std::string _ubicacion, Tanque* _tanque);
    ~EstacionDeServicio(); // Destructor para liberar memoria
    void agregarSurtidor(Surtidor* nuevoSurtidor);
    void mostrarSurtidores() const;
    bool verificarFugas() const;
    void simularVenta();
    int getId() const; // Getter para obtener ID
};

#endif // ESTACIONDESERVICIO_H
