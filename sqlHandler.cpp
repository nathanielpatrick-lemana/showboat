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

bool ShowboatMainWindow::connOpen(){
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("E:/Projects/QtStarter-master/shows.db");

    if(!mydb.open()){
        qDebug() << ("failed to open the database");
        return false;
    }
    else {
        qDebug() << ("successfully opened database");
        return true;
    }
}

void ShowboatMainWindow::connClose(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

void ShowboatMainWindow::loadShowList(){

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

void ShowboatMainWindow::addNewEntry(){
    connOpen();
    QString title,watched,episodes,rating;
    title=showNameUI->text();
    watched=episodesWatchedUI->text();
    episodes=episodesTotalUI->text();
    rating=ratingUI->text();
    if(watched > episodes){
        QMessageBox::critical(this, tr("Showboat - Syntax Error"), tr("Cannot add a show with a greater amount of watched episodes than episodes total"));
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

void ShowboatMainWindow::deleteEntry(){
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

