//
// Created by Nate on 22-Apr-20.
//

#ifndef SHOWBOAT_SHOWCLASS_H
#define SHOWBOAT_SHOWCLASS_H
#include <string>
#include <iostream>
#include <cstdio>

class Show{
protected:
    std::string showName;
    int episodesWatched;
    int episodesTotal;
    double showRating;
public:
    Show(std::string showName, int episodesWatched, int episodesTotal, double showRating);
    void setTitle(std::string newTitle);
    std::string getTitle();
    void setWatched(int newWatched);
    int getWatched();
    void setEpisodes(int newEpisodes);
    int getEpisodes();
    void setRating(double newRating);
    double getRating();
    void setGenre(std::string newGenre);
    std::string getGenre();

};


#endif //SHOWBOAT_SHOWCLASS_H