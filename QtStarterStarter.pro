QT += widgets sql
requires(qtConfig(combobox))

HEADERS     = Showboat.h
SOURCES     = Showboat.cpp ShowboatGame.cpp \
    sqlHandler.cpp
FORMS       = ShowboatMainWindow.ui
RESOURCES   = ShowboatResources.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/layouts/QtStarter
INSTALLS += target
