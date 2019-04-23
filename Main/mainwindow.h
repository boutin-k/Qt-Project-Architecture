#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pluginmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onButtonClicked(bool checked = false);

private:
    Ui::MainWindow *ui;
    PluginManager   mPluginManager;
};

#endif // MAINWINDOW_H
