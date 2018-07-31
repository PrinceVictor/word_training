#ifndef TABLE_H
#define TABLE_H

#include <QWidget>

namespace Ui {
class table;
}
class Word_training;
class QSqlTableModel;
class input;
class table : public QWidget
{
    Q_OBJECT
    friend class Word_training;
    friend class input;
public:
    explicit table(QWidget *parent = 0);
    ~table();

private slots:
    void on_delete_2_clicked();

    void on_motify_clicked();

    void on_revert_clicked();

    void on_revert_2_clicked();

private:
    Ui::table *ui;
    QSqlTableModel *model;
};

#endif // TABLE_H
