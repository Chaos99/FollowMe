#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSize>
#include <QAction>
#include <QFileSystemModel>
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
    void updateFileBrowser(QString path);

private:

    QDialog *ui;
    FMFileList *mfilelist;
    QTreeView *list;
    QFileSystemModel *model;


public slots:
    void openPreferences();
};

#endif // MAINWINDOW_H
