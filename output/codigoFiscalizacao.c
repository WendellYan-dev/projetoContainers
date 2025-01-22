#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
A empresa de automação portuária **Poxim Tech** está desenvolvendo um sistema para a movimentação automatizada dos contêineres de carga de origem internacional no Porto de Sergipe, com o objetivo de maximizar a eficiência da fiscalização aduaneira.

### Requisitos do Sistema:

- **Cadastro de Contêineres**: Todos os contêineres possuem um cadastro eletrônico contendo informações sobre:
  - O código do contêiner
  - O CNPJ da empresa importadora
  - O peso líquido em quilos

- **Critérios de Inspeção**: A inspeção dos contêineres ocorre sempre que há alguma divergência nas informações cadastradas, como:
  - Divergência no CNPJ informado
  - Diferença percentual superior a 10% no peso líquido

- **Critérios de Prioridade para Triagem**:
  1. Divergência de CNPJ
  2. Maior diferença percentual no peso líquido
  */
/*
### Exemplo de Entrada:
6
QOZJ7913219 34.699.211/9365-11 13822
FCCU4584578 50.503.434/5731-28 16022
KTAJ0603546 20.500.522/6013-58 25279
ZYHU3978783 43.172.263/4442-14 24543
IKQZ7582839 51.743.446/1183-18 12160
HAAZ0273059 25.699.428/4746-79 16644
5
ZYHU3978783 43.172.263/4442-14 29765
IKQZ7582839 51.743.446/1113-18 18501
KTAJ0603546 20.500.522/6113-58 17842
QOZJ7913219 34.699.211/9365-11 16722
FCCU4584578 50.503.434/5731-28 16398
*/
/*
1. **KTAJ0603546**: Divergência de CNPJ (20.500.522/6013-58 vs. 20.500.522/6113-58)
2. **IKQZ7582839**: Divergência de CNPJ (51.743.446/1183-18 vs. 51.743.446/1113-18)
3. **QOZJ7913219**: Diferença de peso (2900 kg ou 21%)
4. **ZYHU3978783**: Diferença de peso (5222 kg ou 21%)
*/

typedef struct {
    char codigo[12];
    char cnpj[19];
    int peso;
    int prioridade;
    int diferencaPercentual;
} Container;

void mergeInt(Container *lista, int inicio, int meio, int fim) {

    int tamEsq = meio - inicio;
    int tamDir = fim - meio;

//alocação de memória dinâmica para vetores "temporários á esquerda e á direita" com o tamnnho pré-definido acima
    Container *conteineresEsq = (Container *)malloc(tamEsq * sizeof(Container));
    Container *conteineresDir = (Container *)malloc(tamDir * sizeof(Container));
    if (conteineresEsq == NULL || conteineresDir == NULL) {
    printf("ERRO\n");
    return;
    }


    if (conteineresEsq != NULL && conteineresDir != NULL) {
//lopp de preenchimento dos vetores temporários
        for (int i = 0; i < tamEsq; i++) {
            conteineresEsq[i] = lista[inicio + i];
        }
        for (int i = 0; i < tamDir; i++) {
            conteineresDir[i] = lista[meio + i];
        }

        int i = 0, j = 0, k = inicio;

//aqui é realizada a comparação entre os valores dos vetores temporários e a ordenação dos valores no vetor principal(essa ordenação é decrescente=condição verificada na linha 35)
        while (i < tamEsq && j < tamDir) {
            //a verificação se o código do container da lista temporária da direita é menor ao da lista temporária esquerda
            if (conteineresEsq[i].diferencaPercentual > conteineresDir[j].diferencaPercentual) {
                //a função "stcrmp" retorna números positivos caso o da esquerda for maior que o da direitaa ou 0 se forem iguais
                lista[k++] = conteineresEsq[i++];
            } else {
                lista[k++] = conteineresDir[j++];
            }
        }
        
//preenchendo o vetor principal com os valores restantes.Essa parte é importante pois, após a comparação, pode haver elementos sobrando nas duas metades. Como o código ancima já preencheu o vetor lista até o ponto em que uma das metades acabou, essa estrutura garante que qualquer valor restante na outra metade seja copiado para o vetor principal lista
        while (i < tamEsq) {
            lista[k++] = conteineresEsq[i++];
        }
        while (j < tamDir) {
            lista[k++] = conteineresDir[j++];
        }

//liberando a memória dos vetores temporários
        free(conteineresEsq);
        free(conteineresDir);
        printf("lista ordenada dos selecionados\n");
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void mergeSortInt(Container *lista, int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;
        mergeSortInt(lista, inicio, meio);
        mergeSortInt(lista, meio, fim);
        mergeInt(lista, inicio, meio, fim);
    }
}


void mergeSort(Container *lista, int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;
        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio, fim);
        merge(lista, inicio, meio, fim);
    }
}

