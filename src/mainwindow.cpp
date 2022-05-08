#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include "x_window.h"

#ifdef __cplusplus
extern "C" {
#include "stack.h"
}
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x_var = false;
    connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_lbracket,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_minus,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_division,SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_sin,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_cos,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_tan,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_asin,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_acos,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_atan,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_log,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_ln,SIGNAL(clicked()), this, SLOT(digits_functions()));
    connect(ui->pushButton_pow,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_mod,SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
   QPushButton *button = (QPushButton *)sender();
   QString new_label;
   new_label = ui->textline->text() + button->text();
   ui->textline->setText(new_label);
}

void MainWindow::digits_functions()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->textline->text() + button->text() + "(";
    ui->textline->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
        ui->textline->setText(ui->textline->text() + ".");
}

void MainWindow::on_pushButton_clearall_clicked()
{
    ui->textline->setText("");
}


void MainWindow::on_pushButton_rbracket_clicked()
{
    ui->textline->setText(ui->textline->text() + ")");
}


void MainWindow::on_pushButton_clear_clicked()
{
    QString str = ui->textline->text();
    str = str.left(str.count() - 1);
    ui->textline->setText(str);
}


void MainWindow::on_pushButton_final_clicked()
{
    QString equal = ui->textline->text();
    if (equal == "26.02.1996") {
        ui->textline->setText("Wake up, NEO!");
    } else {
    count = equal.toLocal8Bit();
    if (this->x_var == true) {
        x_window = new X_Window;
        x_window -> show();
        connect(x_window, &X_Window::signalX_Window, this, &MainWindow::slotX_Window);
    } else {
    calculation();
    }
    this->x_var = false;
    }
}

void MainWindow::calculation() {
    char *cstr = count.data();
    char output[1000] = {0};
    float temp_result = 0;
    int err = 0;
    err = check(cstr);
    if (err == 0) {
        temp_result = parse(cstr);
        sprintf(output, "%g", temp_result);
        ui->textline->setText(output);
    } else {
        ui->textline->setText("Invalid data");
    }
}


void MainWindow::on_pushButton_XButton_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label = ui->textline->text() + button->text();
    ui->textline->setText(new_label);
    x_var = true;
}

void MainWindow::slotX_Window(QString a)
{
    QString x_a = a;
    bool ok;
    x_a.toDouble(&ok);
    QByteArray byteArray = x_a.toLocal8Bit();
    char* var = byteArray.data();
    char var_2[500] = {0};
    snprintf(var_2, 499, "%s", "(");
    snprintf(var_2 + strlen(var_2), 400, "%s", var);
    snprintf(var_2 + strlen(var_2), 399, "%s", ")");
    count.replace("x", var_2);
    calculation();
}

void MainWindow::on_BuildGraph_clicked()
{
   Graph window(nullptr, ui->textline->text());
   window.setModal(true);
   window.exec();
}


