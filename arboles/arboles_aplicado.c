/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h> /* abs()*/

typedef struct arbolBin {
    char elem;
    struct arbolBin *izq;
    struct arbolBin *der;
} arbolBin_t;

typedef struct cola {
    arbolBin_t *clave;
    struct cola *sig;
} cola_t;

/* PROTOTIPOS */
arbolBin_t* crearNodo(char elem);
arbolBin_t* crearNodo2(char elem, arbolBin_t *izq, arbolBin_t *der);
void liberarArbol(arbolBin_t *a);
void preOrden(arbolBin_t *a);
void inOrden(arbolBin_t *a);
void postOrden(arbolBin_t *a);
void amplitud(arbolBin_t *a);
void crearCola(cola_t **cola);
int esVacia(cola_t *cola);
void encolar(cola_t **cola, arbolBin_t *elem);
void desencolar(cola_t **cola, arbolBin_t **elem);
/* Ejercicios */
arbolBin_t* buscarNodo(arbolBin_t *a, char objetivo);
arbolBin_t* antecesorNodo(arbolBin_t *raiz, char objetivo);
void sucesoresNodo(arbolBin_t *raiz, char objetivo);
int gradoNodo(arbolBin_t *raiz, char objetivo);
void imprimirHojas(arbolBin_t *a);
int esNodoInterno(arbolBin_t *raiz, char objetivo);
int nivelNodo(arbolBin_t *raiz, char objetivo, int nivelActual);
int alturaArbol(arbolBin_t *a);
int cantidadNodosEnNivel(arbolBin_t *a, int nivelObjetivo, int nivelActual);
int anchuraArbol(arbolBin_t *a);

int esEquilibrado(arbolBin_t *a);

int main() {
    arbolBin_t *a = crearNodo('a');
    arbolBin_t *b = crearNodo('b');
    arbolBin_t *c = crearNodo('c');
    arbolBin_t *d = crearNodo('d');
    arbolBin_t *e = crearNodo('e');
    arbolBin_t *f = crearNodo('f');
    arbolBin_t *g = crearNodo('g');
    arbolBin_t *h = crearNodo('h');
    arbolBin_t *i = crearNodo('i');
    arbolBin_t *j = crearNodo('j');
    arbolBin_t *k = crearNodo('k');
    arbolBin_t *l = crearNodo('l');
    arbolBin_t *m = crearNodo('m');
    arbolBin_t *n = crearNodo('n');
    arbolBin_t *o = crearNodo('o');
    arbolBin_t *p = crearNodo('p');

    a->izq = b; 
    a->der = c;
    b->izq = d; 
    b->der = e;
    c->izq = f; 
    c->der = g;
    d->izq = h; 
    d->der = i;
    e->der = j; 
    // e->izq ya es NULL por defecto
    f->der = k;
    g->der = l;
    i->izq = m; 
    i->der = n;
    l->izq = o; 
    l->der = p;

    printf("\nSe inicia el recorrido en preorden\n");
    preOrden(a);
    
    printf("\n\nSe inicia el recorrido en inorden\n");
    inOrden(a);
    
    printf("\n\nSe inicia el recorrido en postorden\n");
    postOrden(a);
    
    printf("\n\nSe inicia el recorrido en amplitud\n");
    amplitud(a);
    printf("\n");

    printf("\n\n--- RESULTADOS DE LOS EJERCICIOS ---\n");
    /* Antecesor */
    arbolBin_t *padre = antecesorNodo(a, 'h');
    if (padre) printf("El antecesor de 'h' es: %c\n", padre->elem);
    
    /* Sucesores */
    printf("Los sucesores de 'b' son: ");
    sucesoresNodo(a, 'b');
    printf("\n");

    /* Grado */
    printf("El grado del nodo 'c' es: %d\n", gradoNodo(a, 'c'));
    printf("El grado del nodo 'h' es: %d\n", gradoNodo(a, 'h'));

    /* Hojas*/
    printf("Las hojas del arbol son: ");
    imprimirHojas(a);
    printf("\n");

    /* Nodo Interno*/
    printf("¿El nodo 'b' es interno?: %s\n", esNodoInterno(a, 'b') ? "Si" : "No");
    printf("¿El nodo 'h' es interno?: %s\n", esNodoInterno(a, 'h') ? "Si" : "No");

    /* Nivel
        Empezamos pasándole el nivel 0 como parámetro inicial, y a medida que bajamos por las ramas, vamos incrementando ese nivel en 1.
    */
    printf("El nivel del nodo 'a' (raiz) es: %d\n", nivelNodo(a, 'a', 0));
    printf("El nivel del nodo 'h' es: %d\n", nivelNodo(a, 'h', 0));

    /* Altura */
    printf("La altura total del arbol es: %d\n", alturaArbol(a));

    /* Anchura */
    printf("La anchura maxima del arbol es: %d\n", anchuraArbol(a));

    if (esEquilibrado(a)) {
    printf("El arbol ESTA equilibrado.\n");
    } else {
        printf("El arbol NO ESTA equilibrado.\n");
    }
    liberarArbol(a);
    return 0;
}

