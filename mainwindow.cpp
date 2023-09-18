#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "Conjunto.h"
#include "QMessageBox"
#include "busca.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vetor(0)
    , tamanho_vetor(0)
    , vetor_ordenado(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (vetor_ordenado){
        delete[] vetor_ordenado;
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
        if (vetor_ordenado){
            delete[] vetor_ordenado;
            vetor_ordenado = 0;
            tamanho_vetor = 0;
        }

        tamanho_vetor = input_dado.toInt();
        Conjunto conj(&vetor, tamanho_vetor);
        vetor_ordenado = new int[tamanho_vetor];
        for (int i = 0; i < tamanho_vetor; ++i){
            vetor_ordenado[i] = conj.getArraySelectionSort()[i];
        }
        QString saida_dados_aleatorios = "";
        QString saida_dados_ordenados = "";

        for (int i = 0; i < tamanho_vetor; ++i){
            saida_dados_aleatorios += "|" + QString::number(vetor[i]) + "| -> ";
            saida_dados_ordenados += "|" + QString::number(vetor_ordenado[i]) + "| -> ";
        }
        ui->textEdit_dados_aleatorios_vetor->setText(saida_dados_aleatorios);
        ui->textEdit_dados_vetor_ordenado->setText(saida_dados_ordenados);
        ui->textEdit_saida_numero_execucoes_dados_ordenado->setText(QString::number(conj.getNmrExecucoes()));
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
        if (ui->lineEdit_valor_busca_sequencial->text().isNull() || ui->lineEdit_valor_busca_sequencial->text().isEmpty()){
            throw QString("entrada da busca nao pode ser vazia");
        }
        int entrada = ui->lineEdit_valor_busca_sequencial->text().toInt();
        Busca busca(vetor, tamanho_vetor);
        int resultado = busca.BuscaSequencial(entrada);
        if (resultado == -1){
            ui->textEdit_resultado_busca_sequencial->setText("Nao foi encontrado");
        }else{
            ui->textEdit_resultado_busca_sequencial->setText("Foi encontrado e esta na posicao " + QString::number(resultado));
            ui->textEdit_saida_numero_execucoes_busca_sequencial->setText(QString::number(busca.getContador()));
        }
    }catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
}


void MainWindow::on_pushButton_buscar_sequencial_vetor_ordenado_clicked()
{
    try{
        if (!vetor_ordenado || tamanho_vetor <= 0){
            throw QString("Vetor nao existe");
        }
        if (ui->lineEdit_busca_sequencial_vetor_ordenado->text().isNull() || ui->lineEdit_busca_sequencial_vetor_ordenado->text().isEmpty()){
            throw QString("entrada da busca nao pode ser vazia");
        }
        int entrada = ui->lineEdit_busca_sequencial_vetor_ordenado->text().toInt();
        Busca busca(vetor_ordenado, tamanho_vetor);
        int resultado = busca.BuscaSequencialMelhorada(entrada);
        if (resultado == -1){
            ui->textEdit_resultado_busca_sequencial_vetor_ordenado->setText("Nao foi encontrado");
        }else{
            ui->textEdit_resultado_busca_sequencial_vetor_ordenado->setText("Foi encontrado e esta na posicao " + QString::number(resultado));
            ui->textEdit_saida_numero_execucoes_busca_sequencial_vetor_ordenado->setText(QString::number(busca.getContador()));
        }
    }catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
}


void MainWindow::on_pushButton_busca_binaria_clicked()
{
    try{
        if (!vetor_ordenado || tamanho_vetor <= 0){
            throw QString("Vetor nao existe");
        }
        if (ui->lineEdit_busca_binaria->text().isNull() || ui->lineEdit_busca_binaria->text().isEmpty()){
            throw QString("entrada da busca nao pode ser vazia");
        }
        int entrada = ui->lineEdit_busca_binaria->text().toInt();
        Busca busca(vetor_ordenado, tamanho_vetor);
        int resultado = busca.BuscaBinaria(entrada);
        if (resultado == -1){
            ui->textEdit_resultado_busca_binaria->setText("Nao foi encontrado");
        }else{
            ui->textEdit_resultado_busca_binaria->setText("Foi encontrado e esta na posicao " + QString::number(resultado));
            ui->textEdit_saida_numero_execucoes_busca_binaria->setText(QString::number(busca.getContador()));
        }
    }catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
}

