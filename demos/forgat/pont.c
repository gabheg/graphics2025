#include <stdio.h>
#include <math.h>

// Ha a M_PI nincs definiálva, akkor manuálisan definiáljuk
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// A szöget fokból radiánba konvertáló függvény
double toRadians(double angleInDegrees) {
    return angleInDegrees * (M_PI / 180.0);
}

// Elforgatás homogén koordinátákban
void rotatePointHomogeneous(double *x, double *y, double *w, double angleInDegrees) {
    double angleInRadians = toRadians(angleInDegrees);
    
    // Az elforgatás mátrix alkalmazása
    double newX = (*x) * cos(angleInRadians) - (*y) * sin(angleInRadians);
    double newY = (*x) * sin(angleInRadians) + (*y) * cos(angleInRadians);
    
    // Homogén koordináta nem változik (w = 1), ha nem történik transzláció
    *x = newX;
    *y = newY;
    // w-t nem kell változtatni, ha homogén koordinátában dolgozunk (w = 1)
}

// Kiírás homogén koordinátában
void printPoint(double x, double y, double w) {
    printf("Homogén koordináták: (%lf, %lf, %lf)\n", x, y, w);
}

int main() {
    double x, y, w = 1.0, angle;

    // Felhasználótól való adatbekérés
    printf("Add meg a pont x koordinatajat: ");
    scanf("%lf", &x);

    printf("Add meg a pont y koordinátáját: ");
    scanf("%lf", &y);

    printf("Add meg a forgatási szöget (fokban): ");
    scanf("%lf", &angle);

    printf("\nEredeti pont homogén koordinátákban: ");
    printPoint(x, y, w);
    
    rotatePointHomogeneous(&x, &y, &w, angle);

    printf("\nElforgatott pont homogén koordinátákban (%lf fokkal): ", angle);
    printPoint(x, y, w);

    return 0;
}
