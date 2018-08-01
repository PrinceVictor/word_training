#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include "table.h"
#include "ui_table.h"

namespace Ui {
class input;
}
class Word_training;

class input : public QWidget
{
    Q_OBJECT
    friend class Word_training;
public:
    explicit input(QWidget *parent = 0);
    ~input();

public slots:
     void on_pushButton_2_clicked();
private slots:

private:
    Ui::input *ui;
};

#endif // INPUT_H
