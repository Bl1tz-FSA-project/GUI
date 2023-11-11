#include "ConfigManager.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>


ConfigManager::ConfigManager(QWidget *parent)
    : QMainWindow(parent)
{   
    ui.setupUi(this);
    this->setStyleSheet("QMainWindow {"
        "  background-color: #ffffff;"
        "}"
        "QPushButton {"
        "  background-color: #007bff;"
        "  border-color: #007bff;"
        "  color: #ffffff;"
        "}"
        "QPushButton:hover {"
        "  background-color: #0056b3;"
        "  border-color: #0056b3;"
        "  color: #ffffff;"
        "}"
        "QComboBox {"
        "  background-color: #ffffff; color: #000000; border: 1px solid #808080; padding: 2px;"
        "}"
        "QListWidget {"
        "  background-color: #ffffff; color: #000000; border: 1px solid #808080;"
        "}"
        "QTextEdit {"
        "  background-color: #ffffff; color: #000000; border: 1px solid #808080; padding: 2px;"
        "}"
        "QTableWidget {"
        "  background-color: #ffffff; color: #000000; border: 1px solid #808080;"
        "}"
        "QLineEdit {"
        "  background-color: #ffffff; color: #000000; border: 1px solid #808080; padding: 2px;"
        "}"
        "QTextBrowser {"
        "  background-color: #ffffff; color: #000000; border: 1px solid #808080; padding: 2px;"
        "}"

    );


    setFixedSize(943, 542);

    ui.serialPorts_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.syncWord_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.chipConfiguration_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.chipConfiguration_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.bitRate_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.minRSSI_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.freqRange_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.setup4_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.setup5_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.setupN_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.bound_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.serialMonitor_TextBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui.enterCommandHer_TextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.enterCommandHer_TextEdit->setPlaceholderText("Enter command here...");

    connect(ui.addCustomValue_ComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        if (index==1)
        {
            showFreqRangeAddValue();
        }
        });
}
void ConfigManager::showFreqRangeAddValue() {

    QDialog* customDialog = new QDialog(this);

    customDialog->setFixedSize(200, 100);
    customDialog->setWindowTitle("Fill in Min-max freq");

    QLineEdit* lineEdit1 = new QLineEdit(customDialog);
    QLineEdit* lineEdit2 = new QLineEdit(customDialog);

    QPushButton* okButton = new QPushButton("OK", customDialog);
    QPushButton* cancelButton = new QPushButton("Cancel", customDialog);

    QVBoxLayout* mainLayout = new QVBoxLayout(customDialog);

    mainLayout->addWidget(lineEdit1);
    mainLayout->addWidget(lineEdit2);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, [=]() {
        QString res = lineEdit1->text() + "-" + lineEdit2->text();
        

        ui.addCustomValue_ComboBox->addItem(res);

        customDialog->close();
        });

    connect(cancelButton, &QPushButton::clicked, [=]() {
        customDialog->close();
        });

    customDialog->exec();
}
ConfigManager::~ConfigManager()
{}
