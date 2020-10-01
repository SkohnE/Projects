//
//  StreamingWithSearch.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "../Video/Commons.h"
#include "../Streaming.h"
#include "Search.h"

#pragma once

class StreamingWithSearch : public Streaming, public Search{
    
public:
    void findByName(string name_);
    void findByID(string ID_);
    void findByRate(float rate_);
    RatableVideo* findVideo(string title);
    
};
