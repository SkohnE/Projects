//
//  Aeropuerto.h
//  Proyecto Final
//
//  Created by Santiago Kohn on 29/11/19.
//  Copyright © 2019 Santiago Kohn. All rights reserved.
//

#ifndef Aeropuerto_h
#define Aeropuerto_h
#include "Aerolinea.hpp"
using namespace std;

class Aeropuerto
{
private:
    
    string nombre;
    Aerolinea aerolineas[25];
    
public:
    
    Aeropuerto(string nombre_)
    {
        nombre = nombre_;
    }
    //Ponemos un get para cada variable para poderlas sacar del objeto creaado por que los datos estan en privado.
    string getNombre() {return nombre;}
    Aerolinea getAerolinea(int indice){ return aerolineas[indice];}
};
#endif /* Aeropuerto_h */

