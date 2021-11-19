#include "id_red_black.h"

Tno* rotacao_simples_esquerda(Tno* a){//mesmo código da AVL
    Tno *aux;
    aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a = aux;
    return a;
}
Tno * rotacao_simples_direita(Tno *a){//mesmo código da AVL
    Tno *aux;
    aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a = aux;
    return a;
}

Tno* criar(int elemento){//mesmo código da AVL
	Tno * dado = (Tno *)malloc(sizeof(Tno));
    dado->elemento = elemento;
    dado->cor = vermelho;//só um ajuste para inclusão da cor
    dado->esq = NULL;
    dado->dir = NULL;
    return dado;
}
Tno* inserir(Tno* a, int valor){
	Tno* dado = criar(valor);
	a = incluir_no(a, dado);

	if(a != NULL)
		a->cor = preto; //garantimos sempre a propriedade da raiz preta

	return a;
}
Tno* incluir_no(Tno* a, Tno* dado){
    if (a == NULL){
        return dado; //incluímos o dado
    }
    else{
        if(dado->elemento == a->elemento); //não fazemos nada

        else{
            if(a->elemento > dado->elemento)
                a->esq = incluir_no(a->esq, dado);
            else
                a->dir = incluir_no(a->dir, dado);
            //analisando os casos de uma árvore vermelho e preto
            if((cor(a->esq)==vermelho) && (cor(a->dir)==vermelho))
                trocaCor(a);
            if((cor(a->esq)==vermelho) && (cor(a->esq->esq)==vermelho)){//neto esquerdo vermelho
                  a->cor = vermelho;
                  a->esq->cor = preto;
                  a = rotacao_simples_direita(a);
            }

            if((cor(a->esq)==vermelho) && (cor(a->esq->dir)==vermelho)){//neto direito vermelho
                Tno *aux = rotacao_simples_esquerda(a->esq);
                a->esq = aux;
                a->cor = vermelho;
                a->esq->cor = preto;
                a = rotacao_simples_direita(a);
            }
            if((cor(a->dir)==vermelho) && (cor(a->dir->dir)==vermelho)){//neto direito vermelho
                a->cor = vermelho;
                a->dir->cor = preto;
                a = rotacao_simples_esquerda(a);
            }
            if((cor(a->dir)==vermelho) && (cor(a->dir->esq)==vermelho)){//neto esquerdo vermelho
                Tno *aux = rotacao_simples_direita(a->dir);
                a->dir = aux;
                a->cor = vermelho;
                a->dir->cor = preto;
                a = rotacao_simples_esquerda(a);
            }
        }
    }
	return a;
}
int cor(Tno* a){
	if(a==NULL)
		return preto; //toda folha tem cor preta
	else
		return a->cor;
}
void trocaCor(Tno* a){
	a->cor = !a->cor;
	if(a->esq !=NULL)
		a->esq->cor = !a->esq->cor;
	if(a->dir !=NULL)
		a->dir->cor = !a->dir->cor;
}
void imprime(Tno* a){//mesmo código da AVL
    if (a == NULL){
		return;
	}
    printf("%d [cor: %d]",a->elemento, a->cor);

    if(a->esq != NULL)
        printf("(E:%d [cor: %d])",a->esq->elemento, a->esq->cor);
    if(a->dir != NULL)
        printf("(D:%d [cor: %d])",a->dir->elemento, a->dir->cor);
    printf("\n");

    imprime(a->esq);
    imprime(a->dir);
}


