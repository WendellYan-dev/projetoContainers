#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *lista, int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;
        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio, fim);
        merge(lista, inicio, meio, fim);
    }
}

void merge(int *lista, int inicio, int meio, int fim) {

    int tamEsq = meio - inicio;
    int tamDir = fim - meio;

//alocação de memória dinâmica para vetores "temporários á esquerda e á direita" com o tamnnho pré-definido acima
    int *esquerda = (int *)malloc(tamEsq*sizeof(int));
    int *direita = (int *)malloc(tamDir*sizeof(int));

    if (esquerda != NULL && direita != NULL) {
//lopp de preenchimento dos vetores temporários
        for (int i = 0; i < tamEsq; i++) {
            esquerda[i] = lista[inicio + i];
        }
        for (int i = 0; i < tamDir; i++) {
            direita[i] = lista[meio + i];
        }

        int i = 0, j = 0, k = inicio;

//aqui é realizada a comparação entre os valores dos vetores temporários e a ordenação dos valores no vetor principal(essa ordenação é decrescente=condição verificada na linha 35)
        while (i < tamEsq && j < tamDir) {
            if (esquerda[i] > direita[j]) {
                lista[k++] = esquerda[i++];
            } else {
                lista[k++] = direita[j++];
            }
        }
        
//preenchendo o vetor principal com os valores restantes.Essa parte é importante pois, após a comparação, pode haver elementos sobrando nas duas metades. Como o código ancima já preencheu o vetor lista até o ponto em que uma das metades acabou, essa estrutura garante que qualquer valor restante na outra metade seja copiado para o vetor principal lista
        while (i < tamEsq) {
            lista[k++] = esquerda[i++];
        }
        while (j < tamDir) {
            lista[k++] = direita[j++];
        }

//liberando a memória dos vetores temporários
        free(esquerda);
        free(direita);
    } else {
        printf("Erro ao alocar memória.\n");
    }
}


int main() {
    int lista[] = {-651, 687, 166, -835, -320, -523, -55, 311, 280, -713, -148, -255, -469, -466, 614, -419, -961, -882, 307, 845};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    mergeSort(lista, 0, tamanho);
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
