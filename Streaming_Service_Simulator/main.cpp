//
//  main.cpp
//  Proyecto Servicio de Streaming
//
//  Created by Santiago Kohn - A01029109 on 03/06/20.
//  Copyright © 2020 Santiago Kohn. All rights reserved.
//

#include "Video/Commons.h"
#include "Search/StreamingWithSearch.h"


int main() {
    
    StreamingWithSearch* Netflix = new StreamingWithSearch();
    
    Netflix->addSerie("S10", "13 Reasons Why", 7.5, 10, "Crime");
    Netflix->addMovie("M11", "Inception", 148, 8.8, 15, "Mystery", "Christopher Nolan");
    Netflix->addMovie("M22", "A.I. Artificial Intelligence", 146, 7.8, 8, "Ficcion", "Steven Spielberg");
    
    Serie* a = new Serie("S23", "Vikings", 8.9, 4, "History");
    a->addSeason("Ragnar to Aerl");
    a->getSeason(1)->addEpisode("E0100", "Rites of passage", 45);
    a->getSeason(1)->addEpisode("E1111", "Trial", 47);
    a->getSeason(1)->addEpisode("E2122", "Raid", 42);
    a->getSeason(1)->addEpisode("E3133", "All Change", 55);
    a->addSeason("King Ragnar");
    a->getSeason(2)->addEpisode("E4214", "Broter's War", 37);
    a->getSeason(2)->addEpisode("E5225", "Eye for an Eye", 57);
    a->getSeason(2)->addEpisode("E6236", "Boneless", 45);
    a->getSeason(2)->addEpisode("E7247", "The Lord's prayer", 63);
    a->addSeason("England");
    a->getSeason(3)->addEpisode("E8318", "Mercenary", 46);
    a->getSeason(3)->addEpisode("E9329", "Warrior's Fate", 51);
    a->getSeason(3)->addEpisode("E103310", "The Usurper", 61);
    a->getSeason(3)->addEpisode("E113411", "The Dead", 70);
    Netflix->addVideo(a);
    
    Movie* b = new Movie("M34", "Harry Potter and the Philosopher's Stone", 159, 7.6, 20, "Fantasy", "Chris Columbus");
    Netflix->addVideo(b);
    
    Serie* c = dynamic_cast<Serie*>(Netflix->findVideo("13 Reasons Why")); //usamos dynamic cast para poder usar las funciones de serie.
    c->addSeason("Reasons");
    c->getSeason(1)->addEpisode("E12111", "Tape 1", 54);
    c->getSeason(1)->addEpisode("E13122", "Tape 2", 51);
    c->getSeason(1)->addEpisode("E14133", "Tape 3", 57);
    c->addSeason("Photos");
    c->getSeason(2)->addEpisode("E15214", "Photo 1", 59);
    c->getSeason(2)->addEpisode("E16225", "Photo 2", 59);
    c->getSeason(2)->addEpisode("E17236", "Photo 3", 57);
    
    // Imprime la información resumida de las peliculas y series.
    
    cout << "Movies: \n";
    Netflix->printTypeVideo("Movie");
    cout << "Series: \n";
    Netflix->printTypeVideo("Serie");
    
    // Imprime toda la información de la Pelicula o serie buscada.
    Netflix->findByName("13 Reasons Why");
    Netflix->findByID("M22");
    Netflix->findByRate(7.9);
    
    Netflix->findVideo("Vikings")->addRate(10);
    
    delete Netflix;
    
    return 0;
}
