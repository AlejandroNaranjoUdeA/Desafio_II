#include "Transaccion.h"
#include <iostream>

Transaccion::Transaccion(int _id, string _fecha, double _litros, CategoriaCombustible _categoria, double _monto)
    : id(_id), fecha(_fecha), litros(_litros), categoria(_categoria), monto(_monto) {}

void Transaccion::mostrarTransaccion() const {
    cout << "ID: " << id << ", Fecha: " << fecha
         << ", Litros: " << litros << ", Categoria: " << categoria
         << ", Monto: $" << monto << endl;
}

double Transaccion::getMonto() const {
    return monto; // Devuelve el monto de la transacción
}

CategoriaCombustible Transaccion::getCategoria() const {
    return categoria; // Devuelve la categoría de la transacción
}

double Transaccion::getLitros() const {
    return litros; // Devuelve los litros de la transacción
}
