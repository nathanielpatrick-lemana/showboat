#ifndef QTSTARTERSTARTER_QTSTARTER_H
#define QTSTARTERSTARTER_QTSTARTER_H

#include "ui_ShowboatMainWindow.h"
#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

class ShowboatMainWindow : public QMainWindow, private Ui::ShowboatMainWindow {
Q_OBJECT

public:
    ShowboatMainWindow(QMainWindow *parent = nullptr);
    void printStringRep();
    void updateUI();

    bool connOpen();
    void connClose();

    void loadShowList();
    void addNewEntry();
    void deleteEntry();

private:
    bool dummyVariable;
    std::string textOutput;


public Q_SLOTS:
    void pushButtonClickedHandler();
    void on_pushButton_2_clicked();
private slots:
    void on_showListUI_activated(const QModelIndex &index);
};

#endif //QTSTARTERSTARTER_QTSTARTER_H
