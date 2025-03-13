#include "matrix.h"

#include <stdio.h>

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_s(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(int n, double matrix[n][n]) {
    // Minden elemet 0-ra állítunk
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 1.0;  // Átlóba 1 kerül
            } else {
                matrix[i][j] = 0.0;  // Minden más helyre 0
            }
        }
    }
}

// Skalárral való szorzás
void scale_matrix(int n, double matrix[n][n], double scalar) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] *= scalar;  // Minden elem szorzása a skalárral
        }
    }
}

// Mátrix szorzása
void multiply_matrices(int m, int n, int p, double A[m][n], double B[n][p], double C[m][p]) {
    // A mátrix szorzás szabálya szerint:
    // C[i][j] = Σ (A[i][k] * B[k][j]) a k = 0, 1, ..., n-1 (n a közös dimenzió)
    
    // Inicializáljuk a C mátrixot nullákra
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0.0;
        }
    }
    
    // Mátrix szorzás
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix_m(int rows, int cols, double matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_t(double matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Pont kiíratása
void print_point(double point[3]) {
    printf("(%lf, %lf, %lf)\n", point[0], point[1], point[2]);
}

// A transform_point függvény, amely alkalmazza a transzformációt a ponton
void transform_point(double matrix[3][3], double point[3], double result[3]) {
    // Homogén koordináták transzformációja: result = matrix * point
    for (int i = 0; i < 3; i++) {
        result[i] = 0.0;
        for (int j = 0; j < 3; j++) {
            result[i] += matrix[i][j] * point[j];
        }
    }
}


// Skálázás (origó középpontú)
void scale(double matrix[3][3], double Sx, double Sy) {
    matrix[0][0] *= Sx;
    matrix[1][1] *= Sy;
}

// Forgatás (origó középpontú)
void rotate(double matrix[3][3], double theta) {
    // Szög átalakítása radianba
    double rad = theta * M_PI / 180.0;
    
    double cos_theta = cos(rad);
    double sin_theta = sin(rad);
    
    // A forgatás mátrix alkalmazása
    double rotation_matrix[3][3] = {
        {cos_theta, -sin_theta, 0},
        {sin_theta, cos_theta, 0},
        {0, 0, 1}
    };
    
    // Eredeti mátrix szorzása a forgatás mátrixával
    double result[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result[i][j] += matrix[i][k] * rotation_matrix[k][j];
            }
        }
    }

    // Eredmény visszamásolása az eredeti mátrixba
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = result[i][j];
        }
    }
}

// Elmozdítás (shift)
void shift(double matrix[3][3], double Tx, double Ty) {
    matrix[0][2] += Tx;
    matrix[1][2] += Ty;
}


