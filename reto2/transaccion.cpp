#include "Transaccion.h"
#include <iostream>

Transaccion::Transaccion(int _id, string _fecha, double _litros, CategoriaCombustible _categoria, double _monto)
    : id(_id), fecha(_fecha), litros(_litros), categoria(_categoria), monto(_monto) {}

void Transaccion::mostrarTransaccion() const {
    cout << "ID: " << id << ", Fecha: " << fecha
         << ", Litros: " << litros << ", Categoria: " << categoria
         << ", Monto: $" << monto << endl;
}
