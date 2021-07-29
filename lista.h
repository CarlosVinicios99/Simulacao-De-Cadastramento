#ifndef lista_h
#define lista_h

typedef struct lista *Lista;

Lista inicializar();
Lista inserir(Lista lista, char *nome, char *cidade, int idade);
Lista remover(Lista lista, char *nome);
void listar(Lista lista);
void buscar(Lista lista, char *nome);
Lista destruir(Lista lista);


#endif