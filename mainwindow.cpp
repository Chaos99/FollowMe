#include "mainwindow.h"
//#include "ui_mainwindow.h"

#include <QTreeView>
#include <QSettings>
#include <QMenuBar>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QSettings settings ("binaervarianz.de", "FollowMe");
    restoreGeometry(settings.value("geometry", saveGeometry()).toByteArray());
    restoreState(settings.value("windowState", saveState()).toByteArray());

    mfilelist= new FMFileList(parent);
    model = new QFileSystemModel;
    QString extPath = settings.value("extPath",QDir::homePath()).toString();
    model->setRootPath(extPath );
    list = new QTreeView(this);
    updateFileBrowser(extPath);
    setCentralWidget(list);

    QAction *prefAct = new QAction(tr("&Preferences..."), this);
    prefAct->setShortcuts(QKeySequence::Preferences);
    prefAct->setStatusTip(tr("Open preference pane"));
    connect(prefAct, SIGNAL(triggered()), this, SLOT(openPreferences()));

    QMenuBar* menu = menuBar();
    QMenu* fileMenu = menu->addMenu(tr("&File"));
    fileMenu->addAction(prefAct);

    ui = new PreferenceDialog2(this);

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

void MainWindow::updateFileBrowser(QString path)
{


    list->setModel(model);
    list->setRootIndex(model->index(path));
    list->setUniformRowHeights(true);
    list->setAnimated(true);
    list->setSortingEnabled(true);
    list->resizeColumnToContents(1);

    list->setMinimumSize(QSize(200,200));

}

void MainWindow::openPreferences()
{
    ui->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}
