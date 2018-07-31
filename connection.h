#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydata");
    db.setUserName("root");
    db.setPassword("");

    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("无法打开数据库"),
            "无法创建数据库连接！", QMessageBox::Cancel);
        return false;
    }

    // 下面来创建表
    // 如果MySQL数据库中已经存在同名的表，那么下面的代码不会执行
    QSqlQuery query(db);

    // 使数据库支持中文
    query.exec("SET NAMES 'Latin1'");

    query.exec("create table word(word varchar(20), translation varchar(80), right_rate int, wrong_rate  int,"
               "record_date varchar(20), duration_days int, appear_times int)");
//    query.exec("insert into word values('ferry', '渡船，摆渡', '0/0', '0/0', '0', 0, 0)");


    return true;
}

#endif // CONNECTION_H
