#include <stdio.h>
#include <locale.h>
#include <math.h>

double Q(double X) {
    if (X < 50) {
        return 3 * log(X - 50 + 2) + 10;
    }
    else if (X <= 80) {
        return 2 * (X - 65) + 48;
    }
    else {
        return 5 * sqrt(X - 80 + 1) + 58;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    double X;
    printf("Введите X: ");
    scanf("%lf", &X);
    printf("Q(%.2f) = %.4f\n", X, Q(X));

    return 0;
}