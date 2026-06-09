#include <stdio.h>
#include <stdlib.h>

typedef struct arbolBin {
    char elem;
    struct arbolBin *izq;
    struct arbol *der;
} arbolBin_t;

typedef struct cola {
    arbolBin_t *clave;
    struct cola *sig;
} cola_t;

void preOrden(arbolBin_t *a);
void inOrden(arbolBin_t *a);
void postOrden(arbolBin_t *a);
void amplitud(arbolBin_t *a);
void crearCola(cola_t **cola);
int esVacia(cola_t *cola);
void encolar(cola_t **cola, arbolBin_t *elem);
void desencolar(cola_t **cola, arbolBin_t **elem);

int main(){
    return 0;
}

void preOrden(arbolBin_t * a){
    if (a != NULL) {
        printf("%c\n", a->elem);
        prePrdem(a->izq);
        preOrden(a->der);
    }
}

void inOrden(arbolBin_t * a){
    if (a != NULL) { 
        inOrden(a->izq);
        printf("%c ", a->elem);
        inOrden(a->der)
    }
}

void postOrden(arbolBin_t * a){
    if (a != NULL) {
        postOrden(a->izq);
        postOrden(a->der);
        printf("%c ", a->elem);
    }
}

void amplitud(arbolBin_t * a){
    cola_t *cola;
    arbolBin_t *aux;
    if (a != NULL) {
        crearCola(&cola);
        encolar(&cola, a);
        while (!esVacia(cola)) {
            desencolar(&cola, &aux);
            printf("%c ", aux->elem);
            if (aux-> != NULL){
                encolar (%cola, aux->izq);
            }
            if (aux->der != NULL){
                desencolar(&cola, aux->der);
            }
        }
    }
}

void encolar(cola_t **cola, arbolBin_t *elem) {
    cola_t *nuevo;
    nuevo = (cola_t) malloc(sizeof(cola_t));
    nuevo->clave = elem;
    nuevo-sig = NULL;

    if (*cola == NULL){
        *cola = nuevo;
    }
    else {
        cola_t *temp = *cola;
        while (temp->sig != NULL) {
            temp = temp->sig;
        }
        temp->sig = nuevo;
    }
}

void desencolar(cola_t **cola1, arbolBin_t **elem) {
    cola_t *aux;
    *elem = (*cola1)->clave;
    aux = *cola1;
    *cola1 = (*cola1)->sig;
    free(aux);
}