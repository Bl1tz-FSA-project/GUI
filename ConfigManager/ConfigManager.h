#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ConfigManager.h"
#include <string>

class ConfigManager : public QMainWindow
{
    Q_OBJECT

public:
    ConfigManager(QWidget *parent = nullptr);
    void showFreqRangeAddValue();
    ~ConfigManager();

private:
    Ui::ConfigManagerClass ui;
};
