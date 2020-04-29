//
// Created by Nate on 29-Apr-20.
//
#include <iostream>
#include "sqlite3.h"
#include "sqlForShows.h"
#include <string>

static int callbackAdd(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i < argc; i++) {
        std::cerr << azColName[i] << argv[i] << argv[i] << "NULL";
    }
    std::cout << std::endl;
    return 0;
}

void addShow(Show workingShow){
    // Pointer to SQLite connection
    sqlite3 *db;

    // Save any error messages
    char *zErrMsg = 0;

    // Save the result of opening the file
    int rc;

    // Save any SQL
    std::string sql;

    // Save the result of opening the file
    rc = sqlite3_open("shows.db", &db);

    if( rc ){
        // Show an error message
        std::cout << "DB Error: " << sqlite3_errmsg(db) << std::endl;
        // Close the connection
        sqlite3_close(db);
        // Return an error
    }

    // Save SQL to create a table
    sql = "insert into shows values('"
       + workingShow.getTitle() + "', "
       + std::to_string(workingShow.getWatched()) + ", "
       + std::to_string(workingShow.getEpisodes()) + ", "
       + std::to_string(workingShow.getRating()) + "); ";
    std::cout << sql;

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callbackAdd, 0, &zErrMsg);

    // Close the SQL connection
    sqlite3_close(db);

}
