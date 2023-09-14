#include "busca.h"
#include "QString"

Busca::Busca(int *array, int &tamanho_array):
    vetor(0),
    tamanho_vetor(tamanho_array),
    contador(0)
{
    if (tamanho_array <= 0 || !array){
        throw QString("Vetor nao criado");
    }
    try
    {
        vetor = new int[tamanho_array];
        for (int i = 0; i < tamanho_array; ++i){
            vetor[i] = array[i];
        }
    }
    catch(std::bad_alloc& e)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

Busca::~Busca(){
    if (vetor){
        delete[] vetor;
    }
}

int Busca::BuscaSequencial(int entrada){
    if (!vetor || tamanho_vetor <= 0){
        throw QString("Erro, vetor nao criado");
    }
    if (contador){
        contador = 0;
    }
    for (int i = 0; i < tamanho_vetor; ++i){
        if (vetor[i] == entrada){
            return i;
        }
        ++contador;
    }
    return -1;
}

int Busca::BuscaSequencialMelhorada(int entrada){
    if (!vetor || tamanho_vetor <= 0){
        throw QString("Erro, vetor nao criado");
    }
    if (contador){
        contador = 0;
    }
    for (int i = 0; i < tamanho_vetor; ++i){
        if (vetor[i] == entrada){
            return i;
        }
        if (vetor[i] > entrada){
            return -1;
        }
        ++contador;
    }
    return -1;
}

int Busca::BuscaBinaria(int entrada){
    if (!vetor || tamanho_vetor <= 0){
        throw QString("Erro, vetor nao criado");
    }
    if (contador){
        contador = 0;
    }
    int inicio = 0;
    int fim = tamanho_vetor - 1;
    while (inicio <= fim){
        int meio = (inicio + fim)/2;
        if (vetor[meio] == entrada){
            return meio;
        }
        if (vetor[meio] < entrada){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }
        ++contador;
    }
    return -1;
}

int Busca::getContador() const{
    return contador;
}