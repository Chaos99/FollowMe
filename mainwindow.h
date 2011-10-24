#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSize>
#include <QAction>
#include "filelist.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    // ~MainWindow();
    void closeEvent(QCloseEvent *event);
    QSize sizeHint();

private:

    //Ui::MainWindow *ui;
    FMFileList *mfilelist;

public slots:
    void openPreferences();
};

#endif // MAINWINDOW_H
