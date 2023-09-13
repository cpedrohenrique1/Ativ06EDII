#include "Conjunto.h"

Conjunto::Conjunto(int **array, int &tamanho_vetor):
    array_selectionsort(0),
    tamanho_arrayselectionsort(tamanho_vetor),
    nmr_execucoes(0)
{
    if (tamanho_vetor <= 0)
    {
        throw QString("Tamanho invalido");
    }
    if ((*array)){
        delete[] (*array);
        (*array) = 0;
    }
    try
    {
        (*array) = new int[tamanho_vetor];
        array_selectionsort = new int[tamanho_arrayselectionsort];
        srand(time(0));
        for (int i = 0; i < tamanho_vetor; ++i)
        {
            (*array)[i] = array_selectionsort[i] = rand() % 1001;
        }
        selectionSort();
    }
    catch (std::bad_alloc &e)
    {
        throw QString("Erro ao alocar memoria para criacao de array");
    }
}

void Conjunto::selectionSort(){
    if (!array_selectionsort || tamanho_arrayselectionsort <= 0){
        throw QString("Vetor nao criado");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    for (int indice = 0; indice < tamanho_arrayselectionsort - 1; ++indice){
        int min_idc = indice;
        for (int i = indice + 1; i < tamanho_arrayselectionsort; ++i){
            if (array_selectionsort[i] < array_selectionsort[min_idc]){
                min_idc = i;
            }
            ++nmr_execucoes;
        }
        int temp = array_selectionsort[indice];
        array_selectionsort[indice] = array_selectionsort[min_idc];
        array_selectionsort[min_idc] = temp;
    }
}

int *Conjunto::getArraySelectionSort() const{
    return array_selectionsort;
}

int Conjunto::getTamanhoArraySelectionSort() const{
    return tamanho_arrayselectionsort;
}

int Conjunto::getNmrExecucoes() const{
    return nmr_execucoes;
}