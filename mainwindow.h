#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Conjunto.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_gerar_clicked();

    void on_pushButton_buscar_sequencial_clicked();

    void on_pushButton_buscar_sequencial_vetor_ordenado_clicked();

    void on_pushButton_busca_binaria_clicked();

private:
    Ui::MainWindow *ui;
    int *vetor;
    int tamanho_vetor;
    Conjunto *conj;

};
#endif // MAINWINDOW_H
