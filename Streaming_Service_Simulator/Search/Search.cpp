//
//  Search.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Search.h"

void Search::findByName(string name_){
    cout << "buscar por nombre con: " << name_ << endl;
}

void Search::findByID(string ID_){
    cout << "buscar por ID con: " << ID_ << endl;
}

void Search::findByRate(float rate_){
    cout << "buscar mayor de " << rate_ << " rate \n";
}

