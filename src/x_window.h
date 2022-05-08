#ifndef X_WINDOW_H
#define X_WINDOW_H

#include <QMainWindow>

namespace Ui {
class X_Window;
}

class X_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit X_Window(QWidget *parent = nullptr);
    ~X_Window();
    double variation;

private slots:
    void on_pushButton_clicked();

private:
    Ui::X_Window *ui;

signals:
    void signalX_Window(QString);
};

#endif // X_WINDOW_H
