//
//  Rate.h
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "../Commons.h"

#pragma once

class Rate{
    
protected:
    int nRates;
    float rate;

public:
    Rate() = default;
    Rate(float rate_, int nRates_);
    
    virtual void addRate(int rate_);
    float getRate();
    
    virtual ~Rate();
};
