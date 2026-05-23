#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario{
    char username[50];
    int hashSenha;
    struct usuario *prox;
} Usuario;

typedef struct tabelaHash{
    Usuario **itens;
    int qtd;
    int size;
} *TabelaHash;


int valorString(TabelaHash th, char* senha);
TabelaHash criaHash(int size);
int insereHash(TabelaHash th, char *nome, char *senha);
int buscaHash(TabelaHash th, char* user, char* senha);
char removeHash();
void liberaHash(TabelaHash th);
void imprimeHash(TabelaHash th);

int main(){

    return 0;
}

int valorString(TabelaHash th, char* senha){
    int soma = 0;
    int i = 0;

    while(senha[i] != '\0'){
        soma += senha[i];
        i++;
    }

    return soma % th->size;
}

TabelaHash criaHash(int size){
    TabelaHash th = malloc(sizeof(struct tabelaHash));

    if(th != NULL){
        th->size = size;
        th->qtd = 0;
        th->itens = malloc(sizeof(Usuario*) *size);
        if(th->itens != NULL){
            for(int i = 0; i < size; i++)
                th->itens[i] = NULL;
        }
    }
    return th;
}

int insereHash(TabelaHash th, char *nome, char *senha){

    if(th == NULL){
        return 1;
    }

    Usuario *user = malloc(sizeof(Usuario));

    if(user == NULL){
        return 1;
    }

    strcpy(user->username, nome);

    int pos = valorString(th, senha);

    user->hashSenha = pos;

    user->prox = th->itens[pos];
    th->itens[pos] = user;

    th->qtd++;

    return 0;
}

int buscaHash(TabelaHash th, char* user, char* senha){
    if(th == NULL || th->itens == NULL)
        return 1;

    if(user == NULL || senha == NULL)
        return 1;

    int hashSenhaDigitada = valorString(th, senha);
    int indice = valorString(th, user);
    
    Usuario *atual = th->itens[indice];

    while(atual != NULL){
        if(strcmp(atual->username, user) == 0 && atual->hashSenha == hashSenhaDigitada)
            return 0;
        
        atual = atual->prox;
    }

    return 1;
}

char removeHash(){

}

void liberaHash(TabelaHash th){

    if(th == NULL)
        return;
    
    for(int i = 0; i < th->size; i++){
        Usuario *aux = th->itens[i];
        while(aux != NULL){
            Usuario *temp = aux;
            aux = aux->prox;
            free(temp);
        }
    }
    free(th->itens);
    free(th);
}

void imprimeHash(TabelaHash th){

    if(th == NULL){
        printf("Não existe tabela!\n");
        return;
    }
    
    for(int i = 0; i < th->size; i++){
        Usuario *aux = th->itens[i];
        printf("[%d]: ", i);
        
        while(aux != NULL){
            printf("(%s | %d) -> ", aux->username, aux->hashSenha);
            aux = aux->prox;
        }

        printf("NULL\n");
    }

}