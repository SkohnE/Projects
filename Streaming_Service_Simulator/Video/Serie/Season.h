//
//  Season.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "../Commons.h"
#include "Episode.h"

#pragma once
class Season{
    
protected:
    int number;
    string name;
    vector<Episode*> episodes;

public:
    Season() = default;
    Season(int number_, string name_);
    
    void addEpisode(string ID_, string name_, int duration_);
    int getNEpisodes();
    void printSeason();
    string getName();
    
    ~Season();
    
};

