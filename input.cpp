#include "input.h"
#include "ui_input.h"
#include <QSqlquery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include<QDate>
#include<string>
#include<QShortcut>
input::input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
    QObject::connect(ui->trans, SIGNAL(returnPressed()), this, SLOT(on_pushButton_2_clicked()) );
}

input::~input()
{
    delete ui;
}

void input::on_pushButton_2_clicked()
{
    table word_table;
    if(ui->word->text().isEmpty()){
        return ;
    }
    int rowNum = word_table.model->rowCount();
    // 添加一行
    word_table.model->insertRow(rowNum);
    word_table.model->setData(word_table.model->index(rowNum,0),ui->word->text());
    word_table.model->setData(word_table.model->index(rowNum,1),ui->trans->text());
    word_table.model->setData(word_table.model->index(rowNum,2),0);
    word_table.model->setData(word_table.model->index(rowNum,3),100);
    word_table.model->setData(word_table.model->index(rowNum,4),QDate::currentDate().toString("yy-MM-dd"));
    word_table.model->setData(word_table.model->index(rowNum,5),1);
    word_table.model->setData(word_table.model->index(rowNum,6),1);

    word_table.model->database().transaction();

    if (word_table.model->submitAll()) {
        word_table.model->database().commit(); //提交
        ui->word->clear();
        ui->trans->clear();
        ui->word->setFocus();
    } else {
        word_table.model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1").arg(word_table.model->lastError().text()));
    }

}
