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
    mydb.setDatabaseName("../showdata/shows.db");

    if(!mydb.open()){
        qDebug() << ("Failed to open the database. Does it exist or is the path correct?");
        return false;
    }
    else {
        qDebug() << ("Successfully opened database.");
        return true;
    }
}

void ShowboatMainWindow::loadShowList(){ //Load the show list from the titles of shows in the database

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(mydb);

    qry->prepare("select Title from shows;");

    qry->exec();
    modal->setQuery(*qry);
    showListUI->setModel(modal);
}

void ShowboatMainWindow::addNewEntry(Show workingShow) {  //Add a show or change a show with INSERT or REPLACE
    if (workingShow.getTitle() == "") {
        QMessageBox::critical(this, tr("Showboat - Null Error"), tr("Title field is empty, put something in there!"));
    } else {
        if (workingShow.getWatched() > workingShow.getEpisodes()) {
            QMessageBox::critical(this, tr("Showboat - Syntax Error"),
                                  tr("Cannot add a show with a greater amount of watched episodes than episodes total"));
        } else if (workingShow.getEpisodes() == 0) {
            QMessageBox::critical(this, tr("Showboat - Syntax Error"),
                                  tr("Cannot add a show where there are zero episodes to watch"));
        } else {
            QSqlQuery qry;
            qry.prepare(
                    "insert or replace into shows values('" + QString::fromStdString(workingShow.getTitle()) + "', " +
                    QString::number(workingShow.getWatched()) + ", " + QString::number(workingShow.getEpisodes()) +
                    ", " + QString::number(workingShow.getRating(), 'f', 2) + ");");
            if (qry.exec()) {
                QMessageBox::information(this, tr("Showboat - Save Data"), tr("Data saved."));
            } else {
                QMessageBox::critical(this, tr("Showboat - SQL Error"), qry.lastError().text(), qry.executedQuery());
            }
        }
    }
}

void ShowboatMainWindow::deleteEntry(Show workingShow){ //Remove an entry from the database
    if (workingShow.getTitle() == "") {
        QMessageBox::critical(this, tr("Showboat - Null Error"), tr("Title field is empty, put something in there!"));
    } else {
        QString title = QString::fromStdString(workingShow.getTitle());
        QSqlQuery qry;
        qry.prepare("delete from shows where Title = '" + title + "';");
        if (qry.exec()) {
            QMessageBox::information(this, tr("Showboat - Delete Data"), tr("Entry deleted."));
        } else {
            QMessageBox::critical(this, tr("Showboat - SQL Error"), qry.lastError().text(), qry.executedQuery());
        }
    }
}

