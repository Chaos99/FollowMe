#include "preferencedialog2.h"
#include "ui_preferencedialog2.h"

PreferenceDialog2::PreferenceDialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferenceDialog2)
{
    ui->setupUi(this);
}

PreferenceDialog2::~PreferenceDialog2()
{
    delete ui;
}
