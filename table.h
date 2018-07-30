#ifndef TABLE_H
#define TABLE_H

#include <QWidget>

namespace Ui {
class table;
}
class Word_training;
class table : public QWidget
{
    Q_OBJECT
    friend class Word_training;
public:
    explicit table(QWidget *parent = 0);
    ~table();

private:
    Ui::table *ui;
};

#endif // TABLE_H
