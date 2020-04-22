#include <iostream>
#include <fstream>

char addShow;
std::string newShowTitle;
int newTotalEpisodes;


int main() {
    std::cout << "Welcome to Showboat.\n";
    std::cout << "Would you like to add a show?\n";
    std::cin >> addShow;
    switch(addShow){
        case 'y':
            break;
        case 'n':
            return 0;
    }

}
