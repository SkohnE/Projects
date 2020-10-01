//
//  Vuelo.h
//  Proyecto Final
//
//  Created by Santiago Kohn on 29/11/19.
//  Copyright © 2019 Santiago Kohn. All rights reserved.
//

#ifndef Vuelo_h
#define Vuelo_h

class Vuelo
{
private:
    
    int mes, terminal, destino;
    
public:
    Vuelo()
    {
        //Hacemos los randoms para que todos los datos sean al azar 
        mes = rand() % 12;
        terminal = rand() % 2;
        destino = rand() % 20;
    }
    
    int getMes() {return mes;}
    int getTerminal() {return terminal;}
    int getDestino() {return destino;}
        
};
#endif /* Vuelo_h */
