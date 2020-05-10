//
// Created by Arana on 2/18/20.
//
#include <iostream>
#include <QtWidgets>
#include "Showboat.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ShowboatMainWindow QtStarterApp;

    QtStarterApp.updateUI();
    QtStarterApp.show();
    return app.exec();
}

