#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h" // Library for the use of mathematical functions
#include "QString" // Library for the use of text strings

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Metodo,SIGNAL(clicked()),this,SLOT(procesar()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::funcion(double X){ // Original function to evaluate
    return (X*X*X)+X+16;
}
double MainWindow::derivada(double X){ // Derived function
    return 3*(X*X)+1;
}

void MainWindow::procesar(){
    QString temp,temp2,temp3,itera;  // Temporary text strings
    double X=ui->equis->value();  // Retrieve the X value of the spinbox
    double err=ui->error->value();  // Retrieve the value of the spinbox error
    double in=ui->Iteraccion->value();  // Retrieve the value of spinbox interactions
    double Xn=0,Xa=0;
    double ea=100.0;
    int i=0;
    while(ea>err && in>i){
        Xa=(Xn-(funcion(X))/(derivada(X))); // It evaluates the function with the value X1 of the spinbox
        ea=100*std::abs((Xn-Xa)/Xn);  // The error is calculated
        i++; // The number of interactions increases
        Xn=Xa; // // Xn takes the value of Xa



    }
temp.append("Raiz= ").append(temp2.setNum(Xa)).append("\nError=").append(temp3.setNum(ea)).append("\nIteracciones=").append(itera.setNum(i));  // The text to be presented
ui->Texto->setText(temp);  // The text is presented
}
void MainWindow::borrar(){
    ui->equis->setValue(0.0);  // The spinbox is deleted
    ui->error->setValue(0.0);  // The spinbox is deleted
    ui->Texto->clear();  // Text is deleted
}
