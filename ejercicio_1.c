#include <stdio.h>
#include <string.h>

// Prototipos de funciones
void crearMensaje();
void descifrarMensaje();

int main() {
    int opcion = 0;
    
    while (1) {
        printf("\n\t*** ESCÍTALA ESPARTANA ***\n");
        printf("1) Crear mensaje cifrado (Cifrar).\n");
        printf("2) Descifrar mensaje.\n");
        printf("3) Salir.\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                crearMensaje();
                break;
            case 2:
                descifrarMensaje();
                break;
            case 3:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }
    return 0;
}

void crearMensaje() {
    int ren, col, i, j, k = 0;

    printf("\n--- CIFRADO ---\n");
    printf("Ingresar el tamaño de la escítala (Renglones): ");
    scanf("%d", &ren);
    printf("Ingresar el tamaño de la escítala (Columnas/Caras): ");
    scanf("%d", &col);

    char escitala[ren][col];
    char texto[ren * col]; // Arreglo lineal para el texto original

    printf("Escriba el texto a cifrar (sin espacios):");
    scanf(" %s", texto);

    for(int i=0; i<ren; i++){
        for(int j=0; j<col; j++){
            escitala[i][j]=texto[k++];
        }
    }


    printf("El texto cifrado (leído de la tira) es:\n");
        
        for(int i=-0; i<col; i++){
            for(int j=0; j<ren; j++){
                printf("|%c|", escitala[j][i]);
            }
        }

        printf("\n");
}

void descifrarMensaje() {
    int ren, col, i, j, k = 0;

    printf("\n--- DESCIFRADO ---\n");
    printf("Ingresar el tamaño de la escítala (Renglones original): ");
    scanf("%d", &ren);
    printf("Ingresar el tamaño de la escítala (Columnas original): ");
    scanf("%d", &col);

    char escitala[ren][col];
    char texto[ren * col];

    printf("Escriba el texto cifrado: ");
    scanf("%s", texto);

        for(int i=0;i<col;i++){
        for(int j=0;j<ren;j++){
            escitala[j][i] = texto[k++];
        }
    }

    printf("El texto descifrado es:\n");

    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
            printf("|%c|", escitala[i][j]);
        }
    }

    printf("\n");
}

/*
PREGUNTA: En la implementación de una matriz auxiliar de dimensiones ren × col para realizar 
la transposición. 
-Si tuvieras una restricción de memoria severa y no pudieras crear esa matriz bidimensional, 
-¿qué fórmula matemática utilizarías para imprimir el carácter correcto directamente 
desde el arreglo original texto[] ?

k=(i*Columnas)+j

donde k va a ser el indice donde se encuentra el caracter correcto del arreglo unidimensional
j va a ser el valor de la iteración realizada para las columnas
columnas sera la cantidad de columnas que tiene la matriz
i es el valor de la iteración realizada para las filas.

se aplicaria de la siguiente forma.

for (int i = 0; i < filas; i++) {
    for (int j = 0; j < colum; j++) {
        // Esta es la magia:
        int indice = (j * colum) + i; 
        
        if (indice < lon) {
            printf("%c", texto[indice]);
        }
    }
}

Ya que por ejemplo si se tiene una cadena de {1,2,3,4,5,6,7,8,9}

y se ase uso de la fórmula y de los bucles primero i=0 y j=0 en la primera iteracion
quendo la fórmula de esta forma:

k=(0*3)+0 //Donde se elige que usuario eligio que la matriz sea de 3x3 por lo tanto columnas=3
k=0

y al imprimir text[k] pues se imprime texto[0]=1

ahora si que en este caso la fórmula lo que hace es ir avanzando de 3 en 3 y cada 3 posiciones
despues de la incial corresponderian al primer cambio para obtener la primera fila transpuesta
de la matriz.

*/
