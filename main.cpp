#include <iostream>
#include <fstream>
#include <sstream>
#include "showData.h"


char addOrMod;


void addShow();
void modifyExistingShow();
void writeToFile(Show workingShow);

int main() {
    std::cout << "Welcome to Showboat.\n";
    std::cout << "Would you like to [a]dd a show or [m]odify an existing one?\n";
    std::cin >> addOrMod;
    switch(addOrMod){
        case 'a':
            addShow();
            break;
        case 'm':
            //TODO: make this work
            //modifyExistingShow();
            return 0;
        default:
            std::cout << "Invalid operation, aborting!\n";
            break;
    }
    return 0;
}

void addShow(){
    std::string newShowTitle;
    int newTotalEpisodes;
    std::cout << "Please enter in the show's title\n";
    std::cin >> newShowTitle;
    std::cout << "Please enter in the number of episodes in the show (enter 0 for a movie or play):\n";
    std::cin >> newTotalEpisodes;
    Show newShow(newShowTitle, 0, newTotalEpisodes, 0, "null");
    writeToFile(newShow);
}

void writeToFile(Show workingShow){
    std::string fileTitle = Show::getTitle() + ".txt";
    std::ofstream currentShow;
    currentShow.open (fileTitle);
    currentShow << "Writing this to a file.\n";
    currentShow.close();
}