void merge(Container *lista, int inicio, int meio, int fim) {

    int tamEsq = meio - inicio;
    int tamDir = fim - meio;

//alocação de memória dinâmica para vetores "temporários á esquerda e á direita" com o tamnnho pré-definido acima
    Container *conteineresEsq = (Container *)malloc(tamEsq * sizeof(Container));
    Container *conteineresDir = (Container *)malloc(tamDir * sizeof(Container));
    if (conteineresEsq == NULL || conteineresDir == NULL) {
    printf("ERRO\n");
    return;
    }


    if (conteineresEsq != NULL && conteineresDir != NULL) {
//lopp de preenchimento dos vetores temporários
        for (int i = 0; i < tamEsq; i++) {
            conteineresEsq[i] = lista[inicio + i];
        }
        for (int i = 0; i < tamDir; i++) {
            conteineresDir[i] = lista[meio + i];
        }

        int i = 0, j = 0, k = inicio;

//aqui é realizada a comparação entre os valores dos vetores temporários e a ordenação dos valores no vetor principal(essa ordenação é decrescente=condição verificada na linha 35)
        while (i < tamEsq && j < tamDir) {
            //a verificação se o código do container da lista temporária da direita é menor ao da lista temporária esquerda
            if (strcmp(conteineresEsq[i].codigo, conteineresDir[j].codigo) > 0) {
                //a função "stcrmp" retorna números positivos caso o da esquerda for maior que o da direitaa ou 0 se forem iguais
                lista[k++] = conteineresEsq[i++];
            } else {
                lista[k++] = conteineresDir[j++];
            }
        }
        
//preenchendo o vetor principal com os valores restantes.Essa parte é importante pois, após a comparação, pode haver elementos sobrando nas duas metades. Como o código ancima já preencheu o vetor lista até o ponto em que uma das metades acabou, essa estrutura garante que qualquer valor restante na outra metade seja copiado para o vetor principal lista
        while (i < tamEsq) {
            lista[k++] = conteineresEsq[i++];
        }
        while (j < tamDir) {
            lista[k++] = conteineresDir[j++];
        }

//liberando a memória dos vetores temporários
        free(conteineresEsq);
        free(conteineresDir);
        printf("lista ordenada dos selecionados\n");
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

// para usar a busca binária,é recomendado o vetor estar ORDENADO
int buscaBinaria(Container *lista,char *chave,int inicio,int fim){
    int meio;
    if(inicio <= fim){
        meio = (inicio+fim)/2;
        //retornará 0 caso o código do container selecionado bater com o já cadastrado,retornando 0,caso igual satisfazendo a condição
        if(strcmp(chave,lista[meio].codigo) == 0) {
            return meio;//vai retornar o índice na lista ordenada (a lista de cadastrados) em que a chave coincide com o código
        } else {
            if(strcmp(chave, lista[meio].codigo) < 0){
                //a função strcmp retornará um valor negativo quando o da direita for maior que o da esquerda,como nossa lista tá ordenada em ordem decrescente,os menores sempre estarão á direita,logo,o novo inicio será o meio+1
                return buscaBinaria(lista,chave,meio+1,fim);
            } else {
                //a funçaõ será chamada recursivamente caso o strcmp retorne um valor maior que 0.Logo,isso significa que o elemento que estou buscando é maior que o meio.
                //análogo ao que foi dito,os elementos mmaiores se encontram á esquerda,logo,o novo fim será meio -1
                return buscaBinaria(lista,chave,inicio,meio-1);
            }
        }
    } else {
        //quando não encontra o elemento
        return -1;
    }
    
}

void inspecionarConteineres(Container *cadastrados,Container *selecionados,Container *pesoIncompativel,int numeroCadastrados,int numeroSelecionados){
    //o lopp vai percorrer a lista de selecionados com base no código da lista de cadastrados(a qual está mantida sua ordem de cadastramento)
    for(int i =0;i<numeroCadastrados;i++){
        int indice = buscaBinaria(selecionados,cadastrados[i].codigo, 0 ,numeroSelecionados-1);
        //verificação para analisar se o código do selecionado bateu com o cadastrado
        //caso não bata,ele retorna -1,ao contrário,se for igual,o retorno é 0
        if(indice != -1){
                printf("Contêineres para inspeção (ordenados por prioridade):\n");
            //caso o cnpj seja difererente,ele retorna um valor diferente de 0,o que cai no else if
            if (strcmp(cadastrados[i].cnpj, selecionados[indice].cnpj) != 0) {
                // Divergência de CNPJ cai no campo prioridade como 1
                selecionados[indice].prioridade = 1;
                printf("%s: Divergência de CNPJ %s<->%s\n", selecionados[indice].codigo, cadastrados[i].cnpj,selecionados[indice].cnpj);

            } else if (abs(cadastrados[i].peso - selecionados[indice].peso) > 0.1 * cadastrados[i].peso) {
                //copia as informações para o struct pesoIncompativel
                strcpy(pesoIncompativel[i].codigo, selecionados[indice].codigo);
                strcpy(pesoIncompativel[i].cnpj, selecionados[indice].cnpj);
                pesoIncompativel[i].peso = cadastrados[i].peso - selecionados[indice].peso;
                //aqui é realizado o cálculo da diferença percentual entre o peso cadastrado e o peso selecionado,o "abs" é para garantir que o valor seja sempre positivo
                pesoIncompativel[i].diferencaPercentual = (int) roundf(((float) abs(cadastrados[i].peso - selecionados[indice].peso) / cadastrados[i].peso) * 100);
                pesoIncompativel[i].prioridade = 2;
                
            }
        }
    }
}



void ordenarPrioridade2(Container *pesoIncompativel, int m) {
    // Filtrando os contêineres com prioridade 2
    int tamanho = 0;
    for (int i = 0; i < m; i++) {
        if (pesoIncompativel[i].prioridade == 2) {
            tamanho++;
        }
    }
    
    // Ordenando os contêineres com diferenca percentual maior que 10%
    mergeSortInt(pesoIncompativel, 0, tamanho);
    
    //exibe os contêineres (já ordenados pelo mergesort)
    for (int i = 0;i<tamanho;i++){
            printf("%s: Diferença de peso %d (%.2d%%)\n", pesoIncompativel[i].codigo,pesoIncompativel[i].peso, pesoIncompativel[i].diferencaPercentual);
    }

}

int main() {
    int n,m;
    Container *cadastrados, *selecionados, *pesoIncompativel;

    printf("Digite o número de contêineres cadastrados:\n");
    scanf("%d", &n);
    pesoIncompativel = (Container* )malloc(n * sizeof(Container));
    cadastrados = (Container *)malloc(n * sizeof(Container));
    if (!cadastrados) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    for(int i = 0;i<n;i++){
        scanf("%s %s %d", cadastrados[i].codigo, cadastrados[i].cnpj, &cadastrados[i].peso);
    }
    
    printf("CONTEINERS CADASTRADOS\n");
    for(int i = 0;i<n;i++){
        printf("%s %s %d\n", cadastrados[i].codigo, cadastrados[i].cnpj, cadastrados[i].peso);
    }
    
    printf("Digite o número de contêineres selecionados:\n");
    scanf("%d", &m);
    selecionados = (Container *)malloc(m * sizeof(Container));
    if (!selecionados) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    for(int i = 0;i<m;i++){
        scanf("%s %s %d", selecionados[i].codigo, selecionados[i].cnpj, &selecionados[i].peso);
    }
    mergeSort(selecionados, 0 , m);
    
    
    printf("CONTEINERS selecionados\n");
    for(int i = 0;i<m;i++){
        printf("%s %s %d\n", selecionados[i].codigo, selecionados[i].cnpj, selecionados[i].peso);
    }
    inspecionarConteineres(cadastrados, selecionados,pesoIncompativel, n, m);

    ordenarPrioridade2(pesoIncompativel, m);
    
    free(cadastrados);
    free(selecionados);
    free(pesoIncompativel);
    return 0;
}