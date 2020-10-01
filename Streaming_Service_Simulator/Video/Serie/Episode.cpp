//
//  Episode.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Episode.h"

Episode::Episode(string ID_, string name_, int duration_): Video(ID_, name_, duration_){}

void Episode::printInfo(){
    cout << "ID: " << ID << endl;
    cout << "name: " << name << endl;
    cout << "duration: " << duration << endl;
}

void Episode::printVideo(){
    cout << "\t · ";
    cout << "Name: " << name << " " << duration << "min \n";
}

string Episode::getTypeOfVideo(){
    return "Episode";
}

Episode::~Episode(){}
