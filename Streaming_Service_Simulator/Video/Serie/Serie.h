//
//  Serie.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "../Commons.h"
#include "../RatableVideo.h"
#include "Season.h"

#pragma once

class Serie: public RatableVideo{
    
protected:
    string genre;
    vector<Season*> seasons;
    
public:
    Serie() = default;
    Serie(string ID_, string name_, float rate_, int nRates_, string genre_);
    
    void addSeason(string name_);
    virtual void printInfo();
    void printVideo();
    void printEpisodes();
    string getTypeOfVideo();
    string getGenre();
    Season* getSeason(int number_);
    ~Serie();
};
