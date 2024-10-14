#ifndef TANQUE_H
#define TANQUE_H

#include "Transaccion.h"

class Tanque {
private:
    double capacidadOriginal[3]; // Para Regular, Premium, EcoExtra
    double combustibleAlmacenado[3];

public:
    Tanque(double regular, double premium, double ecoExtra);
    double obtenerCombustibleAlmacenado(CategoriaCombustible categoria) const;
    void extraerCombustible(CategoriaCombustible categoria, double cantidad);
    bool verificarFuga() const;
};

#endif // TANQUE_H
