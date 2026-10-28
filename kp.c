#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <locale.h>
#include <math.h>

double Q(double X);
int check_control(double q);

int main() {
    setlocale(LC_ALL, "RUS");

    double X1, X2;
    double q1, q2;
    int status1, status2;

    printf("Введите два последовательных показания X1 и X2: ");
    scanf("%lf %lf", &X1, &X2);

    if (X1 <= 48.0 || X2 <= 48.0) {
        printf("Ошибка: X должно быть больше 48 (ОДЗ логарифма).\n");
        return 1;
    }

    q1 = Q(X1);
    q2 = Q(X2);
    printf("Q(%.2lf) = %.4lf\n", X1, q1);
    printf("Q(%.2lf) = %.4lf\n", X2, q2);
    status1 = check_control(q1);
    status2 = check_control(q2);
    if (status1 == 0 && status2 == 0) {
        printf("Состояние: Отклонение (зафиксировано 2 выхода подряд)\n");
    }
    else {
        printf("Состояние: Норма\n");
    }

    return 0;
}

double Q(double X) {
    if (X < 50.0) {
        return 3 * log(X - 50 + 2) + 10;
    }
    else if (X <= 80.0) {
        return 2 * (X - 65) + 48;
    }
    else {
        return 5 * sqrt(X - 80 + 1) + 58;
    }
}

int check_control(double q) {
    double Q0 = 48.0;
    double tolerance = Q0 * 0.10;
    double lower_bound = Q0 - tolerance;
    double upper_bound = Q0 + tolerance;

    printf("Допустимый диапазон: [%.2lf; %.2lf]\n", lower_bound, upper_bound);
    if (q >= lower_bound && q <= upper_bound) {
        return 1;
    }
    else {
        return 0;
    }
}
