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
void criaHash();
void insereHash();
char buscaHash();
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

void criaHash(){
    
}

void insereHash(){
    
}

char buscaHash(){

}

char removeHash(){

}

void liberaHash(){

}

void imprimeHash(){

}