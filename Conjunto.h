#ifndef CONJUNTO_H_
#define CONJUNTO_H_
#include "QString"
#include "time.h"

class Conjunto{
    private:
        int *array_selectionsort;
        int tamanho_arrayselectionsort;
        int nmr_execucoes;
    public:
        Conjunto(int **array, int &tamanho_vetor);
        ~Conjunto();
        void selectionSort();
        int *getArraySelectionSort() const;
        int getTamanhoArraySelectionSort() const;
        int getNmrExecucoes() const;
};

#endif