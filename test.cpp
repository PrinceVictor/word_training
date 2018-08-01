#include "test.h"
#include "ui_test.h"
#include <QSqlTableModel>
#include <QSqlRecord>
test::test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
}

test::~test()
{
    delete ui;
}

void test::widget_init(){
    table word_table;
    word_table.model->setSort(7,Qt::DescendingOrder);
    word_table.model->select();
    ui->word->show();
    ui->trans->show();
    ui->word->setText(word_table.model->record(num_count).value("word").toString());
    ui->trans->setText(word_table.model->record(num_count).value("translation").toString());
    if(word_flag) ui->word->hide();
    else ui->trans->hide();
}

//next word
void test::on_next_clicked()
{
    table word_table;
    word_table.model->setSort(7,Qt::DescendingOrder);
    word_table.model->select();
    num_count++;
    ui->word->setText(word_table.model->record(num_count).value("word").toString());
    ui->trans->setText(word_table.model->record(num_count).value("translation").toString());
    if(word_flag) ui->word->hide();
    else ui->trans->hide();

}

void test::on_pass_clicked()
{
    table word_table;
    word_table.model->setSort(7,Qt::DescendingOrder);
    word_table.model->select();
    wrong_rate_update(true);
    num_count++;
    ui->word->setText(word_table.model->record(num_count).value("word").toString());
    ui->trans->setText(word_table.model->record(num_count).value("translation").toString());
    if(word_flag) ui->word->hide();
    else ui->trans->hide();
}

//
void test::on_no_pass_clicked()
{
    table word_table;
    word_table.model->setSort(7,Qt::DescendingOrder);
    word_table.model->select();
    wrong_rate_update(false);
    num_count++;
    ui->word->setText(word_table.model->record(num_count).value("word").toString());
    ui->trans->setText(word_table.model->record(num_count).value("translation").toString());
    if(word_flag) ui->word->hide();
    else ui->trans->hide();
}

void test::on_show_clicked()
{
    ui->trans->show();
    ui->word->show();
}
//false for wrong update, true for right update
void test::wrong_rate_update(bool flag){
    table word_table;
    float wrong_rate =  word_table.model->record(num_count).value("wrong_rate").toInt();
    float appear_times = word_table.model->record(num_count).value("appear_times").toInt();
    if(!flag)
        wrong_rate = (int)((wrong_rate/100.0f*appear_times+1)/(appear_times+1)*100.0f) ;
    else
        wrong_rate = (int)((wrong_rate/100.0f*appear_times)/(appear_times+1)*100.0f) ;
    word_table.model->setData(word_table.model->index(num_count,3),wrong_rate);
    word_table.model->setData(word_table.model->index(num_count,2),100-wrong_rate);
    word_table.model->setData(word_table.model->index(num_count,6),appear_times+1);
    word_table.model->submitAll();
}

