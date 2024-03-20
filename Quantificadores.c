#include <stdio.h>
#include <stdlib.h>

int isPrimo(int numero) {
    if (numero <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}


int* lerArquivo(const char* nomeArquivo, int* tamanhoArray) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    int numero;
    *tamanhoArray = 0;
    while (fscanf(arquivo, "%d", &numero) == 1) {
        (*tamanhoArray)++;
    }

    int *array = (int*)malloc(*tamanhoArray * sizeof(int));

    if (array == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    fseek(arquivo, 0, SEEK_SET);

    for (int i = 0; i < *tamanhoArray; i++) {
        fscanf(arquivo, "%d", &array[i]);
    }

    fclose(arquivo);
    return array;
}

int verificarPositivos(int* array, int tamanhoArray ){
    for (int i = 0; i < tamanhoArray; i++) {
        if(array[i] < 0){
            return 0;
        }
    }
    printf("Todos os números são positivos\n");
    return 1;
}

int verificarNegativas(int* array, int tamanhoArray ){
    for (int i = 0; i < tamanhoArray; i++) {
        if(array[i] > 0){
            return 0;
        }
    }
    printf("Todos os números não são positivos\n");
    return 1;
}

int verificarPrimo(int* array, int tamanhoArray ){
    for (int i = 0; i < tamanhoArray; i++) {
        if(isPrimo(array[i]) == 1){
            printf("Há um número primo cujo valor é .... %d\n", array[i]);
            return 0;
        }
    }
    printf("Não há números primos\n");
    return 1;
}

int main() {
    const char* nomeArquivo = "numero45.txt";
    int tamanhoArray;
    int* array = lerArquivo(nomeArquivo, &tamanhoArray);
    int hasPositivo, hasNegativo;
    hasPositivo = verificarPositivos(array, tamanhoArray);
    hasNegativo = verificarNegativas(array, tamanhoArray);

    if(hasNegativo + hasPositivo == 0){
        printf("Nem todos os numeros sao positivos\n");
    }

    verificarPrimo(array, tamanhoArray);

    free(array);

    return 0;
}