arbolBin_t* crearNodo(char elem) {
    arbolBin_t *nuevo = (arbolBin_t *)malloc(sizeof(arbolBin_t));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->elem = elem;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

/* Para crearlo rapido, tendria que crearse de atras hacia adelante en este caso. */
arbolBin_t* crearNodo2(char elem, arbolBin_t *izq, arbolBin_t *der) {
    arbolBin_t *nuevo = (arbolBin_t *)malloc(sizeof(arbolBin_t));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->elem = elem;
    nuevo->izq = izq;
    nuevo->der = der;
    return nuevo;
}

void liberarArbol(arbolBin_t *a) {
    if (a != NULL) {
        liberarArbol(a->izq);
        liberarArbol(a->der);
        free(a);
    }
}

/* RECORRIDOS */
void preOrden(arbolBin_t *a) {
    if (a != NULL) {
        printf("%c ", a->elem);
        preOrden(a->izq);
        preOrden(a->der);
    }
}

void inOrden(arbolBin_t *a) {
    if (a != NULL) { 
        inOrden(a->izq);
        printf("%c ", a->elem);
        inOrden(a->der);
    }
}

void postOrden(arbolBin_t *a) {
    if (a != NULL) {
        postOrden(a->izq);
        postOrden(a->der);
        printf("%c ", a->elem);
    }
}

void amplitud(arbolBin_t *a) {
    cola_t *cola;
    arbolBin_t *aux;
    
    if (a != NULL) {
        crearCola(&cola);
        encolar(&cola, a);
        
        while (!esVacia(cola)) {
            desencolar(&cola, &aux);
            printf("%c ", aux->elem);
            
            if (aux->izq != NULL) {
                encolar(&cola, aux->izq);
            }
            if (aux->der != NULL) {
                encolar(&cola, aux->der);
            }
        }
    }
}

/* COLAS */
void crearCola(cola_t **cola) {
    *cola = NULL;
}

int esVacia(cola_t *cola) {
    return (cola == NULL);
}

void encolar(cola_t **cola, arbolBin_t *elem) {
    cola_t *nuevo = (cola_t *)malloc(sizeof(cola_t));
    if (nuevo == NULL) {
        printf("Error: No se pudo reservar memoria en la cola.\n");
        return;
    }
    nuevo->clave = elem;
    nuevo->sig = NULL;

    if (*cola == NULL) {
        *cola = nuevo;
    } else {
        cola_t *temp = *cola;
        while (temp->sig != NULL) {
            temp = temp->sig;
        }
        temp->sig = nuevo;
    }
}

void desencolar(cola_t **cola1, arbolBin_t **elem) {
    /* Validacion para ver si la cola existe */
    if (*cola1 == NULL) {
        return; 
    }
    cola_t *aux = *cola1;
    *elem = aux->clave;
    *cola1 = aux->sig;
    free(aux);
}

/* Funciones ppt: 15 */
arbolBin_t* buscarNodo(arbolBin_t *a, char objetivo) {
    if (a == NULL) return NULL;
    if (a->elem == objetivo) return a;
    
    arbolBin_t *encontradoIzq = buscarNodo(a->izq, objetivo);
    if (encontradoIzq != NULL) return encontradoIzq;
    
    return buscarNodo(a->der, objetivo);
}

/* Antecesor de un nodo (Padre) */
arbolBin_t* antecesorNodo(arbolBin_t *raiz, char objetivo) {
    if (raiz == NULL) return NULL;
    
    /* Si uno de los hijos es el objetivo, entonces la raíz actual es el antecesor */ 
    if ((raiz->izq != NULL && raiz->izq->elem == objetivo) || 
        (raiz->der != NULL && raiz->der->elem == objetivo)) {
        return raiz;
    }
    
    /* Buscar en la rama izquierda */ 
    arbolBin_t *encontradoIzq = antecesorNodo(raiz->izq, objetivo);
    if (encontradoIzq != NULL) return encontradoIzq;
    
    /* Si no está a la izquierda, buscar en la derecha */
    return antecesorNodo(raiz->der, objetivo);
}

/* Imprime todos los nodos que cuelgan del nodo objetivo */ 
void sucesoresNodo(arbolBin_t *raiz, char objetivo) {
    arbolBin_t *nodo = buscarNodo(raiz, objetivo);
    if (nodo != NULL) {
        /* Utilizamos la función de preorden (o inorden/postorden) para imprimir los hijos */
        if (nodo->izq != NULL) preOrden(nodo->izq);
        if (nodo->der != NULL) preOrden(nodo->der);
    }
}

/* Grado de un nodo (Cantidad de hijos directos: 0, 1 o 2) */
int gradoNodo(arbolBin_t *raiz, char objetivo) {
    arbolBin_t *nodo = buscarNodo(raiz, objetivo);
    if (nodo == NULL) return -1; // Retorna -1 si el nodo no existe
    
    int grado = 0;
    if (nodo->izq != NULL) grado++;
    if (nodo->der != NULL) grado++;
    
    return grado;
}

/* Hojas del árbol (Nodos sin hijos) */
void imprimirHojas(arbolBin_t *a) {
    if (a == NULL) return;
    
    // Si no tiene hijo izquierdo ni derecho, es una hoja
    if (a->izq == NULL && a->der == NULL) {
        printf("%c ", a->elem);
    }
    
    imprimirHojas(a->izq);
    imprimirHojas(a->der);
}

/* Es nodo interno (Verdadero si tiene al menos un hijo) */
int esNodoInterno(arbolBin_t *raiz, char objetivo) {
    arbolBin_t *nodo = buscarNodo(raiz, objetivo);
    if (nodo == NULL) return 0;
    
    return (nodo->izq != NULL || nodo->der != NULL);
}

/* Nivel de un nodo (Distancia desde la raíz, asumiendo raíz = nivel 0) */
int nivelNodo(arbolBin_t *raiz, char objetivo, int nivelActual) {
    if (raiz == NULL) return -1; /* No encontrado */
    if (raiz->elem == objetivo) return nivelActual;
    
    int nivelIzq = nivelNodo(raiz->izq, objetivo, nivelActual + 1);
    if (nivelIzq != -1) return nivelIzq; /* Si lo encontró a la izquierda, retorna ese nivel */
    
    return nivelNodo(raiz->der, objetivo, nivelActual + 1);
}

/* Altura del árbol (Nivel máximo alcanzado) */
int alturaArbol(arbolBin_t *a) {
    if (a == NULL) return 0; /* Un árbol vacío tiene altura 0 */
    
    int altIzq = alturaArbol(a->izq);
    int altDer = alturaArbol(a->der);
    
    /* Retorna la altura de la rama más larga + 1 (contando el nodo actual)*/
    if (altIzq > altDer) {
        return altIzq + 1;
    } else {
        return altDer + 1;
    }
}
/* Cantidad de nodos en un nivel específico */
int cantidadNodosEnNivel(arbolBin_t *a, int nivelObjetivo, int nivelActual) {
    if (a == NULL) return 0;
    if (nivelActual == nivelObjetivo) return 1;
    
    return cantidadNodosEnNivel(a->izq, nivelObjetivo, nivelActual + 1) + 
           cantidadNodosEnNivel(a->der, nivelObjetivo, nivelActual + 1);
}

/* Anchura del árbol (Cantidad máxima de nodos que hay en un mismo nivel) */
int anchuraArbol(arbolBin_t *a) {
    int maxAnchura = 0;
    int altura = alturaArbol(a);
    
    /* Recorremos cada nivel contando cuántos nodos tiene */
    for (int i = 0; i < altura; i++) {
        int anchuraNivel = cantidadNodosEnNivel(a, i, 0);
        if (anchuraNivel > maxAnchura) {
            maxAnchura = anchuraNivel;
        }
    }
    
    return maxAnchura;
}

int esEquilibrado(arbolBin_t *a) {
    /* Un árbol vacío se considera equilibrado */
    if (a == NULL) {
        return 1; 
    }

    /* Obtenemos la altura de los subárboles izquierdo y derecho */
    int altIzq = alturaArbol(a->izq);
    int altDer = alturaArbol(a->der);

    /* Calculamos la diferencia absoluta de las alturas */
    int diferencia = abs(altIzq - altDer);

    /* Si la diferencia es menor o igual a 1, Y además los subárboles 
     * izquierdo y derecho también están equilibrados, entonces es equilibrado.
     */
    if (diferencia <= 1 && esEquilibrado(a->izq) && esEquilibrado(a->der)) {
        return 1;
    }

    return 0; /* No está equilibrado */
}