/* Exercício - 1 - Verificação de Listas Iguais
    
    Utilizando o nodo Ponto Turístico, desenvolva uma função que receba duas listas
    simplesmente encadeadas. 
    A função deve retornar o valor “1” se as duas listas são iguais, 
    ou retornar “0”, em caso contrário. 
    Duas listas são consideradas iguais se os seus nodos possuem os mesmos valores
    para a descrição de cada ponto turístico e estão na mesma sequência.
    Duas listas vazias são consideradas iguais.
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

int verifica_duas_listas_iguais(struct PontoTuristico *cabeca_lista1, struct PontoTuristico *cabeca_lista2){
    struct PontoTuristico *paux_lista1, *paux_lista2;
    int resultado;

    if(cabeca_lista1 == NULL && cabeca_lista2 == NULL){
        resultado = 1;
        return resultado;
    }

    paux_lista1 = cabeca_lista1;
    paux_lista2 = cabeca_lista2;
    while(paux_lista1 != NULL && paux_lista2 != NULL){
        if(strcmp(paux_lista1->descricao, paux_lista2->descricao) == 0){
            resultado = 1;
        } else {
            resultado = 0;
        }
        paux_lista1 = paux_lista1->proximo;
        paux_lista2 = paux_lista2->proximo;
    }
    return resultado;
}

int main(){
    printf("\nDados para a lista 1");
    struct PontoTuristico *cabeca;
    cabeca = criar_lista();
    //cabeca = insere_ordenado(cabeca);
    //cabeca = insere_ordenado(cabeca);
    //cabeca = insere_ordenado(cabeca);

    printf("\nDados para a lista 2");

    struct PontoTuristico *cabeca2;
    cabeca2 = criar_lista();
    //cabeca2 = insere_ordenado(cabeca2);
    //cabeca2 = insere_ordenado(cabeca2);
    //cabeca2 = insere_ordenado(cabeca2);

    if(verifica_duas_listas_iguais(cabeca, cabeca2) == 1){
        printf("\n Duas listas sao iguais");
    } else {
        printf("\n Duas listas diferentes");
    }
    printf("\nLista 1:");
    imprimir(cabeca);

    printf("\nLista 2:");
    imprimir(cabeca2);


    return 0;
}