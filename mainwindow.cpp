#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = dissections();
    in_l = button_segment(3, 0);
    in_m = button_segment(3, 1);
    in_r = button_segment(3, 2);
    out_l = button_segment(6, 3);
    out_m = button_segment(6, 4);
    out_r = button_segment(6, 5);

    in_l.add_shape(0, ui->b_LTriangle);
    in_l.add_shape(1, ui->b_LCircle);
    in_l.add_shape(2, ui->b_LSquare);

    in_m.add_shape(0, ui->b_MTriangle);
    in_m.add_shape(1, ui->b_MCircle);
    in_m.add_shape(2, ui->b_MSquare);

    in_r.add_shape(0, ui->b_RTriangle);
    in_r.add_shape(1, ui->b_RCircle);
    in_r.add_shape(2, ui->b_RSquare);

    out_l.add_shape(0, ui->b_LSphere);
    out_l.add_shape(1, ui->b_LCube);
    out_l.add_shape(2, ui->b_LPyramid);
    out_l.add_shape(3, ui->b_LCylinder);
    out_l.add_shape(4, ui->b_LPrism);
    out_l.add_shape(5, ui->b_LCone);

    out_m.add_shape(0, ui->b_MSphere);
    out_m.add_shape(1, ui->b_MCube);
    out_m.add_shape(2, ui->b_MPyramid);
    out_m.add_shape(3, ui->b_MCylinder);
    out_m.add_shape(4, ui->b_MPrism);
    out_m.add_shape(5, ui->b_MCone);

    out_r.add_shape(0, ui->b_RSphere);
    out_r.add_shape(1, ui->b_RCube);
    out_r.add_shape(2, ui->b_RPyramid);
    out_r.add_shape(3, ui->b_RCylinder);
    out_r.add_shape(4, ui->b_RPrism);
    out_r.add_shape(5, ui->b_RCone);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Left Inside
