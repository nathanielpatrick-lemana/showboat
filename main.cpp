#include <iostream>
#include <fstream>
#include <string>
#include "sqlite3.h"
#include "showData.h"
#include "sqlForShows.h"

char addOrMod;

/*
void addShow();
void printShowDetails(std::string fileTitle);
void createNewEntry(Show workingShow);
void updateExistingEntry(Show workingShow);
*/

int main() {
    std::cout << "Welcome to Showboat.\n";
    Show newShow("test2", 15, 26, 5.0);
    addShow(newShow);

}

/*
void addShow(){
    std::cin.ignore();
    std::string newShowTitle;
    int newTotalEpisodes;
    std::cout << "Please enter in the show's title: \n";
    std::getline(std::cin, newShowTitle);
    std::cout << "Please enter in the number of episodes in the show (enter 0 for a movie or play):\n";
    std::cin >> newTotalEpisodes;
    Show newShow(newShowTitle, 0, newTotalEpisodes, 0, "null");
    createNewEntry(newShow);
}

void printShowDetails(std::string fileTitle){
    std::ifstream currentShow;
    currentShow.open("shows/" + fileTitle + ".txt");
    std::cout << std::ifstream("shows/" + fileTitle + ".txt").rdbuf();
}

void createNewEntry(Show workingShow) {

}

void updateExistingEntry(Show updatedShow) {
    std::string showTitle = updatedShow.getTitle();
    int showEpisodes = updatedShow.getEpisodes();
    std::ofstream currentShow;
    currentShow.open("shows/" + showTitle + ".txt");
    currentShow << "Show title: " << showTitle << "\n"
        << "Number of episodes: " << showEpisodes << "\n"
        << "Number of episodes watched so far: " << updatedShow.getWatched() << "\n"
        << "User rating (out of 10): " << updatedShow.getRating() << "\n";
    currentShow.close();
}
*/