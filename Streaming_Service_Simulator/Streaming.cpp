//
//  Streaming.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Streaming.h"

void Streaming::addVideo(RatableVideo* video_){
    library.push_back(video_);
}

void Streaming::addMovie(string ID_, string name_, int duration_, float rate_, int nRates_, string genre_, string director_){
    library.push_back(new Movie(ID_, name_, duration_, rate_, nRates_, genre_, director_));
}

void Streaming::addSerie(string ID_, string name_, float rate_, int nRates_, string genre_){
    library.push_back(new Serie(ID_, name_, rate_, nRates_, genre_));
}

void Streaming::printTypeVideo(string type){
    for(vector<RatableVideo*>::iterator it = library.begin(); it != library.end(); it++)
    {
        if ((*it)->getTypeOfVideo() == type){
            (*it)->printVideo();
        }
    }
}

Streaming::~Streaming(){
    for(vector<RatableVideo*>::iterator it = library.begin(); it != library.end(); it++)
    {
        delete *it;
    }
}
