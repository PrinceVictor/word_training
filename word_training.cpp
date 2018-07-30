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
    word_input->show();
    word_input->ui->word->setFocus();

    word_table = new table(this->centralWidget());
    word_table->hide();

    model = new QSqlTableModel(this);
    model->setTable("word");
    model->select();

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    word_table->ui->tableView->setModel(model);

}

Word_training::~Word_training()
{
    delete ui;
}

void Word_training::on_action_triggered()
{
    word_table->hide();
    word_input->show();
    word_input->ui->word->setFocus();
}

void Word_training::on_action_2_triggered()
{
    word_input->hide();
    word_table->show();
}
