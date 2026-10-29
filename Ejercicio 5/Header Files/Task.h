#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

    void setText(const QString &texto);

signals:
    void removed(Task *task);

private slots:
    void editTask();

private:
    Ui::Task *ui;
};

#endif