void MainWindow::on_b_LTriangle_clicked()
{
    if (in_l.get_selected() == 1) {
        in_l.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }

    in_l.select(1, &s);

    if (in_m.get_selected() == 2 && in_r.get_selected() == 0) {
        in_r.select(3, &s);
    } else if (in_m.get_selected() == 3 && in_r.get_selected() == 0) {
        in_r.select(2, &s);
    } else if (in_m.get_selected() == 0 && in_r.get_selected() == 2) {
        in_m.select(3, &s);
    } else if (in_m.get_selected() == 0 && in_r.get_selected() == 3) {
        in_m.select(2, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}
void MainWindow::on_b_LCircle_clicked()
{
    if (in_l.get_selected() == 2) {
        in_l.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_l.select(2, &s);

    if (in_m.get_selected() == 1 && in_r.get_selected() == 0) {
        in_r.select(3, &s);
    } else if (in_m.get_selected() == 3 && in_r.get_selected() == 0) {
        in_r.select(1, &s);
    } else if (in_m.get_selected() == 0 && in_r.get_selected() == 1) {
        in_m.select(3, &s);
    } else if (in_m.get_selected() == 0 && in_r.get_selected() == 3) {
        in_m.select(1, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }

}

void MainWindow::on_b_LSquare_clicked()
{
    if (in_l.get_selected() == 3) {
        in_l.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_l.select(3, &s);

    if (in_m.get_selected() == 1 && in_r.get_selected() == 0) {
        in_r.select(2, &s);
    } else if (in_m.get_selected() == 2 && in_r.get_selected() == 0) {
        in_r.select(1, &s);
    } else if (in_m.get_selected() == 0 && in_r.get_selected() == 1) {
        in_m.select(2, &s);
    } else if (in_m.get_selected() == 0 && in_r.get_selected() == 2) {
        in_m.select(1, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}

//Middle Inside
void MainWindow::on_b_MTriangle_clicked()
{
    if (in_m.get_selected() == 1) {
        in_m.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_m.select(1, &s);

    if (in_l.get_selected() == 2 && in_r.get_selected() == 0) {
        in_r.select(3, &s);
    } else if (in_l.get_selected() == 3 && in_r.get_selected() == 0) {
        in_r.select(2, &s);
    } else if (in_l.get_selected() == 0 && in_r.get_selected() == 2) {
        in_l.select(3, &s);
    } else if (in_l.get_selected() == 0 && in_r.get_selected() == 3) {
        in_l.select(2, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}

void MainWindow::on_b_MCircle_clicked()
{
    if (in_m.get_selected() == 2) {
        in_m.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_m.select(2, &s);

    if (in_l.get_selected() == 1 && in_r.get_selected() == 0) {
        in_r.select(3, &s);
    } else if (in_l.get_selected() == 3 && in_r.get_selected() == 0) {
        in_r.select(1, &s);
    } else if (in_l.get_selected() == 0 && in_r.get_selected() == 1) {
        in_l.select(3, &s);
    } else if (in_l.get_selected() == 0 && in_r.get_selected() == 3) {
        in_l.select(1, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}

void MainWindow::on_b_MSquare_clicked()
{
    if (in_m.get_selected() == 3) {
        in_m.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_m.select(3, &s);

    if (in_l.get_selected() == 1 && in_r.get_selected() == 0) {
        in_r.select(2, &s);
    } else if (in_l.get_selected() == 2 && in_r.get_selected() == 0) {
        in_r.select(1, &s);
    } else if (in_l.get_selected() == 0 && in_r.get_selected() == 1) {
        in_l.select(2, &s);
    } else if (in_l.get_selected() == 0 && in_r.get_selected() == 2) {
        in_l.select(1, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}

//Right Inside
void MainWindow::on_b_RTriangle_clicked()
{
    if (in_r.get_selected() == 1) {
        in_r.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_r.select(1, &s);

    if (in_l.get_selected() == 2 && in_m.get_selected() == 0) {
        in_m.select(3, &s);
    } else if (in_l.get_selected() == 3 && in_m.get_selected() == 0) {
        in_m.select(2, &s);
    } else if (in_l.get_selected() == 0 && in_m.get_selected() == 2) {
        in_l.select(3, &s);
    } else if (in_l.get_selected() == 0 && in_m.get_selected() == 3) {
        in_l.select(2, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}

void MainWindow::on_b_RCircle_clicked()
{
    if (in_r.get_selected() == 2) {
        in_r.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_r.select(2, &s);

    if (in_l.get_selected() == 1 && in_m.get_selected() == 0) {
        in_m.select(3, &s);
    } else if (in_l.get_selected() == 3 && in_m.get_selected() == 0) {
        in_m.select(1, &s);
    } else if (in_l.get_selected() == 0 && in_m.get_selected() == 1) {
        in_l.select(3, &s);
    } else if (in_l.get_selected() == 0 && in_m.get_selected() == 3) {
        in_l.select(1, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}

void MainWindow::on_b_RSquare_clicked()
{
    if (in_r.get_selected() == 3) {
        in_r.select(0, &s);
        return;
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0) {
        in_l.select(0, &s);
        in_m.select(0, &s);
        in_r.select(0, &s);
    }
    in_r.select(3, &s);

    if (in_l.get_selected() == 1 && in_m.get_selected() == 0) {
        in_m.select(2, &s);
    } else if (in_l.get_selected() == 2 && in_m.get_selected() == 0) {
        in_m.select(1, &s);
    } else if (in_l.get_selected() == 0 && in_m.get_selected() == 1) {
        in_l.select(2, &s);
    } else if (in_l.get_selected() == 0 && in_m.get_selected() == 2) {
        in_l.select(1, &s);
    }
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}

// the rest (you're reading too much just give up)

void MainWindow::on_b_LSphere_clicked()
{
    if (out_l.get_selected() == 1) {
        out_l.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_l.select(1, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_LCube_clicked()
{
    if (out_l.get_selected() == 2) {
        out_l.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_l.select(2, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_LPyramid_clicked()
{
    if (out_l.get_selected() == 3) {
        out_l.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_l.select(3, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_LCylinder_clicked()
{
    if (out_l.get_selected() == 4) {
        out_l.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_l.select(4, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_LPrism_clicked()
{
    if (out_l.get_selected() == 5) {
        out_l.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_l.select(5, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_LCone_clicked()
{
    if (out_l.get_selected() == 6) {
        out_l.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_l.select(6, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_MSphere_clicked()
{
    if (out_m.get_selected() == 1) {
        out_m.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_m.select(1, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_MCube_clicked()
{
    if (out_m.get_selected() == 2) {
        out_m.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_m.select(2, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_MPyramid_clicked()
{
    if (out_m.get_selected() == 3) {
        out_m.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_m.select(3, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_MCylinder_clicked()
{
    if (out_m.get_selected() == 4) {
        out_m.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_m.select(4, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_MPrism_clicked()
{
    if (out_m.get_selected() == 5) {
        out_m.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_m.select(5, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_MCone_clicked()
{
    if (out_m.get_selected() == 6) {
        out_m.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_m.select(6, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_RSphere_clicked()
{
    if (out_r.get_selected() == 1) {
        out_r.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_r.select(1, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_RCube_clicked()
{
    if (out_r.get_selected() == 2) {
        out_r.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_r.select(2, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_RPyramid_clicked()
{
    if (out_r.get_selected() == 3) {
        out_r.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_r.select(3, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_RCylinder_clicked()
{
    if (out_r.get_selected() == 4) {
        out_r.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_r.select(4, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_RPrism_clicked()
{
    if (out_r.get_selected() == 5) {
        out_r.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_r.select(5, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_RCone_clicked()
{
    if (out_r.get_selected() == 6) {
        out_r.select(0, &s);
        return;
    }
    if (out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        out_l.select(0, &s);
        out_m.select(0, &s);
        out_r.select(0, &s);
    }
    out_r.select(6, &s);
    if (in_l.get_selected() != 0 && in_m.get_selected() != 0 && in_r.get_selected() != 0 && out_l.get_selected() != 0 && out_m.get_selected() != 0 && out_r.get_selected() != 0) {
        s.write_val(0, in_l.get_selected());
        s.write_val(1, in_m.get_selected());
        s.write_val(2, in_r.get_selected());
        s.write_val(3, out_l.get_selected()+3);
        s.write_val(4, out_m.get_selected()+3);
        s.write_val(5, out_r.get_selected()+3);
        std::string out = s.dissection();

        QString output_string = QString::fromStdString(out);

        ui->outText->clear();
        ui->outText->appendPlainText(output_string);
    }
}


void MainWindow::on_b_Reset_clicked()
{
    in_l.select(0, &s);
    in_m.select(0, &s);
    in_r.select(0, &s);
    out_l.select(0, &s);
    out_m.select(0, &s);
    out_r.select(0, &s);
    ui->outText->clear();
}


void MainWindow::on_Mode_clicked()
{
    if (ui->Mode->isChecked() == false) {
        ui->Mode->setText("Current Mode:\nRegular");
        std::cout << "Challenge Mode Disabled" << std::endl << std::endl;
        s.set_challengeMode(false);
    } else {
        ui->Mode->setText("Current Mode:\nChallenge");
        std::cout << "Challenge Mode Enabled" << std::endl << std::endl;
        s.set_challengeMode(true);
    }
}

