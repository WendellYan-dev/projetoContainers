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

    //alocação de memória dinâmica para vetores "temporários á esquerda e á direita"
    int *esquerda = (int *)malloc(tamEsq*sizeof(int));
    int *direita = (int *)malloc(tamDir*sizeof(int));

    if (esquerda != NULL && direita != NULL) {

        for (int i = 0; i < tamEsq; i++) {
            esquerda[i] = lista[inicio + i];
        }
        for (int i = 0; i < tamDir; i++) {
            direita[i] = lista[meio + i];
        }

        int i = 0, j = 0, k = inicio;

        while (i < tamEsq && j < tamDir) {
            if (esquerda[i] > direita[j]) {
                lista[k++] = esquerda[i++];
            } else {
                lista[k++] = direita[j++];
            }
        }
        
        while (i < tamEsq) {
            lista[k++] = esquerda[i++];
        }
        while (j < tamDir) {
            lista[k++] = direita[j++];
        }

        free(esquerda);
        free(direita);
    } else {
        printf("Erro ao alocar memória.\n");
    }
}


int main() {
    int lista[] = {38, 347, -5, 3, 9, 82, 10};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    mergeSort(lista, 0, tamanho);

    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
