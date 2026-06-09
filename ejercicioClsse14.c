/*Escribir una función recursiva que encuentre el número de nodos de un 
árbol binario.*/
int contarNodos(arbolBin_t *a) {
    // Caso base: si el nodo es NULL, no suma nada al conteo
    if (a == NULL) {
        return 0;
    }
    
    // Caso recursivo: 1 (el nodo actual) + nodos izquierda + nodos derecha
    return 1 + contarNodos(a->izq) + contarNodos(a->der);
}

/*Escribir una función recursiva que encuentre la altura de un árbol 
binario.*/
int alturaArbol(arbolBin_t *a) {
    // Caso base: un árbol vacío tiene altura 0
    if (a == NULL) {
        return 0;
    }
    
    // Calcular recursivamente la altura de ambos subárboles
    int alturaIzq = alturaArbol(a->izq);
    int alturaDer = alturaArbol(a->der);
    
    // Retornar 1 (nodo actual) + la altura del subárbol más grande
    if (alturaIzq > alturaDer) {
        return 1 + alturaIzq;
    } else {
        return 1 + alturaDer;
    }
}