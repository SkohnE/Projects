//
//  Episode.hpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "../Commons.h"
#include "../Video.h"

#pragma once

class Episode: public Video{
    
public:
    Episode()=default;
    Episode(string ID_, string name_, int duration_);
    
    void printInfo();
    void printVideo();
    string getTypeOfVideo();
    
    ~Episode();
};
