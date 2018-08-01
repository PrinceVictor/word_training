#include "word_training.h"
#include "ui_word_training.h"
#include <QSqlquery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>

Word_training::Word_training(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Word_training)
{
    ui->setupUi(this);
    word_input = new input(this->centralWidget());
    word_input->hide();
    word_input->ui->word->setFocus();

    word_table = new table(this->centralWidget());
    word_table->model->setSort(4,Qt::DescendingOrder);
    word_table->model->select();
    word_table->show();

    word_test = new test(this->centralWidget());
    word_test->hide();

}

Word_training::~Word_training()
{
    delete ui;
}

void Word_training::on_action_triggered()
{
    word_table->hide();
    word_test->hide();
    word_input->show();
    word_input->ui->word->setFocus();
}

void Word_training::on_action_2_triggered()
{

    word_table->model->setTable("word");
    word_table->model->select();
    word_table->model->setHeaderData(2, Qt::Horizontal, tr("right rate %"));
    word_table->model->setHeaderData(3, Qt::Horizontal, tr("wrong rate %"));
    word_table->model->setHeaderData(4, Qt::Horizontal, tr("record date"));
    word_table->model->setSort(4,Qt::DescendingOrder);
    word_table->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    word_table->ui->tableView->hideColumn(7);
    word_table->model->select();

    word_test->hide();
    word_input->hide();
    word_table->show();

}
//appear times
void Word_training::on_action_6_triggered()
{
    word_input->hide();
    word_test->hide();
    word_table->show();
    static bool toggle_flag =false;
    if(toggle_flag) {
        word_table->model->setSort(6,Qt::AscendingOrder);
    }
    else
        word_table->model->setSort(6,Qt::DescendingOrder);

    word_table->model->select();
    toggle_flag = !toggle_flag ;
}

//duration_days
void Word_training::on_action_5_triggered()
{
    word_input->hide();
    word_test->hide();
    word_table->show();
    static bool toggle_flag =false;
    if(toggle_flag) {
        word_table->model->setSort(5,Qt::AscendingOrder);
    }
    else
        word_table->model->setSort(5,Qt::DescendingOrder);

    word_table->model->select();
    toggle_flag = !toggle_flag ;
}

//wrong rate
void Word_training::on_action_3_triggered()
{
    word_input->hide();
    word_test->hide();
    word_table->show();

    static bool toggle_flag =false;
    if(toggle_flag) {
        word_table->model->setSort(3,Qt::AscendingOrder);
    }
    else
        word_table->model->setSort(3,Qt::DescendingOrder);

    word_table->model->select();
    toggle_flag = !toggle_flag ;
}

void Word_training::on_action_4_triggered()
{
    word_input->hide();
    word_test->hide();
    word_table->show();

    static bool toggle_flag =false;
    if(toggle_flag) {
        word_table->model->setSort(2,Qt::AscendingOrder);
    }
    else
        word_table->model->setSort(2,Qt::DescendingOrder);

    word_table->model->select();
    toggle_flag = !toggle_flag ;
}
//word test
void Word_training::on_action_7_triggered()
{
    word_input->hide();
    word_table->hide();
    word_table->weight_update();
    word_test->word_flag = 0;
    word_test->num_count =0;
    word_test->show();
    word_test->widget_init();
}
//trans test
void Word_training::on_action_8_triggered()
{
    word_input->hide();
    word_table->hide();
    word_table->weight_update();
    word_test->word_flag = 1;
    word_test->num_count =0;
    word_test->show();
    word_test->widget_init();
}
