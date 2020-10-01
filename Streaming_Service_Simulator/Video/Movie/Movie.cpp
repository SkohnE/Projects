//
//  Movie.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Movie.h"

Movie::Movie(string ID_, string name_, int duration_, float rate_, int nRates_, string genre_, string director_): RatableVideo(ID_, name_, duration_, rate_, nRates_), genre(genre_), director(director_){}

void Movie::printInfo(){
    cout << endl;
    cout << "ID: " << ID << endl;
    cout << "name: " << name << endl;
    cout << "Director: " << director << endl;
    cout << "genre: " << genre << endl;
    cout << "duration: " << duration << "min \n";
    cout << "Rate: " << rate << endl;
    cout << endl;
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";
}

void Movie::printVideo(){
    cout << endl;
    cout << "Name: " << name << " Rate: " << rate << endl;
    cout << endl;
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";
}

string Movie::getTypeOfVideo(){
    return "Movie";
}

string Movie::getDirector(){
    return director;
}

string Movie::getgenre(){
    return genre;
}

Movie::~Movie(){}
