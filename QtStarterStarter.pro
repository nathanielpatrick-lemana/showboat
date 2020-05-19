QT += widgets sql
requires(qtConfig(combobox))

HEADERS     = Showboat.h showClass.h
SOURCES     = Showboat.cpp ShowboatGame.cpp \
    sqlHandler.cpp showClass.cpp
FORMS       = ShowboatMainWindow.ui
RESOURCES   = ShowboatResources.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/layouts/QtStarter
INSTALLS += target
