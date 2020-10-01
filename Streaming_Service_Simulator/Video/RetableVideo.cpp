//
//  RetableVideo.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "RatableVideo.h"

RatableVideo::RatableVideo(string ID_, string name_, int duration_, float rate_, int nRates_) : Video(ID_, name_, duration_), Rate(rate_, nRates_) {}

void RatableVideo::addRate(int rate_){
    printVideo();
    float sumRates = (rate * nRates) + rate_;
    nRates++;
    rate = sumRates/nRates;
    rate = (int)(rate * 10.0)/10.0;
    cout << "The new rate is: " << rate << endl;
}

void RatableVideo::printInfo(){
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Duration: " << duration << endl;
    cout << "Rate: " << rate << endl;
}

void RatableVideo::printVideo(){
    cout << "Name: " << name << " rate: " << rate << endl;
}

RatableVideo::~RatableVideo(){}
