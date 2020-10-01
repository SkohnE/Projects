//
//  Search.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "../Video/Commons.h"

#pragma once
class Search{
    
public:
    virtual void findByName(string name_);
    virtual void findByID(string ID_);
    virtual void findByRate(float rate_);
    
};
