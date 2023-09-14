#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "Conjunto.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vetor(0)
    , tamanho_vetor(0)
    , conj(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (conj){
        delete conj;
    }
    if (vetor){
        delete[] vetor;
    }
    delete ui;
}


void MainWindow::on_pushButton_gerar_clicked()
{
    try{
        QString input_dado = ui->lineEdit_quantidade_elementos->text();
        if (input_dado.isNull() || input_dado.isEmpty() || input_dado.toInt() <= 0){
            throw QString("Valor invalido, insira um numero maior que 0");
        }
        if (vetor || tamanho_vetor > 0){
            delete[] vetor;
            vetor = 0;
            tamanho_vetor = 0;
        }
        tamanho_vetor = input_dado.toInt();
        conj = new Conjunto(&vetor, tamanho_vetor);
        QString saida_dados_aleatorios = "";
        QString saida_dados_ordenados = "";

        for (int i = 0; i < tamanho_vetor; ++i){
            saida_dados_aleatorios += "|" + QString::number(vetor[i]) + "| ";
            saida_dados_ordenados += "|" + QString::number(conj->getArraySelectionSort()[i]) + "| ";
        }
        ui->textEdit_dados_aleatorios_vetor->setText(saida_dados_aleatorios);
        ui->textEdit_dados_vetor_ordenado->setText(saida_dados_ordenados);
        ui->textEdit_saida_numero_execucoes_dados_ordenado->setText(QString::number(conj->getNmrExecucoes()));
    }catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
}


void MainWindow::on_pushButton_buscar_sequencial_clicked()
{
    try{
        if (!vetor || tamanho_vetor <= 0){
            throw QString("Vetor nao existe");
        }
        
    }catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
}


void MainWindow::on_pushButton_buscar_sequencial_vetor_ordenado_clicked()
{
    try{
        if (!vetor || tamanho_vetor <= 0){
            throw QString("Vetor nao existe");
        }
    }catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
}


void MainWindow::on_pushButton_busca_binaria_clicked()
{
    try{
        if (!vetor || tamanho_vetor <= 0){
            throw QString("Vetor nao existe");
        }
    }catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
}

