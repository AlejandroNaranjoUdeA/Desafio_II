#ifndef SURTIDOR_H
#define SURTIDOR_H

#include "Transaccion.h"

class Surtidor {
private:
    int id;
    std::string modelo;
    Transaccion** transacciones; // Puntero a un arreglo dinámico de transacciones
    int contadorTransacciones; // Lleva cuenta de las transacciones realizadas
    int capacidadTransacciones; // Capacidad dinámica para transacciones

public:
    Surtidor(int _id, std::string _modelo);
    ~Surtidor(); // Destructor para liberar memoria
    bool venderCombustible(Transaccion* nuevaTransaccion);
    void mostrarTransacciones() const;
    double calcularVentasTotales() const; // Método para calcular ventas en el surtidor
    double calcularLitrosVendidos(CategoriaCombustible categoria) const; // Para cada categoría
    int obtenerID() const { return id; }
};

#endif // SURTIDOR_H
