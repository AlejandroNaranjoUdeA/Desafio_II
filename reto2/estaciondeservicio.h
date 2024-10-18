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

    double precioRegular;
    double precioPremium;
    double precioEcoExtra;

public:
    EstacionDeServicio(int _id, std::string _nombre, std::string _ubicacion, Tanque* _tanque);
    ~EstacionDeServicio(); // Destructor para liberar memoria
    void agregarSurtidor(Surtidor* nuevoSurtidor);
    void eliminarSurtidor(int idSurtidor); // Declaración del método para eliminar surtidor
    void mostrarSurtidores() const;
    bool verificarFugas() const;
    void simularVenta();
    double calcularVentasTotales() const; // Método para calcular ventas totales
    void fijarPrecios(double precioRegular, double precioPremium, double precioEcoExtra); // Fijar precios
    void reportarLitrosVendidos() const; // Reportar litros vendidos
    int getId() const; // Getter para obtener ID
};

#endif // ESTACIONDESERVICIO_H
