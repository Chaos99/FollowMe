#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSize>
#include <QAction>
#include "filelist.h"
#include "preferencedialog2.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    QSize sizeHint();

private:

    QDialog *ui;
    FMFileList *mfilelist;

public slots:
    void openPreferences();
};

#endif // MAINWINDOW_H
