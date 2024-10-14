#ifndef SURTIDOR_H
#define SURTIDOR_H

#include "Transaccion.h"

class Surtidor {
private:
    int id;
    string modelo;
    Transaccion* transacciones[100]; // Máximo 100 transacciones
    int contadorTransacciones; // Lleva cuenta de las transacciones realizadas

public:
    Surtidor(int _id, string _modelo);
    bool venderCombustible(Transaccion* nuevaTransaccion);
    void mostrarTransacciones() const;
    int obtenerID() const { return id; }
};

#endif // SURTIDOR_H
