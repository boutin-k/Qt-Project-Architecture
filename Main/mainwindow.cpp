#include <QDebug>

// UI interfaces
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Statement extension
#include "common/macro/qswitch.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mPluginManager(this)
{
    ui->setupUi(this);
    // Connect UI buttons click event to MainWindow::onButtonClicked function
    connect(ui->OkButton,     SIGNAL(clicked(bool)), this, SLOT(onButtonClicked(bool)));
    connect(ui->CancelButton, SIGNAL(clicked(bool)), this, SLOT(onButtonClicked(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
    mPluginManager.deleteLater();
}

/**
 * @brief MainWindow::onButtonClicked
 * @param checked
 */
void MainWindow::onButtonClicked(bool checked) {
    Q_UNUSED(checked);

    QSSWITCH(sender()->objectName(),
        QSCASE("OkButton",      { mPluginManager.loadPlugins();   })
        QSCASE("CancelButton",  { qDebug() << "Cancel clicked"; })
        QSDEFAULT(              { qDebug() << "Unknown"; })
    );
}

