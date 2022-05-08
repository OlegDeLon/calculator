#include "x_window.h"
#include "ui_x_window.h"

X_Window::X_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::X_Window)
{
    ui->setupUi(this);
}

X_Window::~X_Window()
{
    delete ui;
}

void X_Window::on_pushButton_clicked()
{
    emit signalX_Window(ui->lineEdit_2->text());
    close();
}

