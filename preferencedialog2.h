#ifndef PREFERENCEDIALOG2_H
#define PREFERENCEDIALOG2_H

#include <QDialog>
#include <QSettings>
#include "ui_preferenceDialog2.h"

namespace Ui {
class PreferenceDialog2;
}

class PreferenceDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit PreferenceDialog2(QWidget *parent = 0);
    ~PreferenceDialog2();

public slots:
    void setExtPath(QString path);
    void setIntPath(QString path);

private:
    Ui::PreferenceDialog2 *ui;
    QSettings *settings;
};

#endif // PREFERENCEDIALOG2_H
