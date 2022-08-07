#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  QLineEdit *num1;
private:
    Ui::MainWindow *ui;
private slots:
       void calculate();//Function will be used on a click of a button.
        void clear();//Function will be used on a click of a button.
};

#endif // MAINWINDOW_H
