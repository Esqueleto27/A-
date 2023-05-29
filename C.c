#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARRERAS 7
#define NUM_ANIOS 5

void generarDatosAleatorios(int datos[NUM_ANIOS][NUM_CARRERAS]) {
    srand(time(NULL));

    for (int i = 0; i < NUM_ANIOS; i++) {
        for (int j = 0; j < NUM_CARRERAS; j++) {
            datos[i][j] = rand() % 101;
        }
    }
}

void imprimirMatriz(int datos[NUM_ANIOS][NUM_CARRERAS]) {
    printf("Datos de ingreso de alumnos por año:\n");

    for (int i = 0; i < NUM_ANIOS; i++) {
        printf("Año %d: ", i + 2019);
        
        for (int j = 0; j < NUM_CARRERAS; j++) {
            printf("%d ", datos[i][j]);
        }
        
        printf("\n");
    }
}

void calcularAnioMasAlumnos(int datos[NUM_ANIOS][NUM_CARRERAS]) {
    int maxAlumnos = 0;
    int maxAnio = 0;

    for (int i = 0; i < NUM_ANIOS; i++) {
        if (datos[i][0] > maxAlumnos) {
            maxAlumnos = datos[i][0];
            maxAnio = i + 2019;
        }
    }

    printf("La carrera de Ingeniería de Software (carrera 1) recibió la mayor cantidad de alumnos en el año %d\n", maxAnio);
}

int main() {
    int alumnos[NUM_ANIOS][NUM_CARRERAS];

    generarDatosAleatorios(alumnos);
    imprimirMatriz(alumnos);
    calcularAnioMasAlumnos(alumnos);

    return 0;
}
