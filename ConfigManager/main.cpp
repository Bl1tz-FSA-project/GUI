#include "ConfigManager.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConfigManager w;
    
    w.show();
    
    return a.exec();
    
}
