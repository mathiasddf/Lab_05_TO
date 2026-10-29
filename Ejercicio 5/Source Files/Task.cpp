
#include "Task.h"
#include "ui_Task.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

Task::Task(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    ui->checkbox->setChecked(false);
    ui->Mitext->clear();
    ui->Mitext->setReadOnly(true);

    connect(ui->editButton, &QPushButton::clicked,
            this, &Task::editTask);

    connect(ui->removeButton, &QPushButton::clicked,
            this, [this]() {
                emit removed(this);
            });
}

Task::~Task()
{
    delete ui;
}

void Task::editTask()
{
    bool ok = false;

    QString texto = QInputDialog::getText(
        this,
        "Editar sinónimos",
        "Ingrese los nuevos sinónimos:",
        QLineEdit::Normal,
        ui->Mitext->text(),
        &ok
        );

    if (ok && !texto.trimmed().isEmpty()) {
        ui->Mitext->setText(texto.trimmed());
        qDebug() << "Sinonimos editados:" << texto;
    }
}

void Task::setText(const QString &texto)
{
    ui->Mitext->setText(texto);
}
