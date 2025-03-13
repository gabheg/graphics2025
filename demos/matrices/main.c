#include "matrix.h"
#include <stdio.h>

void print_matrix_s(int n, double matrix[n][n]);


int main(int argc, char* argv[])
{
    int m,n,p;
    double scalar;

	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);

    // Kérjünk be egy mátrix méretet
    printf("Add meg a mátrix méretét (n x n): ");
    scanf("%d", &n);

    // Deklarálunk egy n x n-es mátrixot
    double matrix[n][n];

    // Felhasználó által megadott egységmátrix inicializálása
    printf("Add meg az egységmátrix elemeit (diagonális értékek 1, a többi 0):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 1.0; // Átlóba 1
            } else {
                matrix[i][j] = 0.0; // Minden más elem 0
            }
        }
    }

    // Mátrix kiíratása
    printf("\nEredeti egységmátrix:\n");
    print_matrix_s(n, matrix);

    // Skalár beolvasása
    printf("\nAdd meg a skalárt: ");
    scanf("%lf", &scalar);

    // Skalárral való szorzás
    scale_matrix(n, matrix, scalar);

    // A mátrix kiíratása a skalárral való szorzás után
    printf("\nA mátrix a skalár %lf szorzásával:\n", scalar);
    print_matrix_s(n, matrix);

     // Kérjünk be két mátrix méretét
     printf("Add meg az A mátrix sorainak és oszlopainak számát (m x n): ");
     scanf("%d %d", &m, &n);
     
     printf("Add meg a B mátrix sorainak és oszlopainak számát (n x p): ");
     scanf("%d %d", &n, &p);  // n itt megegyezik, mert A oszlopainak száma = B sorainak száma
     
     // Deklarálunk három mátrixot: A, B és C
     double A[m][n], B[n][p], C[m][p];
     
     // A mátrix beolvasása
     printf("\nAdd meg az A mátrix elemeit (%d x %d):\n", m, n);
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             scanf("%lf", &A[i][j]);
         }
     }
     
     // B mátrix beolvasása
     printf("\nAdd meg a B mátrix elemeit (%d x %d):\n", n, p);
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < p; j++) {
             scanf("%lf", &B[i][j]);
         }
     }
     
     // Mátrix szorzás
     multiply_matrices(m, n, p, A, B, C);
     
     // Eredmény kiíratása
     printf("\nA mátrixok szorzata (A * B) = C:\n");
     print_matrix_m(m, p, C);

        // A transzformációs mátrix (például egy forgatás, transzformációs mátrix)
    double matrix[3][3] = {
        {0.866, -0.5, 0},  // Forgatás 30 fokkal
        {0.5, 0.866, 0},
        {0, 0, 1}
    };
    
    // A pont homogén koordinátákban (x, y, w)
    double point[3] = {1.0, 0.0, 1.0};  // (x, y, w)

    // Eredmény tárolása
    double result[3];

    // Pont transzformálása
    transform_point(matrix, point, result);

    // Eredmény kiíratása
    printf("Eredeti pont: ");
    print_point(point);
    
    printf("Transzformált pont: ");
    print_point(result);

    double matrix[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    };

    // Skálázás 2-szeresére mindkét irányban
    printf("Skálázás 2-szeresére:\n");
    scale(matrix, 2.0, 2.0);
    print_matrix(matrix);

    // Forgatás 45 fokkal
    printf("\nForgatás 45 fokkal:\n");
    rotate(matrix, 45.0);
    print_matrix(matrix);

    // Elmozdítás (shift) 3 egységgel x irányban és 2 egységgel y irányban
    printf("\nElmozdítás 3 egységgel x irányban és 2 egységgel y irányban:\n");
    shift(matrix, 3.0, 2.0);
    print_matrix(matrix);

    return 0;
}

