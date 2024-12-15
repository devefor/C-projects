#include <math.h>
#include <stdio.h>

const double eps = 0.0001;
const int max_iterarion = 1000;

double g(double x);
double g_derivative(double x);
double convergence(double start_segment, double end_segment);

int main(void)
{
    double start_segment = 0.0;
    double end_segment = 0.0;

    if (scanf("%lf %lf", &start_segment, &end_segment) != 2)
        return -1;

    // Проверяем, что границы отрезка находятся в области определения функции g(x)
    if (start_segment <= 0 || end_segment <= 0 || start_segment >= end_segment) {
        printf("no root\n");
        return 0;
    }

    // Проверяем на схожимость, что модуль производной на заданном промежутке для
    // всех итераций < 1
    double max_derivative = convergence(start_segment, end_segment);
    if (max_derivative >= 1) {
        printf("no root\n");
        return 0;
    }

    // Метод простой итерации
    double x0 = (start_segment + end_segment) / 2;
    double x1 = g(x0);
    int iteration = 1;

    while (fabs(x0 - x1) >= eps) {
        if (iteration > max_iterarion) {
            printf("no root\n");
            return 0;
        }
        x0 = x1;
        x1 = g(x0);
        iteration++;
    }

    if (x1 < start_segment || x1 > end_segment)
        printf("no root\n");
    else
        printf("%.4f\n", round(x1 * 10000) / 10000);
    return 0;
}

double g(double x) { return exp(1.0 / (4.0 * (1.0 + sqrt(x)))); }

double g_derivative(double x)
{
    return -1.0 * exp(1.0 / (4.0 * (1.0 + sqrt(x)))) / (8.0 * sqrt(x) * pow(1.0 + sqrt(x), 2));
}

double convergence(double start_segment, double end_segment)
{
    double max_value_derivative = 0.0;
    for (double x = start_segment; x < end_segment; x += (end_segment - start_segment) / max_iterarion) {
        double derivative = fabs(g_derivative(x));
        max_value_derivative = (derivative > max_value_derivative) ? derivative : max_value_derivative;
    }
    return max_value_derivative;
}