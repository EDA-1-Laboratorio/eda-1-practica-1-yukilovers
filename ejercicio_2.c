#include <stdio.h>
// Definimos un tamaño máximo para facilitar la gestión de memoria en esta práctica
#define MAX 20

void generarEspiral(int n, int matriz[MAX][MAX]) {
    int valor = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {  //cambiamos el while porque si no la forma del espiral no concordaba 
        for (int i=left; i <= right; i++) {           // 1. Recorrer de izquierda a derecha (fila superior)
            matriz[top][i] = valor++;                 // TODO: Escribir el bucle for que llena desde 'left' hasta 'right'
        }                                             // Tip: Al terminar, incrementar 'top'
        top++;
        
        for (int i = top; i <= bottom; i++) {         // 2. Recorrer de arriba a abajo (columna derecha)
            matriz[i][right] = valor++;               // TODO: Escribir el bucle for que llena desde 'top' hasta 'bottom'
        }                                             // Tip: Al terminar, decrementar 'right'
        right--;
        
        if (top <= bottom) {          //// if de la fila 21         
            for (int i = right; i >= left; i--) {        // 3. Recorrer de derecha a izquierda (fila inferior)
                matriz[bottom][i] = valor++;             // TODO: Escribir el bucle for
            }                                            // Tip: Al terminar, decrementar 'bottom'
            bottom--;
        }
        if (left <= right) {                              // 4. Recorrer de abajo a arriba (columna izquierda)
            for (int i = bottom; i >= top; i--) {         // TODO: Escribir el bucle for
                matriz[i][left] = valor++;                 // Tip: Al terminar, incrementar 'left'
            }
            left++;
            
           
        }
    }
}

void imprimirMatriz(int n, int matriz[MAX][MAX]) {
    printf("\n--- Matriz Espiral de %dx%d ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]); // %4d para alinear columnas
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Ingrese el tamaño N de la matriz (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: El tamaño excede el máximo permitido.\n");
        return 1;
    }

    generarEspiral(n, matriz);
    imprimirMatriz(n, matriz);

   return 0;
    
}


// PREGUNTA: ¿Qué sucede si se omite la verificación if (top <= bottom) -linea 21- dentro del bucle?
//Durante el proceso del espiral, (top, bottom, left, right) se van reduciendo en cada vuelta. Llega un punto en el que ya no quedan
//filas disponibles. Eso se detecta cuando top es mayor que bottom.
//Si quitamos esa condición, el programa intentará recorrer una fila que ya no existe y comenzara a saltar columnas/espacios.
//Por ello, la condición evita que el algoritmo siga recorriendo cuando ya no quedan posiciones correctas.
