#include "preferencedialog2.h"
#include "ui_preferencedialog2.h"
#include "mainwindow.h"

PreferenceDialog2::PreferenceDialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferenceDialog2),
  settings(new QSettings("binaervarianz.de", "FollowMe"))
{
    Qt::WindowFlags flags = this->windowFlags();
    flags |= Qt::CustomizeWindowHint;
    flags &= ~Qt::WindowMinMaxButtonsHint;
    setWindowFlags(flags);
    ui->setupUi(this);
}

PreferenceDialog2::~PreferenceDialog2()
{
    delete ui;
}

void PreferenceDialog2::setExtPath(QString path)
{
    //TODO: do input validation here
    settings->setValue("extPath",path);
    ((MainWindow*)parent())->updateFileBrowser(path);
}

void PreferenceDialog2::setIntPath(QString path)
{
    //TODO: do input validation here
    settings->setValue("intPath", path);
    ((MainWindow*)parent())->updateFileBrowser(path);
}
