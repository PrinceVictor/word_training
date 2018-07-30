#ifndef INPUT_H
#define INPUT_H

#include <QWidget>

namespace Ui {
class input;
}
class Word_training;
class input : public QWidget
{
    Q_OBJECT
    friend class Word_training;
public:
    explicit input(QWidget *parent = 0);
    ~input();

private:
    Ui::input *ui;
};

#endif // INPUT_H
