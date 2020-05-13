#include <iostream>
#include <cstdio>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

#include "Showboat.h"
#include "ui_ShowboatMainWindow.h"

QSqlDatabase mydb;

bool ShowboatMainWindow::connOpen(){ //Open a SQL connection
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("E:/Projects/QtStarter-master/shows.db");

    if(!mydb.open()){
        qDebug() << ("Failed to open the database. Does it exist or is the path correct?");
        return false;
    }
    else {
        qDebug() << ("Successfully opened database.");
        return true;
    }
}

void ShowboatMainWindow::connClose(){ //Close a SQL connection
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

void ShowboatMainWindow::loadShowList(){ //Load the show list from the titles of shows in the database

    QSqlQueryModel * modal=new QSqlQueryModel();
    connOpen();
    QSqlQuery* qry=new QSqlQuery(mydb);

    qry->prepare("select Title from shows;");

    qry->exec();
    modal->setQuery(*qry);
    showListUI->setModel(modal);
    connClose();
    qDebug() << (modal->rowCount());
}

void ShowboatMainWindow::addNewEntry(){  //Add a show or change a show with INSERT or REPLACE
    connOpen();
    QString title,watched,episodes,rating;
    title=showNameUI->text();
    watched=episodesWatchedUI->text();
    episodes=episodesTotalUI->text();
    rating=ratingUI->text();
    int watchedCompare = watched.toInt();
    int episodesCompare = episodes.toInt();
    if(watchedCompare > episodesCompare){
        QMessageBox::critical(this, tr("Showboat - Syntax Error"), tr("Cannot add a show with a greater amount of watched episodes than episodes total"));
    }
    else if (watchedCompare == 0) {
        QMessageBox::critical(this, tr("Showboat - Syntax Error"), tr("Cannot add a show where there are zero episodes to watch"));
    } else {
            QSqlQuery qry;
            qry.prepare("insert or replace into shows values('"+title+"', "+watched+", "+episodes+", "+rating+");");
            if(qry.exec()){
                QMessageBox::information(this, tr("Showboat - Save Data"), tr("Data saved."));
                connClose();
            }
            else{
                QMessageBox::critical(this, tr("Showboat - SQL Error"), qry.lastError().text(), qry.executedQuery());
                connClose();
            }
        }
    }

void ShowboatMainWindow::deleteEntry(){ //Remove an entry from the database
    connOpen();
    QString title;
    title = showNameUI->text();

    QSqlQuery qry;
    qry.prepare("delete from shows where Title = '"+title+"';");
    if(qry.exec()){
        QMessageBox::information(this, tr("Showboat - Delete Data"), tr("Entry deleted."));
        connClose();
    }
    else{
        QMessageBox::critical(this, tr("Showboat - SQL Error"), qry.lastError().text(), qry.executedQuery());
        connClose();
    }
}

