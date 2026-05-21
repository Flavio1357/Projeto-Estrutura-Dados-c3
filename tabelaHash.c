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
void insereHash();
char buscaHash(TabelaHash th, char* username, char* senha, int valor);
char removeHash();
void liberaHash();
void imprimeHash();

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

void insereHash(){
    
}

char buscaHash(TabelaHash th, char* user, char* senha, int valor){
    if(th->itens != NULL){
        int indice = valorString(th, user);
        int hashSenha = valorString(th, senha);
        
        Usuario *atual = th->itens[indice];

        while(atual != NULL){
            if(strcmp(atual->username, user) && atual->hashSenha == hashSenha)
                return 0;
        }
        atual = atual->prox;
    }

    return 1;
}

char removeHash(){

}

void liberaHash(){

}

void imprimeHash(){

}