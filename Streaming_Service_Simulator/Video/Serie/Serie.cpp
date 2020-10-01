//
//  Serie.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Serie.h"

Serie::Serie(string ID_, string name_, float rate_, int nRates_, string genre_):RatableVideo(ID_, name_, 0, rate_, nRates_), genre(genre_){}

void Serie::addSeason(string name_){
    duration++;
    int number_ = (int)seasons.size() + 1;
    seasons.push_back(new Season(number_, name_));
}

void Serie::printInfo(){
    cout << endl;
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Genre: " << genre << endl;
    cout << "Duration: " << duration << "Seasons \n";
    cout << "Rate: " << rate << endl;
    printEpisodes();
    cout << endl;
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";
}

void Serie::printVideo(){
    cout << endl;
    cout << "Nombre: " << name << " Rate: " << rate << endl;
    cout << endl;
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";
}

void Serie::printEpisodes(){
    
    for(vector<Season*>::iterator it = seasons.begin(); it != seasons.end(); it++){
        (*it)->printSeason();
    }
}

string Serie::getTypeOfVideo(){
    return "Serie";
}

string Serie::getGenre(){
    return genre;
}
Season* Serie::getSeason(int number_){
    number_--;
    if ((number_ > seasons.size()) || number_ < 0){
        number_ = (int)seasons.size() - 1;
    }
    return seasons[number_];
}

Serie::~Serie(){
    for(vector<Season*>::iterator it = seasons.begin(); it != seasons.end(); it++)
    {
        delete *it;
    }
}
