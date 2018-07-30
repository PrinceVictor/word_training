#include "word_training.h"
#include <QApplication>
#include"connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!createConnection()) return 1;

    Word_training w;
    w.show();

    return a.exec();
}
