#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "driver.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    dissections s;
    button_segment in_l, in_m, in_r, out_l, out_m, out_r;

private slots:
    void on_b_LTriangle_clicked();

    void on_b_LCircle_clicked();

    void on_b_LSquare_clicked();

    void on_b_MTriangle_clicked();

    void on_b_MCircle_clicked();

    void on_b_MSquare_clicked();

    void on_b_RTriangle_clicked();

    void on_b_RCircle_clicked();

    void on_b_RSquare_clicked();

    void on_b_LSphere_clicked();

    void on_b_LCube_clicked();

    void on_b_LPyramid_clicked();

    void on_b_LCylinder_clicked();

    void on_b_LPrism_clicked();

    void on_b_LCone_clicked();

    void on_b_MSphere_clicked();

    void on_b_MCube_clicked();

    void on_b_MPyramid_clicked();

    void on_b_MCylinder_clicked();

    void on_b_MPrism_clicked();

    void on_b_MCone_clicked();

    void on_b_RSphere_clicked();

    void on_b_RCube_clicked();

    void on_b_RPyramid_clicked();

    void on_b_RCylinder_clicked();

    void on_b_RPrism_clicked();

    void on_b_RCone_clicked();

    void on_b_Reset_clicked();

    void on_Mode_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
