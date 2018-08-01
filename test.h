#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include "table.h"
#include "ui_table.h"

namespace Ui {
class test;
}
class Word_training;
class test : public QWidget
{
    Q_OBJECT
    friend class Word_training;
public:
    explicit test(QWidget *parent = 0);
    ~test();

private slots:
    void widget_init();

    void on_next_clicked();

    void on_pass_clicked();

    void on_show_clicked();

    void on_no_pass_clicked();

    void wrong_rate_update(bool);

private:
    Ui::test *ui;
    uint8_t word_flag = 0; //0 for hide trans, 1 for hide word
    int num_count =0;
};

#endif // TEST_H
