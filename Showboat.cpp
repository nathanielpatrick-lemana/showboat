#include <iostream>
#include <cstdio>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

#include "Showboat.h"
#include "ui_ShowboatMainWindow.h"

ShowboatMainWindow :: ShowboatMainWindow(QMainWindow *parent):
        dummyVariable { true }
{
    setupUi(this);

    if (!connOpen()){
        testLabelUI->setText("The database is unhappy");
    }

    testLabelUI->setText("The database is happy");
    QSqlQuery qry;
    qry.prepare("select * from shows");

    loadShowList();

    QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClickedHandler()));
}


void ShowboatMainWindow::printStringRep() {
    // String representation for QtStarter.
    return;
}


void ShowboatMainWindow::updateUI() {
//    printf("Inside updateUI()\n");
    loadShowList();
}

void ShowboatMainWindow::pushButtonClickedHandler() {
    addNewEntry();
    updateUI();
}

void ShowboatMainWindow::on_pushButton_2_clicked()
{
    deleteEntry();
    updateUI();
}


void ShowboatMainWindow::on_showListUI_activated(const QModelIndex &index)
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
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
}
