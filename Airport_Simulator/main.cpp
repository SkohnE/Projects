//
//  main.cpp
//  Proyecto Final
//
//  Created by Santiago Kohn on 29/11/19.
//  Copyright © 2019 Santiago Kohn. All rights reserved.
//  A01029109

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
 
#include "Aeropuerto.hpp"
using namespace std;

int main()
{
    srand((int)time(0)); //Cambio de seed.
    //Arreglo con los nombres que pueden aparecer en cada variable. En las clases solo tendremos "int"
    string destinos [20] = {"YXX","AUH","ADL","CAK","ALY","ALC","AMS","ATH","BCN","BSB","BUD","CCS","CUZ","DUB","EDI","FRA","GDL","LAP","LCY", "LAX"};
    
    string meses [12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    
    string terminales[2] = {"Terminal 1", "Terminal 2"};
    
    string aerolineas [25] = {"AEROMAR", "AeroMexico", "AIR CANADA", "AIRFRANCE", "Southwest", "AmericanAirlines", "Avianca", "BRITISH AIRWAYS", "Copa Airlines", "WINGO", "CUBANA", "Delta", "IBERIA", "Interjet", "KLM", "Lacsa", "LATAM AIRLINES", "Lufthansa", "TACA", "UNITED", "VIVA AEROBUS", "Volaris", "ANA", "ALASKA", "WEST JET",};
    //Creamos el objeta de clases aeropuerto que genera todo lo demas.
    Aeropuerto Aeropuerto("MEX");
    //Creamos los arreglos para llevar la cuenta de cada uno.
    int contadorMes [12] = {0};
    int contadorDestino[20] = {0};
    int contadorTerminales[2] = {0};
    //Se hace el conteo con un ciclo anidado para ia por todas las aerolineas y todos los vuelos de cada una de ellas.
    for (int aerolinea_=0; aerolinea_<25; aerolinea_++)
    {
        for (int vuelo_=0; vuelo_<Aeropuerto.getAerolinea(aerolinea_).getCantidadVuelos(); vuelo_++)
        {
            contadorMes[Aeropuerto.getAerolinea(aerolinea_).getVuelo(vuelo_).getMes()]++;
            contadorDestino[Aeropuerto.getAerolinea(aerolinea_).getVuelo(vuelo_).getDestino()]++;
            contadorTerminales[Aeropuerto.getAerolinea(aerolinea_).getVuelo(vuelo_).getTerminal()]++;
        }
    }
    // imprimimos todos los resultados de las sumas.
    for (int i=0; i<12; i++)
        cout << "En " << meses[i] << " hay " << contadorMes[i] << " vuelos" << endl;
    
    for (int i=0; i<20; i++)
        cout << "A " << destinos[i] << " hay " << contadorDestino[i] << " vuelos" << endl;
    
    for (int i=0; i<25; i++)
        cout << aerolineas[i] << " tiene " << Aeropuerto.getAerolinea(i).getCantidadVuelos() << " vuelos" << endl;
    
    for (int i=0; i<2; i++)
        cout << "En la " << terminales[i] << " hay " << contadorTerminales[i] << " vuelos" << endl;
    
    return 0;
    
}
