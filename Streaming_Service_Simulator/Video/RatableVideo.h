//
//  RetableVideo.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Commons.h"
#include "Rate/Rate.h"
#include "Video.h"

#pragma once

class RatableVideo : public Video, public Rate{
    
public:
    RatableVideo() = default;
    RatableVideo(string ID_, string name_, int duration_, float rate_, int nRates_);
    
    void addRate(int rate_);
    void printInfo();
    void printVideo();
    
    ~RatableVideo();
};
