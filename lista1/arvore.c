#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====

void preordem (Arvore *a)
{
   if (!verifica_arv_vazia(a))
   {
      printf("%c ", a->info);
      preordem(a->esq);
      preordem(a->dir);
   }
}

//========= Exercício 2 - in-ordem ====

void inordem (Arvore *a)
{
   if (!verifica_arv_vazia(a))
   {
      preordem(a->esq);
      printf("%c ", a->info);
      preordem(a->dir);
   }
}

//========= Exercício 2 - pós-ordem ====

void posordem (Arvore *a)
{
   if (!verifica_arv_vazia(a))
   {
      preordem(a->esq);
      preordem(a->dir);
      printf("%c ", a->info);
   }
}

//========= Exercício 3 - pertence ====

int pertence_arv (Arvore *a, char c)
{
   int r = 0;
   if (!verifica_arv_vazia(a))
   {
      if (a->info == c)
         return 1;
      r = pertence_arv(a->esq, c);
      if (!r)
         r = pertence_arv(a->dir, c);
   }
   return r;
}

//========= Exercício 4 - conta nós ====

int conta_nos (Arvore* a)
{
   int n = 0;
   if (!verifica_arv_vazia(a))
   {
      n++;
      n += conta_nos(a->dir);
      n += conta_nos(a->esq);
   }
   return n;
}

//========= Exercício 5 - calcula altura ====

int calcula_altura_arvore (Arvore* a)
{
   int h = 0;
   if (!verifica_arv_vazia(a))
   {
      if (!verifica_arv_vazia(a->dir) && !verifica_arv_vazia(a->esq))
      {
         h = 1;
         int he = calcula_altura_arvore(a->esq), 
         hd = calcula_altura_arvore(a->dir);
         h += hd > he ? hd : he;
      }
   }
   return h;
}

//========= Exercício 6 - conta folhas ====

int conta_nos_folhas(Arvore *a)
{
   int f = 0;
   if (!verifica_arv_vazia(a))
   {
      if (verifica_arv_vazia(a->dir) && verifica_arv_vazia(a->esq))
      {
         f++;
      }
      else
      {
         f += conta_nos_folhas(a->dir);
         f += conta_nos_folhas(a->esq);
      }
   }
   return f;   
}

int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   // preordem(a);
   // printf("\n");
   // inordem(a);
   // printf("\n");
   // posordem(a);

   // printf("%d\n", pertence_arv(a, 'l'));
   // printf("%d\n", conta_nos(a));
   // printf("%d\n", calcula_altura_arvore(a));
   printf("%d\n", conta_nos_folhas(a));
   arv_libera (a);

   return 0;
}

