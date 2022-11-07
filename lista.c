#include <stdio.h>
#include <stdlib.h>

typedef struct __Nodo{
    int elem;
    struct __Nodo* next;
} nodo ;

void printNodo(nodo*);
nodo* addOrdinato(nodo*, int);

int main(){
    nodo* ptr = NULL;
    ptr = addOrdinato(ptr, 4);
    ptr = addOrdinato(ptr, 2);
    ptr = addOrdinato(ptr, 1);
    ptr = addOrdinato(ptr, 3);
    ptr = addOrdinato(ptr, 0);
    ptr = addOrdinato(ptr ,5);
    printNodo(ptr);
}

nodo* addOrdinato(nodo* testa, int e){
    nodo* superiore = testa;

    //entro qui se la lista è vuota
    if(testa == NULL){
        nodo* n = malloc(sizeof(nodo));
        n->elem = e;
        n->next = NULL;
        return n;
    }
    

    //qui il nodo va in prima posizione
    if(testa->elem >= e){
        nodo* n = malloc(sizeof(nodo));
        n->next = testa;
        n->elem = e;
        return n;
    }
    
    while(testa->next != NULL){
        if(testa->next->elem>e) {
            nodo* n = malloc(sizeof(nodo));
            n->next = testa->next;
            n->elem = e;
            return superiore;
        }
        testa = testa->next;
    }

    //si inserisce alla fine
    nodo* n = malloc(sizeof(nodo));
    n->next=NULL;
    n->elem=e;
    testa->next = n;
    
    return superiore;

    //FUNZIONA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void printNodo(nodo* testa){
    if(testa == NULL){
        printf("Lista vuota\n");
    } else {
        printf("Contenuto lista: ");
        while(testa != NULL){
            printf("%d ", testa->elem);
            testa = testa->next;
        }
    }
}
