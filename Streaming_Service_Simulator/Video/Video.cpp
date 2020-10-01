//
//  Video.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Video.h"

Video::Video(string ID_, string name_, int duration_) : ID(ID_), name(name_), duration(duration_) {}

string Video::getID(){
    return ID;
}

string Video::getName(){
    return name;
}

int Video::getDuration(){
    return duration;
}

void Video::printVideo(){
    cout << "Name: " << name << endl;
}

Video::~Video(){}
