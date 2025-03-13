#ifndef MATRIX_H
#define MATRIX_H

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

void print_matrix_s(int n, double matrix[n][n]);

void init_identity_matrix(int n, double matrix[n][n]);

void scale_matrix(int n, double matrix[n][n], double scalar);

void multiply_matrices(int m, int n, int p, double A[m][n], double B[n][p], double C[m][p]);

void print_matrix_m(int rows, int cols, double matrix[rows][cols]);

void print_matrix_t(double matrix[3][3]);

void print_point(double point[3]);

void transform_point(double matrix[3][3], double point[3], double result[3]);

void scale(double matrix[3][3], double Sx, double Sy);

void rotate(double matrix[3][3], double theta);

void shift(double matrix[3][3], double Tx, double Ty);


#endif // MATRIX_H

