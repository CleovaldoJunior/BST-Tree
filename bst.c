#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

nodo* inserir(nodo* raiz, int valorParam){
	if(raiz == NULL){
		nodo* nova_raiz = (nodo*) malloc(sizeof(nodo));
		nova_raiz->valor = valorParam;
		nova_raiz->esq = NULL;
		nova_raiz->dir = NULL;
		return nova_raiz;
	}else{
		if(valorParam > raiz->valor){
			raiz->dir = inserir(raiz->dir, valorParam);
		}else{
			raiz->esq = inserir(raiz->esq, valorParam);
		}
		return raiz;
	}
}

int maiorNo(nodo* raiz) {
	nodo* aux = raiz;
    if (aux == NULL){
        return 0;
    }else{
		while(aux->dir != NULL){
			aux = aux-> dir;		
		}
		return aux->valor;	
	}
}

int menorNo(nodo* raiz){
	if(raiz == NULL){
	}else{
		if(raiz-> esq == NULL){
			return raiz->valor;
		}else{
			menorNo(raiz->esq);	
		}

	}
}

void exibirMaiorElemento(nodo* raiz){
	if(raiz == NULL){
	}else{
		if(raiz-> dir == NULL){
			printf("[%d]", raiz-> valor);
		}else{
			exibirMaiorElemento(raiz->dir);	
		}

	}
}

void exibirMenorElemento(nodo* raiz){
	if(raiz == NULL){
	}else{
		if(raiz-> esq == NULL){
			printf("[%d]", raiz-> valor);
		}else{
			exibirMenorElemento(raiz->esq);	
		}

	}
}


nodo* remover(nodo* raiz, int valorParam){
	
	if(raiz == NULL){
		return NULL;
	}
	if(valorParam == raiz -> valor){
			if(raiz -> esq == NULL && raiz -> dir == NULL){
           			return NULL;
        		}
	
        		if(raiz -> esq != NULL && raiz -> dir == NULL){
            			return raiz->esq;
        		}
        		if(raiz -> esq == NULL && raiz -> dir != NULL){
            			return raiz-> dir;
        		}

        		if(raiz -> esq != NULL && raiz-> dir != NULL){
            			raiz -> valor = maiorNo(raiz-> esq);
            			raiz -> esq = remover(raiz -> esq, raiz-> valor);
            			return raiz;
        		}
	} 
	if(valorParam > raiz-> valor){
			raiz-> dir = remover(raiz->dir, valorParam);
	}else{
		raiz-> esq = remover(raiz->esq, valorParam);		
	}
	return raiz;
}


nodo* procurarElemento(nodo* raiz, int elemento){
	if(raiz == NULL || elemento == raiz-> valor){	
		return raiz;
	}else{
		if(elemento > raiz-> valor){
			return procurarElemento(raiz->dir, elemento);
		}
		else{
			return procurarElemento(raiz->esq, elemento);
		}	
	}
}


void preorder(nodo* raiz){
	if(raiz == NULL){
	}else{
		printf("[%d]", raiz->valor);
		preorder(raiz->esq);
		preorder(raiz->dir);
	}
}

void inorder(nodo* raiz){
	if(raiz == NULL){
	}else{
		inorder(raiz->esq);
		printf("[%d]", raiz->valor);
		inorder(raiz->dir);
	}
}

void posorder(nodo* raiz){
	if(raiz == NULL){
	}else{
		posorder(raiz->esq);
		posorder(raiz->dir);
		printf("[%d]", raiz->valor);
	}
}


int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(nodo *raiz){
   if((raiz == NULL) || (raiz->esq == NULL && raiz->dir == NULL))
       return 0;
   else
       return 1 + maior(altura(raiz->esq), altura(raiz->dir));
}


nodo* buscarPai(nodo* raiz, int elemento){
	nodo* aux;
	if(raiz == NULL){
		return NULL;
	}else{
		if(raiz-> esq == NULL && raiz -> dir == NULL){
			return NULL;	
		}
		else if(raiz-> esq != NULL && raiz-> esq -> valor == elemento){
			return raiz;
		}
		else if(raiz-> dir != NULL && raiz-> dir -> valor == elemento){
			return raiz;	
		}else{
			aux = buscarPai(raiz->esq, elemento);
			if(aux == NULL){
				aux = buscarPai(raiz->dir, elemento);			
			}
			return aux;
		}
	}
}

void printarPai(nodo* raiz){
	if(raiz == NULL){
		printf("%d", -1);
	}else{
		printf("%d", raiz-> valor);
	}
	
}

void antecessor(nodo* raiz, int elemento){
	nodo* aux = procurarElemento(raiz, elemento);
	nodo* aux2 = NULL;
	int menorNoDir = menorNo(raiz->dir);
	int maiorNoEsq = maiorNo(raiz->esq);
	
	if(aux == NULL){
		printf("%d", -1);
	}
	else{
		if(aux -> esq == NULL && aux != raiz){
			aux2 = buscarPai(raiz, aux->valor);
			if(aux-> valor == menorNoDir){
				printf("%d", raiz->valor);
			}else{
				if(aux2-> valor < aux-> valor){
					printarPai(aux2);		
				}else{
					printf("%d", -1);			
				}
			}
			
		}else{
			if(aux == raiz){
				if(raiz->esq != NULL){
					printf("%d", maiorNoEsq);
				}else{
					printf("%d",-1);
				}
							
			}else{
				printf("%d", aux->esq->valor);	
			}
		}	
	}
}

void sucessor(nodo* raiz, int elemento){
	nodo* aux = procurarElemento(raiz, elemento);
	nodo* aux2 = NULL;
	int maiorNoEsq = maiorNo(raiz->esq);
	int menorNoDir = menorNo(raiz->dir);

	if(aux == NULL){
		printf("%d",-1);
	}
	else{
		if(aux -> dir == NULL && aux != raiz){
			aux2 = buscarPai(raiz, aux-> valor);
			if(aux -> valor == maiorNoEsq){
				printf("%d", raiz->valor);
			}else{
				if(aux2 -> valor > aux->valor){
					printarPai(aux2);	
				}else{
					printf("%d", -1);			
				}
			}						
		}else{
			if(aux == raiz){
				if(raiz-> dir != NULL){
					printf("%d", menorNoDir);
				}else{
					printf("%d", -1);
				}
			}else{
				printf("%d", aux->dir->valor);				
			}	
		}
	}
}