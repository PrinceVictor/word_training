#ifndef WORD_TRAINING_H
#define WORD_TRAINING_H

#include <QMainWindow>
#include "input.h"
#include "ui_input.h"
#include "table.h"
#include "ui_table.h"

class QSqlTableModel;

namespace Ui {
class Word_training;
}

class Word_training : public QMainWindow
{
    Q_OBJECT

public:
    explicit Word_training(QWidget *parent = 0);
    ~Word_training();

private slots:
    void on_action_triggered();

    void on_action_2_triggered();

private:
    Ui::Word_training *ui;
    input *word_input;
    table *word_table;
    QSqlTableModel *model;
};

#endif // WORD_TRAINING_H
