//
// Created by Nate on 22-Apr-20.
//

#ifndef SHOWBOAT_SHOWDATA_H
#define SHOWBOAT_SHOWDATA_H
#include <string>

class Show{
protected:
    std::string showName;
    int episodesWatched;
    int episodesTotal;
    int showRating;
    std::string showGenre;
public:
    Show(std::string showTitle = "null", int episodesWatched = 0, int episodesTotal = 0, int showRating = 0, std::string showGenre = "null");
    void setTitle(std::string newTitle);
    std::string getTitle();
    void setWatched(int newWatched);
    int getWatched();
    void setEpisodes(int newEpisodes);
    int getEpisodes();
    void setRating(int newRating);
    int getRating();
    void setGenre(std::string newGenre);
    std::string getGenre();

};


#endif //SHOWBOAT_SHOWDATA_H
