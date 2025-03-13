#ifndef MATRIX_H
#define MATRIX_H

#define M_PI 3.14159265358979323846

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * define identity matrix
 */

void init_identity_matrix(int n, double matrix[n][n]);

// Skalárral való szorzás
void scale_matrix(int n, double matrix[n][n], double scalar);

// Mátrix szorzása
void multiply_matrices(int m, int n, int p, double A[m][n], double B[n][p], double C[m][p]);

//szorzott mátrixhoz kiírás
void print_matrix_m(int rows, int cols, double matrix[rows][cols]);

//transzformált mátrix kiírás
void print_matrix_t(double matrix[3][3]);

// Pont kiíratása
void print_point(double point[3]);

// A transform_point függvény, amely alkalmazza a transzformációt a ponton
void transform_point(double matrix[3][3], double point[3], double result[3]);

// Skálázás (origó középpontú)
void scale(double matrix[3][3], double Sx, double Sy);

// Forgatás (origó középpontú)
void rotate(double matrix[3][3], double theta);

// Elmozdítás (shift)
void shift(double matrix[3][3], double Tx, double Ty);

#endif // MATRIX_H

