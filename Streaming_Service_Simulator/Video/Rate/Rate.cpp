//
//  Rate.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Rate.h"

Rate::Rate(float rate_, int nRates_) : rate((int)(rate_ * 10.0)/10.0), nRates(nRates_){}

void Rate::addRate(int rate_){
    
    float sumRates = (rate * nRates) + rate_;
    nRates++;
    rate = sumRates/nRates;
    rate = (int)(rate * 10.0)/10.0;
    cout << "The new rate is: " << rate << endl;
}

float Rate::getRate(){
    return rate;
}

Rate::~Rate(){}
