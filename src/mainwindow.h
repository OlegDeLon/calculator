#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graph.h>
#include "x_window.h"
#include <QVector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool x_var;
    double x;
    QByteArray count;

private:
    Ui::MainWindow *ui;
    X_Window *x_window;

private slots:
    void digits_numbers();
    void digits_functions();
    void on_pushButton_dot_clicked();
    void on_pushButton_clearall_clicked();
    void on_pushButton_rbracket_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_final_clicked();
    void calculation();
    void on_pushButton_XButton_clicked();
    void slotX_Window(QString a);
    void on_BuildGraph_clicked();
};

#endif // MAINWINDOW_H
