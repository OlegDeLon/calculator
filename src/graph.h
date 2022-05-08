#ifndef GRAPH_H
#define GRAPH_H
#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include "ui_graph.h"

#ifdef __cplusplus
extern "C" {
#include "stack.h"
}
#endif

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    Graph(QWidget *parent, QString abc);
    ~Graph();
    double x_start, x_end, x_step, X, y_start, y_end;
//    int N;
    QVector<double> x,y;

private slots:
    void on_BuildGraph_clicked();

private:
    Ui::Graph *ui;
    QString strOut;
};

#endif // GRAPH_H
