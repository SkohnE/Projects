//
//  Movie.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "../Commons.h"
#include "../RatableVideo.h"

#pragma once

class Movie : public RatableVideo{
    
protected:
    string director;
    string genre;
    
public:
    Movie()=default;
    Movie(string ID_, string name_, int duration_, float rate_, int nRates_, string genre_, string director_);
    
    void printInfo();
    void printVideo();
    string getTypeOfVideo();
    
    string getDirector();
    string getgenre();
    
    ~Movie();
};

