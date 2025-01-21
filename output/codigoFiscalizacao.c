#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} Container;




int main() {
    int n;

    printf("Digite o número de contêineres cadastrados:\n");
    scanf("%d", &n);
    Container *cadastrados = malloc(n * sizeof(Container));
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

    free(cadastrados);
    return 0;
}