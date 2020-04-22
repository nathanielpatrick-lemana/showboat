#include <iostream>
#include <fstream>
#include <string>
#include "showData.h"

char addOrMod;

void addShow();
void printShowDetails(std::string fileTitle);
void createNewEntry(Show workingShow);
void updateExistingEntry(Show workingShow);

int main() {
    std::cout << "Welcome to Showboat.\n";
    std::cout << "Would you like to:\n[A]dd a show\nor\n[M]odify an existing one?\n";
    std::cin >> addOrMod;
    switch(addOrMod){
        case 'a':
        case 'A':
            addShow();
            break;
        case 'm':
        case 'M':
            std::cin.ignore();
            std::string file;
            std::cout << "Please select a show to modify: \n";
            char command[50] = "dir shows /B";
            system(command);
            std::getline(std::cin, file);
            printShowDetails(file);
            //modifyExistingShow(file);
            break;
        //default:
            std::cout << "Invalid operation, aborting! \n";
            break;
    }
    return 0;
}

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

void createNewEntry(Show workingShow){

}


void createNewEntry(Show workingShow) {
    std::string showTitle = workingShow.getTitle();
    int showEpisodes = workingShow.getEpisodes();
    std::ofstream currentShow;
    currentShow.open("shows/" + showTitle + ".txt");
    currentShow << "Show title: " << showTitle << "\n"
        << "Number of episodes: " << showEpisodes << "\n"
        << "Number of episodes watched so far: " << 0 << "\n"
        << "User rating (out of 10): " << "No rating yet" << "\n";
    currentShow.close();
}

void updateExistingEntry(Show workingShow) {
    std::string showTitle = workingShow.getTitle();
    int showEpisodes = workingShow.getEpisodes();
    std::ofstream currentShow;
    currentShow.open("shows/" + showTitle + ".txt");
    currentShow << "Show title: " << showTitle << "\n"
        << "Number of episodes: " << showEpisodes << "\n"
        << "Number of episodes watched so far: " << workingShow.getWatched() << "\n"
        << "User rating (out of 10): " << workingShow.getRating() << "\n";
    currentShow.close();
}
