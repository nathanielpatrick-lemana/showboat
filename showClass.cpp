//
// Created by Nate on 22-Apr-20.
//

#include "showClass.h"

Show :: Show(std::string title, int watched, int epTotal, double rate){
    showName = title;
    episodesWatched = watched;
    episodesTotal = epTotal;
    showRating = rate;
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

void Show::setRating(double newRating){
    showRating = newRating;
}

double Show::getRating(){
    return showRating;
}
