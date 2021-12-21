#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
       	int opcao;

      	nodo* arvore = NULL;
		nodo* pai = NULL;


        while(1==1) {
            scanf("%d", &opcao);
            switch(opcao) {
                int n;
                case 1:
                    scanf("%d", &n);
                    arvore = inserir(arvore, n);  
					break;
                case 2:
                    preorder(arvore);
                    printf("\n");                    
                    break;
                case 3:
                    inorder(arvore);                    
                    printf("\n");
                    break;
                case 4:
                    posorder(arvore);                    
                    printf("\n");
                    break;
                case 5:
                    scanf("%d", &n);
                    arvore = remover(arvore, n);
                    break;
				case 6:
					exibirMaiorElemento(arvore);
					printf("\n");
					break;
				case 7:
					exibirMenorElemento(arvore);
					printf("\n");
					break;	
				case 8:
					printf("%d \n",altura(arvore));
					printf("\n");
					break;
				case 9:
					scanf("%d", &n);
					pai = buscarPai(arvore, n);
					printarPai(pai);
					printf("\n");
					break;
				case 10:
					scanf("%d", &n);
					sucessor(arvore, n);
					printf("\n");
					break;
				case 11:
					scanf("%d", &n);
					antecessor(arvore, n);
					printf("\n");
					break;
				case 999:
					exit(0);
            }

        }

}
