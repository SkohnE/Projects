//
//  Aerolinea.h
//  Proyecto Final
//
//  Created by Santiago Kohn on 29/11/19.
//  Copyright © 2019 Santiago Kohn. All rights reserved.
//

#ifndef Aerolinea_h
#define Aerolinea_h
#include "Vuelo.hpp"
using namespace std;
class Aerolinea
{
private:
    
    int cantidadVuelos = 0;
    vector<Vuelo> vuelos; //Creamos un vector de vuelo con ningun valor puesto.
    
public:
    
    Aerolinea()
    {
        cantidadVuelos = rand() % 25;
        vuelos.resize(cantidadVuelos);//Con el random escogemos la cantidad de vuelos y le agregamos la cantidad de datos que nos haya salido y se crean los objetos automaticamante.
    }
    int getCantidadVuelos() {return cantidadVuelos;}
    Vuelo getVuelo(int numVuelo) {return vuelos[numVuelo];}
};

#endif /* Aerolinea_h */
