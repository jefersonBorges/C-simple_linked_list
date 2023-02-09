
/* Exercicio - 0 - Lista ordenada
Criar uma operação para a lista que sempre insira o nodo de modo ordenado. 
A ordenação deve ser crescente utilizando a descrição do Ponto Turístico. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PontoTuristico{
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};

struct PontoTuristico* criar_lista(void){
    return NULL;
}

struct PontoTuristico ler_ponto(struct PontoTuristico *aux){
    printf("\nDescricao: ");
    scanf("%[^\n]", aux->descricao);
    fflush(stdin);

    printf("\nLatitude: ");
    scanf("%f", &aux->latitude);
    fflush(stdin);

    printf("\nLongitude: ");
    scanf("%f", &aux->longitude);
    fflush(stdin);
}

struct PontoTuristico* inserir_ordenado(struct PontoTuristico *cabeca){
    struct PontoTuristico *novo = (struct PontoTuristico*)malloc(sizeof(struct PontoTuristico));
    struct PontoTuristico *paux, *paux_anterior;
    ler_ponto(novo);


    if(cabeca == NULL){ /* ok */
        cabeca = novo;
        novo->proximo = NULL;
        return cabeca;
    } else {
        if (strcmp(novo->descricao, cabeca->descricao) < 0){ /* ok */
            novo->proximo = cabeca;
            return novo;
        } else {
            paux = cabeca;
            while(paux != NULL && strcmp(novo->descricao, paux->descricao) > 0){
                paux_anterior = paux;
                paux = paux->proximo;
            }
            paux_anterior->proximo = novo;
            novo->proximo = paux;
            return cabeca;
        }
    }
}

void imprimir(struct PontoTuristico *cabeca){
    struct PontoTuristico *paux;
    for(paux = cabeca; paux != NULL; paux = paux->proximo){
        printf(
            "\nDescricao: %s\tLatitude: %.2f\tLongitude: %.2f",
            paux->descricao, paux->latitude, paux->longitude
        );
    }
}

int verifica_lista_vazia(struct PontoTuristico *cabeca){
    return (cabeca == NULL);
}

int main(){
    struct PontoTuristico *cabeca;
    cabeca = criar_lista();
    cabeca = inserir_ordenado(cabeca);
    cabeca = inserir_ordenado(cabeca);
    cabeca = inserir_ordenado(cabeca);
    cabeca = inserir_ordenado(cabeca);

    imprimir(cabeca);

    return 0;
}