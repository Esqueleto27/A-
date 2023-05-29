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

void calcularCarreraMasAlumnos(int datos[NUM_ANIOS][NUM_CARRERAS]) {
    int totalAlumnosPorCarrera[NUM_CARRERAS] = {0};
    int maxAlumnos = 0;
    int maxCarrera = 0;

    for (int i = 0; i < NUM_ANIOS; i++) {
        for (int j = 0; j < NUM_CARRERAS; j++) {
            totalAlumnosPorCarrera[j] += datos[i][j];
        }
    }

    for (int i = 0; i < NUM_CARRERAS; i++) {
        if (totalAlumnosPorCarrera[i] > maxAlumnos) {
            maxAlumnos = totalAlumnosPorCarrera[i];
            maxCarrera = i;
        }
    }

    printf("La carrera que recibió la mayor cantidad de alumnos en el último año es la carrera %d\n", maxCarrera + 1);
}

int main() {
    int alumnos[NUM_ANIOS][NUM_CARRERAS];

    generarDatosAleatorios(alumnos);
    imprimirMatriz(alumnos);
    calcularCarreraMasAlumnos(alumnos);

    return 0;
}
