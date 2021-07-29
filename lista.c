#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

struct lista{
    char nome[50];
    char cidade[50];
    int idade;
    struct lista *prox;
};

Lista inicializar(){
    Lista lista = NULL;
    FILE *arq = fopen("cadastros.bin", "rb");

    if(arq == NULL){
        return lista;
    }
    else{
        fseek(arq, 0, SEEK_END);
        long tamanhoDoArquivo = ftell(arq);
        int qtdCadastros = tamanhoDoArquivo / (sizeof(struct lista) - sizeof(Lista));
        rewind(arq);
        char nome[50], cidade[50];
        int idade;
        for(int i = 0; i < qtdCadastros; i++){
            fread(nome, sizeof(char), 50, arq);
            fread(cidade, sizeof(char), 50, arq);
            fread(&idade, sizeof(int), 1, arq);
            lista = inserir(lista, nome, cidade, idade);
        }
        fclose(arq);
        return lista;
    }
}

Lista inserir(Lista lista, char *nome, char *cidade, int idade){ 

    Lista novoCadastro = (Lista) malloc(sizeof(struct lista));

    strcpy(novoCadastro->nome, nome);
    strcpy(novoCadastro->cidade, cidade);
    novoCadastro->idade = idade;
    novoCadastro->prox = lista;

    return novoCadastro;

}

Lista remover(Lista lista, char *nome){

    if(lista == NULL){
        return NULL;
    }   

    Lista aux, ant;
    ant = lista;
    aux = ant->prox;
    if(strcmp(ant->nome, nome) == 0){
        lista = aux;
        free(ant);
        return lista;
    }
    else{
        while(aux != NULL && strcmp(aux->nome, nome) != 0){
            ant = aux;
            aux = aux->prox;
        }
        if(aux != NULL){
            ant->prox = aux->prox;
            free(aux);
        }
        return lista;
    }
}

void listar(Lista lista){

    while(lista != NULL){
        printf("\nNOME: %s\nCIDADE: %s\nIDADE: %d anos\n\n",lista->nome, lista->cidade, lista->idade);
        lista = lista->prox;
    }
}

void buscar(Lista lista, char *nome){
    while(lista != NULL){   

        if(strcmp(lista->nome, nome) == 0){
            printf("\nCadastro Encontrado!");
            printf("\nNOME: %s\nCIDADE: %s\nIDADE: %d anos\n", lista->nome, lista->cidade, lista->idade);
            return;
        }
        lista = lista->prox;
    }
    printf("\nCadastro NAO Encontrado!");  
}

Lista destruir(Lista lista){
    FILE *arq = fopen("cadastros.bin","wb");
    Lista aux = lista;

    while(aux != NULL){
        fwrite(aux->nome, sizeof(char), 50, arq);
        fwrite(aux->cidade, sizeof(char), 50, arq);
        fwrite(&aux->idade, sizeof(int), 1, arq);
        free(aux);
        lista = lista->prox;
        aux = lista;
    }

    fclose(arq);
    return NULL;
}

