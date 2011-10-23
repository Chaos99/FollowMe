#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QFileSystemModel>
#include <QTreeView>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QSettings settings ("binaervarianz.de", "FollowMe");
    restoreGeometry(settings.value("geometry", saveGeometry()).toByteArray());
    restoreState(settings.value("windowState", saveState()).toByteArray());

    mfilelist= new FMFileList(parent);
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::homePath());

    QTreeView *list = new QTreeView(this);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::homePath()));
    list->setUniformRowHeights(true);
    list->setAnimated(true);
    list->setSortingEnabled(true);
    list->resizeColumnToContents(1);

    list->setMinimumSize(QSize(200,200));
    setCentralWidget(list);




}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings ("binaervarianz.de", "FollowMe");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);

}

QSize MainWindow::sizeHint()
{
    return QSize(800,600);
}


//    ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}
