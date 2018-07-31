#include "table.h"
#include "ui_table.h"
#include <QSqlquery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QDate>

table::table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("word");
    model->select();
    model->setHeaderData(2, Qt::Horizontal, tr("right rate %"));
    model->setHeaderData(3, Qt::Horizontal, tr("wrong rate %"));
    model->setHeaderData(4, Qt::Horizontal, tr("record date"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

}

table::~table()
{
    delete ui;
}

void table::on_delete_2_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                  tr("你确定删除当前行吗？"),QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        model->revertAll();
    } else { // 否则提交，在数据库中删除该行
        model->submitAll();
    }
}

void table::on_motify_clicked()
{
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1").arg(model->lastError().text()));
    }
}

void table::on_revert_clicked()
{
    model->revertAll();
}
//refresh
void table::on_revert_2_clicked()
{
    model->select();
    for(int i =0; i< model->rowCount();i++){
        QSqlRecord record = model->record(i);
        QDate begin_date =QDate::fromString( record.value("first_data").toString(),"yy-MM-dd").addYears(100);
        QDate now_date = QDate::currentDate();
        int days = begin_date.daysTo(now_date)+1 ;
        model->setData(model->index(i,5),days);
    }
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1").arg(model->lastError().text()));
    }
    model->select();
//    this->hide();
}
