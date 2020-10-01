//
//  Season.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Season.h"

Season::Season(int number_, string name_): number(number_), name(name_){}

void Season::addEpisode(string ID_, string name_, int duration_){
    episodes.push_back(new Episode(ID_, name_, duration_));
}

int Season::getNEpisodes(){
    return (int)episodes.size();
}

void Season::printSeason(){
    cout << number << ". " << name << ": \n";

    for(vector<Episode*>::iterator it = episodes.begin(); it != episodes.end(); it++){
        (*it)->printVideo();
    }
}

string Season::getName(){
    return name;
}

Season::~Season(){
    for(vector<Episode*>::iterator it = episodes.begin(); it != episodes.end(); it++)
    {
        delete *it;
    }
}
