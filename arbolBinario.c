#include <stdio.h>
#include <stdlib.h>

typedef struct arbolBin {
    char elem;
    struct arbolBin *izq;
    struct arbolBin *der;
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

int main() {
    arbolBin_t *a, *b, *c, *d, *e, *f, *g, *h;
    arbolBin_t *i, *j, *k, *l, *m, *n, *o, *p;

    // validando memoria
    a=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    b=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    c=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    d=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    e=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    f=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    g=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    h=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    i=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    j=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    k=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    l=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    m=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    n=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    o=(arbolBin_t *)malloc(sizeof(arbolBin_t));
    p=(arbolBin_t *)malloc(sizeof(arbolBin_t));

    a->elem='a';
    a->izq=b;
    a->der=c;

    b->elem='b';
    b->izq=d;
    b->der=e;

    c->elem='c';
    c->izq=f;
    c->der=g;

    d->elem='d';
    d->izq=h;
    d->der=i;

    e->elem='e';
    e->izq=NULL;
    e->der=j;

    f->elem='f';
    f->izq=NULL;
    f->der=k;

    g->elem='g';
    g->izq=NULL;
    g->der=l;

    h->elem='h';
    h->izq=NULL;
    h->der=NULL;

    i->elem='i';
    i->izq=m;
    i->der=n;

    j->elem='j';
    j->izq=NULL;
    j->der=NULL;

    k->elem='k';
    k->izq=NULL;
    k->der=NULL;

    l->elem='l';
    l->izq=o;
    l->der=p;

    m->elem='m';
    m->izq=NULL;
    m->der=NULL;

    n->elem='n';
    n->izq=NULL;
    n->der=NULL;

    o->elem='o';
    o->izq=NULL;
    o->der=NULL;

    p->elem='p';
    p->izq=NULL;
    p->der=NULL;

    printf("\nSe inicia el recorrido en preorden\n");
    preOrden(a);
    printf("\nSe inicia el recorrido en inorden\n");
    inOrden(a);
    printf("\nSe inicia el recorrido en postorden\n");
    postOrden(a);
    printf("\nSe inicia el recorrido en amplitud\n");
    amplitud(a);

    return 0;
}

void preOrden(arbolBin_t * a){
    if (a != NULL) {
        printf("%c ", a->elem);
        preOrden(a->izq);
        preOrden(a->der);
    }
}

void inOrden(arbolBin_t * a){
    if (a != NULL) { 
        inOrden(a->izq);
        printf("%c ", a->elem);
        inOrden(a->der);
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
            if (aux->izq != NULL){
                encolar (&cola, aux->izq);
            }
            if (aux->der != NULL){
                encolar(&cola, aux->der);
            }
        }
    }
}

void crearCola(cola_t **cola) {
    *cola = NULL;
}

int esVacia(cola_t *cola) {
    return (cola == NULL);
}

void encolar(cola_t **cola, arbolBin_t *elem) {
    cola_t *nuevo;
    nuevo = (cola_t *)malloc(sizeof(cola_t));
    if (nuevo == NULL) {
        return;
    }
    nuevo->clave = elem;
    nuevo->sig = NULL;

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