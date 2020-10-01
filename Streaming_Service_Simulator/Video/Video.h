//
//  Video.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Commons.h"

#pragma once

class Video{
    
protected:
    string ID;
    string name;
    int duration;
    
public:
    Video()=default;
    Video(string ID_, string name_, int duration_);
    
    virtual void printInfo() = 0;
    virtual void printVideo();
    virtual string getTypeOfVideo() = 0;
    
    string getID();
    string getName();
    int getDuration();
    
    virtual ~Video();
};
