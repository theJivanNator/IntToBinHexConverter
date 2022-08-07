#include<QtGui>
#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include<Qstring>
#include<qmessagebox.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),num1(new QLineEdit),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Connecting the button with signal and slot
    //signal(click), Slot(function to call
    connect(ui->btnConvert, SIGNAL(clicked()), this, SLOT(calculate()));
     connect(ui->btnClear, SIGNAL(clicked()), this, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clear(){
    ui->edtInput->setText("");
     ui->lcdNumberBinary->display(0);
      ui->lcdNumberHex->display(0);
}

void MainWindow::calculate(){
  QString r;
QString input=ui->edtInput->text();
bool isInt=true;
for (int i = 0; i < input.length(); i++)
        if (isdigit(input.toStdString()[i]) == false) {

            isInt= false;
        break;}

    if(isInt){

          int n = input.toInt();
      // char array to store hexadecimal number
      char hexaDeciNum[100];

      // counter for hexadecimal number array
      int i = 0;
      while (n != 0) {
          // temporary variable to store remainder
          int temp = 0;

          // storing remainder in temp variable.
          temp = n % 16;

          // check if temp < 10
          if (temp < 10) {
              hexaDeciNum[i] = temp + 48;
              i++;
          }
          else {
              hexaDeciNum[i] = temp + 55;
              i++;
          }

          n = n / 16;
      }    
      for (int j = i - 1; j >= 0; j--){
          r.append(hexaDeciNum[j]);}
      if(r.length()<11){
       ui->lcdNumberHex->display(r);
      }else{
          QMessageBox::information(
                 this,
                 tr("DitgitViewer"),
                 tr("Please enter a smaller interger") );
            ui->lcdNumberHex->display(r);
      }

      r.clear();
        n = input.toInt();
        //Binary
     QString j;
      while(n!=0) {
          j.append((n%2==0 ?"0":"1")+j);
          n/=2;
      }
      if(j.length()<11){
         ui->lcdNumberBinary->display(j);
         }else{
             QMessageBox::information(
                    this,
                    tr("DitgitViewer"),
                    tr("Please enter a smaller interger") );
             ui->lcdNumberBinary->display(j);
         }


    }else
    {
        QMessageBox::information(
               this,
               tr("DitgitViewer"),
               tr("Please enter a valid interger") );
        }
    }
