#ifndef PREFERENCEDIALOG2_H
#define PREFERENCEDIALOG2_H

#include <QDialog>

namespace Ui {
    class PreferenceDialog2;
}

class PreferenceDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit PreferenceDialog2(QWidget *parent = 0);
    ~PreferenceDialog2();

private:
    Ui::PreferenceDialog2 *ui;
};

#endif // PREFERENCEDIALOG2_H
