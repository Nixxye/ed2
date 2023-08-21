#include "abbLista.h"


Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) 
{
    if (!a)
    {
        a = (Arvore *) malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (a->info < v)
        a->dir = inserir(a->dir, v);
    else 
        a->esq = inserir(a->esq, v);
    return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) 
{
    if (!a)
        return NULL;
    if (a->info < v)
        a->dir = remover(a->dir, v);
    else if (a->info > v)
        a->esq = remover(a->esq, v);
    else
    {
        if (!a->esq && !a->dir)
        {
            free(a);
            a = NULL;
        }
        else if (!a->esq)
        {
            Arvore* it = a->dir;
            while (it->esq)
                it = it->esq;
            a->info = it->info;
            it->info = v;
            a->dir = remover(a->dir, v);
        }
        else 
        {
            Arvore* it = a->esq;
            while (it->dir)
                it = it->dir;
            a->info = it->info;
            it->info = v;
            a->esq = remover(a->esq, v);            
        }
    }
   return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
    if (!a)
        return 0;
    if (a->info < v)
        return buscar(a->dir, v);
    if (a->info > v)
        return buscar(a->esq, v);
    return 1;
}

//========= Q2 - min =====

int minimo (Arvore* a)
{
    if (!a)
        return 0;
    if (!a->esq)
        return a->info;
    int tmp = minimo(a->esq);
    return a->info < tmp ? a->info : tmp;
}

//========= Q2 - max =====

int maximo (Arvore* a)
{
    if (!a)
        return 0;
    if (!a->dir)
        return a->info;
    int tmp = maximo(a->dir);
    return a->info > tmp ? a->info : tmp;
}
//========= Q3 - imprime_decrescente =====

void imprime_decrescente (Arvore *a)
{
    if (!a)
        return;
    imprime_decrescente(a->dir);
    printf("%d ", a->info);
    imprime_decrescente(a->esq);
}

//========= Q4 - maior ramo =====
int maior_ramo (Arvore *a)
{
    if (!a)
        return 0;
    int e = maior_ramo(a->esq);
    int d = maior_ramo(a->dir);
    return a->info + (e > d ? e : d);    
}


void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {

   int i;
   Arvore *a = cria_arvore_vazia ();

    a = inserir (a, 50);
    a = inserir (a, 30);
    a = inserir (a, 90);
    a = inserir (a, 20);
    a = inserir (a, 40);
    a = inserir (a, 95);
    a = inserir (a, 10);
    a = inserir (a, 35);
    a = inserir (a, 45);

   printf("\n");
   pre_order (a);	
   printf("\n");
   printf("%d", maior_ramo(a));
	
   printf("\n");
   // ====== Q5 ====

   return 0;
}

