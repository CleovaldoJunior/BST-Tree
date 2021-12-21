#ifndef BST_H
#define BST_H

typedef struct no{
	int valor;
	struct no *esq;
	struct no *dir;
}nodo;

nodo* inserir(nodo* raiz, int elemento);

nodo* remover(nodo* raiz, int elemento);

nodo* procurarElemento(nodo* raiz, int elemento);

int maiorNo(nodo* raiz);

int menorNo(nodo* raiz);

void exibirMaiorElemento(nodo* raiz);

void exibirMenorElemento(nodo* raiz);

void preorder(nodo* raiz);

void inorder(nodo* raiz);

void posorder(nodo* raiz);

int maior(int a, int b);

int altura(nodo* raiz);

nodo* buscarPai(nodo* raiz, int elemento);

void printarPai(nodo* raiz);

void sucessor(nodo* raiz, int elemento);

void antecessor(nodo* raiz, int elemento);

#endif
