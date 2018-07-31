#include "word_training.h"
#include <QApplication>
#include"connection.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QProcess process;
    process.start("C:/Program Files (x86)/MySQL/MySQL Server 5.6/bin/mysqld.exe");
    if (!createConnection()) return 1;

    Word_training w;
    w.show();

    return a.exec();
}
