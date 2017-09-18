#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double funcion(double X);
    double derivada(double x);

private:
    Ui::MainWindow *ui;
public slots:
    void borrar();
    void procesar();
};
#endif // MAINWINDOW_H
