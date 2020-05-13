#include <iostream>
#include <cstdio>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

#include "Showboat.h"
#include "ui_ShowboatMainWindow.h"

ShowboatMainWindow :: ShowboatMainWindow(QMainWindow *parent) //When starting the program, fetch all data from the database
{
    setupUi(this);

    if (!connOpen()){
        testLabelUI->setText("Failed to open the database. Does it exist or is the path correct?");
        QMessageBox::critical(this, tr("Showboat - Database Error"), tr("Failed to open the database. Does it exist or is the path correct?"));
    }

    testLabelUI->setText("Successfully opened the database.");
    QSqlQuery qry;
    qry.prepare("select * from shows");

    loadShowList();

    QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClickedHandler()));
}

/*
void ShowboatMainWindow::printStringRep() {
    // String representation for QtStarter.
    return;
}
 */


void ShowboatMainWindow::updateUI() { //Reload the show list after deleting or committing changes
//    printf("Inside updateUI()\n");
    loadShowList();
}

void ShowboatMainWindow::pushButtonClickedHandler() { //Add the new entry to database upon clicking "Commit changes"
    addNewEntry();
    updateUI();
}

void ShowboatMainWindow::on_pushButton_2_clicked() //Delete entry from database upon clicking "Delete entry"
{
    deleteEntry();
    updateUI();
}


void ShowboatMainWindow::on_showListUI_activated(const QModelIndex &index) //Handling loading information into entry boxes upon loading from the list
{
    QString val=showListUI->model()->data(index).toString();
    connOpen();

    QSqlQuery qry;
    qry.prepare("select * from shows where Title='"+val+"';");
    if (qry.exec())
    {
        while(qry.next())
        {
            showNameUI->setText(qry.value(0).toString());
            episodesWatchedUI->setValue(qry.value(1).toInt());
            episodesTotalUI->setValue(qry.value(2).toInt());
            ratingUI->setValue(qry.value(3).toDouble());
        }
        connClose();
    }
    else {
        QMessageBox::critical(this, tr("Showboat - SQL Error"), qry.lastError().text());
    }
}
