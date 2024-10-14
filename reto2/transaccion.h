#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
using namespace std;

enum CategoriaCombustible { Regular, Premium, EcoExtra };

class Transaccion {
private:
    int id;
    string fecha;
    double litros;
    CategoriaCombustible categoria;
    double monto;

public:
    Transaccion(int _id, string _fecha, double _litros, CategoriaCombustible _categoria, double _monto);
    void mostrarTransaccion() const;
};

#endif // TRANSACCION_H
