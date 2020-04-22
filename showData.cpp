//
// Created by Nate on 22-Apr-20.
//

#include "showData.h"

Show :: Show(std::string title, int watched, int epTotal, int rate, std::string showGenre){
    showName = title;
    episodesWatched = watched;
    episodesTotal = epTotal;
    showRating = rate;
    showGenre = showGenre;
}

void Show::setTitle(std::string newTitle){
    showName = newTitle;
}
std::string Show::getTitle(){
    return showName;
}

void Show::setWatched(int newWatched){
    episodesWatched = newWatched;
}

int Show::getWatched(){
    return episodesWatched;
}

void Show::setEpisodes(int newEpisodes){
    episodesTotal = newEpisodes;
}

int Show::getEpisodes(){
    return episodesTotal;
}

void Show::setRating(int newRating){
    showRating = newRating;
}

int Show::getRating(){
    return showRating;
}

void Show::setGenre(std::string newGenre){
    showGenre = newGenre;
}

std::string Show::getGenre(){
    return showGenre;
}