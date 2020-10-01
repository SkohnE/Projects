//
//  StreamingWithSearch.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "StreamingWithSearch.h"

void StreamingWithSearch::findByName(string name_){
    bool find = true;
    for(vector<RatableVideo*>::iterator it = library.begin(); it != library.end(); it++){
        if ((*it)->getName() == name_){
            (*it)->printInfo();
            find = false;
        }
    }
    
    if (find){
        cout << "No Vidio with name: " << name_ << endl;
        cout << "==================================\n";
    }
    
}

void StreamingWithSearch::findByID(string ID_){
    bool find = true;
    for(vector<RatableVideo*>::iterator it = library.begin(); it != library.end(); it++){
        if ((*it)->getID() == ID_){
            (*it)->printInfo();
            find = false;
        }
    }
    
    if (find){
        cout << "No Vidio with ID: " << ID_ << endl;
        cout << "==================================\n";
    }

}

void StreamingWithSearch::findByRate(float rate_){
    bool find = true;
    for(vector<RatableVideo*>::iterator it = library.begin(); it != library.end(); it++){
        if ((*it)->getRate() >= rate_){
            (*it)->printInfo();
            find = false;
        }
    }
    
    if (find){
        cout << "No Vidio with better rate than: " << rate_ << endl;
        cout << "==================================\n";
    }

}

RatableVideo* StreamingWithSearch::findVideo(string title){
    for(vector<RatableVideo*>::iterator it = library.begin(); it != library.end(); it++){
        if ((*it)->getName() == title){
            return (*it);
        }
    }
    return 0;
}
