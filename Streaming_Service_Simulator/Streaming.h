//
//  Streaming.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Video/Commons.h"
#include "Video/RatableVideo.h"
#include "Video/Movie/Movie.h"
#include "Video/Serie/Serie.h"

#pragma once

class Streaming {
protected:
    vector<RatableVideo*> library;
    
public:
    Streaming() = default;
    
    void addVideo(RatableVideo* video_);
    void addMovie(string ID_, string name_, int duration_, float rate_, int nRates_, string genre_, string director_);
    void addSerie(string ID_, string name_, float rate_, int nRates_, string genre_);
    
    void printTypeVideo(string type);
    
    ~Streaming();
};
