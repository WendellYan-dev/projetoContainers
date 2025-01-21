#include <stdio.h>
#include <stdlib.h>

// para usar a busca binária,é recomendado o vetor estar ORDENADO
int buscaBinaria(int *lista,int chave,int inicio,int fim){
    int meio;
    if(inicio <= fim){
        meio = (inicio+fim)/2;
        if(chave == lista[meio]) {
            printf("Valor encontrado: %d",lista[meio]);
            return 0;
        } else {
            if(chave < lista[meio]){
                return buscaBinaria(lista,chave,inicio,meio-1);
            } else {
                return buscaBinaria(lista,chave,meio+1,fim);
            }
        }
    } else {
        printf("ELEMENTO NÃO ENCONTRADO\n");
        return -1;
    }
    
}

int main() {
    int lista[] = {-5,8,12,17,44,86,90};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int chave;
    printf("qual elemento você procura?\n");
    scanf("%d", &chave);
    buscaBinaria(lista,chave,0,tamanho);

    return 0;
}
