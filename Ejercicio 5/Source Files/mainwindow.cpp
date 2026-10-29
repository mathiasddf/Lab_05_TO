#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->addButton->setText("Agregar sinónimos");

    this->setStyleSheet(R"(
    QMainWindow, QMainWindow QWidget#centralwidget {
        background-color: #F8FAFC;
    }

    QLabel {
        color: #1E293B;
        font-size: 20px;
        font-weight: 600;
    }

    QScrollArea,
    QWidget#scrollAreaWidgetContents {
        background-color: #F8FAFC;
        border: none;
    }

    QLineEdit {
        background-color: white;
        color: #334155;
        border: 1px solid #E2E8F0;
        border-radius: 5px;
        padding: 6px 10px;
        font-size: 13px;
    }

    QLineEdit:focus {
        border: 1px solid #94A3B8;
    }

    QPushButton {
        background-color: #2563EB;
        color: white;
        border: none;
        border-radius: 5px;
        padding: 7px 14px;
        font-size: 12px;
    }

    QPushButton:hover {
        background-color: #1D4ED8;
    }

    QPushButton#editButton {
        background-color: transparent;
        color: #64748B;
    }

    QPushButton#editButton:hover {
        background-color: #F1F5F9;
    }

    QPushButton#removeButton {
        background-color: transparent;
        color: #DC2626;
    }

    QPushButton#removeButton:hover {
        background-color: #FEF2F2;
    }

    QCheckBox {
        spacing: 6px;
    }

    QScrollBar:vertical {
        background: #F8FAFC;
        width: 8px;
        margin: 0px;
    }

    QScrollBar::handle:vertical {
        background: #CBD5E1;
        border-radius: 4px;
        min-height: 25px;
    }

    QScrollBar::add-line:vertical,
    QScrollBar::sub-line:vertical {
        height: 0px;
    }

    QScrollBar::add-page:vertical,
    QScrollBar::sub-page:vertical {
        background: none;
    }
)");



    // Configurar el área de desplazamiento
    ui->scrollArea->setWidgetResizable(true);

    ui->scrollArea->setVerticalScrollBarPolicy(
        Qt::ScrollBarAsNeeded
        );

    ui->scrollArea->setHorizontalScrollBarPolicy(
        Qt::ScrollBarAlwaysOff
        );

    // Evitar que las filas se compriman
    ui->taskLayout->setSizeConstraint(
        QLayout::SetMinAndMaxSize
        );

    ui->taskLayout->setAlignment(Qt::AlignTop);
    ui->taskLayout->setSpacing(5);
    taskLayout = ui->taskLayout;

    ui->taskLayout->setAlignment(Qt::AlignTop);
    ui->taskLayout->setSpacing(5);

    connect(ui->addButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    QString texto = ui->taskInput->text().trimmed();

    if (texto.isEmpty()) {
        return;
    }

    Task *task = new Task(ui->scrollAreaWidgetContents);

    task->setText(texto);

    taskLayout->addWidget(task);

    connect(task, &Task::removed,
            this, &MainWindow::removeTask);

    ui->taskInput->clear();

    qDebug() << "Sinonimo agregado:" << texto;
}

void MainWindow::removeTask(Task *task)
{
    taskLayout->removeWidget(task);
    task->deleteLater();

    qDebug() << "Sinonimo eliminado";
}