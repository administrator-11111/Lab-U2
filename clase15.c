/*Función de Búsqueda*/
int buscar(arbolBin_t *a, char elem) {
    if (a == NULL) {
        printf("No se ha encontrado el elemento %c", elem);
        return 0; // Falso
    }
    else if (a->elem < elem) {
        return buscar(a->der, elem);
    }
    else if (a->elem > elem) {
        return buscar(a->izq, elem);
    }
    else {
        printf("Se ha encontrado el elemento %c", a->elem);
        return 1; // Verdadero
    }
}

/*Función de Inserción*/
void insertar(arbolBin_t **a, int elem) {
    if (*a == NULL) {
        *a = (arbolBin_t *)malloc(sizeof(arbolBin_t));
        (*a)->elem = elem;
        (*a)->izq = (*a)->der = NULL;
    }
    else if ((*a)->elem < elem) {
        insertar(&(*a)->der, elem);
    }
    else if ((*a)->elem > elem) {
        insertar(&(*a)->izq, elem);
    }
}

/*Funciones de Borrado*/
// Sustituye el nodo borrado por la mayor de las menores
void sustituir(arbolBin_t **a, arbolBin_t **aux) {
    if ((*a)->der != NULL) {
        sustituir(&(*a)->der, aux);
    } else {
        (*aux)->elem = (*a)->elem;
        *aux = *a;
        *a = (*a)->izq;
    }
}

void borrar(arbolBin_t **a, int elem) {
    arbolBin_t *aux;
    if (*a == NULL) {
        return;
    }
    if ((*a)->elem < elem) {
        borrar(&(*a)->der, elem);
    }
    else if ((*a)->elem > elem) {
        borrar(&(*a)->izq, elem);
    }
    else if ((*a)->elem == elem) {
        aux = *a;
        if ((*a)->izq == NULL) {
            *a = (*a)->der;
        }
        else if ((*a)->der == NULL) {
            *a = (*a)->izq;
        }
        else {
            sustituir(&(*a)->izq, &aux);
        }
        free(aux);
    }
}

/*Ejercicios Clase 15*/
// 1. Grado de un nodo (0 si es hoja, 1 si tiene un hijo, 2 si tiene ambos)
int gradoNodo(arbolBin_t *nodo) {
    if (nodo == NULL) return -1; // Caso de error
    int grado = 0;
    if (nodo->izq != NULL) grado++;
    if (nodo->der != NULL) grado++;
    return grado;
}

// 2. ¿Es nodo interno? (1 si tiene al menos un hijo, 0 si es hoja)
int esNodoInterno(arbolBin_t *nodo) {
    if (nodo == NULL) return 0;
    return (nodo->izq != NULL || nodo->der != NULL) ? 1 : 0;
}

// 3. Imprimir todas las hojas del árbol
void imprimirHojas(arbolBin_t *a) {
    if (a != NULL) {
        if (a->izq == NULL && a->der == NULL) {
            printf("%d ", a->elem);
        }
        imprimirHojas(a->izq);
        imprimirHojas(a->der);
    }
}

// 4. Nivel de un nodo (Distancia desde la raíz. La raíz asume Nivel 1)
int nivelNodo(arbolBin_t *a, int elem_buscado, int nivel_actual) {
    if (a == NULL) return 0; // No encontrado
    if (a->elem == elem_buscado) return nivel_actual;
    
    if (elem_buscado < a->elem) {
        return nivelNodo(a->izq, elem_buscado, nivel_actual + 1);
    } else {
        return nivelNodo(a->der, elem_buscado, nivel_actual + 1);
    }
}

// 5. Altura del Árbol
int alturaArbol(arbolBin_t *a) {
    if (a == NULL) return 0;
    int altIzq = alturaArbol(a->izq);
    int altDer = alturaArbol(a->der);
    return (altIzq > altDer ? altIzq : altDer) + 1;
}

// 6. Sucesores directos (imprimir los hijos inmediatos de un nodo dado)
void sucesoresDirectos(arbolBin_t *a, int elem) {
    if (a == NULL) return;
    if (a->elem == elem) {
        if (a->izq != NULL) printf("Hijo Izq: %d ", a->izq->elem);
        if (a->der != NULL) printf("Hijo Der: %d ", a->der->elem);
        return;
    }
    (elem < a->elem) ? sucesoresDirectos(a->izq, elem) : sucesoresDirectos(a->der, elem);
}

// 7. Antecesor directo (Padre del nodo buscado)
arbolBin_t* antecesorDirecto(arbolBin_t *a, int elem) {
    if (a == NULL || a->elem == elem) return NULL; // La raíz o un nodo no existente no tienen padre
    
    if ((a->izq != NULL && a->izq->elem == elem) || 
        (a->der != NULL && a->der->elem == elem)) {
        return a; // Encontramos al padre
    }
    
    if (elem < a->elem) return antecesorDirecto(a->izq, elem);
    else return antecesorDirecto(a->der, elem);
}

// 8. Anchura del árbol (Función auxiliar para calcular el máximo de nodos en un nivel)
int obtenerAnchoNivel(arbolBin_t *a, int nivel) {
    if (a == NULL) return 0;
    if (nivel == 1) return 1;
    else if (nivel > 1) {
        return obtenerAnchoNivel(a->izq, nivel - 1) + obtenerAnchoNivel(a->der, nivel - 1);
    }
    return 0;
}

int anchuraArbol(arbolBin_t *a) {
    int maxAnchura = 0;
    int h = alturaArbol(a);
    for (int i = 1; i <= h; i++) {
        int ancho = obtenerAnchoNivel(a, i);
        if (ancho > maxAnchura) {
            maxAnchura = ancho;
        }
    }
    return maxAnchura;
}