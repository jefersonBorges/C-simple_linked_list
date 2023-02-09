/*Exercício 2 
    Inserção em lista encadeada com verificação de duplicidade
    Utilizar o nodo ponto turístico.
    Ao inserir um novo nodo, realizar uma verificação se o nodo já existe na lista.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PontoTuristico {
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};

struct PontoTuristico* criar_lista(void){
    return NULL;
}

void ler_ponto(struct PontoTuristico *ponto){
    printf("\nEspaco %p", ponto);

    printf("\nDescricao: ");
    scanf("%[^\n]", ponto->descricao);
    fflush(stdin);

    printf("\nLatitude: ");
    scanf("%f", &ponto->latitude);
    fflush(stdin);

    printf("\nLongitude: ");
    scanf("%f", &ponto->longitude);
    fflush(stdin);
}

int verifica_duplicidade(struct PontoTuristico *cabeca, struct PontoTuristico *novo){
    struct PontoTuristico *paux;
    for(paux = cabeca; paux != NULL; paux = paux->proximo){
        if(strcmp(novo->descricao, paux->descricao) == 0){
            printf("\n Valor Duplicado");
            free(novo);
            return 0;
        }
    }
    return 1;
}

struct PontoTuristico* insere_ordenado(struct PontoTuristico *cabeca){
    struct PontoTuristico *novo = (struct PontoTuristico*) malloc (sizeof(struct PontoTuristico));
    struct PontoTuristico *paux, *paux_anterior;

    ler_ponto(novo);

    if(cabeca == NULL){
        cabeca = novo;
        cabeca->proximo = NULL;
        return cabeca;
    } else {
        if(verifica_duplicidade(cabeca, novo) == 0){
            return cabeca;
        }
        if(strcmp(novo->descricao, cabeca->descricao) < 0){
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

int main(){
    struct PontoTuristico *cabeca;
    cabeca = criar_lista();
    cabeca = insere_ordenado(cabeca);
    cabeca = insere_ordenado(cabeca);
    cabeca = insere_ordenado(cabeca);
    cabeca = insere_ordenado(cabeca);
    imprimir(cabeca);

    return 0;
}