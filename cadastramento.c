#include<stdio.h>
#include "lista.h"

int main(){
    char nome[50];
    char cidade[50];
    int opcao = 0, idade;
    Lista lista = inicializar();

    while(opcao != 5){      
        printf("\n(1)Realizar Cadastro\n(2)Remover Cadastro\n(3)Consultar Cadastro");
        printf("\n(4)Listar cadastros\n(5)Sair\n");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("\nDigite o nome: ");
                scanf(" %[^\n]s",nome);
                printf("\nDigite a cidade: ");
                scanf(" %[^\n]s",cidade);
                printf("\nDigite a idade: ");
                scanf("%d",&idade);
                lista = inserir(lista, nome, cidade, idade);
                break;

            case 2:
                printf("\nDigite o nome: ");
                scanf(" %[^\n]s",nome);
                lista = remover(lista, nome);
                break;

            case 3:
                printf("\nDigite o nome: ");
                scanf(" %[^\n]s",nome);
                buscar(lista, nome);
                break;

            case 4:
                listar(lista);
                break;

            case 5:
                lista = destruir(lista);
                continue;

            default:
                printf("\nOpcao invalida!\nTente novamente!");
        }
    }
    return 0;
}