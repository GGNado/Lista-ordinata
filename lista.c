#include <stdio.h>
#include <stdlib.h>
 typedef struct Nodo{
    int elem;
    struct Nodo* next;
 } nodo;
 
 nodo*insert(nodo*,int);
 nodo*delate(nodo*,int);
 int isEmpty(nodo*);
 int size(nodo*);
 void printList(nodo*);
int main(){
    
    nodo* ptr = NULL;
    ptr = insert(ptr, 4);
    ptr = insert(ptr, 2);
    ptr = insert(ptr, 1);
    ptr = insert(ptr, 3);
    ptr = insert(ptr, 0);
    ptr = insert(ptr ,5);
    ptr = insert(ptr, 7);
    ptr = insert(ptr, 6);
    
    int dim = size(ptr);
    printf("size: %d\n ", dim);
    printList(ptr);
    return 0;
}

int isEmpty(nodo* lista){
    if(lista==NULL){
        return 1;
    }
    return 0;
}
int size(nodo*lista){
    int i=0;
    while(lista!=NULL){
        i++;
        lista = lista->next;
    }
    return i;
}
nodo* insert(nodo* lista,int e){
    nodo* testa = lista;
    
    //QUI SI ENTRA SE LA LISTA è VUOTA
    if(lista==NULL){
        nodo* n=(nodo*)malloc(sizeof(nodo));
        n->elem=e;
        n->next=NULL;
        return n;
    }
    
    //QUI SE STA PRIMA,QUINDI SE DIVENTA LA NUOVA TESTA
    if(lista->elem>=e){
        nodo* n=(nodo*)malloc(sizeof(nodo));
        n->next=lista;
        n->elem=e;
        return n;
    }
    
    while(lista->next!=NULL){
        //SI ENTRA SE IL VALORE è IN MEZZO A DUE NUMERI
        if(lista->next->elem>e){
             nodo* n=(nodo*)malloc(sizeof(nodo));
             n->next=lista->next;
             n->elem=e;
             lista->next=n;
             return testa;
        }
        lista = lista->next;
    }
    
    //IL NUMERO è IL PIU GRANDE DELLA LISTA, QUINDI VA IN FONDO
    nodo* n=(nodo*)malloc(sizeof(nodo));
    n->next=NULL;
    n->elem=e;
    lista->next = n;      
    return testa;
}

void printList(nodo*lista){
    if(lista==NULL){
        printf("lista vuota");
    }else{
        printf("contenuto lista: ");
        while(lista!=NULL){
            printf("%d ",lista->elem);
            lista=lista->next;
        }
        
    }
}

