#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_gerar_clicked()
{

}


void MainWindow::on_pushButton_buscar_sequencial_clicked()
{

}


void MainWindow::on_pushButton_buscar_sequencial_vetor_ordenado_clicked()
{

}


void MainWindow::on_pushButton_busca_binaria_clicked()
{

}

