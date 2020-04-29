#include <iostream>
#include <fstream>
#include <string>
#include "sqlite3.h"
#include "showData.h"

char addOrMod;

/*
void addShow();
void printShowDetails(std::string fileTitle);
void createNewEntry(Show workingShow);
void updateExistingEntry(Show workingShow);
*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main() {
    std::cout << "Welcome to Showboat.\n";
    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc;
    const char *sql;
    rc = sqlite3_open("shows.db", &db);
    if(rc) {
        std::cerr << "Failed open database: " << sqlite3_errmsg(db)
                  << std::endl;
        return (0);
    }
    else {
        std::cerr << "Database successfully opened" << std::endl;
    }
    sql = "select * from shows;";
          //"values('Konosuba', 13, 7, 5); ";
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);
    if(rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cerr << "Records created successfully" << std::endl;
    }
    sqlite3_close(db);
    return 0;
}

static int callback(void *data, int argc, char **argv, char **azColName)
{
    fprintf(stderr, "\nCallback function call: ", &data);
    for(auto i = 0; i < argc; i++) {
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

/*
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i < argc; i++) {
        std::cerr << azColName[i] << argv[i] << argv[i] << "NULL";
    }
    std::cout << std::endl;
    return 0;
}
 */


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