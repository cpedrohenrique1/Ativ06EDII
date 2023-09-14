#ifndef BUSCA_H_
#define BUSCA_H_

class Busca{
private:
    int *vetor;
    int tamanho_vetor;
    int contador;
public:
    Busca(int *array, int &tamanho_array);
    ~Busca();
    int BuscaSequencial(int entrada);
    int BuscaSequencialMelhorada(int entrada);
    int BuscaBinaria(int entrada);
    int getContador() const;
};

#endif